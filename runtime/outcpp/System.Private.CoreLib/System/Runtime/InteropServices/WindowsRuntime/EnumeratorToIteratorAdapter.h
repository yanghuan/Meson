#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace EnumeratorToIteratorAdapterNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(EnumeratorToIteratorAdapter, T) {
  public: T get_Current();
  private: Object get_CurrentOfIBindableIterator();
  public: Boolean get_HasCurrent();
  public: Boolean MoveNext();
  public: Int32 GetMany(Array<T> items);
  private: IEnumerator<T> m_enumerator;
  private: Boolean m_firstItem;
  private: Boolean m_hasCurrent;
};
} // namespace EnumeratorToIteratorAdapterNamespace
template <class T>
using EnumeratorToIteratorAdapter = EnumeratorToIteratorAdapterNamespace::EnumeratorToIteratorAdapter<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
