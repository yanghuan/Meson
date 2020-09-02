#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEnumerator.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections::Generic;

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  Array<Int32> array = rt::newarr<Array<Int32>>(10);
  IList<Int32> list = array;
  IEnumerator<Int32> enumerator = list->GetEnumerator();
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
