#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace UtilitiesNamespace {
class Utilities {
  public: static Int32 SelectBucketIndex(Int32 bufferSize);
  public: static Int32 GetMaxSizeForBucket(Int32 binIndex);
};
} // namespace UtilitiesNamespace
using Utilities = UtilitiesNamespace::Utilities;
} // namespace System::Private::CoreLib::System::Buffers
