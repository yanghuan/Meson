#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace GenericDelegateCacheNamespace {
template <class TAntecedentResult, class TResult>
class GenericDelegateCache {
  private: static void ctor_static();
  public: static Func<Task<Task<>>, Object, TResult> CWAnyFuncDelegate;
  public: static Func<Task<Task<>>, Object, TResult> CWAnyActionDelegate;
  public: static Func<Task<Array<Task<TAntecedentResult>>>, Object, TResult> CWAllFuncDelegate;
  public: static Func<Task<Array<Task<TAntecedentResult>>>, Object, TResult> CWAllActionDelegate;
};
} // namespace GenericDelegateCacheNamespace
template <class TAntecedentResult, class TResult>
using GenericDelegateCache = GenericDelegateCacheNamespace::GenericDelegateCache<TAntecedentResult, TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
