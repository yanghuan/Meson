#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace TypeFilterNamespace {
CLASS(TypeFilter) {
  public: Boolean Invoke(Type m, Object filterCriteria);
  public: IAsyncResult BeginInvoke(Type m, Object filterCriteria, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
};
} // namespace TypeFilterNamespace
using TypeFilter = TypeFilterNamespace::TypeFilter;
} // namespace System::Private::CoreLib::System::Reflection
