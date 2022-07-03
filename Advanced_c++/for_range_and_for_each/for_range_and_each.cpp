#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i)
{
    cout << i << endl;
}

int main()
{
    std::vector<int> vec;
    int ar[10];
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        ar[i] = i;
    }

    for (int i : ar)
    {
        cout << i << endl;
    }

    for_each(vec.begin(),vec.end(),
        [](int i) { 
            cout << i << endl;
        }
    );

    for_each(vec.begin(),vec.end(),print);
}