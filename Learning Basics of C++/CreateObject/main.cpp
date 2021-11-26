#include <iostream>
using namespace std;

class Dog // A declaration of a data structure.
{
    private: // Access specifier.
    int age, weight;    // Variables within classes are known as members.
    string colour;
    public: // Access specifier.
    void bark(){ cout << "WOOF!"<< endl;} // Functions within classes are known as methods.
    void setAge(int yrs){ age = yrs;} // A setter method to assign data to private members.
    void setWeight(int kg){ weight = kg;} // Another setter method.
    void setColour(string clr){ colour = clr;} // Setter method.
    int getAge(){return age;} // A getter method to retrieve data from private members.
    int getWeight(){return weight;}
    string getColour(){return colour;}
};

int main()
{
    Dog gemma; // An instance of the "Dog" class.
    gemma.setAge(7); // Note the dot operator is used to apply the a setter methods to this instance of the dog class.
    gemma.setWeight(40);
    gemma.setColour( "brown");

    cout << "Gemma is a " << gemma.getColour() << " dog." << endl; // Now the getter methods are being used to retrieve the set information.
    cout << "Gemma weighs " << gemma.getWeight() << " Kilograms." << endl;
    cout << "Gemma is " << gemma.getAge() << " years old." << endl;

    gemma.bark(); // Finally a call to the Dog class' bark function.
return 0;
}
