#include <iostream>
using namespace std;

struct A {
    int x;      // 4 bytes
    double d;   // 8 bytes
};

// |x|x|x|x|-|-|-|-|d|d|d|d|d|d|d|d| = 16 bytes

struct B
{
    int y;      // 4 bytes
    A a;        // 16 bytes, the same logic to above does not apply.
                // B will look inside A and check the largest which will be 8
                // So the memory will be assorted in blocks of 8 bytes, not 16.
};
// Like this:
// |y|y|y|y|-|-|-|-|x|x|x|x|-|-|-|-|d|d|d|d|d|d|d|d| = 24 bytes.

// Not like this:
// |y|y|y|y|-|-|-|-|-|-|-|-|-|-|-|-|x|x|x|x|-|-|-|-|d|d|d|d|d|d|d|d| = 32 bytes

// The order of your variables matter.

int main () {
    cout << sizeof(B) << endl;
    return 0;
}
