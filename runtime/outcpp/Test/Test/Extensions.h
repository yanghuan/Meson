#pragma once

#include <rt/GCObject.h>

namespace Test::Test {
namespace ExtensionsNamespace {
class Extensions {
  public: static void Test();
};
} // namespace ExtensionsNamespace
using Extensions = ExtensionsNamespace::Extensions;
} // namespace Test::Test
