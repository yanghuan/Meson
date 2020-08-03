#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
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
FORWARDS(Rune)
namespace UTF8EncodingNamespace {
using namespace Buffers;
class UTF8EncodingSealed___;
using UTF8EncodingSealed = rt::ref<UTF8EncodingSealed___>;
CLASS(UTF8Encoding) : public Encoding::in {
  friend class UTF8EncodingSealed___;
  public: using UTF8EncodingSealed = UTF8EncodingSealed;
  public: static ReadOnlySpan<Byte> get_PreambleSpan();
  public: ReadOnlySpan<Byte> get_Preamble();
  public: void Ctor();
  public: void Ctor(Boolean encoderShouldEmitUTF8Identifier);
  public: void Ctor(Boolean encoderShouldEmitUTF8Identifier, Boolean throwOnInvalidBytes);
  public: void SetDefaultFallbacks();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String chars);
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetByteCount(ReadOnlySpan<Char> chars);
  private: Int32 GetByteCountCommon(Char* pChars, Int32 charCount);
  public: Int32 GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Int32 GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  private: Int32 GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount);
  public: Int32 GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetCharCount(ReadOnlySpan<Byte> bytes);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: Int32 GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars);
  private: Int32 GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount);
  public: Int32 GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed);
  public: Int32 GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder);
  public: String GetString(Array<Byte> bytes, Int32 index, Int32 count);
  private: Int32 GetCharCountCommon(Byte* pBytes, Int32 byteCount);
  public: Int32 GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  public: Boolean TryGetByteCount(Rune value, Int32& byteCount);
  public: OperationStatus EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten);
  public: OperationStatus DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Array<Byte> GetPreamble();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: static void SCtor();
  public: static UTF8EncodingSealed s_default;
  private: Boolean _emitUTF8Identifier;
  private: Boolean _isThrowException;
};
CLASS(UTF8EncodingSealed) : public UTF8Encoding::in {
  public: ReadOnlySpan<Byte> get_Preamble();
  public: void Ctor(Boolean encoderShouldEmitUTF8Identifier);
  public: Object Clone();
  public: Array<Byte> GetBytes(String s);
  private: Array<Byte> GetBytesForSmallInput(String s);
  public: String GetString(Array<Byte> bytes);
  private: String GetStringForSmallInput(Array<Byte> bytes);
};
} // namespace UTF8EncodingNamespace
using UTF8Encoding = UTF8EncodingNamespace::UTF8Encoding;
} // namespace System::Private::CoreLib::System::Text
