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
    void bark( string noise ) { cout << noise << endl;} // Overloaded bark method.
    int getAge(){return age;} // A getter method to retrieve data from private members.
    int getWeight(){return weight;}
    string getColour(){return colour;}
    Dog(int,int,string); // This is a constructor prototype.
    Dog(); // an overloaded Default constructor method prototype.
    Dog( int, int); // An overloaded Default constructor method.
    ~Dog(); // This is a de-constructor  prototype.
};
Dog::Dog() // Overloaded constructor method definition.
{
    age = 1;
    weight = 2;
    colour = "black";
}
Dog::Dog( int age, int weight)
{
    this -> age = age;
    this -> weight = weight;
    colour = "white";
}
Dog::Dog(int age, int weight, string colour) // constructor method implementation, defined outside the class.
    {
        this-> age = age;
        this-> weight = weight;
        this-> colour = colour;
    }
    Dog::~Dog() // Associated de-constructor method implementation.
    {
        cout << "Object destroyed." << endl;
    }
int main()
{
    Dog baxter; // Creating a dog object without passing arguments using the default constructor method.
    cout << "Baxter is a " << baxter.getAge();
    cout << "year old " << baxter.getColour();
    cout << "dog who weighs " << baxter.getWeight();
    cout << " kilograms.";
    baxter.bark( "WUFF!");
    Dog lilly( 14, 20); // Creating an object passing two arguments to use the overloaded default method.
    cout << "Lilly is a " << lilly.getAge();
    cout << "year old " << lilly.getColour();
    cout << "dog who weighs " << lilly.getWeight();
    cout << "kilograms.";
    lilly.bark("BOWOW!");
    Dog gemma(7, 40, "brown"); // Pass values to constructor method.
    cout << "Gemma is a " << gemma.getColour() << " dog." << endl; // Now the getter methods are being used to retrieve the set information.
    cout << "Gemma weighs " << gemma.getWeight() << " Kilograms." << endl;
    cout << "Gemma is " << gemma.getAge() << " years old." << endl;
    gemma.bark(); // A call to the Dog class' bark function.

    return 0;
}
