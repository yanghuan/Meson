#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;

void Program___::f(Single a) {
}

void Program___::f(Double a) {
}

void Program___::Main(Array<String> args) {
  String text = "<hello,word>";
  Console::WriteLine(text->Substring(1, text->get_Length() - 1 - 1));
  Int32 num = 65535;
  Console::WriteLine(String::in::Format("\\u{0:x}", num));
  if (args->get_Length() != 2) {
    0.ToString();
  }
  Console::WriteLine(String::in::Format("\\u{0:x}", num));
  f(31.14);
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
