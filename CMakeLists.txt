cmake_minimum_required(VERSION 3.8)
project(cpp_ex3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/MemPool.cpp hdr/MemPool.h src/MemoryManager.cpp hdr/MemoryManager.h)
add_executable(cpp_ex3 ${SOURCE_FILES})