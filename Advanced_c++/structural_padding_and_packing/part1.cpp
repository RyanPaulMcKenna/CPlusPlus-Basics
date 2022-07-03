// Question: What is structural padding and packing in c and c++?
// Answers: It is a way to speed up cpu optimization.

#include <iostream>
using namespace std;

// padding adds extra bits packing does not.

// #pragma pack(1) // disable padding, pack instead.

struct Base {
    char a;         // 1 byte
    char b;         // 1 byte
    char c;         // 1 byte
    // 1 padding byte.
    int i;          // 4 bytes
};

// |a|b|c|-|i|i|i|i|
//  0 1 2 3 4 5 6 7 = 8 bytes.

// 4 bytes data type will store itself at multiple of 4 memory slot.

int main() {
    cout << sizeof(Base) << endl;
}

// 1 word is 4 Byte in 32 bit processor
// 1 word is 8 byte in 64 bit processor

/*

------------------------CASE 1-------------------------
struct Base {
    char a;
    char b;
    int i;
}

|a|b|-|-|i|i|i|i|
 0 1 2 3 4 5 6 7 = 8 bytes

-----------------------CASE 2----------------------------

struct Base {
    char a;
    int i;
    char b;
}

|a|-|-|-|i|i|i|i|b|-|-|-|
 0 1 2 3 4 5 6 7 8 9 10 11 = 12 bytes
--------------------------------------------------------

when you run your program it gets divided into pages and is stored in your hard drive
Each page is then loaded in to ram this is called segment

// 32 bit processor can process 32 bits at a time, in one clock cycle
// 64 bit processor can process 64 bits at a time, in one clock cycle 

32-bit processor example:
struct Base {
    char a;
    char b;
    int i
};

    if the data was stored like this and we read 32 bits = 4 bytes
    |a|b|i|i|i|i
    we would read |a|b|i|i| and have to read again to get the order half of the int |i|i|-|-|
    This is inefficient. By using padding we can store the data in 32 bit blocks like so.
    |a|b|-|-|i|i|i|i| 
    we would read 32 bits = 4 bytes on the first clock cycle |a|b|-|-|
    and a further 32 bits= 4 bytes on the second clock cycle |i|i|i|i|  

    These 32 bit reads are called pages or segments.
    divide memory into segments.
    If it is stored in hard disk it is called pages.
    If it is stored in memory (RAM) or processor memory, it is called segments.
    This is the concept of paging.

    How data gets memory slots, memory mapping.

    1 Byte ==> can be stored at multiple of 1 memory slot
    2 Byte ==> can be stored at multiple of 2 memory slot
    4 Byte ==> can be stored at multiple of 4 memory slot
    8 Byte ==> can be stored at multiple of 8 memory slot


*/