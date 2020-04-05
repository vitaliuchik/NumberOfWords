cmake_minimum_required(VERSION 3.10)
project(CountWords)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
#set(LibArchive_INCLUDE_DIR "/usr/local/Cellar/libarchive/3.4.2_1/include")
find_package(LibArchive REQUIRED)
find_package(Boost COMPONENTS filesystem program_options system locale REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${LibArchive_INCLUDE_DIR})
#include_directories('/usr/local/opt/libarchive')
#include_directories(/usr/local/Cellar/libarchive/3.2.1/lib/libarchive.dylib')
add_executable(CountWords main.cpp multithread.cpp file_to_vector.cpp file_to_vector.h main.h multithread.h one_threaded.cpp one_threaded.h time_counting.h)
TARGET_LINK_LIBRARIES(CountWords LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(CountWords LINK_PUBLIC ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(CountWords LINK_PUBLIC ${LibArchive_LIBRARIES})
#SET( MAIN_EXE сount_words)
#add_executable(count_words main.cpp)



