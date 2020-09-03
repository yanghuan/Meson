#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

Array<Int32> Program___::Get(Array<Int32> args) {
  return args;
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Array<Int32> array = Get(Array<>::in::Empty<Int32>());
  Array<Int32> array2 = Get(Array<>::in::Empty<Int32>());
  Console::WriteLine(array == array2);
  Console::WriteLine(array == Array<>::in::Empty<Int32>());
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
