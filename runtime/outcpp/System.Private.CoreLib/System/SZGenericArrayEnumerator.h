#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
namespace SZGenericArrayEnumeratorNamespace {
CLASS(SZGenericArrayEnumerator, T) {
  public: T get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: Boolean MoveNext();
  public: void Dispose();
  private: Array<T> _array;
  private: Int32 _index;
  public: static SZGenericArrayEnumerator<T> Empty;
};
} // namespace SZGenericArrayEnumeratorNamespace
template <class T>
using SZGenericArrayEnumerator = SZGenericArrayEnumeratorNamespace::SZGenericArrayEnumerator<T>;
} // namespace System::Private::CoreLib::System
