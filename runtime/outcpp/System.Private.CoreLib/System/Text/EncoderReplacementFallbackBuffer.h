#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderReplacementFallback)
namespace EncoderReplacementFallbackBufferNamespace {
CLASS(EncoderReplacementFallbackBuffer) : public EncoderFallbackBuffer::in {
  public: Int32 get_Remaining();
  public: void Ctor(EncoderReplacementFallback fallback);
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  private: String _strDefault;
  private: Int32 _fallbackCount;
  private: Int32 _fallbackIndex;
};
} // namespace EncoderReplacementFallbackBufferNamespace
using EncoderReplacementFallbackBuffer = EncoderReplacementFallbackBufferNamespace::EncoderReplacementFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
