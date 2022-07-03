/*
    TOPIC: std::queue In C++

    NOTES:
    0. std::queue class is a container adapter that gives the programmer the functionality of a queue
    1. queue is FIFO (first-in-first-out) data strucuture.
    2. std::queue provides only specific set of functions.
    3. stdL:queue allows to push(insert) at back and pop(remove) from front.
    4. std::queue gives front, back, push, pop, empty, size.


    PROGRAM:
*/

#include <iostream>
#include <queue>
using namespace std;

void print(std::queue<int> que)
{
    while(!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
}

int main() 
{
    std::queue<int> que;
    que.push(2);
    que.push(3);
    que.push(4);

    

    return 0;
}