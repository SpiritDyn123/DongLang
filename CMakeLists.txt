cmake_minimum_required(VERSION 3.22)  
project(DongLang VERSION 1.0)  

set(CMAKE_CXX_STANDARD 17)  

include(ProcessorCount)
ProcessorCount(PROCESSOR_COUNT)
message(STATUS "processor_cnt:${PROCESSOR_COUNT}")

set(CMAKE_BUILD_PARALLEL_LEVEL ${PROCESSOR_COUNT})

#可能不起作用

set(CMAKE_CXX_COMPILER clang++)

# 调试信息
set(CMAKE_CXX_FLAGS "-g")

#include
include_directories(
	. 
	/data/app/llvm/include
	/data/app/antlr4-runtime/cpp/include/antlr4-runtime) 

#libraries path
link_directories(
	/data/app/llvm/lib/
	/data/app/antlr4-runtime/cpp/lib/
)

# app cpp files
file(GLOB_RECURSE SRC_FILES 
	${PROJECT_SOURCE_DIR}/font/*.cpp
	${PROJECT_SOURCE_DIR}/src/*.cpp
    #${PROJECT_SOURCE_DIR}/font/**/*.cpp # 从src目录及其子目录中查找  
)  

message(STATUS "SRC_FILES:${PROJECT_SOURCE_DIR} ${SRC_FILES}")

add_executable(DongLang main.cpp ${SRC_FILES})

# link libraries
if(1)
	target_link_libraries(DongLang
		LLVMCore
		LLVMRemarks
		LLVMBitstreamReader
		LLVMBinaryFormat
		LLVMTargetParser
		LLVMSupport
		LLVMDemangle
		rt
		dl
		m
		z
		zstd
		tinfo
		xml2
		antlr4-runtime
		gflags
		gmock
		gmock_main)

endif()
