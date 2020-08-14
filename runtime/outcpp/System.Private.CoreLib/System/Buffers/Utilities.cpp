#include "Utilities-dep.h"

#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::UtilitiesNamespace {
using namespace System::Numerics;

Int32 Utilities::SelectBucketIndex(Int32 bufferSize) {
  return BitOperations::Log2((UInt32)((bufferSize - 1) | 15)) - 3;
}

Int32 Utilities::GetMaxSizeForBucket(Int32 binIndex) {
  return 16 << binIndex;
}

} // namespace System::Private::CoreLib::System::Buffers::UtilitiesNamespace
