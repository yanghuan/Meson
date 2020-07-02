#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics::Hashing {
namespace HashHelpersNamespace {
class HashHelpers {
  public: static Int32 Combine(Int32 h1, Int32 h2);
  public: static Int32 RandomSeed;
};
} // namespace HashHelpersNamespace
using HashHelpers = HashHelpersNamespace::HashHelpers;
} // namespace System::Private::CoreLib::System::Numerics::Hashing
