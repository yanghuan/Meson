#include "Program-dep.h"

#include <System.Console/System/Console-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <Test/Test/Program-dep.h>
#include <Test/Test/TestA-dep.h>

namespace Test::Test::ProgramNamespace {
using namespace ::System::Console::System;
using namespace ::System::Private::CoreLib::System;

void Program___::__c__DisplayClass1_0___::ctor() {
}

void Program___::__c__DisplayClass1_0___::_f2_b__0() {
  a++;
}

void Program___::__c__DisplayClass1_0___::_f2_b__1() {
  a++;
}

void Program___::f2() {
}

void Program___::f2(Int32 a) {
  __c__DisplayClass1_0 __c__DisplayClass1_ = rt::newobj<__c__DisplayClass1_0>();
  __c__DisplayClass1_->a = a;
  Action<> action = {__c__DisplayClass1_, &__c__DisplayClass1_0::in::_f2_b__0};
  Action<> action2 = {__c__DisplayClass1_, &__c__DisplayClass1_0::in::_f2_b__1};
  Int32 a2 = __c__DisplayClass1_->a;
}

void Program___::Main(Array<String> args) {
  Console::WriteLine(args);
  TestA object = rt::newobj<TestA>();
  Action<> action = {object, &TestA::in::f};
  Action<> action2 = &TestA::in::f1;
  Action<> action3 = f2;
}

void Program___::ctor() {
}

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
}
