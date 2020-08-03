#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MemberInfo)
namespace MemberFilterNamespace {
CLASS(MemberFilter) : public MulticastDelegate::in {
  public: void Ctor(Object object, IntPtr method);
  public: Boolean Invoke(MemberInfo m, Object filterCriteria);
  public: IAsyncResult BeginInvoke(MemberInfo m, Object filterCriteria, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
};
} // namespace MemberFilterNamespace
using MemberFilter = MemberFilterNamespace::MemberFilter;
} // namespace System::Private::CoreLib::System::Reflection
