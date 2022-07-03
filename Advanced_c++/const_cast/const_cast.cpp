#include <iostream>
using namespace std;

int main() {
    const int a1 = 10;
    const int* b1 = &a1;
    int *d1 = const_cast<int*>(b1);
    *d1 = 15; // Invalid and Undefined Behaviour! Mite work but should not be done.
    cout << d1 << " " << *d1 << "\n";
    int a2 = 20;
    const int *b2 = &a2;
    int *d2 = const_cast<int*>(b2);
    *d2 = 30;
    cout << d2 << " " << *d2 << "\n";
    
    int x;
    cin >> x;
    return 0;
}