#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> Vec;
    Vec.reserve(31); 
    // The reserve has allowed us to avoid a huge number of copies
    // Since the vector doesn't need to increase its size until the final element is added.
    // Otherwise it would be much slower.
    for (int i = 0; i < 32; i++)
    {
        Vec.push_back(i);
        cout << "Size:" << Vec.size() << "  Capacity:" << Vec.capacity() << endl;
    }
    return 0;
}