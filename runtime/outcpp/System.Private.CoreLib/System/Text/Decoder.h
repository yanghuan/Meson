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
FORWARD(DecoderFallback)
FORWARD(DecoderFallbackBuffer)
namespace DecoderNamespace {
CLASS(Decoder) : public object {
  public: DecoderFallback get_Fallback();
  public: void set_Fallback(DecoderFallback value);
  public: DecoderFallbackBuffer get_FallbackBuffer();
  public: Boolean get_InternalHasFallbackBuffer();
  protected: void ctor();
  public: void Reset();
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, Boolean flush);
  public: Int32 GetCharCount(ReadOnlySpan<Byte> bytes, Boolean flush);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush);
  public: Int32 GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush);
  public: void Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: void Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: void Convert(ReadOnlySpan<Byte> bytes, Span<Char> chars, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: DecoderFallback _fallback;
  public: DecoderFallbackBuffer _fallbackBuffer;
};
} // namespace DecoderNamespace
using Decoder = DecoderNamespace::Decoder;
} // namespace System::Private::CoreLib::System::Text
