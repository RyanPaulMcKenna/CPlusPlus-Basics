#include <iostream>

using namespace std;

int main() {
    int number = 7; // 0111
    int count = 0;

    // Simple way
    while(number)
    {
        count = count + (number & 1);
        number >>= 1;
    }
    cout << count << endl;

    // Brian Kernighan's way
    for (count = 0; number ; ++count) { // if number is zero, is same as false.
        number &= number-1;
    }
    cout << count << endl;
}