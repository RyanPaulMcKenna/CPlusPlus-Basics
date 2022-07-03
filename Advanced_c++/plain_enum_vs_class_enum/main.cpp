#include <iostream>
using namespace std;

int main() {

// Plain Enum
    enum Color1{ red, green, blue}; // bad, these names are in the scope.
    Color1 c1 = red;

    switch(c1)
    {
        case red:    cout << "red" << endl; break;
        case green : cout << "green" << endl; break;
        case blue:   cout << "blue" << endl; break;
    }

    // int red,green,blue; // Not allowed those names are already taken by the enum.

///////////////////////////////////////////////////////////////////////////////
// Class Enum
    enum class Color2 {red,green,blue}; // good, these name are no in the scope, 
    // you must access with the class scope operator
    Color2 c2 = Color2::red;

    switch(c2) {
        case Color2::red:    cout << "red" << endl; break;
        case Color2::green : cout << "green" << endl; break;
        case Color2::blue:   cout << "blue" << endl; break;
    }

    // int red,green,blue; // This is allowed since the name are not taken by the enum.
    // If it is passed around it will not be implicitly converted to int like the plain enum will.
    // It will require a specific Color2 type, this is better, less confusion.

    return 0;
}