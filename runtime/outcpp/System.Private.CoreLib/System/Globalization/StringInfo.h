#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory;
FORWARD(TextElementEnumerator)
namespace StringInfoNamespace {
CLASS(StringInfo) {
  private: Array<Int32> get_Indexes();
  public: String get_String();
  public: void set_String(String value);
  public: Int32 get_LengthInTextElements();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: String SubstringByTextElements(Int32 startingTextElement);
  public: String SubstringByTextElements(Int32 startingTextElement, Int32 lengthInTextElements);
  public: static String GetNextTextElement(String str);
  public: static Int32 GetCurrentTextElementLen(String str, Int32 index, Int32 len, UnicodeCategory& ucCurrent, Int32& currentCharCount);
  public: static String GetNextTextElement(String str, Int32 index);
  public: static TextElementEnumerator GetTextElementEnumerator(String str);
  public: static TextElementEnumerator GetTextElementEnumerator(String str, Int32 index);
  public: static Array<Int32> ParseCombiningCharacters(String str);
  private: String _str;
  private: Array<Int32> _indexes;
};
} // namespace StringInfoNamespace
using StringInfo = StringInfoNamespace::StringInfo;
} // namespace System::Private::CoreLib::System::Globalization