# compile c code.
gcc -c filename.c
gcc -c filename.cpp


# try to link an generate executable
g++ inc_c.cpp.o cfile.o

# view object file
nm inc_c.o

# The issue is function overloading is not available in c
so we must tell the compiler not to change the name of the external c code function.
using extern, this is called name mangling.