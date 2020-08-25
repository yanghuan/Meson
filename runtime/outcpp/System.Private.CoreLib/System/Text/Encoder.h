#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallback)
FORWARD(EncoderFallbackBuffer)
namespace EncoderNamespace {
CLASS(Encoder) : public object {
  public: EncoderFallback get_Fallback();
  public: void set_Fallback(EncoderFallback value);
  public: EncoderFallbackBuffer get_FallbackBuffer();
  public: Boolean get_InternalHasFallbackBuffer();
  protected: void ctor();
  public: void Reset();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush);
  public: Int32 GetByteCount(Char* chars, Int32 count, Boolean flush);
  public: Int32 GetByteCount(ReadOnlySpan<Char> chars, Boolean flush);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush);
  public: Int32 GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush);
  public: void Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: void Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: void Convert(ReadOnlySpan<Char> chars, Span<Byte> bytes, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: EncoderFallback _fallback;
  public: EncoderFallbackBuffer _fallbackBuffer;
};
} // namespace EncoderNamespace
using Encoder = EncoderNamespace::Encoder;
} // namespace System::Private::CoreLib::System::Text
