#include <iostream>
using namespace std;

// Whenever you want to initalise a none static const data member from outside your class
// you must use initalizer list.

// Case 1, const member
class Base {
    const int _x;
    public:
    Base(int x): _x{x} {} // can only be set with the initalizer list
    void print() {cout << _x << endl;}
};


// Case 2, reference member
class Base1 {
    int& _x;
    public:
    Base1(int x): _x{x} {} // can only be set with the initalizer list
    void print() {cout << _x << endl;}
};

// Case 3, Initalize class within another class
// If the first class doesn't use the default constructor.

class One {
    int _x;
    public:
    // One() {} 
    One(int x) : _x{x} {} // none default constructor.
};

class Two {
    One a;
    public:
    Two(One x): a{x} {} // we need the initalizer list.
};

// Case 4, cannot initalize base class from derived without initalizer list.
class myBase {
    int _x;
    public:
    myBase(int x): _x{x} {}
};

class myChild: public myBase {
    int _y;
public:
    myChild(int x, int y): myBase{x}, _y{y} { cout << "done" << endl;}
};
 
 // whenever you use initalizer list you optimize your code slightly.
 // As you will see, less operations are performed with the initializer as opposed to the regular assignment.
 // Example.
class Base_class {
    int _x;
    public:
        Base_class() {cout << "base default" << endl;}
        Base_class(int x): _x{x} { /*_x = x;*/ cout << "base parameter constructor" << endl;}
        Base_class(const Base_class & obj) { this->_x = obj._x; cout << "base copy constructor" << endl;}
        Base& operator = (const Base& obj) {cout << "base assignment operator" << endl;}
};

class Myclass {
    Base_class _b;
    public:
    Myclass() {cout << "myclass default" << endl;}
    Myclass(Base_class b) :_b{b} { /*_b = b;*/ cout << "myclass parameter" << endl;}
};


int main() {
    //case 1
    Base b(10);
    b.print();
    //case 1
    Base1 b1(20);
    b1.print();
    // case 3
    One one(30);
    Two two(one);
    // case 4
    myChild c(1,2);
    // case 5
    Base_class bc(100);
    Myclass mc(bc);

    return 0;
}

