#include "foo.h"

template<typename T>
T Foo<T>::getValue() {
    return _val;
}

template<typename T>
void Foo<T>::setValue(T val)
{
    _val = val;
}

//template class Foo<int>; // This is another way, you do not need include in .h if you do this.