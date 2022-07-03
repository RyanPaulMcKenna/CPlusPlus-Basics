#include <iostream>

// Override keyword makes testing easier .
// Override keyword peforms extra compile time check to avoid future errors.
// For example if a different function signature was used in the derived class
// but the intention was to override then the compiler would show an error.

class Base {
    int b_var;
    public:
        virtual void fun() {std::cout << "Base function" << std::endl;}
};

class Derived : public Base {
    int d_var;
    public:
        void fun() override {std::cout << "Derived fun" << std::endl;}
};

int main() {
    Base *b = new Derived();
    b->fun(); // polymorphism.
    return 0;
}