// What is RVO and NRVO in C++?
// Answer: It stands for Return Value Optimization and Named Return Value Optimization.
#include <iostream>
#include <vector>

class Base 
{ 
    public:
        Base() 
        {
            std::cout << "Constructor of Base." << std::endl;
        }
        Base(const Base &) 
        {
            std::cout << "Copy-constructor of Base." << std::endl;
        }   
};



Base func()
{
    // Base b;
    // return b;  // NRVO
    return Base(); // RVO
}

int main()
{
    Base b = func(); // This will not vall the copy constructor because the compiler is clever and avoids that.
    // If you compile with g++ -fno-elide-constructors main.cpp
    // The feature will not be used and all the extra copies will be created.
    // Can be useful for debugging purposes.
    return 0;
}