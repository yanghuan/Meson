#include "runtime.h"

template <class T>
struct Array
{
    int length;
    T first[0];
};

template <class T>
struct Array1
{
    //int length;
    //T first[5];
    T a;
    T b;
};

const constexpr int a = sizeof(Array<char>);
const constexpr int b = sizeof(Array1<char>);



