//
// Created by danyl on 4/5/2020.
//

#ifndef COUNTWORDS_FILE_TO_VECTOR_H
#define COUNTWORDS_FILE_TO_VECTOR_H

#include <iostream>
#include <archive.h>
#include <archive_entry.h>
#include <vector>
#include <fstream>
#include <boost/locale.hpp>
#include <boost/locale/boundary.hpp>
#include "multithread.h"
#include "main.h"

std::string archive_to_memory(std::string &buffer);
std::string read_archive (std::string &file_in);
std::string read_txt (std::string &file_in);
std::vector<std::string> extract_words(std::string &file_in);

#endif //COUNTWORDS_FILE_TO_VECTOR_H
