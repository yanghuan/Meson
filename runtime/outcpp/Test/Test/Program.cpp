#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>
#include <Test/Test/TestA-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Array<TestA> array = rt::newarr<Array<TestA>>(2);
  Array<TestA> array2 = array;
  for (TestA&& testA : *array2) {
    testA.Do();
  }
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
