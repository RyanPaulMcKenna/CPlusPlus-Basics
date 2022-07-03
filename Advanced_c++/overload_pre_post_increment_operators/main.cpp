// Question: How to overload pr3e and post operator in c+?

#include <iostream>
using namespace std;

class Int {
    int elem;
    public:
    Int() {}
    Int(int val): elem{val} {}
    void printValue() { cout << elem << endl;}

    Int & operator++() { // pre increment
        elem++;
        return *this;
    }

    Int operator++(int dummy) { // post increment
        Int tmp = *this;
        ++(*this);
        return tmp;
    }
};

int main() {
    Int i(100);
    (i++).printValue(); // call printValue on the old value.
    (++i).printValue(); // call printValue on the updated value.
    i.printValue();

    return 0;
}