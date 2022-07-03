#include <iostream>

// lvalue is a real variable with a location.
// rvalue is a temporary value that is not a variable.

int GetRValue() {
  return 10;
}

int& GetlValue() { // return reference to memory location.
    static int x = 10; // provide static memory location.
    return x;
}

void OnlyAcceptLvalue(std::string& name)
{
    std::cout << "Name: " << name << std::endl;
}

void AcceptBothValues(const std::string& name)
{
    std::cout << "Name: " << name << std::endl;
}

void OnlyAcceptRvalue(std::string&& name)
{
    std::cout << "Name: " << name << std::endl;
}

void PrintName(const std::string& name) {

    std::cout << "[lvalue] " << name << std::endl;
}

void PrintName(std::string&& name) {

    std::cout << "[rvalue] " << name << std::endl;
}

int main() {

    // i is an lvalue and 10 (numeric literal) is an rvalue.
    // Generally lvalue is on the left side of an assignment operator
    // and rvalue is on the right side of an assignment operator.

    int i = 10;

    // However, this is not always the case.
    // You cannot assign something to an rvalue.
    10 = i; // Error: cannot assign to rvalue, not possible.

    // You can assign an lvalue to another lvalue.
    int a = i;

    a = GetRValue(); // GetValue is an rvalue

    GetRValue() = 5; // Error: cannot assign to rvalue, not possible.

    GetlValue() = 5; // This is fine because GetlValue is an lvalue.

    // You can only have an lvalue reference of an lvalue.
    // You cannot for example have an lvalue reference of an rvalue.
    // the value 10 does not have a referencable memory location.

    // The amberssand operator (&) is used to get the address of an lvalue.
    int& a = 10; // which is not possible because 10 is an rvalue. 

    // Whereas this is allowed, the compiler probably creates some
    // temporary memory to store 10 and reference that location.
    const int& a = 10; 

    // Everything on the left is lvalue and on the right is rvalue.
    std::string firstname = "Ryan";
    std::string lastname = "McKenna";
    // whilst firstname and lastname are lvalues, their sum is an rvalue.
    // because it is temporary.
    std::string fullname = firstname + lastname;

    OnlyAcceptLvalue(fullname); // This is fine because fullname is an lvalue.
    OnlyAcceptLvalue(firstname + lastname); // This is not okay because the expression is an rvalue.

    AcceptBothValues(fullname); // This is fine because the parameter type is const it can change rvalues into lvalues.
    // const std::string& name. So that would be the preferred way to type the argument.

    // The parameter type in this case is an "rvalue reference"
    OnlyAcceptRvalue(fullname); // Error, only accepts rvalues.
    OnlyAcceptRvalue(firstname + lastname);

    // THIS CAN BE USEFUL TO CREATES OVERLOADS OF THE SAME FUNCTION TO DEAL WITH LVALUE AND RVALUE ARGS DIFFERENTLY.
    PrintName(fullname); // This must be kept alive as the memory has a longterm location.
    PrintName(firstname + lastname); // know it is a temorary value, you can steal its resources for performance gain.

    return 0;
}