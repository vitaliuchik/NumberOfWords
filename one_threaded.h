#ifndef COUNTWORDS_ONE_THREADED_H
#define COUNTWORDS_ONE_THREADED_H

#include <string>
#include <map>
#include <cstdio>
#include <boost/algorithm/string.hpp>
#include <boost/locale.hpp>
#include <iostream>

void writeKeySortedMap(const std::string& fileName, std::map<std::string, unsigned int>& map);
void writeValueSortedMap(const std::string& fileName, std::map<std::string, unsigned int>& mapCount);
void oneThreadCount(const std::string& in, const std::string& outA, const std::string& outN);

#endif //COUNTWORDS_ONE_THREADED_H
