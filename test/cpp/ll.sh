clang++ test.cpp -emit-llvm -S -o test.ll $1 
cat test.ll
