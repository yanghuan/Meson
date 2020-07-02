#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Char)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace EncoderExceptionFallbackBufferNamespace {
CLASS(EncoderExceptionFallbackBuffer) {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
};
} // namespace EncoderExceptionFallbackBufferNamespace
using EncoderExceptionFallbackBuffer = EncoderExceptionFallbackBufferNamespace::EncoderExceptionFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
