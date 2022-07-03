#include <iostream>
using namespace std;

class Shape // Abstract Data Type, made by initializing one or more class methods with zero.
{
public:
    virtual int getArea() = 0; // Pure Virtual Methods
    virtual int getEdge() = 0;
    virtual void draw() = 0;
};
class Rect : public Shape // Derived Class.
{
private:
    int height, width;
public:
Rect( int initHeight, int initWidth) // Public constructor passes private base class variables to derived class for arguments.
{
    height = initHeight; // Be careful to keep variables on their aliases on the same side or else program will function incorrectly without errors.
    width = initWidth;
};
~Rect(); // Always provide de-constructor immediately after constructor.
    int getArea(){return height * width;} // Overriding Virtual Method(s)
    int getEdge(){return (2 * height) + (2 * width);}
    void draw() // For whatever Height or Width equal the loop will iterate that many times.
    {for ( int i = 0; i < height; i++ ){ for ( int j = 0 ; j < width ; j++){ cout << "x ";} cout << endl;}} //Warning - Be careful that '}'token does not accidentally tangle functions together, hard to spot errors.
};

int main()
{
    Shape* pQuad = new Rect( 3,7); // Creates instances and provide values through pointers.
    Shape* pSquare = new Rect( 5, 5);
    pQuad -> draw();
    cout << "Area is " << pQuad -> getArea() << endl;
    cout << "Perimeter is " << pQuad -> getEdge() << endl;
    pSquare -> draw();
    cout << "Area is " << pSquare -> getArea() << endl;
    cout << "Perimeter is " << pSquare -> getEdge() << endl;
    return 0;
}
