#include "Extensions-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>

namespace Test::Test::ExtensionsNamespace {
using namespace ::System::Private::CoreLib::System;

void Extensions::Test() {
  Int32 as[2] = {};
  Int32* ptr = as;
  ptr[10] = 2;
}

} // namespace Test::Test::ExtensionsNamespace
