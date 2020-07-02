#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableIterator)
namespace BindableIterableToEnumerableAdapterNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(BindableIterableToEnumerableAdapter) {
  private: CLASS(NonGenericToGenericIterator) {
    public: Object get_Current();
    public: Boolean get_HasCurrent();
    public: Boolean MoveNext();
    public: Int32 GetMany(Array<Object> items);
    private: IBindableIterator iterator;
  };
  public: IEnumerator GetEnumerator_Stub();
};
} // namespace BindableIterableToEnumerableAdapterNamespace
using BindableIterableToEnumerableAdapter = BindableIterableToEnumerableAdapterNamespace::BindableIterableToEnumerableAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
