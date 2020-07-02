#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Boolean)
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace DecoderExceptionFallbackBufferNamespace {
CLASS(DecoderExceptionFallbackBuffer) {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  private: void Throw(Array<Byte> bytesUnknown, Int32 index);
};
} // namespace DecoderExceptionFallbackBufferNamespace
using DecoderExceptionFallbackBuffer = DecoderExceptionFallbackBufferNamespace::DecoderExceptionFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
