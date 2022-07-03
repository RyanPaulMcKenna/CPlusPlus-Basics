// Keep copy constructor and assignment operator as private in your class.

#include <iostream>
using namespace std;

class Base {
    int _x;
    public:
        Base () {}
        Base (int x) :_x{x} {}
    private:
        Base(const Base& obj) :_x{obj._x} {}
        Base& operator = (const Base& rhs) {_x = rhs._x; return *this;}
};

int main() {
    Base b1(10);
    Base b2(20);

    b1 = b2; // error

    return 0;
}