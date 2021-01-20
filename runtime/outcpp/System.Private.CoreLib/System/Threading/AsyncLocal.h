#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(AsyncLocalValueChangedArgs, T)
FORWARD(IAsyncLocal)
namespace AsyncLocalNamespace {
CLASS(AsyncLocal, T) : public object {
  public: using interface = rt::TypeList<IAsyncLocal>;
  public: T get_Value();
  public: void set_Value(T value);
  public: void ctor();
  public: void ctor(Action<AsyncLocalValueChangedArgs<T>> valueChangedHandler);
  private: void OnValueChangedOfIAsyncLocal(Object previousValueObj, Object currentValueObj, Boolean contextChanged);
  private: Action<AsyncLocalValueChangedArgs<T>> m_valueChangedHandler;
};
} // namespace AsyncLocalNamespace
template <class T>
using AsyncLocal = AsyncLocalNamespace::AsyncLocal<T>;
} // namespace System::Private::CoreLib::System::Threading
