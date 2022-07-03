// Question: How to assign any OBJECT to primitive data types (int, float...)
// Answer: you need to define opeartor int() to allow the conversion from class to int.

#include <iostream>
using namespace std;

class Base {
    int var;
    public:
    Base() {}
    Base(int val): var{val} {}
    operator int () const {
        return var;
    }
};

int main() {
    Base b(100);
    int tmp = b;
    cout << tmp << endl;
    return 0;
}