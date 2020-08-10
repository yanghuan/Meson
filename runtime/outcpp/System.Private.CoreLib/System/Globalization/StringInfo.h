#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(TextElementEnumerator)
namespace StringInfoNamespace {
CLASS(StringInfo) : public Object::in {
  private: Array<Int32> get_Indexes();
  public: String get_String();
  public: void set_String(String value);
  public: Int32 get_LengthInTextElements();
  public: void ctor();
  public: void ctor(String value);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: String SubstringByTextElements(Int32 startingTextElement);
  public: String SubstringByTextElements(Int32 startingTextElement, Int32 lengthInTextElements);
  public: static String GetNextTextElement(String str);
  public: static String GetNextTextElement(String str, Int32 index);
  public: static TextElementEnumerator GetTextElementEnumerator(String str);
  public: static TextElementEnumerator GetTextElementEnumerator(String str, Int32 index);
  public: static Array<Int32> ParseCombiningCharacters(String str);
  private: static Array<Int32> ParseCombiningCharactersForLargeString(String str);
  private: String _str;
  private: Array<Int32> _indexes;
};
} // namespace StringInfoNamespace
using StringInfo = StringInfoNamespace::StringInfo;
} // namespace System::Private::CoreLib::System::Globalization
