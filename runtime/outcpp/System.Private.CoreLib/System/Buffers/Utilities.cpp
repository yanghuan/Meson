#include "Utilities-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::UtilitiesNamespace {
Int32 Utilities::SelectBucketIndex(Int32 bufferSize) {
}

Int32 Utilities::GetMaxSizeForBucket(Int32 binIndex) {
  return 16 << binIndex;
}

} // namespace System::Private::CoreLib::System::Buffers::UtilitiesNamespace
