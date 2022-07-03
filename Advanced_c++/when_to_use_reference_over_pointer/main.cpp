#include <iostream>
using namespace std;

class BigClass {

};

void fun(BigClass& obj) // pass big object as reference to avoid copy.
{
    // better than passing pointer as then you will have to 
    // derefence and whatknot, reference is better. makes life easier.
    // also avoids object slicing. If is part of hierarchy
    // pass by value will slice but reference will not.
}

int main() 
{
    BigClass obj;
    fun(obj);

    int i = 10;
    int &r = i; // This cannot be changed r will always point to i.
    r = 44; // This doesn't range r, it changes i, now i == 44.
}
