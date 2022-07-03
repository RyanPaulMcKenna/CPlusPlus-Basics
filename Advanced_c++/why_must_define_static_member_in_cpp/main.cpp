#include <iostream>
#include "foo.h"

int main() 
{
    Foo o1, o2;

    o1.setNormal(10);
    o2.setNormal(5);

    std::cout << o1.getNormal() << std::endl;
    std::cout << o2.getNormal() << std::endl;

    o1.setStatic(60);
    std::cout << o2.getStatic() << std::endl;

    return 0;
}