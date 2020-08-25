#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderNLS)
FORWARD(Encoding)
FORWARDS(Rune)
namespace EncoderFallbackBufferNamespace {
CLASS(EncoderFallbackBuffer) : public object {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  public: void InternalReset();
  public: void InternalInitialize(Char* charStart, Char* charEnd, EncoderNLS encoder, Boolean setEncoder);
  public: static EncoderFallbackBuffer CreateAndInitialize(Encoding encoding, EncoderNLS encoder, Int32 originalCharCount);
  public: Char InternalGetNextChar();
  private: Boolean InternalFallback(ReadOnlySpan<Char> chars, Int32& charsConsumed);
  public: Int32 InternalFallbackGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed);
  public: Boolean TryInternalFallbackGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten);
  public: Boolean TryDrainRemainingDataForGetBytes(Span<Byte> bytes, Int32& bytesWritten);
  public: Int32 DrainRemainingDataForGetByteCount();
  private: Rune GetNextRune();
  public: Boolean InternalFallback(Char ch, Char*& chars);
  public: static void ThrowLastCharRecursive(Int32 charRecursive);
  protected: void ctor();
  public: Char* charStart;
  public: Char* charEnd;
  public: EncoderNLS encoder;
  public: Boolean setEncoder;
  public: Boolean bUsedEncoder;
  public: Boolean bFallingBack;
  public: Int32 iRecursionCount;
  private: Encoding encoding;
  private: Int32 originalCharCount;
};
} // namespace EncoderFallbackBufferNamespace
using EncoderFallbackBuffer = EncoderFallbackBufferNamespace::EncoderFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
