#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
namespace CharEnumeratorNamespace {
CLASS(CharEnumerator) {
  private: Object get_CurrentOfIEnumerator();
  public: Char get_Current();
  public: void Ctor(String str);
  public: Object Clone();
  public: Boolean MoveNext();
  public: void Dispose();
  public: void Reset();
  private: String _str;
  private: Int32 _index;
  private: Char _currentElement;
};
} // namespace CharEnumeratorNamespace
using CharEnumerator = CharEnumeratorNamespace::CharEnumerator;
} // namespace System::Private::CoreLib::System
