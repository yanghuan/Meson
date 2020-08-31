#include "SecurityElement-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/ArrayList-dep.h>
#include <System.Private.CoreLib/System/Collections/IDictionaryEnumerator.h>
#include <System.Private.CoreLib/System/Collections/IEnumerator.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Security/SecurityElement-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Security::SecurityElementNamespace {
using namespace System::Collections;
using namespace System::Text;

String SecurityElement___::get_Tag() {
  return _tag;
}

void SecurityElement___::set_Tag(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("Tag");
  }
  if (!IsValidTag(value)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementTag(), value));
  }
  _tag = value;
}

Hashtable SecurityElement___::get_Attributes() {
  if (_attributes == nullptr || _attributes->get_Count() == 0) {
    return nullptr;
  }
  Hashtable hashtable = rt::newobj<Hashtable>(_attributes->get_Count() / 2);
  Int32 count = _attributes->get_Count();
  for (Int32 i = 0; i < count; i += 2) {
    hashtable->Add(_attributes[i], _attributes[i + 1]);
  }
  return hashtable;
}

void SecurityElement___::set_Attributes(Hashtable value) {
  if (value == nullptr || value->get_Count() == 0) {
    _attributes = nullptr;
    return;
  }
  ArrayList arrayList = rt::newobj<ArrayList>(value->get_Count());
  IDictionaryEnumerator enumerator = value->GetEnumerator();
  while (enumerator->MoveNext()) {
    String text = (String)enumerator->get_Key();
    String text2 = (String)enumerator->get_Value();
    if (!IsValidAttributeName(text)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementName(), text));
    }
    if (!IsValidAttributeValue(text2)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementValue(), text2));
    }
    arrayList->Add(text);
    arrayList->Add(text2);
  }
  _attributes = arrayList;
}

String SecurityElement___::get_Text() {
  return Unescape(_text);
}

void SecurityElement___::set_Text(String value) {
  if (value == nullptr) {
    _text = nullptr;
    return;
  }
  if (!IsValidText(value)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementTag(), value));
  }
  _text = value;
}

ArrayList SecurityElement___::get_Children() {
  return _children;
}

void SecurityElement___::set_Children(ArrayList value) {
  if (value != nullptr && value->Contains(nullptr)) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentNull_Child());
  }
  _children = value;
}

void SecurityElement___::ctor(String tag) {
  if (tag == nullptr) {
    rt::throw_exception<ArgumentNullException>("tag");
  }
  if (!IsValidTag(tag)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementTag(), tag));
  }
  _tag = tag;
}

void SecurityElement___::ctor(String tag, String text) {
  if (tag == nullptr) {
    rt::throw_exception<ArgumentNullException>("tag");
  }
  if (!IsValidTag(tag)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementTag(), tag));
  }
  if (text != nullptr && !IsValidText(text)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementText(), text));
  }
  _tag = tag;
  _text = text;
}

void SecurityElement___::AddAttributeSafe(String name, String value) {
  if (_attributes == nullptr) {
    _attributes = rt::newobj<ArrayList>(8);
  } else {
    Int32 count = _attributes->get_Count();
    for (Int32 i = 0; i < count; i += 2) {
      String a = (String)_attributes[i];
      if (String::in::Equals(a, name)) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_AttributeNamesMustBeUnique());
      }
    }
  }
  _attributes->Add(name);
  _attributes->Add(value);
}

void SecurityElement___::AddAttribute(String name, String value) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (!IsValidAttributeName(name)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementName(), name));
  }
  if (!IsValidAttributeValue(value)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidElementValue(), value));
  }
  AddAttributeSafe(name, value);
}

void SecurityElement___::AddChild(SecurityElement child) {
  if (child == nullptr) {
    rt::throw_exception<ArgumentNullException>("child");
  }
  if (_children == nullptr) {
    _children = rt::newobj<ArrayList>(1);
  }
  _children->Add(child);
}

Boolean SecurityElement___::Equal(SecurityElement other) {
  if (other == nullptr) {
    return false;
  }
  if (!String::in::Equals(_tag, other->_tag)) {
    return false;
  }
  if (!String::in::Equals(_text, other->_text)) {
    return false;
  }
  if (_attributes == nullptr || other->_attributes == nullptr) {
    if (_attributes != other->_attributes) {
      return false;
    }
  } else {
    Int32 count = _attributes->get_Count();
    if (count != other->_attributes->get_Count()) {
      return false;
    }
    for (Int32 i = 0; i < count; i++) {
      String a = (String)_attributes[i];
      String b = (String)other->_attributes[i];
      if (!String::in::Equals(a, b)) {
        return false;
      }
    }
  }
  if (_children == nullptr || other->_children == nullptr) {
    if (_children != other->_children) {
      return false;
    }
  } else {
    if (_children->get_Count() != other->_children->get_Count()) {
      return false;
    }
    IEnumerator enumerator = _children->GetEnumerator();
    IEnumerator enumerator2 = other->_children->GetEnumerator();
    while (enumerator->MoveNext()) {
      enumerator2->MoveNext();
      SecurityElement securityElement = (SecurityElement)enumerator->get_Current();
      SecurityElement other2 = (SecurityElement)enumerator2->get_Current();
      if (securityElement == nullptr || !securityElement->Equal(other2)) {
        return false;
      }
    }
  }
  return true;
}

SecurityElement SecurityElement___::Copy() {
  SecurityElement securityElement = rt::newobj<SecurityElement>(_tag, _text);
  securityElement->_children = ((_children == nullptr) ? nullptr : rt::newobj<ArrayList>(_children));
  securityElement->_attributes = ((_attributes == nullptr) ? nullptr : rt::newobj<ArrayList>(_attributes));
  return securityElement;
}

Boolean SecurityElement___::IsValidTag(String tag) {
  if (tag == nullptr) {
    return false;
  }
  return tag->IndexOfAny(s_tagIllegalCharacters) == -1;
}

Boolean SecurityElement___::IsValidText(String text) {
  if (text == nullptr) {
    return false;
  }
  return text->IndexOfAny(s_textIllegalCharacters) == -1;
}

Boolean SecurityElement___::IsValidAttributeName(String name) {
  return IsValidTag(name);
}

Boolean SecurityElement___::IsValidAttributeValue(String value) {
  if (value == nullptr) {
    return false;
  }
  return value->IndexOfAny(s_valueIllegalCharacters) == -1;
}

String SecurityElement___::GetEscapeSequence(Char c) {
  Int32 num = s_escapeStringPairs->get_Length();
  for (Int32 i = 0; i < num; i += 2) {
    String text = s_escapeStringPairs[i];
    String result = s_escapeStringPairs[i + 1];
    if (text[0] == c) {
      return result;
    }
  }
  return c.ToString();
}

String SecurityElement___::Escape(String str) {
  if (str == nullptr) {
    return nullptr;
  }
  StringBuilder stringBuilder = nullptr;
  Int32 length = str->get_Length();
  Int32 num = 0;
  while (true) {
    Int32 num2 = str->IndexOfAny(s_escapeChars, num);
    if (num2 == -1) {
      break;
    }
    if (stringBuilder == nullptr) {
      stringBuilder = rt::newobj<StringBuilder>();
    }
    stringBuilder->Append(str, num, num2 - num);
    stringBuilder->Append(GetEscapeSequence(str[num2]));
    num = num2 + 1;
  }
  if (stringBuilder == nullptr) {
    return str;
  }
  stringBuilder->Append(str, num, length - num);
  return stringBuilder->ToString();
}

String SecurityElement___::GetUnescapeSequence(String str, Int32 index, Int32& newIndex) {
  Int32 num = str->get_Length() - index;
  Int32 num2 = s_escapeStringPairs->get_Length();
  for (Int32 i = 0; i < num2; i += 2) {
    String result = s_escapeStringPairs[i];
    String text = s_escapeStringPairs[i + 1];
    Int32 length = text->get_Length();
    if (length <= num && String::in::Compare(text, 0, str, index, length, StringComparison::Ordinal) == 0) {
      newIndex = index + text->get_Length();
      return result;
    }
  }
  newIndex = index + 1;
  return str[index].ToString();
}

String SecurityElement___::Unescape(String str) {
  if (str == nullptr) {
    return nullptr;
  }
  StringBuilder stringBuilder = nullptr;
  Int32 length = str->get_Length();
  Int32 newIndex = 0;
  while (true) {
    Int32 num = str->IndexOf(38, newIndex);
    if (num == -1) {
      break;
    }
    if (stringBuilder == nullptr) {
      stringBuilder = rt::newobj<StringBuilder>();
    }
    stringBuilder->Append(str, newIndex, num - newIndex);
    stringBuilder->Append(GetUnescapeSequence(str, num, newIndex));
  }
  if (stringBuilder == nullptr) {
    return str;
  }
  stringBuilder->Append(str, newIndex, length - newIndex);
  return stringBuilder->ToString();
}

String SecurityElement___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
}

void SecurityElement___::ToString(Object obj, Action<Object, String> write) {
  write(obj, "<");
  write(obj, _tag);
  if (_attributes != nullptr && _attributes->get_Count() > 0) {
    write(obj, " ");
    Int32 count = _attributes->get_Count();
    for (Int32 i = 0; i < count; i += 2) {
      String arg = (String)_attributes[i];
      String arg2 = (String)_attributes[i + 1];
      write(obj, arg);
      write(obj, "=\"");
      write(obj, arg2);
      write(obj, "\"");
      if (i != _attributes->get_Count() - 2) {
        write(obj, "\r\n");
      }
    }
  }
  if (_text == nullptr && (_children == nullptr || _children->get_Count() == 0)) {
    write(obj, "/>");
    write(obj, "\r\n");
    return;
  }
  write(obj, ">");
  write(obj, _text);
  if (_children != nullptr) {
    write(obj, "\r\n");
    for (Int32 j = 0; j < _children->get_Count(); j++) {
      ((SecurityElement)_children[j])->ToString(obj, write);
    }
  }
  write(obj, "</");
  write(obj, _tag);
  write(obj, ">");
  write(obj, "\r\n");
}

String SecurityElement___::Attribute(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (_attributes == nullptr) {
    return nullptr;
  }
  Int32 count = _attributes->get_Count();
  for (Int32 i = 0; i < count; i += 2) {
    String a = (String)_attributes[i];
    if (String::in::Equals(a, name)) {
      String str = (String)_attributes[i + 1];
      return Unescape(str);
    }
  }
  return nullptr;
}

SecurityElement SecurityElement___::SearchForChildByTag(String tag) {
  if (tag == nullptr) {
    rt::throw_exception<ArgumentNullException>("tag");
  }
  if (_children == nullptr) {
    return nullptr;
  }
  for (SecurityElement& child : _children) {
    if (child != nullptr && String::in::Equals(child->get_Tag(), tag)) {
      return child;
    }
  }
  return nullptr;
}

String SecurityElement___::SearchForTextOfTag(String tag) {
  if (tag == nullptr) {
    rt::throw_exception<ArgumentNullException>("tag");
  }
  if (String::in::Equals(_tag, tag)) {
    return Unescape(_text);
  }
  if (_children == nullptr) {
    return nullptr;
  }
  for (SecurityElement& item : get_Children()) {
    String text = (item != nullptr) ? item->SearchForTextOfTag(tag) : nullptr;
    if (text != nullptr) {
      return text;
    }
  }
  return nullptr;
}

SecurityElement SecurityElement___::FromString(String xml) {
  if (xml == nullptr) {
    rt::throw_exception<ArgumentNullException>("xml");
  }
  return nullptr;
}

void SecurityElement___::cctor() {
  s_tagIllegalCharacters = rt::newarr<Array<Char>>(3);
  s_textIllegalCharacters = rt::newarr<Array<Char>>(2);
  s_valueIllegalCharacters = rt::newarr<Array<Char>>(3);
  s_escapeChars = rt::newarr<Array<Char>>(5);
  s_escapeStringPairs = rt::newarr<Array<String>>(10);
}

} // namespace System::Private::CoreLib::System::Security::SecurityElementNamespace
