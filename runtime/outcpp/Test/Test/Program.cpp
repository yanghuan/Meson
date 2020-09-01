#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
}

ValueTuple<Int32, Int32> Program___::GetDefault() {
  return rt::default__;
}

String Program___::GetDefaultS() {
  return nullptr;
}

Int32 Program___::GetDefaultA() {
  return 0;
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
