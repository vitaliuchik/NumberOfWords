
#include "one_threaded.h"

#include "time_counting.h"
#include "file_to_vector.h"

class InvalidConfigurationException;

void writeKeySortedMap(const std::string& fileName, std::map<std::string, unsigned int>& map) {
    FILE *fp = fopen(fileName.c_str(), "w");
    for(auto & it : map) {
        fprintf(fp, "%s : %u\n", it.first.c_str(), it.second);
    }

    fclose(fp);
}

void writeValueSortedMap(const std::string& fileName, std::map<std::string, unsigned int>& map){
    FILE *fp = fopen(fileName.c_str(), "w");
    typedef std::function<bool(std::pair<std::string, unsigned int>, std::pair<std::string, unsigned int>)> Comparator;
    // Lambda function to compare two pairs.
    Comparator compFunctor =
            [](const std::pair<std::string, int>& elem1 ,const std::pair<std::string, int>& elem2)
            {
                return elem1.second > elem2.second;
            };
    std::set<std::pair<std::string, int>, Comparator> sortedMap(
            map.begin(), map.end(), compFunctor);
    for (std::pair<std::string, unsigned int> iter : sortedMap)
        fprintf(fp, "%s : %u\n", iter.first.c_str(), iter.second);

    fclose(fp);
}

void oneThreadCount(const std::string& in, const std::string& outA, const std::string& outN){

    std::vector<std::string> words = extract_words((std::string &) in);
    // Start of counting words occurrences in file
    auto analizingStart = get_current_time_fenced();
    std::map<std::string, unsigned int> wordsCount;
    for (auto &word: words){
        //Look if it's already there.
        if (wordsCount.find(word) == wordsCount.end()) // encountered the word for a first time.
            wordsCount[word] = 1; // initialize in map to 1.
        else
            wordsCount[word]++; // increment if already met word.
    }
    auto analizingFinish = get_current_time_fenced();
    auto analizing_time = analizingFinish - analizingStart;
    std::cout << "Analyzing: " << to_us(analizing_time) << std::endl;

    // Start writing words occurrences to file
    auto wtitingStart = get_current_time_fenced();
    writeKeySortedMap("../"+outA.substr (1,outN.length()-2), wordsCount);
    writeValueSortedMap("../"+outN.substr (1,outN.length()-2), wordsCount);
    auto writingFinish = get_current_time_fenced();
    auto writing_time = writingFinish - wtitingStart;

}
