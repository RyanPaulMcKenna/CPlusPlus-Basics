// 1. Using some struct/class and fill the value in that.
// 2. Use tuple in C++11

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// Second Example
std::tuple<int, char, string> fun (bool flg) {
    if (flg) {
        return make_tuple(1,'x',"Rupesh");
    } else {
        return make_tuple(2,'y', "Hitesh");
    }
}

int main() {
    int num; char code; string name;

    tie(num,code,name) = fun(true);
    cout << num << " " << code << " " << name << endl;
    tie(num,code,name) = fun(false);
    cout << num << " " << code << " " << name << endl;


    // Another way.
    auto v = fun(true);
    num = std::get<0>(v);
    code = std::get<1>(v);
    name = std::get<2>(v);


    return 0;
}