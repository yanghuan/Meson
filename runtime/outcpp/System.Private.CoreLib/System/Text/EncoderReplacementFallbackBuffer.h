#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace EncoderReplacementFallbackBufferNamespace {
CLASS(EncoderReplacementFallbackBuffer) {
  public: Int32 get_Remaining();
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
