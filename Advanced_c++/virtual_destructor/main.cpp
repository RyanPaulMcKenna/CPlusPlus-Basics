#include <iostream>

// Destructor of Base class should be virtual so that the destructor of the
// derived class is called first and then the base class destructor will be called.
// Other wise only base destructor will be called and you will have a memory leak
// Because the derived class' memory has not been freed.

class Base {
    public:
        virtual void fun() { std::cout << "Base fun" << std::endl;}
        Base() {std::cout << "Base Constructor" << std::endl;}
        virtual ~Base() { std::cout << "Base destructor" << std::endl;}
};

class Derived : public Base {
    public:
        virtual void fun() {std::cout << "Derived fun" << std::endl;}
        Derived() {std::cout << "Derived Constructor" << std::endl;}
        ~Derived() {std::cout << "Derived destructor" << std::endl;}
};

int main() {
    Base *b1 = new Base();
    Base *b2 = new Derived();

    b1->fun();
    b2->fun();

    delete b1;
    delete b2;
    return 1;
}