#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderNLS)
FORWARD(Encoding)
FORWARDS(Rune)
namespace DecoderFallbackBufferNamespace {
CLASS(DecoderFallbackBuffer) : public Object::in {
  public: Int32 get_Remaining();
  public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  public: void InternalReset();
  public: void InternalInitialize(Byte* byteStart, Char* charEnd);
  public: static DecoderFallbackBuffer CreateAndInitialize(Encoding encoding, DecoderNLS decoder, Int32 originalByteCount);
  public: Boolean InternalFallback(Array<Byte> bytes, Byte* pBytes, Char*& chars);
  public: Int32 InternalFallback(Array<Byte> bytes, Byte* pBytes);
  public: Int32 InternalFallbackGetCharCount(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength);
  public: Boolean TryInternalFallbackGetChars(ReadOnlySpan<Byte> remainingBytes, Int32 fallbackLength, Span<Char> chars, Int32& charsWritten);
  private: Rune GetNextRune();
  public: Int32 DrainRemainingDataForGetCharCount();
  public: Boolean TryDrainRemainingDataForGetChars(Span<Char> chars, Int32& charsWritten);
  public: void ThrowLastBytesRecursive(Array<Byte> bytesUnknown);
  protected: void ctor();
  public: Byte* byteStart;
  public: Char* charEnd;
  public: Encoding _encoding;
  public: DecoderNLS _decoder;
  private: Int32 _originalByteCount;
};
} // namespace DecoderFallbackBufferNamespace
using DecoderFallbackBuffer = DecoderFallbackBufferNamespace::DecoderFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
