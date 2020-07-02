#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IIterator, T)
namespace IteratorToEnumeratorAdapterNamespace {
CLASS(IteratorToEnumeratorAdapter, T) {
  public: T get_Current();
  private: Object get_CurrentOfIEnumerator();
  public: Boolean MoveNext();
  public: void Reset();
  public: void Dispose();
  private: IIterator<T> m_iterator;
  private: Boolean m_hadCurrent;
  private: T m_current;
  private: Boolean m_isInitialized;
};
} // namespace IteratorToEnumeratorAdapterNamespace
template <class T>
using IteratorToEnumeratorAdapter = IteratorToEnumeratorAdapterNamespace::IteratorToEnumeratorAdapter<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
