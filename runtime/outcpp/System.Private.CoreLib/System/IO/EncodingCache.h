#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace EncodingCacheNamespace {
using namespace Text;
class EncodingCache : public Object::in {
  private: static void SCtor();
  public: static Encoding UTF8NoBOM;
};
} // namespace EncodingCacheNamespace
using EncodingCache = EncodingCacheNamespace::EncodingCache;
} // namespace System::Private::CoreLib::System::IO
