#include <iostream>
#include <string>

using namespace std;
string trim(string s)
    {   
        int L = 0;
        int R = s.size();
        string ans = "";
        bool start = false;
        while(L < R)
        {
            if (s[L] == '-' || isdigit(s[L])) 
            {
                ans += s[L];
            }
            if (isdigit(s[L]))
            {
                start = true;
            }
            if (start && !isdigit(s[L]))
            {
                break;
            }
            ++L;
        }
        return ans;
}

int main()
{
    string s = "words and 987";
    cout << trim(s) << "A";
    return 0;
}