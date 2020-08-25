#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
namespace SZGenericArrayEnumeratorNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(SZGenericArrayEnumerator, T) : public object {
  public: using interface = rt::TypeList<IEnumerator<T>, IDisposable, IEnumerator_>;
  public: T get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: void ctor(Array<T> array);
  public: Boolean MoveNext();
  public: void Dispose();
  private: static void cctor();
  private: Array<T> _array;
  private: Int32 _index;
  public: static SZGenericArrayEnumerator<T> Empty;
};
} // namespace SZGenericArrayEnumeratorNamespace
template <class T>
using SZGenericArrayEnumerator = SZGenericArrayEnumeratorNamespace::SZGenericArrayEnumerator<T>;
} // namespace System::Private::CoreLib::System
