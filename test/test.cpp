#include <atomic>
#include <iostream>

#include "../rt/GCObject.h"

using namespace std;
using namespace meson;

class A {
 public:
  ~A() { cout << "AA" << endl; }
  void f() { cout << "ff" << this << endl;
  }
 private:
};

void f() { A a[2] = {A(), A()}; }

int main() { 
  f();
  meson::ref<A> i = nullptr;
  i->f();
  return 1;
}
