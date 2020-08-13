#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

void Program___::F(String s, Array<Object> args) {
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  F("aaa", rt::newarr<Array<Object>>(4, 1, 2, 3, 4));
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
