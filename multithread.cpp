//
// Created by danyl on 4/4/2020.
//

#include "multithread.h"

#include "file_to_vector.h"
#include "time_counting.h"
#include "one_threaded.h"

//#define DebugOutput


void wordsCounting(std::vector<std::string>::iterator wordsIterBegin, std::vector<std::string>::iterator wordsIterEnd, std::map<std::string, unsigned int>& res_map) {
    for (auto it = wordsIterBegin ; it != wordsIterEnd; ++it) {
        //Look if it's already there.
        if (res_map.find(*it) == res_map.end()) // encountered the word for a first time.
            res_map[*it] = 1; // initialize in map to 1.
        else
            ++res_map[*it]; // increment if already met word.
    }
}

void mapsJoin(std::map<std::string, unsigned int>& res_map, std::map<std::string, unsigned int>& map_to_join) {
    for (const auto& elem: map_to_join) {
        if (res_map.find(elem.first) == res_map.end()) {
            res_map[elem.first] = elem.second;
        }
        else {
            res_map[elem.first] += elem.second;
        }
    }
}


void multiThreadCount(const std::string& in, const std::string& outA, const std::string& outN, int threadsNum){
    std::vector<std::string> words = extract_words((std::string &) in);

    auto analizingStart = get_current_time_fenced();

    std::vector<std::thread> threads_v(threadsNum);
    std::vector<std::map<std::string, unsigned int>> map_v(threadsNum);

    const int iterStep = static_cast<int>(words.size()/threadsNum);

    for (int i = 0; i < threads_v.size(); ++i) {
        threads_v[i] = std::thread{
                wordsCounting,
                words.begin() + i*iterStep,
                words.begin() + (i+1)*iterStep,
                std::ref(map_v[i])
        };
    }

    for(auto& t: threads_v) {
        t.join();
    }

    int numOfActiveMaps = threadsNum;
    int j = 1;
    while (numOfActiveMaps > 1) {
#ifdef DebugOutput
        std::cout << "numOfActiveMaps = " << static_cast<int>(numOfActiveMaps) << std::endl;
#endif
        for (int i = 0; i < static_cast<int>(numOfActiveMaps/2); ++i) {
#ifdef DebugOutput
            std::cout << "thread " << i*j*2 << " is joining " << i*j*2 << " and " << i*j*2 + j << " maps" << std::endl;
#endif
            threads_v[i*j*2] = std::thread{
                mapsJoin,
                std::ref(map_v[i*j*2]),
                std::ref(map_v[i*j*2 + j])
            };
        }


        for (int i = 0; i < static_cast<int>(numOfActiveMaps/2); ++i) {
            threads_v[i*j*2].join();
        }



        numOfActiveMaps = static_cast<int>(std::ceil(static_cast<float>(numOfActiveMaps)/2));
        j *= 2;


    }

    auto analizingFinish = get_current_time_fenced();
    auto analizing_time = analizingFinish - analizingStart;
    std::cout << "Analyzing: " << to_us(analizing_time) << std::endl;
    writeKeySortedMap("../"+outA.substr (1,outN.length()-2), map_v[0]);
    writeValueSortedMap("../"+outN.substr (1,outN.length()-2), map_v[0]);


//    std::map<std::string, unsigned int> wordsCount;
//    for (int i = 0; i < map_v.size(); ++i) {
//        mapsJoin(std::ref(wordsCount),std::ref(map_v[i]));
//    }
//    writeKeySortedMap("../"+outA.substr (1,outN.length()-2), &wordsCount);
//    writeValueSortedMap("../"+outN.substr (1,outN.length()-2), wordsCount);

}

