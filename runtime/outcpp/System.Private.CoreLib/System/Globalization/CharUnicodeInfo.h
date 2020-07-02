#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Byte)
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Double)
FORWARDS(Char)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory;
enum class BidiCategory;
namespace CharUnicodeInfoNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class CharUnicodeInfo {
  private: static ReadOnlySpan<Byte> get_CategoryLevel1Index();
  private: static ReadOnlySpan<Byte> get_CategoryLevel2Index();
  private: static ReadOnlySpan<Byte> get_CategoryLevel3Index();
  private: static ReadOnlySpan<Byte> get_CategoriesValue();
  private: static ReadOnlySpan<Byte> get_NumericLevel1Index();
  private: static ReadOnlySpan<Byte> get_NumericLevel2Index();
  private: static ReadOnlySpan<Byte> get_NumericLevel3Index();
  private: static ReadOnlySpan<Byte> get_NumericValues();
  private: static ReadOnlySpan<Byte> get_DigitValues();
  public: static Int32 InternalConvertToUtf32(String s, Int32 index);
  public: static Int32 InternalConvertToUtf32(StringBuilder s, Int32 index);
  public: static Int32 InternalConvertToUtf32(String s, Int32 index, Int32& charLength);
  public: static Double InternalGetNumericValue(Int32 ch);
  public: static Byte InternalGetDigitValues(Int32 ch, Int32 offset);
  public: static Double GetNumericValue(Char ch);
  public: static Double GetNumericValue(String s, Int32 index);
  public: static Int32 GetDecimalDigitValue(Char ch);
  public: static Int32 GetDecimalDigitValue(String s, Int32 index);
  public: static Int32 GetDigitValue(Char ch);
  public: static Int32 GetDigitValue(String s, Int32 index);
  public: static UnicodeCategory GetUnicodeCategory(Char ch);
  public: static UnicodeCategory GetUnicodeCategory(String s, Int32 index);
  public: static UnicodeCategory GetUnicodeCategory(Int32 codePoint);
  public: static Byte InternalGetCategoryValue(Int32 ch, Int32 offset);
  public: static UnicodeCategory InternalGetUnicodeCategory(String value, Int32 index);
  public: static BidiCategory GetBidiCategory(String s, Int32 index);
  public: static BidiCategory GetBidiCategory(StringBuilder s, Int32 index);
  public: static UnicodeCategory InternalGetUnicodeCategory(String str, Int32 index, Int32& charLength);
  public: static Boolean IsCombiningCategory(UnicodeCategory uc);
};
} // namespace CharUnicodeInfoNamespace
using CharUnicodeInfo = CharUnicodeInfoNamespace::CharUnicodeInfo;
} // namespace System::Private::CoreLib::System::Globalization
