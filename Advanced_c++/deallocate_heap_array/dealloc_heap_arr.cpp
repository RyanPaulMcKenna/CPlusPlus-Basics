#include <iostream>

int const n = 10;

class Base {
    public:
        int b_var;
};

int main() {
    // Over allocation Technique

    // Words size is generally 4 byte 4 bytes for 32 bit machine, 8 byte for 64 bit machine.
    Base *bp = new Base[n]; // When you write this, it does the Over allocation technique shown below.

    char* tmp = (char*) operator new[] (WORDSIZE + n * sizeof(Base)); // size of class multiplied by number of objects + WORDSIZE amount of memory.
    Base* bp = (Base*) (tmp + WORDSIZE); // shift the pointer's start position forward by WORDSIZE, This is where your objects will be stored
    // It is case into the coorect type of Base*, incrementing this pointer by one will jump forward by sizeof(Base).
    
    // cast the start of the memory location of size WORDSIZE into size_t* and store the length of the array at that location.
    *(size_t*)tmp = n;
    // starting at p allocate memory at location p of type Base() incrementing by sizeof(Base) until end of memory block.
    for (size_t i = 0; i < n; i++)
        new(bp+i) Base(); // placement new, calls constructor and allocates memory at location p+i.

    delete[] bp; // When you write this, it does what you see below.

    size_t n = *(size_t*) ((char*)bp - WORDSIZE); // get the length stored at the front of the memory block preceeding the data.
    while (n-- != 0)
        (bp+n)->~Base(); // call the detructors from end to beginning. Because we used placement new we must call desturctor explicitly.
    operator delete[] ((char*)bp - WORDSIZE);

    // Associative Array Technique
    Base *bp = new Base[n];

    Base* bp =  (Base*) operator new[] (n*sizeof(Base));
    size_t i;
    for (i = 0; i < n; ++i)
        new(bp+i) Base(); // Placement new.
    assocationArray.insert(bp,n);

    delete[] bp; 
    size_t n = associationArray.lookup(bp);
    while (n-- != 0)
        (bp + n)->~Base();
    operator delete[] (bp);
    
    return 1;
}