#include <iostream>
using namespace std;

class Bird
{
public:
    virtual int talk() const{return -1;} // Methods changed to integer to allow for return statement, also reflected in derived classes.
    virtual int fly() const{return -1;}
};

class Pigeon : public Bird
{
public:
    int talk()const { cout << "Coo Coo!" << endl;}
    int fly() const { cout << "A Pigeon flies away..." << endl;}
};
class Chicken : public Bird
{
public:
    int talk()const { cout << "Cluck Cluck!" << endl;}
    int fly()const { cout << "I/'m just a chicken - I can't fly!" << endl;}
};
int main()
{
    Bird* pPigeon = new Pigeon; // "Base class pointer using new keyword instead of & address of operator.
    Bird* pChicken = new Chicken;

    pPigeon -> talk();
    pPigeon -> fly();
    pChicken -> talk();
    pChicken -> fly();
    pPigeon -> Bird::talk();
    if( -1 ){cout << "Error! - Program ended." << endl; return 0;} // Return error for attempting to call capability class.
    pChicken -> Bird::fly(); // Inappropriate call.
    return 0;
}
