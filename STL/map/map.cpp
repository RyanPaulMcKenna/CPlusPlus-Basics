/*
Map In C++

NOTES:  
1. Syntax: map<T1, T2> obj; // T1 is key type and T2 is value type.
2. std::map is associative container that store elements in key value combination
    where key should be unique, otherwise it overrides the previous value.
3.  It is implemented using Self-Balancing Binary Search Tree (AVL/Red Black Tree).
4.  It stores key value pair in sorted order on the basis of key (ascending/decending).
5.  std::map is generally used in Dictionary type problems.
// EXAMPLE: Dictionary
*/

#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main() {
    std::map<string, int, std::greater<string>> Map; // order greater or std::less<>
    Map["Chotu"] = 90909009;
    Map["Amit"] = 98234819;
    Map.insert(std::make_pair("Bot", 782348818));

    // Loop through map
    for (auto &elem: Map)
    {
        cout << elem.first << " " << elem.second << endl;
    }

    // Access using [] opeartor
    cout << Map["Chotu"] << endl;

}