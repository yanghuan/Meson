#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace TextElementEnumeratorNamespace {
using namespace Collections;
CLASS(TextElementEnumerator) : public Object::in {
  public: using interface = rt::TypeList<IEnumerator>;
  public: Object get_Current();
  public: Int32 get_ElementIndex();
  public: void Ctor(String str, Int32 startIndex);
  public: Boolean MoveNext();
  public: String GetTextElement();
  public: void Reset();
  private: String _str;
  private: Int32 _strStartIndex;
  private: Int32 _currentTextElementOffset;
  private: Int32 _currentTextElementLength;
  private: String _currentTextElementSubstr;
};
} // namespace TextElementEnumeratorNamespace
using TextElementEnumerator = TextElementEnumeratorNamespace::TextElementEnumerator;
} // namespace System::Private::CoreLib::System::Globalization
