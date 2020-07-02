#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
namespace EncodingInfoNamespace {
CLASS(EncodingInfo) {
  public: Encoding GetEncoding();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
};
} // namespace EncodingInfoNamespace
using EncodingInfo = EncodingInfoNamespace::EncodingInfo;
} // namespace System::Private::CoreLib::System::Text
