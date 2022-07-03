// WAYS TO CRATE THREADS IN c++11
// 1. Function Pointers
// 2. Lambda Functioins
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
                EvenSum += i;
        }
    }
}

void findOdd (ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            OddSum += i;
        }
    }
}

void fun (int x)
{
    while(x --> 0)
    {
        cout << x << endl;
    }
}

class Base {
    public:
    void operator () (int x) 
    {
        while (x --> 0)
        {
            cout << x << endl;
        }
    }
    void run(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }
    static void static_run(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }
};

int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);
    // Running in parallel
    t1.join();
    t2.join();

    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum : " << OddSum << endl;
    cout << "EvenSum : " << EvenSum << endl;

    cout << "Sec : " << duration.count()/1000000 << endl; // microseconds to seconds.


    // Ways to make threads.

    // Function pointer type, most basic.
    std::thread t3(fun, 11);
    t3.join();

    // Lambda function pointer.
    std::thread t4([](int x) { while (x --> 0) { cout << x << endl; }} , 10);
    t3.join();

    // functor
    std::thread t5((Base()), 10);
    t5.join();

    // none static member function
    Base b;
    std::thread t6(&Base::run, &b, 10);
    t5.join();

    // static member function
    std::thread t7(&Base::static_run, 10);
    t7.join();

    return 0;
}