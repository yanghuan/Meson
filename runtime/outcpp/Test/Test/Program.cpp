#include "Program-dep.h"

#include <System.Private.CoreLib/System/Single-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Private::CoreLib::System;
void Program___::Ctor() {
};

void Program___::Ctor(Int32 a) {
};

void Program___::Main(Array<String> args) {
  Single num = Single::NaN;
  Single num2 = Single::PositiveInfinity;
  Single num3 = Single::NegativeInfinity;
};

void Program___::Print(Int32 a) {
};

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
};
