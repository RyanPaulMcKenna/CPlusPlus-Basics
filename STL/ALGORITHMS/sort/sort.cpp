/*
    TOPIC: STL Sort

    NOTES:
    0.  In C++ STL we have sort function which can sort in increasing and decreasing order.
    1. Not only integral but user define data can be sorted using this function.
    1. Internally it uses IntroSort which combination of QuickSort, HeapSort and InsertionSort.
    2. By Default, it uses QuickSort, but if QuickSort is doing unfair partitioning and taking more
        than N*logN time, it switches to HeapSort and which the array size becomes really small,
        it switches to InsertionSort.
    3.  We can use parallel execution policy for better performance.

    TYPES:
    1.  Sorting integral data types
    2. Sorting user defined data types
    3. Sort using a function object
    4. Sort using lambda expression
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <execution> // need to add this library to path.
using namespace std;

class Point {
    public:
        int x;
        int y;
        Point(int x=0, int y=0):x{x}, y{y} {}
        bool operator < (const Point& p1) {
            return (x+y) < (p1.x+p1.y);
        }
};

struct {
    bool operator()(int a, int b) const
    {
        return a < b;
    }
} customLess;

int main ()
{
    // 1. sort with integral data types
    std::vector<int> vec {5,4,6,7,3,2,8,9,1};
    std::sort(std::execution::par, vec.begin(), vec.end());
    for (auto elm: vec)
    {
        cout << elm << " ";
    }

    // sort with user defined types
    std::vector<Point> point_vec {{1,2},{3,1},{0,1}};
    std::sort(point_vec.begin(), point_vec.end());
    for (auto e: point_vec)
    {
        cout << e.x << " " << e.y << endl;
    }

    //  sort using function object
    std::vector<int> my_vec {5,4,6,7,3,2,8,9,1};
    std::sort(my_vec.begin(), my_vec.end(), customLess);
    for (auto elm: my_vec)
    {
        cout << elm << " ";
    }

    // Sort using lambda function
     std::vector<int> my_vec1 {5,4,6,7,3,2,8,9,1};
    std::sort(my_vec1.begin(), my_vec1.end(), std::greater<int>());
    for (auto elm: my_vec1)
    {
        cout << elm << " ";
    }



    return 0;
}







