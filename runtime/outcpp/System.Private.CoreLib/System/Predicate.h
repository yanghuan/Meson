#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace PredicateNamespace {
CLASS(Predicate, T) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: Boolean Invoke(T obj);
  public: IAsyncResult BeginInvoke(T obj, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace PredicateNamespace
template <class T>
using Predicate = PredicateNamespace::Predicate<T>;
} // namespace System::Private::CoreLib::System
