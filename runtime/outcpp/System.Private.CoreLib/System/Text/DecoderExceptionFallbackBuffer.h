#pragma once

#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace DecoderExceptionFallbackBufferNamespace {
CLASS(DecoderExceptionFallbackBuffer) : public DecoderFallbackBuffer::in {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  private: void Throw(Array<Byte> bytesUnknown, Int32 index);
  public: void ctor();
};
} // namespace DecoderExceptionFallbackBufferNamespace
using DecoderExceptionFallbackBuffer = DecoderExceptionFallbackBufferNamespace::DecoderExceptionFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
