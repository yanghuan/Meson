#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Double)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARDS(Rune)
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Text::Unicode {
enum class GraphemeClusterBreakType;
} // namespace System::Private::CoreLib::System::Text::Unicode
namespace System::Private::CoreLib::System::Globalization {
enum class StrongBidiCategory;
enum class UnicodeCategory;
namespace CharUnicodeInfoNamespace {
using namespace Text;
using namespace Text::Unicode;
class CharUnicodeInfo {
  private: static ReadOnlySpan<Byte> get_CategoryCasingLevel1Index();
  private: static ReadOnlySpan<Byte> get_CategoryCasingLevel2Index();
  private: static ReadOnlySpan<Byte> get_CategoryCasingLevel3Index();
  private: static ReadOnlySpan<Byte> get_CategoriesValues();
  private: static ReadOnlySpan<Byte> get_NumericGraphemeLevel1Index();
  private: static ReadOnlySpan<Byte> get_NumericGraphemeLevel2Index();
  private: static ReadOnlySpan<Byte> get_NumericGraphemeLevel3Index();
  private: static ReadOnlySpan<Byte> get_DigitValues();
  private: static ReadOnlySpan<Byte> get_NumericValues();
  private: static ReadOnlySpan<Byte> get_GraphemeSegmentationValues();
  public: static StrongBidiCategory GetBidiCategory(String s, Int32 index);
  public: static StrongBidiCategory GetBidiCategory(StringBuilder s, Int32 index);
  private: static StrongBidiCategory GetBidiCategoryNoBoundsChecks(UInt32 codePoint);
  public: static Int32 GetDecimalDigitValue(Char ch);
  public: static Int32 GetDecimalDigitValue(String s, Int32 index);
  private: static Int32 GetDecimalDigitValueInternalNoBoundsCheck(UInt32 codePoint);
  public: static Int32 GetDigitValue(Char ch);
  public: static Int32 GetDigitValue(String s, Int32 index);
  private: static Int32 GetDigitValueInternalNoBoundsCheck(UInt32 codePoint);
  public: static GraphemeClusterBreakType GetGraphemeClusterBreakType(Rune rune);
  public: static Boolean GetIsWhiteSpace(Char ch);
  public: static Double GetNumericValue(Char ch);
  public: static Double GetNumericValue(Int32 codePoint);
  public: static Double GetNumericValue(String s, Int32 index);
  private: static Double GetNumericValueNoBoundsCheck(UInt32 codePoint);
  public: static UnicodeCategory GetUnicodeCategory(Char ch);
  public: static UnicodeCategory GetUnicodeCategory(Int32 codePoint);
  public: static UnicodeCategory GetUnicodeCategory(String s, Int32 index);
  public: static UnicodeCategory GetUnicodeCategoryInternal(String value, Int32 index);
  public: static UnicodeCategory GetUnicodeCategoryInternal(String str, Int32 index, Int32& charLength);
  private: static UnicodeCategory GetUnicodeCategoryNoBoundsChecks(UInt32 codePoint);
  private: static Int32 GetCodePointFromString(String s, Int32 index);
  private: static UIntPtr GetCategoryCasingTableOffsetNoBoundsChecks(UInt32 codePoint);
  private: static UIntPtr GetNumericGraphemeTableOffsetNoBoundsChecks(UInt32 codePoint);
};
} // namespace CharUnicodeInfoNamespace
using CharUnicodeInfo = CharUnicodeInfoNamespace::CharUnicodeInfo;
} // namespace System::Private::CoreLib::System::Globalization
