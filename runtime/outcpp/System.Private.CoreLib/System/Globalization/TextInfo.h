#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARD(ICloneable)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory;
FORWARD(CultureData)
namespace TextInfoNamespace {
using namespace Runtime::Serialization;
using namespace Text;
CLASS(TextInfo) : public Object::in {
  public: using interface = rt::TypeList<ICloneable, IDeserializationCallback>;
  private: enum class Tristate : uint8_t {
    NotInitialized = 0,
    False = 1,
    True = 2,
  };
  private: struct ToUpperConversion : public valueType<ToUpperConversion> {
  };
  private: struct ToLowerConversion : public valueType<ToLowerConversion> {
  };
  public: Int32 get_ANSICodePage();
  public: Int32 get_OEMCodePage();
  public: Int32 get_MacCodePage();
  public: Int32 get_EBCDICCodePage();
  public: Int32 get_LCID();
  public: String get_CultureName();
  public: Boolean get_IsReadOnly();
  public: String get_ListSeparator();
  public: void set_ListSeparator(String value);
  private: Boolean get_IsAsciiCasingSameAsInvariant();
  public: Boolean get_IsRightToLeft();
  private: Boolean get_IsInvariant();
  public: void Ctor(CultureData cultureData);
  private: void Ctor(CultureData cultureData, Boolean readOnly);
  public: Object Clone();
  public: static TextInfo ReadOnly(TextInfo textInfo);
  private: void VerifyWritable();
  public: void SetReadOnlyState(Boolean readOnly);
  public: Char ToLower(Char c);
  public: static Char ToLowerInvariant(Char c);
  public: String ToLower(String str);
  private: Char ChangeCase(Char c, Boolean toUpper);
  public: void ChangeCaseToLower(ReadOnlySpan<Char> source, Span<Char> destination);
  public: void ChangeCaseToUpper(ReadOnlySpan<Char> source, Span<Char> destination);
  private: template <class TConversion>
  void ChangeCaseCommon(ReadOnlySpan<Char> source, Span<Char> destination);
  private: template <class TConversion>
  void ChangeCaseCommon(Char& source, Char& destination, Int32 charCount);
  private: template <class TConversion>
  String ChangeCaseCommon(String source);
  public: static String ToLowerAsciiInvariant(String s);
  public: static void ToLowerAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination);
  private: static String ToUpperAsciiInvariant(String s);
  public: static void ToUpperAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination);
  private: static Char ToLowerAsciiInvariant(Char c);
  public: Char ToUpper(Char c);
  public: static Char ToUpperInvariant(Char c);
  public: String ToUpper(String str);
  private: static Char ToUpperAsciiInvariant(Char c);
  private: void PopulateIsAsciiCasingSameAsInvariant();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToTitleCase(String str);
  private: static Int32 AddNonLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen);
  private: Int32 AddTitlecaseLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen);
  private: void ChangeCaseCore(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper);
  private: static Boolean IsWordSeparator(UnicodeCategory category);
  private: static Boolean IsLetterCategory(UnicodeCategory uc);
  private: static Boolean NeedsTurkishCasing(String localeName);
  public: void IcuChangeCase(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper);
  private: void NlsChangeCase(Char* pSource, Int32 pSourceLen, Char* pResult, Int32 pResultLen, Boolean toUpper);
  private: static Boolean IsInvariantLocale(String localeName);
  private: static void SCtor();
  private: String _listSeparator;
  private: Boolean _isReadOnly;
  private: String _cultureName;
  private: CultureData _cultureData;
  private: String _textInfoName;
  private: Tristate _isAsciiCasingSameAsInvariant;
  public: static TextInfo Invariant;
  private: Tristate _needsTurkishCasing;
  private: IntPtr _sortHandle;
};
} // namespace TextInfoNamespace
using TextInfo = TextInfoNamespace::TextInfo;
} // namespace System::Private::CoreLib::System::Globalization
