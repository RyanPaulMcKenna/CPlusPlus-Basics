#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
    char array[100];
    int val;

    int printOut = printf("%s", "hi there!!\n");
    int scanfOut = scanf("%s", array);

    cout << printOut << endl; // size of string.
    cout << scanfOut << endl;   // 1 for how many variables are being read into, in this case one.

}