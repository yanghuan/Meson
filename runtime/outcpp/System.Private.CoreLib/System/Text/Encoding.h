#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Text/Decoder.h>
#include <System.Private.CoreLib/System/Text/Encoder.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
FORWARD(CodePageDataItem)
FORWARD(DecoderFallback)
FORWARD(DecoderFallbackBuffer)
FORWARD(DecoderNLS)
FORWARD(EncoderFallback)
FORWARD(EncoderFallbackBuffer)
FORWARD(EncoderNLS)
FORWARD(EncodingInfo)
FORWARD(EncodingProvider)
FORWARDS(Rune)
namespace EncodingNamespace {
using namespace Buffers;
using namespace IO;
using namespace Runtime::Serialization;
CLASS(Encoding) : public Object::in {
  public: CLASS(DefaultEncoder) : public Encoder::in {
    public: void Ctor(Encoding encoding);
    public: Object GetRealObject(StreamingContext context);
    public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush);
    public: Int32 GetByteCount(Char* chars, Int32 count, Boolean flush);
    public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush);
    public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush);
    private: Encoding _encoding;
  };
  public: CLASS(DefaultDecoder) : public Decoder::in {
    public: void Ctor(Encoding encoding);
    public: Object GetRealObject(StreamingContext context);
    public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
    public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush);
    public: Int32 GetCharCount(Byte* bytes, Int32 count, Boolean flush);
    public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
    public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush);
    public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush);
    private: Encoding _encoding;
  };
  public: CLASS(EncodingCharBuffer) : public Object::in {
    public: Boolean get_MoreData();
    public: Int32 get_BytesUsed();
    public: Int32 get_Count();
    public: void Ctor(Encoding enc, DecoderNLS decoder, Char* charStart, Int32 charCount, Byte* byteStart, Int32 byteCount);
    public: Boolean AddChar(Char ch, Int32 numBytes);
    public: Boolean AddChar(Char ch);
    public: void AdjustBytes(Int32 count);
    public: Byte GetNextByte();
    public: Boolean Fallback(Byte fallbackByte);
    public: Boolean Fallback(Array<Byte> byteBuffer);
    private: Char* _chars;
    private: Char* _charStart;
    private: Char* _charEnd;
    private: Int32 _charCountResult;
    private: Encoding _enc;
    private: DecoderNLS _decoder;
    private: Byte* _byteStart;
    private: Byte* _byteEnd;
    private: Byte* _bytes;
    private: DecoderFallbackBuffer _fallbackBuffer;
  };
  public: CLASS(EncodingByteBuffer) : public Object::in {
    public: Boolean get_MoreData();
    public: Int32 get_CharsUsed();
    public: Int32 get_Count();
    public: void Ctor(Encoding inEncoding, EncoderNLS inEncoder, Byte* inByteStart, Int32 inByteCount, Char* inCharStart, Int32 inCharCount);
    public: Boolean AddByte(Byte b, Int32 moreBytesExpected);
    public: Boolean AddByte(Byte b1);
    public: Boolean AddByte(Byte b1, Byte b2);
    public: Boolean AddByte(Byte b1, Byte b2, Int32 moreBytesExpected);
    public: void MovePrevious(Boolean bThrow);
    public: Char GetNextChar();
    private: Byte* _bytes;
    private: Byte* _byteStart;
    private: Byte* _byteEnd;
    private: Char* _chars;
    private: Char* _charStart;
    private: Char* _charEnd;
    private: Int32 _byteCountResult;
    private: Encoding _enc;
    private: EncoderNLS _encoder;
    public: EncoderFallbackBuffer fallbackBuffer;
  };
  public: static Encoding get_Default();
  public: ReadOnlySpan<Byte> get_Preamble();
  public: String get_BodyName();
  public: String get_EncodingName();
  public: String get_HeaderName();
  public: String get_WebName();
  public: Int32 get_WindowsCodePage();
  public: Boolean get_IsBrowserDisplay();
  public: Boolean get_IsBrowserSave();
  public: Boolean get_IsMailNewsDisplay();
  public: Boolean get_IsMailNewsSave();
  public: Boolean get_IsSingleByte();
  public: EncoderFallback get_EncoderFallback();
  public: void set_EncoderFallback(EncoderFallback value);
  public: DecoderFallback get_DecoderFallback();
  public: void set_DecoderFallback(DecoderFallback value);
  public: Boolean get_IsReadOnly();
  public: void set_IsReadOnly(Boolean value);
  public: static Encoding get_ASCII();
  private: static Encoding get_Latin1();
  public: Int32 get_CodePage();
  public: static Encoding get_Unicode();
  public: static Encoding get_BigEndianUnicode();
  public: static Encoding get_UTF7();
  public: static Encoding get_UTF8();
  public: static Encoding get_UTF32();
  private: static Encoding get_BigEndianUTF32();
  protected: void Ctor();
  protected: void Ctor(Int32 codePage);
  protected: void Ctor(Int32 codePage, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: void SetDefaultFallbacks();
  public: static Array<Byte> Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes);
  public: static Array<Byte> Convert(Encoding srcEncoding, Encoding dstEncoding, Array<Byte> bytes, Int32 index, Int32 count);
  public: static void RegisterProvider(EncodingProvider provider);
  public: static Encoding GetEncoding(Int32 codepage);
  public: static Encoding GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: static Encoding GetEncoding(String name);
  public: static Encoding GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: static Array<EncodingInfo> GetEncodings();
  public: Array<Byte> GetPreamble();
  private: void GetDataItem();
  public: Object Clone();
  public: Int32 GetByteCount(Array<Char> chars);
  public: Int32 GetByteCount(String s);
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String s, Int32 index, Int32 count);
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetByteCount(ReadOnlySpan<Char> chars);
  public: Array<Byte> GetBytes(Array<Char> chars);
  public: Array<Byte> GetBytes(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Array<Byte> GetBytes(String s);
  public: Array<Byte> GetBytes(String s, Int32 index, Int32 count);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Int32 GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  public: Int32 GetCharCount(Array<Byte> bytes);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetCharCount(ReadOnlySpan<Byte> bytes);
  public: Array<Char> GetChars(Array<Byte> bytes);
  public: Array<Char> GetChars(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: Int32 GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars);
  public: String GetString(Byte* bytes, Int32 byteCount);
  public: String GetString(ReadOnlySpan<Byte> bytes);
  public: Boolean IsAlwaysNormalized();
  public: Boolean IsAlwaysNormalized(NormalizationForm form);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: String GetString(Array<Byte> bytes);
  public: String GetString(Array<Byte> bytes, Int32 index, Int32 count);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: static Stream CreateTranscodingStream(Stream innerStream, Encoding innerStreamEncoding, Encoding outerStreamEncoding, Boolean leaveOpen);
  public: Array<Char> GetBestFitUnicodeToBytesData();
  public: Array<Char> GetBestFitBytesToUnicodeData();
  public: void ThrowBytesOverflow();
  public: void ThrowBytesOverflow(EncoderNLS encoder, Boolean nothingEncoded);
  public: static void ThrowConversionOverflow();
  public: void ThrowCharsOverflow();
  public: void ThrowCharsOverflow(DecoderNLS decoder, Boolean nothingDecoded);
  public: OperationStatus DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed);
  public: OperationStatus EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten);
  public: Boolean TryGetByteCount(Rune value, Int32& byteCount);
  public: Int32 GetByteCount(Char* pChars, Int32 charCount, EncoderNLS encoder);
  public: Int32 GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed);
  public: Int32 GetByteCountWithFallback(Char* pCharsOriginal, Int32 originalCharCount, Int32 charsConsumedSoFar);
  private: Int32 GetByteCountWithFallback(Char* pOriginalChars, Int32 originalCharCount, Int32 charsConsumedSoFar, EncoderNLS encoder);
  public: Int32 GetByteCountWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, EncoderNLS encoder);
  public: Int32 GetBytes(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount, EncoderNLS encoder);
  public: Int32 GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed);
  public: Int32 GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar);
  private: Int32 GetBytesWithFallback(Char* pOriginalChars, Int32 originalCharCount, Byte* pOriginalBytes, Int32 originalByteCount, Int32 charsConsumedSoFar, Int32 bytesWrittenSoFar, EncoderNLS encoder);
  public: Int32 GetBytesWithFallback(ReadOnlySpan<Char> chars, Int32 originalCharsLength, Span<Byte> bytes, Int32 originalBytesLength, EncoderNLS encoder);
  public: Int32 GetCharCount(Byte* pBytes, Int32 byteCount, DecoderNLS decoder);
  public: Int32 GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed);
  public: Int32 GetCharCountWithFallback(Byte* pBytesOriginal, Int32 originalByteCount, Int32 bytesConsumedSoFar);
  private: Int32 GetCharCountWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Int32 bytesConsumedSoFar, DecoderNLS decoder);
  private: Int32 GetCharCountWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, DecoderNLS decoder);
  public: Int32 GetChars(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount, DecoderNLS decoder);
  public: Int32 GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed);
  public: Int32 GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar);
  public: Int32 GetCharsWithFallback(Byte* pOriginalBytes, Int32 originalByteCount, Char* pOriginalChars, Int32 originalCharCount, Int32 bytesConsumedSoFar, Int32 charsWrittenSoFar, DecoderNLS decoder);
  public: Int32 GetCharsWithFallback(ReadOnlySpan<Byte> bytes, Int32 originalBytesLength, Span<Char> chars, Int32 originalCharsLength, DecoderNLS decoder);
  private: static void SCtor();
  private: static Object/*UTF8Encoding.UTF8EncodingSealed*/ s_defaultEncoding;
  public: Int32 _codePage;
  public: CodePageDataItem _dataItem;
  private: Boolean _isReadOnly;
  public: EncoderFallback encoderFallback;
  public: DecoderFallback decoderFallback;
};
} // namespace EncodingNamespace
using Encoding = EncodingNamespace::Encoding;
} // namespace System::Private::CoreLib::System::Text
