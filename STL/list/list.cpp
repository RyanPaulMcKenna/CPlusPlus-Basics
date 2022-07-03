// list in STL

// 1. This is a double linked list
// 2. sequence container allows non-contiguous memory allocation.
// 3. list is faster compared to other squence containers (vector, forward_list, deque)
//  in terms of insertion, removal and moving elements in any position provided
// we have the iterator of the position.
// 4. We should use this calss instead of traditional double linked list beacuse
//      a. well tested.
//      b. Bunch of available functions.
// 5. Few Available Operations
//      operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back
//      pop_back, push_front, pop_fron, reverse, sort, merge, splice, unique, remove, remove_if, resize


#include <iostream>
#include <list>
using namespace std;



int main() 
{
    list<int> list1 = {5,2,4,6,2};
    list<int> list2 = {7, 6, 1, 9};

    list1.sort();
    list2.sort();
    list1.merge(list2);

    for (auto& elm: list1)
        cout << elm << " ";
    cout << endl;


    for (auto& elm: list2)
        cout << elm << " ";
    cout << endl;
    
    return 0;
}