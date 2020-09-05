#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace EncodingCacheNamespace {
using namespace System::Text;
class EncodingCache {
  public: static void cctor();
  public: static Encoding UTF8NoBOM;
};
} // namespace EncodingCacheNamespace
using EncodingCache = EncodingCacheNamespace::EncodingCache;
} // namespace System::Private::CoreLib::System::IO
