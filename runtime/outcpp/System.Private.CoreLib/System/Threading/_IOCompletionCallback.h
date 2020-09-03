#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
namespace _IOCompletionCallbackNamespace {
CLASS(_IOCompletionCallback) : public object {
  public: void ctor(IOCompletionCallback ioCompletionCallback, ExecutionContext executionContext);
  public: static void IOCompletionCallback_Context(Object state);
  public: static void PerformIOCompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pNativeOverlapped);
  private: static void cctor();
  private: IOCompletionCallback _ioCompletionCallback;
  private: ExecutionContext _executionContext;
  private: UInt32 _errorCode;
  private: UInt32 _numBytes;
  private: NativeOverlapped* _pNativeOverlapped;
  public: static ContextCallback _ccb;
};
} // namespace _IOCompletionCallbackNamespace
using _IOCompletionCallback = _IOCompletionCallbackNamespace::_IOCompletionCallback;
} // namespace System::Private::CoreLib::System::Threading
