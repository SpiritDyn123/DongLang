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

#macro

add_definitions(-DIN_DEV)
add_definitions(-DCUSTOM_PASS_OPR=1) #pass操作0无pass 1使用legacy  2使用new

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
)  

file(GLOB SRC_BK_FILES
	${PROJECT_SOURCE_DIR}/backend/*.cpp
	${PROJECT_SOURCE_DIR}/backend/pass/*.cpp
	${PROJECT_SOURCE_DIR}/backend/pass/FunctionSymbol/*.cpp
)

#llvm pass nortti需要单独设置编译选项
set_source_files_properties(
	${PROJECT_SOURCE_DIR}/backend/pass/FunctionSymbol/FunctionSymbolPass.cpp
	${PROJECT_SOURCE_DIR}/backend/pass/CustomPass.cpp
	PROPERTIES COMPILE_FLAGS "-fno-rtti"
)

#message(STATUS "SRC_FILES:${PROJECT_SOURCE_DIR} ${SRC_FILES}")

add_executable(DongLang main.cpp ${SRC_FILES}
	${SRC_BK_FILES}
)

execute_process(COMMAND llvm-config  --system-libs --libs all
	OUTPUT_VARIABLE LLVM_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(REPLACE "\n" " " LLVM_LIBS "${LLVM_LIBS}")

#message(STATUS "llvm_cxx_flags:${LLVM_CXX_FLAGS} \n llvm_libs:${LLVM_LIBS}")

# link libraries
target_link_libraries(DongLang
	"${LLVM_LIBS}"
	antlr4-runtime
	gflags
	gmock
	gmock_main)

