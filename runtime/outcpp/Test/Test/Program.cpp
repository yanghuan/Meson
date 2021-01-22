#include "Program-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Private::CoreLib::System;

void Program___::Main(Array<String> args) {
  Char c = u'ÿ';
  Char c2 = u'\xffff';
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
