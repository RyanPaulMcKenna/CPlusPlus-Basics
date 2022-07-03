#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void talk() const { cout << "A bird talks..." << endl;}
    virtual void fly() const { cout << "A bird flies..." << endl;}
};

class Pigeon : public Bird
{
public:
    void talk() const{ cout << "Coo Coo!" << endl;}
    void fly() const { cout << "A Pigeon flies away..." << endl;}
};
class Chicken : public Bird
{
public:
    void talk() const { cout << "Cluck Cluck!" << endl;}
    void fly()const { cout << "I/'m just a chicken - I can't fly!" << endl;}
};
int main()
{
    Bird* pPigeon = new Pigeon; // "Base class pointer using new keyword instead of & address of operator.
    Bird* pChicken = new Chicken;

    pPigeon -> talk();
    pPigeon -> fly();
    pChicken -> talk();
    pChicken -> fly();
    pPigeon -> Bird::talk(); // Call Base class explicitly with scope resolution operator.
    pChicken -> Bird::fly(); // Inappropriate call.
    
    int x;
    std::cin >> x;
    return 0;
}
