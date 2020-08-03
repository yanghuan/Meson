#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(DecoderFallback)
FORWARD(DecoderNLS)
FORWARD(Encoder)
FORWARD(EncoderFallback)
FORWARD(EncoderNLS)
FORWARDS(Rune)
namespace ASCIIEncodingNamespace {
using namespace Buffers;
CLASS(ASCIIEncoding) : public Encoding::in {
  friend class ASCIIEncodingSealed___;
  public: Boolean get_IsSingleByte();
  public: void Ctor();
  public: void SetDefaultFallbacks();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String chars);
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetByteCount(ReadOnlySpan<Char> chars);
  private: Int32 GetByteCountCommon(Char* pChars, Int32 charCount);
  public: Int32 GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed);
  public: Int32 GetBytes(String chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Int32 GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  private: Int32 GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount);
  public: Int32 GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed);
  public: Int32 GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetCharCount(ReadOnlySpan<Byte> bytes);
  private: Int32 GetCharCountCommon(Byte* pBytes, Int32 byteCount);
  public: Int32 GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: Int32 GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars);
  private: Int32 GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount);
  public: Int32 GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed);
  public: Int32 GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder);
  public: String GetString(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount);
  public: Boolean TryGetByteCount(Rune value, Int32& byteCount);
  public: OperationStatus EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten);
  public: OperationStatus DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  private: static void SCtor();
  public: static ASCIIEncodingSealed s_default;
};
CLASS(ASCIIEncodingSealed) : public ASCIIEncoding::in {
  public: Object Clone();
  public: void Ctor();
};
} // namespace ASCIIEncodingNamespace
using ASCIIEncoding = ASCIIEncodingNamespace::ASCIIEncoding;
} // namespace System::Private::CoreLib::System::Text
