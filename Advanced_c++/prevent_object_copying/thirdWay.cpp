// Delete copy constructor and assignment operator from your class as below.
#include <iostream>
using namespace std;

class Base {
    int _x;
    public:
        Base() {}
        Base(int x) :_x{x} {}
        Base& operator = (const Base& rhs) = delete;
};

int main() {
    Base b1(10);
    Base b2(19);

    b2 = b1;
}