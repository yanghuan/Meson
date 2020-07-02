#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ParameterizedThreadStartNamespace {
CLASS(ParameterizedThreadStart) {
  public: void Invoke(Object obj);
  public: IAsyncResult BeginInvoke(Object obj, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace ParameterizedThreadStartNamespace
using ParameterizedThreadStart = ParameterizedThreadStartNamespace::ParameterizedThreadStart;
} // namespace System::Private::CoreLib::System::Threading
