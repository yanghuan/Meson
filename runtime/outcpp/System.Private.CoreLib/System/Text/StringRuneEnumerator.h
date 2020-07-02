#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/Rune.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace StringRuneEnumeratorNamespace {
struct StringRuneEnumerator {
  public: Rune get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: StringRuneEnumerator GetEnumerator();
  public: Boolean MoveNext();
  private: String _string;
  private: Rune _current;
  private: Int32 _nextIndex;
};
} // namespace StringRuneEnumeratorNamespace
using StringRuneEnumerator = StringRuneEnumeratorNamespace::StringRuneEnumerator;
} // namespace System::Private::CoreLib::System::Text
