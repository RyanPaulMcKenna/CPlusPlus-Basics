#include <iostream>
using namespace std;

class Polygon // The base class.
{
protected:
int width,height;
public:
void setValues( int w, int h){ width = w; height = h;}
};
class Rectangle : public Polygon // A derived class with all the features of the base class as well as it's own features.
{
public:
int area() { return ( width * height);}

};
class Triangle : public Polygon
{
public:
int area() {return ((width * height) / 2);}
};

int main()
{
    Rectangle rect; Triangle trgl;
    rect.setValues(4, 5);
    trgl.setValues(4, 5);
    cout << "Rectangle area: " << rect.area() << endl; // Derived classes using their unique methods based on the values set.
    cout << "Triangle area: " << trgl.area() << endl; // from the base class' setValues method.
    return 0;
}
