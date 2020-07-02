#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MemberInfo)
namespace MemberFilterNamespace {
CLASS(MemberFilter) {
  public: Boolean Invoke(MemberInfo m, Object filterCriteria);
  public: IAsyncResult BeginInvoke(MemberInfo m, Object filterCriteria, AsyncCallback callback, Object object);
  public: Boolean EndInvoke(IAsyncResult result);
};
} // namespace MemberFilterNamespace
using MemberFilter = MemberFilterNamespace::MemberFilter;
} // namespace System::Private::CoreLib::System::Reflection
