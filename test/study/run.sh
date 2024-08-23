cppFile=pass_test.cpp
if [ ! -z "$1" ];then
	cppFile=$1
fi

clang++ $cppFile `llvm-config --cxxflags --ldflags --system-libs --libs core` -g
