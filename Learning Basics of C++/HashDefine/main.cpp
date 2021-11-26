#ifndef BOOK
#define BOOK "C++ Programming in easy steps"
#endif
#include <iostream>
using namespace std;

int main()
{
   #ifdef BOOK
   cout << BOOK;
   #endif //BOOK
   #ifndef AUTHOR
   #define AUTHOR "Mike McGrath"
   cout << " By " << AUTHOR << endl;
   #endif // AUTHOR
   #ifdef BOOK
   #undef BOOK
   #endif // BOOK
   #ifndef BOOK
   #define BOOK "Linux in easy steps"
   cout << BOOK << " By " << AUTHOR << endl;
   #endif // BOOK
    return 0;
}
