#include <iostream>
#include <typeinfo>

class A{};

class B{};

int main() {
    A a1, a2;
    B b1, b2;

    if (typeid(a1) == typeid(b1))
    {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
}