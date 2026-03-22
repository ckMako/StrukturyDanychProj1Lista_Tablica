#wersja cmake
cmake_minimum_required(VERSION 3.28)
project(algoSortowanie)
#wersja c++
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp src/singleLinkedList.cpp src/cell.cpp)
#dodaj inc do headers


# Add inc
include_directories(${CMAKE_SOURCE_DIR}/inc)