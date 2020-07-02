#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderExceptionFallbackNamespace {
CLASS(EncoderExceptionFallback) {
  public: Int32 get_MaxCharCount();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
};
} // namespace EncoderExceptionFallbackNamespace
using EncoderExceptionFallback = EncoderExceptionFallbackNamespace::EncoderExceptionFallback;
} // namespace System::Private::CoreLib::System::Text
