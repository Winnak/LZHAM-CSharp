// This is the main DLL file.

#pragma once

#include "stdafx.h"

#include "LZHAMWrapper.h"


#define BUFFER_SIZE (1024 * 1024)

/// Compresses input
array<byte>^ LZHAM::Comrpess(array<byte>^ input) // because no default arguments.
{
    return LZHAM::Comrpess(input, Z_BEST_COMPRESSION);
}

/// Compresses input
array<byte>^ LZHAM::Comrpess(array<byte>^ input, int level)
{
    pin_ptr<byte> data = &input[0];

    byte buffer[BUFFER_SIZE];

    // Create a stream
    z_stream stream;
    stream.zalloc = 0;
    stream.zfree = 0;
    stream.opaque = 0;
    stream.avail_in = input->Length;
    stream.next_in = (Bytef*)data;
    stream.avail_out = sizeof(buffer);
    stream.next_out = (Bytef*)buffer;

    //compress
    deflateInit(&stream, level);
    deflate(&stream, Z_FINISH);
    deflateEnd(&stream);

    //convert to managed array
    array<byte>^ result = gcnew array<byte>(stream.total_out);
    System::Runtime::InteropServices::Marshal::Copy(IntPtr(buffer), result, 0, stream.total_out);

    return result;
}

/// Decompresses input
array<byte>^ LZHAM::Decompress(array<byte>^ input)
{
    pin_ptr<byte> data = &input[0];
    byte outbuffer[BUFFER_SIZE];

    // create a stream
    z_stream destream;
    destream.zalloc = 0;
    destream.zfree = 0;
    destream.opaque = 0;
    destream.avail_in = input->Length;
    destream.next_in = (Bytef*)data;
    destream.avail_out = sizeof(outbuffer);
    destream.next_out = (Bytef*)outbuffer;

    //decompress
    inflateInit(&destream);
    inflate(&destream, Z_NO_FLUSH);
    inflateEnd(&destream);

    //convert to managed array
    array<byte>^ result = gcnew array<byte>(destream.total_out);
    System::Runtime::InteropServices::Marshal::Copy(IntPtr(outbuffer), result, 0, destream.total_out);

    return result;
}