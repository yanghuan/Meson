#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Extensions-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Extensions::Test();
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
