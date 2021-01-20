#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD_(Func)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
namespace GenericDelegateCacheNamespace {
template <class TAntecedentResult, class TResult>
class GenericDelegateCache {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: TResult _cctor_b__4_0(Task<Task<>> wrappedWinner, Object state);
    public: TResult _cctor_b__4_1(Task<Task<>> wrappedWinner, Object state);
    public: TResult _cctor_b__4_2(Task<Array<Task<TAntecedentResult>>> wrappedAntecedents, Object state);
    public: TResult _cctor_b__4_3(Task<Array<Task<TAntecedentResult>>> wrappedAntecedents, Object state);
    public: static __c __9;
  };
  public: static void cctor();
  public: static Func<Task<Task<>>, Object, TResult> CWAnyFuncDelegate;
  public: static Func<Task<Task<>>, Object, TResult> CWAnyActionDelegate;
  public: static Func<Task<Array<Task<TAntecedentResult>>>, Object, TResult> CWAllFuncDelegate;
  public: static Func<Task<Array<Task<TAntecedentResult>>>, Object, TResult> CWAllActionDelegate;
};
} // namespace GenericDelegateCacheNamespace
template <class TAntecedentResult, class TResult>
using GenericDelegateCache = GenericDelegateCacheNamespace::GenericDelegateCache<TAntecedentResult, TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
