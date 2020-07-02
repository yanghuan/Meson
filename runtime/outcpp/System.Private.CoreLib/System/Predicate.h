#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
namespace PredicateNamespace {
CLASS(Predicate, T) {
  public: Boolean Invoke(T obj);
  public: IAsyncResult BeginInvoke(T obj, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
};
} // namespace PredicateNamespace
template <class T>
using Predicate = PredicateNamespace::Predicate<T>;
} // namespace System::Private::CoreLib::System
