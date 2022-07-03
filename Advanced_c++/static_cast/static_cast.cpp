// Use static_cast when conversion between types is provided through conversion operator
// or conversion constructor.

#include <iostream>
#include <string>
using namespace std;

class Int {
    int x;
    public:
    Int(int x=0):x{x} { // Note consturctor uses same type
        cout << "conversion consturctor" << endl;
    }
    operator string() { // Conversion constructor makes the below code possible.
        cout << "conversion operator" << endl;
        return to_string(x);
    }
};

class Base {};
class Derived : private Base {};

class Base1{};
class Derived1 : public Base1 {};
class Derived2 : public Base1 {};


int main() {
    float f = 3.5;
    int a;

    a = f; // run time. non searchable
    a = static_cast<int>(f);    // compile time, searchable.

    Int obj(3);
    string str1 = obj; // implicit conversion, not readable
    obj = 20; // implicit conversion, not readble.

    // do it this way instead.
    string str2 = static_cast<string>(obj); // explicitly cast is more readable and happens at compile time.
    obj = static_cast<Int>(30);

    // Another Example

    // Static cast is more restrictive  than C-style casting. This dangerous code compiles
    char c; // one byte allocated.
    int *p = (int*)&c;  // pointing at 4 bytes block
    *p = 5; // writes over memory that wasn't allocated to it. DANGEROUS!

    // This does the same thing but it does not compile, compile time error.
    int* ip = static_cast<int*>(&c);


    // Avoid cast from derived to private base pointer.

    Derived d1;
    Base *bp1 = (Base*)&d1; //Allowed at compile-time.
    Base *bp2 = static_cast<Base*>(&d1);    // Not allowed at compile-time.


    // Use for all upcasts, but never use for confused down cast.
    Derived1 dd1;
    Derived2 dd2;

    Base1* bbp1 = static_cast<Base1*>(&dd1);    // fine.
    Base1* bbp2 = static_cast<Base1*>(&dd2);    // fine.

    Derived1 *dd1p = static_cast<Derived1*>(bbp2);  // confused down cast, bad this compiles
    Derived2 *dd2p = static_cast<Derived2*>(bbp1);  // confused down cast, bad this compiles
    // Should use dynamic cast.

    // STATIC CAST SHOULD BE PREFERED WHEN CONVERTING TO void* OR FROM void*

    int i = 10;
    void *v = static_cast<void*>(&i); // compile time check, good.
    int *ip = static_cast<int*>(v); // compile time check good.


    // Bottom line:
    // use static_cast for compatible type conversion like float to int.
    // for conversion operator and conversion constructors use static_cast.
    //  to avoid unrelated pointer conversion.
    // avoid derived to private base pointer conversion.
    // use for all upacst but never for confued down cast because no runtime checks performed.
    // makes intensions clearer than c-style cast.
    // finding is easier and review is easier.
    // error found at compile-time.

    return 0;
}