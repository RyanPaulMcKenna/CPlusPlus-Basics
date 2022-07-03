#include <iostream>
using namespace std;

class Base {
    virtual void print() {  cout << "Base" << endl;} 
    // need at least one virtual method in base class to use dynamic cast
};

class Derived1: public Base {
    void print() { cout << "Derived1" << endl;}
};

class Derived2: public Base {
    void print() { cout << "Derived2" << endl;}
};

int main() {
    Derived1 d1;

    Base *bp = dynamic_cast<Base*>(&d1); // cast type Derived1 into type Base
    // if it fails and new tye is pointer it returns a null pointer of that type.
    // if it fails and new tye is reference it throws an exceptions that matches a handler of type std::bad_cast 
    
    Derived2 *dp2 = dynamic_cast<Derived2*>(bp); // This will fail.
    if (dp2 == nullptr)
    {
        cout << "The dynamic cast failed" << endl;
    }
    return 0;
}