#include <iostream>
using namespace std;

class Base
{
public:
    void identify( int adr ) const {cout << "Base class called by 0x" << hex << adr << endl;} // Outputs Int variable argument in hexadecimal format, using the "hex" output manipulator.
};

class SubA : public Base{}; // Two derived classes.
class SubB : public Base{};

int main()
{
Base* ptrA = new SubA; // Two Base class pointers, pointing to the location of the two derived classes.
Base* ptrB = new SubB;

ptrA -> identify((int)&ptrA); // pointers calling the base class function to output the addresses of the derived classes.
ptrB -> identify((int)&ptrB);

return 0;
}
