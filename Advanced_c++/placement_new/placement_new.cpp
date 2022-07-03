// Whatis placement new in c++?

#include <iostream>

class Base{
    int a;
    public:
        Base() {std::cout << "Constructor" << std::endl;}
        ~Base() {std::cout << "Destructor" << std::endl;}
};

int main() {
    // Normal Case:
    std::cout << "Normal Case:" << std::endl;
    // new shifts from user mode to kernel mode and returns allocated memory and constructs object at that location.
    Base *obj = new Base(); 
    delete obj;

    // Switching between user mode and kernel mode is costly.

    // placement new Case:
    std::cout << "placement new Case:" << std::endl;
    
    char *memory = new char[10*sizeof(Base)]; // create memory pool.
    Base *obj1 = new (&memory[0]) Base(); // instead of asking kernel for memory, memory is passed
    Base *obj2 = new (&memory[4]) Base(); // so the mode does not need to be switched.
    Base *obj3 = new (&memory[8]) Base(); // and the class is constructed in memory pool.
    // 4 bytes apart since the class only holds an integer that is the size of the class.

    obj1->~Base(); // When using placement new we must call destructor explicitly.
    obj2->~Base(); 
    obj3->~Base(); 

    delete[] memory; // then delete memory block.

    return 0;
}