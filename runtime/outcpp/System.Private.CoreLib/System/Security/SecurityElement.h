#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ArrayList)
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Security {
namespace SecurityElementNamespace {
using namespace System::Collections;
CLASS(SecurityElement) : public object {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _ToString_b__38_0(Object obj, String str);
    public: static __c __9;
    public: static Action<Object, String> __9__38_0;
  };
  public: String get_Tag();
  public: void set_Tag(String value);
  public: Hashtable get_Attributes();
  public: void set_Attributes(Hashtable value);
  public: String get_Text();
  public: void set_Text(String value);
  public: ArrayList get_Children();
  public: void set_Children(ArrayList value);
  public: void ctor(String tag);
  public: void ctor(String tag, String text);
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
  private: void ToString(Object obj, Action<Object, String> write);
  public: String Attribute(String name);
  public: SecurityElement SearchForChildByTag(String tag);
  public: String SearchForTextOfTag(String tag);
  public: static SecurityElement FromString(String xml);
  public: static void cctor();
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
