#pragma once

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
enum class OperationStatus : int32_t;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm : int32_t;
FORWARD(Decoder)
FORWARD(DecoderFallback)
FORWARD(Encoder)
FORWARD(EncoderFallback)
FORWARDS(Rune)
namespace Latin1EncodingNamespace {
using namespace System::Buffers;
CLASS(Latin1Encoding) : public Encoding::in {
  public: FRIENDN(Latin1EncodingSealed)
  public: ReadOnlySpan<Byte> get_Preamble();
  public: Boolean get_IsSingleByte();
  public: void ctor();
  public: void SetDefaultFallbacks();
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(ReadOnlySpan<Char> chars);
  public: Int32 GetByteCount(String s);
  private: Int32 GetByteCountCommon(Char* pChars, Int32 charCount);
  public: Int32 GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  private: Int32 GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount);
  public: Int32 GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetCharCount(Array<Byte> bytes);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(ReadOnlySpan<Byte> bytes);
  public: Int32 GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: Array<Char> GetChars(Array<Byte> bytes);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Array<Char> GetChars(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars);
  public: String GetString(Array<Byte> bytes);
  public: String GetString(Array<Byte> bytes, Int32 index, Int32 count);
  private: Int32 GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount);
  public: Int32 GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  public: Boolean TryGetByteCount(Rune value, Int32& byteCount);
  public: OperationStatus EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten);
  public: OperationStatus DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed);
  public: Boolean IsAlwaysNormalized(NormalizationForm form);
  private: static Boolean FallbackSupportsFastGetByteCount(EncoderFallback fallback);
  private: static void cctor();
  public: static Latin1EncodingSealed s_default;
};
CLASS(Latin1EncodingSealed) : public Latin1Encoding::in {
  public: Object Clone();
  public: void ctor();
};
} // namespace Latin1EncodingNamespace
using Latin1Encoding = Latin1EncodingNamespace::Latin1Encoding;
} // namespace System::Private::CoreLib::System::Text
