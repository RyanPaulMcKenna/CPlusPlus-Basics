/*
    TOPIC: STL ALGORITHM partial_sort

    NOTES:
    0. partial_sort rearranges elements such that the range [first, middle) contains the sorted elements.
    1. The roder of equal elements is not guaranteed to be preserved.
    2. The order of remaining elements is unspecificed.

    Look for the overloads in cppreff site.
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    vector<int> vec {5,7,4,2,8,6,1,9,0,3};
    std::partial_sort(vec.begin(), vec.end() + 4, vec.end());

    for (int val : vec)
    {
        std::cout << val << " ";
    }
    
}