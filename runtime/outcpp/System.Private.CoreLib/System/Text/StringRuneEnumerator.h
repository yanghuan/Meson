#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/Rune.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace StringRuneEnumeratorNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
struct StringRuneEnumerator : public valueType<StringRuneEnumerator> {
  public: using interface = rt::TypeList<IEnumerable<Rune>, IEnumerable_, IEnumerator<Rune>, IDisposable, IEnumerator_>;
  public: Rune get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: explicit StringRuneEnumerator(String value);
  public: StringRuneEnumerator GetEnumerator();
  public: Boolean MoveNext();
  public: explicit StringRuneEnumerator() {}
  private: String _string;
  private: Rune _current;
  private: Int32 _nextIndex;
};
} // namespace StringRuneEnumeratorNamespace
using StringRuneEnumerator = StringRuneEnumeratorNamespace::StringRuneEnumerator;
} // namespace System::Private::CoreLib::System::Text
