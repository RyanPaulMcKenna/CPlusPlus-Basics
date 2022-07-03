// Question: How to print without loops or recursion
// use array and constructor as below.

#include <iostream>
using namespace std;

class Base {
    public:
    Base() { cout << "Bingo!" << endl;}
};

int main() {
    Base b[10];
    return 0;
}