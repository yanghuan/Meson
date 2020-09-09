#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  stringBuilder->Append((Int32)10);
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
