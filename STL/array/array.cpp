#include <iostream>
#include <array>
using namespace std;

// std::array<type, size> name is container that encapsulated fixed size arrays.

// at, [], front(), back(), data()

int main()
{
    // Declare
    std::array<int, 5> myarray;

    // Initalization
    std::array<int,5> myarray1 = {1,2,3,4,5}; // Initalizer list
    std::array<int,5> myarray2 {1,2,3,4,5}; // Uniform initalization

    /// Assign using initalizer list
    std::array<int, 5> myarray3;
    myarray3 = {1,2,3,4,5};

}