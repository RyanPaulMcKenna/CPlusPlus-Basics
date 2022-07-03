#include <iostream>
using namespace std;

// reinterpret cast is not portable as it performs at the byte level / hardware level.
// If the architecture is different the code will not work.

// Basically just don't use reinterpret_cast.

class Mango {
    public:
    void eatMango() {cout << "eating Mango" << endl;}
};

class Banana {
    public:
    void eatBanana() {cout << "eating Banana" << endl;}
};

struct myStruct
{
    int x;
    int y;
    char c;
    bool b;
};


int main() {
    Banana *b = new Banana();
    Mango *m = new Mango();

    Banana *newBanana = reinterpret_cast<Banana*>(m);
    newBanana->eatBanana(); // This is dangerous and should not be done.


    myStruct s;
    s.x=5;  s.y=10; s.c = 'a';  s.b = true;
    int * p = reinterpret_cast<int*>(&s);
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    char * c = reinterpret_cast<char*>(p);
    cout << *c << endl;
    cout << *(reinterpret_cast<bool*>(++c)) << endl;


    return 0;
}