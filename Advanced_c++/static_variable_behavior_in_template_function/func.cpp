#include <iostream>
using namespace std;

// static variable is local to the scope, it cannot be accessed outside the local scope.
// static variable will be alive throughout the life of the program.
// How does this differ when using templates, 
// like the situation in main where 3 different types of print function are made.

// Each type gets its own static variable.

// Function Example
template<typename T>
void print(const T x) {
    static int var = 10;
    cout << ++var << endl;
}

int main() {
    
    print(1);
    print('x');
    print(1.5);

    print(1);
    print('x');
    print(1.5);
    
    return 0;
}