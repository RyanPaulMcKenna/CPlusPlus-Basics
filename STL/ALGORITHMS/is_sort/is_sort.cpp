/*
    TOPIC: STL ALGORITHM is_sort

    NOTES:
    0. Checks if the elements in the range [first, last) are sorted in on-descending order.

    TYPES:
    1. Can check integral data types
    2. Can check user defined data types
    3. Can check using a function object
    4. Can check using lambda expression
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{5,4,6,7,3,2,8,9,1};

    sort(vec.begin(),vec.end());

    for (auto elm : vec)
    {
        cout << elm << " ";
    }

    cout << endl << is_sorted(vec.begin(), vec.end());
    return 0;
}