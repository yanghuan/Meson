#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitCallback)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
namespace UnwrapPromiseNamespace {
CLASS(UnwrapPromise, TResult) : public Task<TResult>::in {
  public: using interface = rt::TypeList<ITaskCompletionAction>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _InvokeCoreAsync_b__8_0(Object state);
    public: static __c __9;
    public: static WaitCallback __9__8_0;
  };
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: void ctor(Task<> outerTask, Boolean lookForOce);
  public: void Invoke(Task<> completingTask);
  private: void InvokeCore(Task<> completingTask);
  private: void InvokeCoreAsync(Task<> completingTask);
  private: void ProcessCompletedOuterTask(Task<> task);
  private: Boolean TrySetFromTask(Task<> task, Boolean lookForOce);
  private: void ProcessInnerTask(Task<> task);
  private: Byte _state;
  private: Boolean _lookForOce;
};
} // namespace UnwrapPromiseNamespace
template <class TResult>
using UnwrapPromise = UnwrapPromiseNamespace::UnwrapPromise<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
