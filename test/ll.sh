clang++ ll_test.cpp -emit-llvm -S -o ll_test.ll $1 
cat ll_test.ll