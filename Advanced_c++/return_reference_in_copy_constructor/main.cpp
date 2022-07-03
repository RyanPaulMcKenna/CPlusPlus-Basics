// Question: Why does copy constructor return base reference?
// Answer: Supports chaining, see brackets and assignments below.
#include <iostream>
using namespace std;

class Base {
        int _var;
    public:
        Base() {}
        Base(int val) : _var{val} {}
        Base& operator = (const Base& rhs) {
            _var = rhs._var;
            return *this;
        }
        void print() {
            cout << _var << endl;
        }
};


int main() 
{
    Base b1(10);
    Base b2, b3, b4;

    (b2 = b3) = b1; // If copy cons does not return Base referece it wil not work.
    b2 = b3 = b4 = b1;

    b1.print(); b2.print(); b3.print(); b4.print();

    return 0;
}