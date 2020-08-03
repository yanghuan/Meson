#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
namespace SZGenericArrayEnumeratorNamespace {
CLASS(SZGenericArrayEnumerator, T) : public Object::in {
  public: T get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: void Ctor(Array<T> array);
  public: Boolean MoveNext();
  public: void Dispose();
  private: static void SCtor();
  private: Array<T> _array;
  private: Int32 _index;
  public: static SZGenericArrayEnumerator<T> Empty;
};
} // namespace SZGenericArrayEnumeratorNamespace
template <class T>
using SZGenericArrayEnumerator = SZGenericArrayEnumeratorNamespace::SZGenericArrayEnumerator<T>;
} // namespace System::Private::CoreLib::System
