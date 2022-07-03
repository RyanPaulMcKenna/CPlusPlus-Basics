#include <iostream>

using namespace std;

int main() {
    // SET ONE BIT

    int number = 3; // 0011
    // 0111
    // set one bit [ use of bitwise OR operator]
    int bitPos = 2;
    number |= (1 << bitPos);
    //  0011 
    //  0100
    //  0111
    cout << number << endl;

    // UNSET ONE BIT
    number = 3; // 0011

    bitPos = 1;
    number &= ~(1<<bitPos); // ~ is negation
    //  0001 << 1 = 0010
    // ~ 0010 = 1101
    // number = 3 = 0011
    //      0011
    //      1101
    //   &= 0001 
    cout << number << endl;


    // TOGGLE ONE BIT [use of xor operator]
    number = 3; /// 0011

    bitPos = 0; // toggle zeroth bit.
    number ^= (1 << bitPos); // ^= xor equals
    //           0011
    //           0001
    //       ^=  0010
    cout << number << endl; // we have toggled the zeroth bit.


    // CHECKING A BIT
    number = 3; // 0011
    bitPos = 2;
    int bit = (number >> bitPos) & 1;
    // 0011 >> 2 = 0000 
    //      0000
    //      0001
    //   &= 0000
    cout << bit << endl;


    // Changing nth bit value
    number = 3; // 0011
    
    int n = 2;
    int bitVal =  1 ;
    number = number & ~(1 << n) | (bitVal << n);
    cout << number << endl; // 7 = 0111

     return 0;
}