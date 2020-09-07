#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
namespace ExtensionsNamespace {
using namespace ::System::Private::CoreLib::System;
class Extensions {
  public: static String To(String s);
};
} // namespace ExtensionsNamespace
using Extensions = ExtensionsNamespace::Extensions;
} // namespace Test::Test
