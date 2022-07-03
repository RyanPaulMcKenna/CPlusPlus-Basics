#ifndef foo_h
#define foo_h

#include <iostream>

template<typename T>
class Foo 
{
        T _val;
    public:
        T getValue();
        void setValue(T val);
};
#include "foo.cpp" // This is needed to separate declaration and definition
                   // when using templates.
#endif