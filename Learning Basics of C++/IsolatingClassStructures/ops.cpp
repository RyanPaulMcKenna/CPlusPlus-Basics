#include "ops.h"
#include <iostream>
using namespace std;

Calculator::Calculator() // Implementation file to contain the definitions of each method in the header file.
{ status = true;} // Initialize status.

void Calculator::launch() // Display instructions.
{
cout << endl << "*** SUM CALCULATOR ***" << endl;
cout << "Enter a number, an operator (+,-,*,/), and another number."<< endl;
cout << "Hit return to calculate. Enter zero to exit." << endl;
}

void Calculator::readInput() // Get expression.
{
cout << " > " ; cin >> num1; // Gets first number.
if ( num1 == 0 ) status = false; // Exit if zero.
else {cin >> oper ; cin >> num2;} // Gets second number.
}

void Calculator::writeOutput() // Display result.
{
    if ( status ) switch (oper) // If continuing.

     {case '+' : {cout << (num1 + num2) << endl; break;} // Show result!
     case '-' : {cout << (num1 - num2) << endl; break;}
     case '*' : {cout << (num1 * num2) << endl; break;}
     case '/' : if ( num2 != 0) cout << ( num1 / num2) << endl;
     else cout << "Cannot divide by zero" << endl;}
}

bool Calculator::run() // Get current status.
{return status;}
