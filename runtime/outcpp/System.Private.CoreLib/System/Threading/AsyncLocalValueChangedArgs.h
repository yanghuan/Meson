#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading {
namespace AsyncLocalValueChangedArgsNamespace {
template <class T>
struct AsyncLocalValueChangedArgs : public valueType<AsyncLocalValueChangedArgs<T>> {
  public: T get_PreviousValue() { return PreviousValue; }
  public: T get_CurrentValue() { return CurrentValue; }
  public: Boolean get_ThreadContextChanged() { return ThreadContextChanged; }
  public: explicit AsyncLocalValueChangedArgs(T previousValue, T currentValue, Boolean contextChanged);
  public: explicit AsyncLocalValueChangedArgs() {}
  private: T PreviousValue;
  private: T CurrentValue;
  private: Boolean ThreadContextChanged;
};
} // namespace AsyncLocalValueChangedArgsNamespace
template <class T>
using AsyncLocalValueChangedArgs = AsyncLocalValueChangedArgsNamespace::AsyncLocalValueChangedArgs<T>;
} // namespace System::Private::CoreLib::System::Threading
