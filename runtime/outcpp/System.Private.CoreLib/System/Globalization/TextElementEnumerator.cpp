#include "TextElementEnumerator-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/TextSegmentationUtility-dep.h>

namespace System::Private::CoreLib::System::Globalization::TextElementEnumeratorNamespace {
using namespace System::Text::Unicode;

Object TextElementEnumerator___::get_Current() {
  return GetTextElement();
}

Int32 TextElementEnumerator___::get_ElementIndex() {
  if (_currentTextElementOffset >= _str->get_Length()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return _currentTextElementOffset - _strStartIndex;
}

void TextElementEnumerator___::ctor(String str, Int32 startIndex) {
  _str = str;
  _strStartIndex = startIndex;
  Reset();
}

Boolean TextElementEnumerator___::MoveNext() {
  _currentTextElementSubstr = nullptr;
  Int32 num = _currentTextElementOffset += _currentTextElementLength;
  _currentTextElementLength = 0;
  if (num >= _str->get_Length()) {
    return false;
  }
  _currentTextElementLength = TextSegmentationUtility::GetLengthOfFirstUtf16ExtendedGraphemeCluster(MemoryExtensions::AsSpan(_str, num));
  return true;
}

String TextElementEnumerator___::GetTextElement() {
  String text = _currentTextElementSubstr;
  if (text == nullptr) {
    if (_currentTextElementOffset >= _str->get_Length()) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
    }
    text = (_currentTextElementSubstr = _str->Substring(_currentTextElementOffset, _currentTextElementLength));
  }
  return text;
}

void TextElementEnumerator___::Reset() {
  _currentTextElementOffset = _str->get_Length();
  _currentTextElementLength = _strStartIndex - _str->get_Length();
  _currentTextElementSubstr = nullptr;
}

} // namespace System::Private::CoreLib::System::Globalization::TextElementEnumeratorNamespace
