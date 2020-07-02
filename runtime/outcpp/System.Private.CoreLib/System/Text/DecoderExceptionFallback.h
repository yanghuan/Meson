#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
namespace DecoderExceptionFallbackNamespace {
CLASS(DecoderExceptionFallback) {
  public: Int32 get_MaxCharCount();
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
};
} // namespace DecoderExceptionFallbackNamespace
using DecoderExceptionFallback = DecoderExceptionFallbackNamespace::DecoderExceptionFallback;
} // namespace System::Private::CoreLib::System::Text
