#²Î¿¼ https://missking.cc/2020/09/11/llvm2/
cmake_minimum_required(VERSION 3.22)
project(customPass)
set(LLVM_DIR /data/app/llvm/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-rtti") #-fno-rtti

find_package(LLVM REQUIRED CONFIG)
#list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
#include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
add_subdirectory(FunctionSymbol)