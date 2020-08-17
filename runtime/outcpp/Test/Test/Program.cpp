#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;

void Program___::f(TestEnum E) {
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Write(args, (Array<String>)nullptr);
  Task<>::in::FromResult(2);
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
