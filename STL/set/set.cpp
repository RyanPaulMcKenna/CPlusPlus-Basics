/*
TOPIC: std::set<T>

SYNTAX: std::set<T> objectName;

1. std::set is an Associative Container that contains a sorted set of unique objects of type key.
2. It is usually implememtned using Red-Black Tree.
3. Insertion, Removal, Search have logarithmic complexity.
4. If we want to store user defined data type in set then we will have to provide 
    compare function so that set can store them in sorted order.
5. We can pass the order of sorting while constructing set object.

BOTTOM LINE:
It store unique elements and they are soted in sorted order (A/D)
*/

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class A {
    public:
    int x;
    A(int x=0) : x{x} {cout << "Construct" << endl;}
    A(const A& rhs) { x = rhs.x; cout << "copy" << endl;}
};

bool operator < (const A& lhs, const A& rhs) { return lhs.x < rhs.x;}

class Person {
    public:
        float age;
        string name;
        bool operator < (const Person& rhs) const { return age < rhs.age;} // by default this will be used to sort the set.
        bool operator > (const Person& rhs) const { return age > rhs.age;} // by default this will be used to sort the set.
};

int main() {
    set<A> Set;
    Set.insert(A(1)); // inset and emplace are equivalent for primitive types.
    Set.emplace(2); // emplace: Inserts in-place, avoiding unnecessary copy. 

    set<int, std::greater<int>> Set1 = {1,2,3,4,5,1,2,3,4,5}; // No duplicates. // descending.
    for(const auto& e: Set1)
    { 
        cout << e << endl;
    }

    set<Person, std::greater<Person>> people = {{30, "Rupesh"},{25, "Hitesh"}, {22, "Jhon"}};
    for(const auto& e: people)
    { 
        cout << e.age << " " << e.name << endl;
    }



    return 0;
}
