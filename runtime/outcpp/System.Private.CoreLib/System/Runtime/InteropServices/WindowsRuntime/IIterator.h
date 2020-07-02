#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IIteratorNamespace {
CLASS(IIterator, T) {
  public: T get_Current();
  public: Boolean get_HasCurrent();
  public: Boolean MoveNext();
  public: Int32 GetMany(Array<T> items);
};
} // namespace IIteratorNamespace
template <class T>
using IIterator = IIteratorNamespace::IIterator<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
