#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace TypeFilterNamespace {
CLASS(TypeFilter) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: Boolean Invoke(Type m, Object filterCriteria);
  public: IAsyncResult BeginInvoke(Type m, Object filterCriteria, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace TypeFilterNamespace
using TypeFilter = TypeFilterNamespace::TypeFilter;
} // namespace System::Private::CoreLib::System::Reflection
