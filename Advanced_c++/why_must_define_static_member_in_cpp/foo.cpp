#include "foo.h"

int Foo::staticVariable = 10; // must be declared here
//  due to #include "foo.h" here and in main will cause it to be defined twice.
// which will cause compilation error.


Foo::Foo() {
    normalVariable=0;
}


Foo::Foo(const Foo& obj) {
    normalVariable = obj.normalVariable;
}

void Foo::setNormal(int newVal) {
    normalVariable = newVal;
}

int Foo::getNormal() {
    return normalVariable;
}

void Foo::setStatic(int newVal) {
    staticVariable = newVal;
}

int Foo::getStatic() {
    return staticVariable;
}