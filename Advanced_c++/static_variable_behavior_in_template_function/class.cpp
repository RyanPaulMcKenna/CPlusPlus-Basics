#include <iostream>
using namespace std;

// every type of the class has its own static variable, the static is not shared across types
// tey are different classes.

// Class Example
template<typename T>
class Print{
    private:
        int x;
    public:
        static T var;
        void printVal() {cout << ++var << endl; }
};

template<class T>
T Print<T>::var = 0;

int main() {
    
    Print<int> p;
    p.printVal();

    Print<float> f;
    f.printVal();
    
    return 0;
}