#include <iostream>
using namespace std;

void fun3(){
    int fun3Var = 25;
    cout << fun3Var << endl;
}

void fun2(){
    int fun2Var = 20;
    cout << fun2Var << endl;
    fun3();
}

void fun1(){
    int fun1Var = 15;
    cout << fun1Var << endl;
    fun2();
}

int main() {
    int mainVar = 10;
    cout << mainVar << endl;
    fun1();
    return 0;
}