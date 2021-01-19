#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace EncoderLatin1BestFitFallbackBufferNamespace {
CLASS(EncoderLatin1BestFitFallbackBuffer) : public EncoderFallbackBuffer::in {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  private: Char TryBestFit(Char cUnknown);
  public: void ctor();
  public: static void cctor();
  private: Char _cBestFit;
  private: Int32 _iCount;
  private: Int32 _iSize;
  private: static Array<Char> s_arrayCharBestFit;
};
} // namespace EncoderLatin1BestFitFallbackBufferNamespace
using EncoderLatin1BestFitFallbackBuffer = EncoderLatin1BestFitFallbackBufferNamespace::EncoderLatin1BestFitFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
