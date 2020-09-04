#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;

String Program___::f(TestAAA& aa) {
  return String::in::Empty;
}

void Program___::f(TestAAA* ctx) {
  String text = f(*ctx);
  TestAAA& reference = *ctx;
}

void Program___::f(IntPtr a) {
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  f((IntPtr)(Int32)(-2147483647));
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
