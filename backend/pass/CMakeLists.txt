#�ο� https://missking.cc/2020/09/11/llvm2/
cmake_minimum_required(VERSION 3.22)
project(customPass)
set(LLVM_DIR /data/app/llvm/)

set(CMAKE_CXX_STANDARD 17)

#llvm-config --cxxflags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-rtti") #-fno-rtti

if(DEFINED LEGACY )
	if( LEGACY EQUAL 1)
		message(STATUS "has legacy pass")
		add_definitions(-DOPT_LEGACY_PASS)
	endif()
endif()

add_definitions(-DOPT_LOAD_PLUGIN)

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
add_subdirectory(FunctionSymbol)