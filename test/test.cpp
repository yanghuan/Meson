#include <iostream>
#include <atomic>
#include "../rt/gc_object.hpp"

using namespace std;

int main()
{ 
  cout << sizeof(meson::GCObjectHead);
}


