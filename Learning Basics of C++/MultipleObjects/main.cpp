#include <iostream>
#include <string>
using namespace std;

class Dog // A declaration of a data structure.
{
    private: // Access specifier.
    int age, weight;    // Variables within classes are known as members.
    string colour;
    public: // Access specifier.
    void bark(){ cout << "WOOF!" << endl;} // Functions within classes are known as methods.
    int getAge(){return age;} // A getter method to retrieve data from private members.
    int getWeight(){return weight;}
    string getColour(){return colour;}
    void setValues(int age, int weight, string colour) // This function combines the setter methods in to one.
        {
        this -> age = age; // The "this" class pointer -> can be used to specify the class member private variable when variables have the same names.
        this -> weight = weight;
        this -> colour = colour;
        };
};

int main()
{
    Dog gemma, rosey; // two instances of the "Dog" class.
    gemma.setValues( 7 , 40 , " brown"); // A Call to the combined setter method.
    rosey.setValues( 1, 5, "Blonde");
    cout << "Gemma is a " << gemma.getColour() << " dog." << endl; // Now the getter methods are being used to retrieve the set information.
    cout << "Gemma weighs " << gemma.getWeight() << " Kilograms." << endl;
    cout << "Gemma is " << gemma.getAge() << " years old." << endl;
    gemma.bark(); // A call to the Dog class' bark function.
    cout << "Rosey is a " << rosey.getColour() << " dog." << endl; // Now the getter methods are being used to retrieve the set information.
    cout << "Rosey weighs " << rosey.getWeight() << " Kilograms." << endl;
    cout << "Rosey is " << rosey.getAge() << " years old." << endl;
    rosey.bark();
    return 0;
}
