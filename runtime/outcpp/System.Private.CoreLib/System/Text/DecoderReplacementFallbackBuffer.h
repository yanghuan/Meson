#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderReplacementFallback)
namespace DecoderReplacementFallbackBufferNamespace {
CLASS(DecoderReplacementFallbackBuffer) : public DecoderFallbackBuffer::in {
  public: Int32 get_Remaining();
  public: void ctor(DecoderReplacementFallback fallback);
  public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  public: Int32 InternalFallback(Array<Byte> bytes, Byte* pBytes);
  private: String _strDefault;
  private: Int32 _fallbackCount;
  private: Int32 _fallbackIndex;
};
} // namespace DecoderReplacementFallbackBufferNamespace
using DecoderReplacementFallbackBuffer = DecoderReplacementFallbackBufferNamespace::DecoderReplacementFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
