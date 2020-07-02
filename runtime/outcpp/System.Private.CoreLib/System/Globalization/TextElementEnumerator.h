#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class UnicodeCategory;
namespace TextElementEnumeratorNamespace {
CLASS(TextElementEnumerator) {
  public: Object get_Current();
  public: Int32 get_ElementIndex();
  public: Boolean MoveNext();
  public: String GetTextElement();
  public: void Reset();
  private: String _str;
  private: Int32 _index;
  private: Int32 _startIndex;
  private: Int32 _strLen;
  private: Int32 _currTextElementLen;
  private: UnicodeCategory _uc;
  private: Int32 _charLen;
};
} // namespace TextElementEnumeratorNamespace
using TextElementEnumerator = TextElementEnumeratorNamespace::TextElementEnumerator;
} // namespace System::Private::CoreLib::System::Globalization
