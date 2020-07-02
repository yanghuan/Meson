#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableIterator)
namespace EnumerableToBindableIterableAdapterNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(EnumerableToBindableIterableAdapter) {
  public: CLASS(NonGenericToGenericEnumerator) {
    public: Object get_Current();
    public: Boolean MoveNext();
    public: void Reset();
    public: void Dispose();
    private: IEnumerator enumerator;
  };
  public: IBindableIterator First_Stub();
};
} // namespace EnumerableToBindableIterableAdapterNamespace
using EnumerableToBindableIterableAdapter = EnumerableToBindableIterableAdapterNamespace::EnumerableToBindableIterableAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
