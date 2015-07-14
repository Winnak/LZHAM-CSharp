// CLR_LZHAM.h

#pragma once

#define byte unsigned char

using namespace System;

public ref class LZHAM
{
public: 
    static array<byte>^ Comrpess(array<byte>^ input);
    static array<byte>^ Comrpess(array<byte>^ input, int level);
    static array<byte>^ Decompress(array<byte>^ input); 
};
