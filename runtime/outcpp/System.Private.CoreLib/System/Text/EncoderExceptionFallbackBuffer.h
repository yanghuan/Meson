#pragma once

#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace EncoderExceptionFallbackBufferNamespace {
CLASS(EncoderExceptionFallbackBuffer) : public EncoderFallbackBuffer::in {
  public: Int32 get_Remaining();
  public: void ctor();
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
};
} // namespace EncoderExceptionFallbackBufferNamespace
using EncoderExceptionFallbackBuffer = EncoderExceptionFallbackBufferNamespace::EncoderExceptionFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
