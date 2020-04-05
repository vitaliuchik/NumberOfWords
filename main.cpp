#include "multithread.h"
#include "file_to_vector.h"
#include "main.h"

void printMap(const std::map<std::string, unsigned int>& map)
{
    typedef typename std::map<std::string , int>::iterator iterator;
    for (auto & item : map)
        std::cout << item.first << ": " << item.second << std::endl;
}

int writeKeySortedMap(const std::string& fileName, std::map<std::string, unsigned int> *map) {
    int count = 0;
    if (map->empty())
        return 0;

    FILE *fp = fopen(fileName.c_str(), "w");
    if (!fp)
        return -errno;
    for(auto & it : *map) {
        fprintf(fp, "%s : %u\n", it.first.c_str(), it.second);
        count++;
    }

    fclose(fp);
    return count;
}

int writeValueSortedMap(const std::string& fileName, std::map<std::string, unsigned int> mapCount){
    std::multimap<unsigned int, std::string> multiMap;
    std::map<std::string, unsigned int> :: iterator it;
    FILE *fp = fopen(fileName.c_str(), "w");

    for (it=mapCount.begin(); it!=mapCount.end(); it++)
    {
        multiMap.insert(make_pair(it->second, it->first));
    }

    std::multimap<unsigned int, std::string> :: iterator iter;
    if (!fp)
        return -errno;
    for (iter=multiMap.begin(); iter!=multiMap.end(); iter++)
    {
        // order of (key,value) is reversed in the multimap
        fprintf(fp, "%s : %u\n", iter->second.c_str(), iter->first);
    }
    return 1;
};


static void oneThreadCount(const std::string& in, const std::string& outA, const std::string& outN){
        std::vector<std::string> words = extract_words((std::string &) in);
        std::map<std::string, unsigned int> wordsCount;
        for (auto &word: words){
                //Look if it's already there.
                if (wordsCount.find(word) == wordsCount.end()) // encountered the word for a first time.
                    wordsCount[word] = 1; // initialize in map to 1.
                else
                    wordsCount[word]++; // increment if already met word.
        }
        // Print the words map.
//        printMap(wordsCount);
        writeKeySortedMap("../"+outA.substr (1,outN.length()-2), &wordsCount);
        writeValueSortedMap("../"+outN.substr (1,outN.length()-2), wordsCount);

}


int main(int argc, char *argv[]) {
    std::cout << "ho there" <<std::endl;
    std::string conf_file;
    if (argc == 2) {
        conf_file = argv[1];
    } else if (argc == 1) {
        conf_file = "../config.dat";
    } else {
        std::cerr << "Invalid arguments.\n";
        exit(1);
    }
    std::string inFile, outByA, outByN;
    int threadsNum=0;
    std::string conf = read_txt(conf_file);
    std::vector<std::string> confArgs;
    boost::split(confArgs, conf, boost::is_any_of("\n"));

    std::vector<std::string> in;
    boost::split(in, confArgs[0], boost::is_any_of("="));
    inFile = in[1];
    boost::erase_all(inFile, "'");

    std::vector<std::string> out;
    boost::split(out, confArgs[1], boost::is_any_of("="));
    outByA = out[1];

    std::vector<std::string> out1;
    boost::split(out1, confArgs[2], boost::is_any_of("="));
    outByN = out1[1];

    std::vector<std::string> thr;
    boost::split(thr, confArgs[3], boost::is_any_of("="));
    threadsNum = std::stoi(thr[1]);



    if (threadsNum == 1){
        oneThreadCount(inFile, outByA, outByN);
        std::cout << "done" << std::endl;
    }
    else{
        multiThreadCount(inFile, outByA, outByN, threadsNum);

    }
    std::cout << "done" << std::endl;
    return EXIT_SUCCESS;
}