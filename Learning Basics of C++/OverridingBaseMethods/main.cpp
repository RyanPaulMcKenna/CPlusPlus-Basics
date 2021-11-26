#include <iostream>
#include <string>
using namespace std;

class Man
{
 public:
     void speak() { cout << "Hello!" << endl;}
     void speak(string msg) { cout << " " << msg << endl;}
};
class Hombre : public Man
{
public:
    void speak(string msg) { cout << msg << endl;}
};
int main()
{
    Man henry;
    Hombre enrique;
    henry.speak(); // Calling base method of base class.
    henry.speak("It's a beautiful morning."); // calling overloaded base method of base class.
    enrique.speak("Hola!"); // Calling overriding method of derived class.
    enrique.Man::speak( "Es una tarde hermosa."); // Explicitly calling base method from derived class using resolution operator.
    return 0;
}
