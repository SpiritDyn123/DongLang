#!/bin/bash

cppFile=pass_test.cpp
if [ ! -z "$1" ];then
	cppFile=$1
fi

cFlags=${@:2:${#@}-1}
echo "cFlags:" $cFlags
clang++ $cppFile `llvm-config --cxxflags --ldflags --system-libs --libs all` $cFlags
