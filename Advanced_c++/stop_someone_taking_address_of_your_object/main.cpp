// By making address of operator overload private we can prevent the memory address from being taken.
// Or you can tell the compiler not to create it in the first place by assigning to delete.
#include <iostream>
using namespace std;

class Base  {
    int x;
    public:
        Base() {}
        Base(int x): x{x} {}
    private:
        // Base* operator & () {
        //     return this;
        // }
        Base* operator & () = delete;
};

int main() {
    Base b;
    Base *bp = &b;

    cout << &b << endl;
}