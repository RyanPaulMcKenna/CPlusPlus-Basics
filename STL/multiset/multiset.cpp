/*
// TOPIC: std::multiset<T>

// SYNTAX: std::multiset<T> objectName;

1. std::multiset is an Associateive Container that contains a sorted set of duplicate boejcts of type key.
2. It is usually implemented using Red-Black tree.
3. Insertion, Removal, Search have logarithmic complexity.
4. If we want to store user defined data type in muliset then we will have to provide
    compare function so that muliset can store them in sorted order.
5.  We can pass the order of sorting while constructing set object.


BOTTOME LINE:
multiset is simialr to set except it can have multiple element with same value.
*/

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

// Example

class Person 
{
    public:
        float age;
        string name;
        bool operator < (const Person& rhs) const  {return age < rhs.age;}
        bool operator > (const Person& rhs) const  {return age > rhs.age;}
};

int main() {

    std::multiset<int, std::less<int>> multiSet = {5,2,4,3,2,5};
    multiSet.insert(20);
    multiSet.insert(20); // duplicates.
    for (const auto& e: multiSet)
    {
        cout << e << endl;
    }




}








