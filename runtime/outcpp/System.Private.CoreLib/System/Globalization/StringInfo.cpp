#include "StringInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/StringInfo-dep.h>
#include <System.Private.CoreLib/System/Index-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/TextSegmentationUtility-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::StringInfoNamespace {
using namespace System::Collections::Generic;
using namespace System::Text::Unicode;

Array<Int32> StringInfo___::get_Indexes() {
  if (_indexes == nullptr && get_String()->get_Length() > 0) {
    _indexes = ParseCombiningCharacters(get_String());
  }
  return _indexes;
}

String StringInfo___::get_String() {
  return _str;
}

void StringInfo___::set_String(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  _str = value;
  _indexes = nullptr;
}

Int32 StringInfo___::get_LengthInTextElements() {
  Array<Int32> indexes = get_Indexes();
  if (indexes == nullptr) {
    return 0;
  }
  return indexes->get_Length();
}

void StringInfo___::ctor() {
}

void StringInfo___::ctor(String value) {
  get_String(value);
}

Boolean StringInfo___::Equals(Object value) {
  StringInfo stringInfo = rt::as<StringInfo>(value);
  if (stringInfo != nullptr) {
    return _str->Equals(stringInfo->_str);
  }
  return false;
}

Int32 StringInfo___::GetHashCode() {
  return _str->GetHashCode();
}

String StringInfo___::SubstringByTextElements(Int32 startingTextElement) {
  Array<Int32> indexes = get_Indexes();
  return SubstringByTextElements(startingTextElement, ((indexes != nullptr) ? indexes->get_Length() : 0) - startingTextElement);
}

String StringInfo___::SubstringByTextElements(Int32 startingTextElement, Int32 lengthInTextElements) {
  auto& default = get_Indexes();
  Array<Int32> array = default != nullptr ? default : Array<>::in::Empty<Int32>();
  if ((UInt32)startingTextElement >= (UInt32)array->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("startingTextElement", startingTextElement, SR::get_Arg_ArgumentOutOfRangeException());
  }
  if ((UInt32)lengthInTextElements > (UInt32)(array->get_Length() - startingTextElement)) {
    rt::throw_exception<ArgumentOutOfRangeException>("lengthInTextElements", lengthInTextElements, SR::get_Arg_ArgumentOutOfRangeException());
  }
  Int32 value = array[startingTextElement];
}

String StringInfo___::GetNextTextElement(String str) {
  return GetNextTextElement(str, 0);
}

String StringInfo___::GetNextTextElement(String str, Int32 index) {
  if (str == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::str);
  }
  if ((UInt32)index > (UInt32)str->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRange_IndexException();
  }
  return str->Substring(index, TextSegmentationUtility::GetLengthOfFirstUtf16ExtendedGraphemeCluster(MemoryExtensions::AsSpan(str, index)));
}

TextElementEnumerator StringInfo___::GetTextElementEnumerator(String str) {
  return GetTextElementEnumerator(str, 0);
}

TextElementEnumerator StringInfo___::GetTextElementEnumerator(String str, Int32 index) {
  if (str == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::str);
  }
  if ((UInt32)index > (UInt32)str->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRange_IndexException();
  }
  return rt::newobj<TextElementEnumerator>(str, index);
}

Array<Int32> StringInfo___::ParseCombiningCharacters(String str) {
  if (str == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::str);
  }
  if (str->get_Length() > 256) {
    return ParseCombiningCharactersForLargeString(str);
  }
  Int32 default[str->get_Length()] = {};
  Span<Int32> span = default;
  Int32 length = 0;
  ReadOnlySpan<Char> input = str;
  while (!input.get_IsEmpty()) {
    span[length++] = str->get_Length() - input.get_Length();
    input = input.Slice(TextSegmentationUtility::GetLengthOfFirstUtf16ExtendedGraphemeCluster(input));
  }
  return span.Slice(0, length).ToArray();
}

Array<Int32> StringInfo___::ParseCombiningCharactersForLargeString(String str) {
  List<Int32> list = rt::newobj<List<Int32>>();
  ReadOnlySpan<Char> input = str;
  while (!input.get_IsEmpty()) {
    list->Add(str->get_Length() - input.get_Length());
    input = input.Slice(TextSegmentationUtility::GetLengthOfFirstUtf16ExtendedGraphemeCluster(input));
  }
  return list->ToArray();
}

} // namespace System::Private::CoreLib::System::Globalization::StringInfoNamespace
