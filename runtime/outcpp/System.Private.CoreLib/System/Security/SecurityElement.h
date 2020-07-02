#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ArrayList)
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Security {
namespace SecurityElementNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(SecurityElement) {
  public: String get_Tag();
  public: void set_Tag(String value);
  public: Hashtable get_Attributes();
  public: void set_Attributes(Hashtable value);
  public: String get_Text();
  public: void set_Text(String value);
  public: ArrayList get_Children();
  public: void set_Children(ArrayList value);
  public: void ConvertSecurityElementFactories();
  public: void AddAttributeSafe(String name, String value);
  public: void AddAttribute(String name, String value);
  public: void AddChild(SecurityElement child);
  public: Boolean Equal(SecurityElement other);
  public: SecurityElement Copy();
  public: static Boolean IsValidTag(String tag);
  public: static Boolean IsValidText(String text);
  public: static Boolean IsValidAttributeName(String name);
  public: static Boolean IsValidAttributeValue(String value);
  private: static String GetEscapeSequence(Char c);
  public: static String Escape(String str);
  private: static String GetUnescapeSequence(String str, Int32 index, Int32& newIndex);
  private: static String Unescape(String str);
  public: String ToString();
  private: void ToString(String indent, Object obj, Action<Object, String> write);
  public: String Attribute(String name);
  public: SecurityElement SearchForChildByTag(String tag);
  public: String SearchForTextOfTag(String tag);
  public: static SecurityElement FromString(String xml);
  public: String _tag;
  public: String _text;
  private: ArrayList _children;
  public: ArrayList _attributes;
  private: static Array<Char> s_tagIllegalCharacters;
  private: static Array<Char> s_textIllegalCharacters;
  private: static Array<Char> s_valueIllegalCharacters;
  private: static Array<Char> s_escapeChars;
  private: static Array<String> s_escapeStringPairs;
};
} // namespace SecurityElementNamespace
using SecurityElement = SecurityElementNamespace::SecurityElement;
} // namespace System::Private::CoreLib::System::Security
