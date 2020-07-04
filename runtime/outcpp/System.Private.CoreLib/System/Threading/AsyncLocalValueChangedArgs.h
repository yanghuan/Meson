#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Threading {
namespace AsyncLocalValueChangedArgsNamespace {
template <class T>
struct AsyncLocalValueChangedArgs {
  public: T get_PreviousValue() { return PreviousValue; }
  public: T get_CurrentValue() { return CurrentValue; }
  public: Boolean get_ThreadContextChanged() { return ThreadContextChanged; }
  private: T PreviousValue;
  private: T CurrentValue;
  private: Boolean ThreadContextChanged;
};
} // namespace AsyncLocalValueChangedArgsNamespace
template <class T>
using AsyncLocalValueChangedArgs = AsyncLocalValueChangedArgsNamespace::AsyncLocalValueChangedArgs<T>;
} // namespace System::Private::CoreLib::System::Threading
