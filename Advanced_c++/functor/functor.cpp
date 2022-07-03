#include <iostream>

using namespace std;

class Mul {
    int _val;
    public:
        Mul() {}
        Mul(int val):_val{val} {}

        int operator () (int val) {
            return val*_val;
        }
};

int main()
{
    Mul mul2(12); // set the state
    cout << mul2(2) << endl; // performs operation(s) on the state.
    cout << mul2(3) << endl;

    return 0;
}