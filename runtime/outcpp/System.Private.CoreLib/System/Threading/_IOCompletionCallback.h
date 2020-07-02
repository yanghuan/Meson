#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(NativeOverlapped)
FORWARD(IOCompletionCallback)
FORWARD(ExecutionContext)
FORWARD_(ContextCallback, T1, T2)
namespace _IOCompletionCallbackNamespace {
CLASS(_IOCompletionCallback) {
  public: static void IOCompletionCallback_Context(Object state);
  public: static void PerformIOCompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pNativeOverlapped);
  private: IOCompletionCallback _ioCompletionCallback;
  private: ExecutionContext _executionContext;
  private: UInt32 _errorCode;
  private: UInt32 _numBytes;
  private: NativeOverlapped* _pNativeOverlapped;
  public: static ContextCallback<> _ccb;
};
} // namespace _IOCompletionCallbackNamespace
using _IOCompletionCallback = _IOCompletionCallbackNamespace::_IOCompletionCallback;
} // namespace System::Private::CoreLib::System::Threading
