#ifndef COUNTWORDS_MULTITHREAD_H
#define COUNTWORDS_MULTITHREAD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <cmath>


void wordsCounting(std::vector<std::string>::iterator wordsIterBegin, std::vector<std::string>::iterator wordsIterEnd, std::map<std::string, unsigned int>& res_map);
void mapsJoin(std::map<std::string, unsigned int>& res_map, std::map<std::string, unsigned int>& map_to_join);
void multiThreadCount(const std::string& in, const std::string& outA, const std::string& outN, int threadsNum);

#endif //COUNTWORDS_MULTITHREAD_H
