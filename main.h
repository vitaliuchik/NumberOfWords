//
// Created by danyl on 4/5/2020.
//

#ifndef COUNTWORDS_MAIN_H
#define COUNTWORDS_MAIN_H

#include <iostream>
#include <map> // A map will be used to count the words.
#include <boost/algorithm/string.hpp>
#include <boost/locale.hpp>
#include <string>
#include "file_to_vector.h"
#include <cstdio>
#include "multithread.h"
#include "file_to_vector.h"


void printMap(const std::map<std::string, unsigned int>& map);
int writeKeySortedMap(const std::string& fileName, std::map<std::string, unsigned int> *map);
int writeValueSortedMap(const std::string& fileName, std::map<std::string, unsigned int> mapCount);
static void oneThreadCount(const std::string& in, const std::string& outA, const std::string& outN);

#endif //COUNTWORDS_MAIN_H
