
#include "main.h"

#include "one_threaded.h"
#include "multithread.h"
#include "time_counting.h"
#include "file_to_vector.h"

int main(int argc, char *argv[]) {
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
    int threadsNum;
    std::string conf = read_txt(conf_file);
    std::vector<std::string> confArgs;
    boost::split(confArgs, conf, boost::is_any_of("\n="));

    if (!confArgs[1].empty() && !confArgs[3].empty() && !confArgs[5].empty() && !confArgs[7].empty()){
        inFile = confArgs[1];
        outByA = confArgs[3];
        outByN = confArgs[5];
        threadsNum = std::stoi(confArgs[7]);
    }
    else
        throw InvalidConfigurationException();
    auto totalStart = get_current_time_fenced();
    if (threadsNum == 1){
        oneThreadCount(inFile, outByA, outByN);
    }
    else if (threadsNum > 1 ){
        multiThreadCount(inFile, outByA, outByN, threadsNum);
    }
    else {
        throw InvalidConfigurationException();
    }
    auto totalFinish = get_current_time_fenced();
    auto total_time = totalFinish- totalStart;
    std::cout << "Total: " << to_us(total_time) << std::endl;
    return EXIT_SUCCESS;
}