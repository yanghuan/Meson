#include "EncodingCache-dep.h"

#include <System.Private.CoreLib/System/Text/UTF8Encoding-dep.h>

namespace System::Private::CoreLib::System::IO::EncodingCacheNamespace {
using namespace System::Text;

void EncodingCache::cctor() {
  UTF8NoBOM = rt::newobj<UTF8Encoding>(false, true);
}

} // namespace System::Private::CoreLib::System::IO::EncodingCacheNamespace
