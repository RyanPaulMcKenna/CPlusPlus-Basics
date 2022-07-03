#include <iostream>
#include <typeinfo>

using namespace std;

extern "C"{
    #include "cfile.h"
}

int main() 
{
    fun();
    return 0;
}