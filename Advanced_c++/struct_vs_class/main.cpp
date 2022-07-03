#include <iostream>

class classBase {
    int _bar; // private by default.
};

struct structBase
{
    int _bar;   // public by default.
};

int main() {
    classBase cb;
    structBase sb;
}