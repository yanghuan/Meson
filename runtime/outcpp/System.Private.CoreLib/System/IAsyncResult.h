#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace IAsyncResultNamespace {
using namespace System::Threading;
CLASS(IAsyncResult) : public Object::in {
  public: Boolean get_IsCompleted();
  public: WaitHandle get_AsyncWaitHandle();
  public: Object get_AsyncState();
  public: Boolean get_CompletedSynchronously();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncResultNamespace
using IAsyncResult = IAsyncResultNamespace::IAsyncResult;
} // namespace System::Private::CoreLib::System
