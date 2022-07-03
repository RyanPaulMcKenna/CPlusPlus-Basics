#include <iostream>
using namespace std;

class Parent // Data Structure.
{
public: // Access Specifier.
    void common() const { cout << "I am part of this Family, ";} //Base Class method.
    virtual void identify() const { cout << "I am the Parent" << endl;} // Over-ridable-able "Virtual" Base Class method.
};

class Child : public Parent
{
public:
    void identify() const { cout << "I am the Child" << endl;} // May Over-ride virtual method.

};
class Grandchild : public Child // Derived from the derived class that was derived from the base class.
{
public:
    void identify() const{ cout << "I am the Grandchild" << endl;}
    void relate() const { cout << "Grandchild has Parent and Grandparent";}
};

int main()
{
Child son; // Instance of child class.
Grandchild grandson; // Instance of Grandchild class.
Parent* ptrChild = &son; // Base Parent class pointer to link to Child Son class.
Parent* ptrGrandchild = &grandson;

ptrChild -> common(); // Call to inherited method.
ptrChild -> identify(); // Call to overriding method, Child version!
ptrGrandchild -> common(); // Call to inherited method.
ptrGrandchild -> identify(); // Call to overriding method, Grandchild version!
ptrChild -> Parent::common(); // Call Base class method explicitly using scope resolution operator.
ptrChild -> Parent::identify(); // Call Base class method explicitly using scope resolution operator.
grandson.relate(); // Call final derived classes unique method without the need for a pointer.
// ptrGrandchild->relate(); // Cannot use in this context as base class pointer does not have a version of this method.
    return 0;
}
