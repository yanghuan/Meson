#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
namespace IAsyncResultNamespace {
using namespace Threading;
CLASS(IAsyncResult) {
  public: Boolean get_IsCompleted();
  public: WaitHandle get_AsyncWaitHandle();
  public: Object get_AsyncState();
  public: Boolean get_CompletedSynchronously();
};
} // namespace IAsyncResultNamespace
using IAsyncResult = IAsyncResultNamespace::IAsyncResult;
} // namespace System::Private::CoreLib::System
