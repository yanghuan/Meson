#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
enum class E : int32_t;
namespace ExtensionNamespace {
using namespace ::System::Private::CoreLib::System;
class Extension {
  public: static void F(E e, Int32 a = 10, Boolean c = false);
};
} // namespace ExtensionNamespace
using Extension = ExtensionNamespace::Extension;
} // namespace Test::Test
