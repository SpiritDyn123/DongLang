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
	${PROJECT_SOURCE_DIR}/backend/*.cpp

    #${PROJECT_SOURCE_DIR}/font/**/*.cpp # 从src目录及其子目录中查找  
)  

#message(STATUS "SRC_FILES:${PROJECT_SOURCE_DIR} ${SRC_FILES}")

add_executable(DongLang main.cpp ${SRC_FILES})

execute_process(COMMAND llvm-config --cxxflags
	OUTPUT_VARIABLE LLVM_CXX_FLAGS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

#添加会导致有些library报错
#string(APPEND CMAKE_CXX_FLAGS " ${LLVM_CXX_FLAGS}")  

execute_process(COMMAND llvm-config  --system-libs --libs all
	OUTPUT_VARIABLE LLVM_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(REPLACE "\n" " " LLVM_LIBS "${LLVM_LIBS}")

message(STATUS "llvm_cxx_flags:${LLVM_CXX_FLAGS} \n llvm_libs:${LLVM_LIBS}")

# link libraries
if(1)
	target_link_libraries(DongLang
		"${LLVM_LIBS}"
		antlr4-runtime
		gflags
		gmock
		gmock_main)

endif()
