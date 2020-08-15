#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Int32 num = args->get_Length();
  Console::WriteLine(String::in::Format("dddd{0:x}ddd", num));
  {
    rt::lock(args);
    num = 2;
  }
  auto& default = args;
  default == nullptr ? nullptr : default->get_Length().ToString();
  auto& extern = args;
  auto& ref = extern == nullptr ? nullptr : extern->GetType();
  auto& out = ref == nullptr ? nullptr : ref->get_Assembly();
  String text = out == nullptr ? nullptr : out->get_FullName()->ToString();
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
