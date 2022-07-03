#include <iostream>
using namespace std;

// Note the extra const on the getValue function prevents the getValue from changing the value
// stored in the this pointer.

class Base {
    int _a;
    public:
    void setValue(int a) {_a = a;}
    // void setValue(Base* const this, int a) { this->_a = a;}
    int getValue() const { return _a;}
    // int getValue(const Base* const this) const { return this->_a;}
};

int main() {
    Base b;
    b.setValue(10);
    // setValue(&b,10);
    b.getValue();
    // getValue(&b);

    return 0;
}