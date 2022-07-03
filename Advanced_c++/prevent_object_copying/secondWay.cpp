// Inherit dummy class with private copy constructor and assignment operator.
// keeps the base class clean.

#include <iostream>
using namespace std;

class StopCopy {
    int _x;
    public:
        StopCopy() {}
    private:
        StopCopy(const StopCopy& obj) {}
        StopCopy& operator = (const StopCopy& rhs) {}
};

class Base : public StopCopy {
        int _x;
    public:
        Base() : _x{0} {}
        Base(int x) : _x{x} {}
};

int main() {
    Base b1(10);
    b1 = b2; // error

    return 0;
}