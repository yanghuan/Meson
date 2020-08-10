#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(ICloneable)
FORWARD(IDisposable)
FORWARD(String)
namespace CharEnumeratorNamespace {
using namespace Collections;
using namespace Collections::Generic;
using Collections::Generic::IEnumerator;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator1 = Collections::IEnumerator;
CLASS(CharEnumerator) : public Object::in {
  public: using interface = rt::TypeList<IEnumerator1, IEnumerator<Char>, IDisposable, ICloneable>;
  private: Object get_CurrentOfIEnumerator();
  public: Char get_Current();
  public: void ctor(String str);
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
