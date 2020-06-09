#include "test.h"
#include "runtime.h"

template <class T> struct A;   // forward declaration

template <class T=int> struct A { };

int main() {
  return 0;
}