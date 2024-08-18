cmake_minimum_required(VERSION 3.22)
project(CustomPass VERSION 1.0)  

set(CMAKE_CXX_STANDARD 17)  

include(ProcessorCount)
ProcessorCount(PROCESSOR_COUNT)
set(CMAKE_BUILD_PARALLEL_LEVEL ${PROCESSOR_COUNT})

set(CMAKE_CXX_COMPILER clang++)

# µ÷ÊÔÐÅÏ¢
set(CMAKE_CXX_FLAGS "-g")

#include
include_directories(
	. 
	/data/app/llvm/include
)

#libraries path
link_directories(
	/data/app/llvm/lib/
)

# app cpp files
file(GLOB_RECURSE SRC_FILES 
	./*.cpp
)  

add_library(CustomPass SHARED ${SRC_FILES})

execute_process(COMMAND llvm-config --cxxflags
	OUTPUT_VARIABLE LLVM_CXX_FLAGS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(COMMAND llvm-config  --system-libs --libs all
	OUTPUT_VARIABLE LLVM_LIBS
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(REPLACE "\n" " " LLVM_LIBS "${LLVM_LIBS}")

target_link_libraries(CustomPass
	"${LLVM_LIBS}"
	)

