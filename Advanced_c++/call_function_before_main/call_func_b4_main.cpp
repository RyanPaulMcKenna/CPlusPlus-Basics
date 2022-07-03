#include <iostream>
using namespace std;


void func() {cout << "inside Base" << endl;}

class Base {
    public:
    Base() {func();} // constructor runs the function.
};

Base b; // Global variable assignment runs before main.

int func1() { cout << "inside func1" << endl; return 10;}

class Base1 {
    public:
        static int staticVariable;
};

int Base1::staticVariable = func1(); // Again global variable assignment but this time using static variable.

int main() {
    cout << "inside main" << endl;
    return 0;
}

