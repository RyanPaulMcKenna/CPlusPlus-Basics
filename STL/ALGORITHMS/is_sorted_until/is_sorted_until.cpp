/*
    TOPIC: STL ALGORITHM is_sorted_until

    NOTES:
    0. Finds how many elements are sorted in given range [first, last).

    SUPPORTS TYPES:
    1. Sorting integral data types
    2. Sorting user defined data types
    3. sort using a function object
    4. sort using lambda expression
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec {4,3,2,6,8,1};
    auto it = is_sorted_until(vec.begin(),vec.end(), greater<int>());
    auto diff = distance(vec.begin(), it);
    cout << diff << endl; // query range of sorted elements.
}