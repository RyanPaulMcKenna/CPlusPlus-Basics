#include "foo.h"
using namespace std;

int main() 
{
    Foo<int> obj;
    obj.setValue(5);
    cout << endl << obj.getValue() << endl;
}