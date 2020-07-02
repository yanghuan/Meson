#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace UnwrapPromiseNamespace {
CLASS(UnwrapPromise, TResult) {
  public: Boolean get_InvokeMayRunArbitraryCode();
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
