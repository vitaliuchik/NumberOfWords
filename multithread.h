//
// Created by danyl on 4/5/2020.
//

#ifndef COUNTWORDS_MULTITHREAD_H
#define COUNTWORDS_MULTITHREAD_H

#include <string>
#include <vector>
#include <map>
#include <thread>
#include <cmath>
#include "file_to_vector.h"
#include "main.h"

void wordsCounting(std::vector<std::string>::iterator wordsIterBegin, std::vector<std::string>::iterator wordsIterEnd, std::map<std::string, unsigned int>& res_map);
void mapsJoin(std::map<std::string, unsigned int>& res_map, std::map<std::string, unsigned int>& map_to_join);
void multiThreadCount(const std::string& in, const std::string& outA, const std::string& outN, int threadsNum);

#endif //COUNTWORDS_MULTITHREAD_H
