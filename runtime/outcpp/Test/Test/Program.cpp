#include "Program-dep.h"

#include <System.Private.CoreLib/System/DateTime-dep.h>
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
  Int32 a = *(Int32*)(&num);
  Int32 a2 = *(Int32*)(&num2);
  Int32 a3 = *(Int32*)(&num3);
  Print(a);
  Print(a2);
  Print(a3);
  rt::default<DateTime>.AddDays(2).ToString();
};

void Program___::Print(Int32 a) {
};

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
};
