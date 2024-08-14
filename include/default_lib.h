#pragma once
#include <iostream>
using namespace std;

const string defaultLibContent = R"(
extern C func int printf(string fmt, ...);
extern C func byte* memcpy(byte *dst, byte*src, int len);
)";