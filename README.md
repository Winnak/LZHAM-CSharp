# [LZHAM](https://github.com/richgel999/lzham_codec) for C# #

To compress a byte array in C# use:
```csharp
LZHAM.Compress(byte[], int (default = 9)) : byte[]
```
To decompress a byte array in C# use:
```csharp
LZHAM.Decompress(byte[]) : byte[]
```
Example: 
```csharp
using System;
using System.Text;

namespace LZHAMExample
{
    class Program
    {
        static void Main(string[] args)
        {
            string raw = 
@"Hello world, Hello world, Hello world, Hello world, Hello world, Hello world,
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world, 
Hello world, Hello world, Hello world, Hello world, Hello world, Hello world.";

            byte[] data = Encoding.Unicode.GetBytes(raw); // Convert to bytes

            byte[] compressed = LZHAM.Comrpess(data);
            byte[] decompresed = LZHAM.Decompress(compressed);

            string output = Encoding.Unicode.GetString(decompresed);

            Console.WriteLine(output == raw); // Should be true.
            
            Console.ReadKey();
        }
    }
}
```
