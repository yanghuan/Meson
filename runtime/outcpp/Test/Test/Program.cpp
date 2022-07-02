#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;

void Program___::Main(Array<String> args) {
  Console::WriteLine((String)"hello,word");
  Int32 num = 65535;
  Console::WriteLine(String::in::Format("\\u{0:x}", num));
  if (args->get_Length() != 2) {
    0.ToString();
  }
  Console::WriteLine(String::in::Format("\\u{0:x}", num));
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
