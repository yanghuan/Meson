#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/A-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;
void Program___::f() {
}

void Program___::Main(Array<String> args) {
  f();
  Console::WriteLine(args);
  Int32 num = 10;
  A a = rt::newobj<A>();
  a->F((Double)num);
}

void Program___::Ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
