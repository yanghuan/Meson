#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

void Program___::Print(Array<Object> args) {
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Print(rt::newarr<Array<Object>>(2, args, args));
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
