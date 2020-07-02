#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IBindableIteratorNamespace {
CLASS(IBindableIterator) {
  public: Object get_Current();
  public: Boolean get_HasCurrent();
  public: Boolean MoveNext();
};
} // namespace IBindableIteratorNamespace
using IBindableIterator = IBindableIteratorNamespace::IBindableIterator;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
