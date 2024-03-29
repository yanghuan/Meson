#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace IdnMappingNamespace {
CLASS(IdnMapping) : public object {
  public: Boolean get_AllowUnassigned();
  public: void set_AllowUnassigned(Boolean value);
  public: Boolean get_UseStd3AsciiRules();
  public: void set_UseStd3AsciiRules(Boolean value);
  private: UInt32 get_IcuFlags();
  private: UInt32 get_NlsFlags();
  public: void ctor();
  public: String GetAscii(String unicode);
  public: String GetAscii(String unicode, Int32 index);
  public: String GetAscii(String unicode, Int32 index, Int32 count);
  public: String GetUnicode(String ascii);
  public: String GetUnicode(String ascii, Int32 index);
  public: String GetUnicode(String ascii, Int32 index, Int32 count);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: static String GetStringForOutput(String originalString, Char* input, Int32 inputLength, Char* output, Int32 outputLength);
  private: String GetAsciiInvariant(String unicode, Int32 index, Int32 count);
  private: static Boolean ValidateStd3AndAscii(String unicode, Boolean bUseStd3, Boolean bCheckAscii);
  private: static String PunycodeEncode(String unicode);
  private: static Boolean IsDot(Char c);
  private: static Boolean IsSupplementary(Int32 cTest);
  private: static Boolean Basic(UInt32 cp);
  private: static void ValidateStd3(Char c, Boolean bNextToDot);
  private: String GetUnicodeInvariant(String ascii, Int32 index, Int32 count);
  private: static String PunycodeDecode(String ascii);
  private: static Int32 DecodeDigit(Char cp);
  private: static Int32 Adapt(Int32 delta, Int32 numpoints, Boolean firsttime);
  private: static Char EncodeBasic(Char bcp);
  private: static Boolean HasUpperCaseFlag(Char punychar);
  private: static Char EncodeDigit(Int32 d);
  private: String IcuGetAsciiCore(String unicodeString, Char* unicode, Int32 count);
  private: String IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count);
  private: String IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength, Boolean reattempt);
  private: static void CheckInvalidIdnCharacters(Char* s, Int32 count, UInt32 flags, String paramName);
  private: String NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count);
  private: String NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count, UInt32 flags, Char* output, Int32 outputLength);
  private: String NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count);
  private: String NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength);
  private: static void ThrowForZeroLength(Boolean unicode);
  public: static void cctor();
  private: Boolean _allowUnassigned;
  private: Boolean _useStd3AsciiRules;
  private: static Array<Char> s_dotSeparators;
};
} // namespace IdnMappingNamespace
using IdnMapping = IdnMappingNamespace::IdnMapping;
} // namespace System::Private::CoreLib::System::Globalization
