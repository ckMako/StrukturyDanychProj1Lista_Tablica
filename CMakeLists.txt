#wersja cmake
cmake_minimum_required(VERSION 3.28)
project(algoSortowanie)
#wersja c++
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp src/singleLinkedList.cpp src/cell.cpp src/tempCodeRunnerFile.cpp)
#dodaj inc do headers
target_include_directories(${PROJECT_NAME} PRIVATE inc)