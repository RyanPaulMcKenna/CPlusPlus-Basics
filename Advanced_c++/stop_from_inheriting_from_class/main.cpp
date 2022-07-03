#include <iostream>

class Base final{ // final keyword prevents inheritance from the class.
    int b_var;
    public:
    Base() {}
    Base (int var): b_var{var} {}
};

class Derived: public Base {
    int d_var;
    public: 
        Derived() {}
        Derived(int a, int b) : Base(a), d_var(b) {}
};

int main() {
    Derived d(1,2);

    return 0;
}