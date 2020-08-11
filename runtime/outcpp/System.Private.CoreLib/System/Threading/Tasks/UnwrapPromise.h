#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
namespace UnwrapPromiseNamespace {
CLASS(UnwrapPromise, TResult) : public Task<TResult>::in {
  public: using interface = rt::TypeList<ITaskCompletionAction>;
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
