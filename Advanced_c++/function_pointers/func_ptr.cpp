#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}
// func ptr return type, typedef makes code a lot cleaner.
typedef int(*mathFun)(int,int);

mathFun func (int type) {
    if (type == 1)
        return add;
    if (type == 2)
        return sub;
    return nullptr;
}

// func ptr return type without using typedef.

int (*fun2 (int type))(int,int) {
    if (type == 1)
        return add;
    if (type == 2)
        return sub;
    return nullptr;
}


int fun1 (int (*someFun)(int,int))
{
    int c = someFun(1,2);
    return c;
}

int compare(const void *p, const void *q)
{
    int l = *(const int*)p;
    int r = *(const int*)q;
    return l<r;
}

int main(){
    int (*fun)(int,int) = add;
    int a = (*fun)(1,2); // Traditional way.
    int c = fun(1,2); // New way.
    printf("%d\n",c);

    int b = fun1(add); // pass func ptr as argument.

    int (*a_add)(int,int) = func(1); // return the add function;
    mathFun a_sub = fun2(2);

    a_add(1,2); // add 1 and 2
    a_sub(2,1); // sub 2 and 1

    mathFun Arr[2] = {add, sub};
    int f = Arr[0](1,2);
    int g = Arr[1](2,1);
    int h = (*Arr[0])(1,2);
    int j = (*Arr[1])(2,1);

    std::cout << std::endl;
    // Practical Example.
    int Arr1[5] = {3,2,4,1,5};

    int Arr1Size = sizeof(Arr1) / sizeof(Arr1[0]);
    int elementSize = sizeof(Arr1[0]);
    qsort(Arr1, Arr1Size,elementSize,compare);

    for (int i=0;i<Arr1Size;i++){
        printf("%d\n",Arr1[i]);
    }
    int x;
    std::cin >> x;
}