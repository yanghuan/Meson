#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::IO {
FORWARD(TextWriter)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Net {
namespace WebUtilityNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
class WebUtility {
  private: struct UrlDecoder : public valueType<UrlDecoder> {
    private: void FlushBytes();
    public: explicit UrlDecoder(Int32 bufferSize, Encoding encoding);
    public: void AddChar(Char ch);
    public: void AddByte(Byte b);
    public: String GetString();
    public: explicit UrlDecoder() {}
    private: Int32 _bufferSize;
    private: Int32 _numChars;
    private: Array<Char> _charBuffer;
    private: Int32 _numBytes;
    private: Array<Byte> _byteBuffer;
    private: Encoding _encoding;
  };
  private: class HtmlEntities {
    public: static Char Lookup(ReadOnlySpan<Char> entity);
    private: static UInt64 ToUInt64Key(ReadOnlySpan<Char> entity);
    public: static void cctor();
    private: static Dictionary<UInt64, Char> s_lookupTable;
  };
  public: static String HtmlEncode(String value);
  public: static void HtmlEncode(String value, TextWriter output);
  private: static void HtmlEncode(ReadOnlySpan<Char> input, ValueStringBuilder& output);
  public: static String HtmlDecode(String value);
  public: static void HtmlDecode(String value, TextWriter output);
  private: static void HtmlDecode(ReadOnlySpan<Char> input, ValueStringBuilder& output);
  private: static Int32 IndexOfHtmlEncodingChars(ReadOnlySpan<Char> input);
  private: static void GetEncodedBytes(Array<Byte> originalBytes, Int32 offset, Int32 count, Array<Byte> expandedBytes);
  public: static String UrlEncode(String value);
  public: static Array<Byte> UrlEncodeToBytes(Array<Byte> value, Int32 offset, Int32 count);
  private: static String UrlDecodeInternal(String value, Encoding encoding);
  private: static Array<Byte> UrlDecodeInternal(Array<Byte> bytes, Int32 offset, Int32 count);
  public: static String UrlDecode(String encodedValue);
  public: static Array<Byte> UrlDecodeToBytes(Array<Byte> encodedValue, Int32 offset, Int32 count);
  private: static void ConvertSmpToUtf16(UInt32 smpChar, Char& leadingSurrogate, Char& trailingSurrogate);
  private: static Int32 GetNextUnicodeScalarValueFromUtf16Surrogate(ReadOnlySpan<Char> input, Int32& index);
  private: static Int32 HexToInt(Char h);
  private: static Boolean IsUrlSafeChar(Char ch);
  private: static Boolean ValidateUrlEncodingParameters(Array<Byte> bytes, Int32 offset, Int32 count);
  private: static Int32 IndexOfHtmlDecodingChars(ReadOnlySpan<Char> input);
};
} // namespace WebUtilityNamespace
using WebUtility = WebUtilityNamespace::WebUtility;
} // namespace System::Private::CoreLib::System::Net
