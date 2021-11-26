#include <cstdlib> //Random number support
#include <ctime>   // Time support
#include <iostream>
using namespace std;

int main()
{
int i, j, k, nums[50]; //Initialize 3 integers an integer array.

srand((int)time(0)); // Seed random number generator with the current time cast in to an integer.

for(i=1; i < 50; i++)
{
nums[i] = i; // Fill integer array elements with integers 1-49
} 
for(i=1; i < 50; i++)
{
j = rand()%49+ 1;
k = nums[i]; nums[i]= nums[j]; nums[j]=nums[k]; // Randomize numbers in each element with a maximum of 1-49
}
cout << " Your six lucky numbers are: ";
for(i=1; i<7; i++)cout << nums[i] << " ";

return 0;
}
