/*
    forward_list is STL's singley linked list.
    has a bunch of useful functions.

    few important operations:
    opeartor =, assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
    splice_after, unique, remove, remove_if, resize
*/


#include <iostream>
#include <forward_list>
using namespace std;

int main() 
{
    forward_list<int> list1 = {5,2, ,4,6,2};
    forward_list<int> list2 = {7,6,1,9};

    list1.insert_after(list1.begin(), 8);
    list1.reverse();
    list2.sort();
    list1.merge(list2);
    list1.sort();
    for (auto& elm: list1)
        cout << elm << endl;

    list1.splice_after(list1.begin(), list2); // insert whole list2 after list.begin() in list1.

    cout << "size of list2 : " << std::distance(list2.begin(), list2.end()) << endl;

    list1.unique(); // remove adjacent duplicates, so you must sort first.
    list1.remove(2); //remove every occurence of 2.

    list1.remove_if([] (int n) { return n > 4;}); // lambda remove

    return 0;
}