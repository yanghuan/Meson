#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/E.h>
#include <Test/Test/Extension-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

Int32 Program___::get_A() {
  return A;
}

void Program___::set_A(Int32 value) {
  A = value;
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Extension::F(E::A, 10, true);
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
