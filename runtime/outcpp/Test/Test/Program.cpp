#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

Int32 Program___::get_A() {
  return a;
}

void Program___::set_A(Int32 value) {
  a = value;
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  get_A() = args->get_Length();
  Int32 num = get_A();
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
