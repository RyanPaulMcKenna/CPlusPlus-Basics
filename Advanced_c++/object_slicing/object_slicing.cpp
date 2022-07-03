#include <iostream>

class Base {
    public:
        int b_var;
        Base() {std::cout << "Base constructor" << std::endl;}
        ~Base() {std::cout << "Base constructor" << std::endl;}

};

class Derived : public Base {
    public:
        int d_var;
        Derived() {std::cout << "Derived Constructor" << std::endl;}
        ~Derived() {std::cout << "Derived Destructor" << std::endl;}
};

int main() {
    Derived d_obj;
    Base b_obj = d_obj; // slices off the derived part of the class.
    return 1;
}

