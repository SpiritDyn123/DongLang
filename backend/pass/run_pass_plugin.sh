#legacy
#opt  --bugpoint-enable-legacy-pm -load ./cbuild/FunctionSymbol/libfunSymbol.so -funsymbol ../../tmp.ll
opt --load-pass-plugin ./FunctionSymbol/libfunSymbol.so -p funsymbol ../../tmp.ll -S
