#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncValueTaskMethodBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct AsyncValueTaskMethodBuilder {
};
template <>
struct AsyncValueTaskMethodBuilder<> {
  public: ValueTask<> get_Task();
  private: AsyncTaskMethodBuilder<> _methodBuilder;
  private: Boolean _haveResult;
  private: Boolean _useBuilder;
};
template <class TResult>
struct AsyncValueTaskMethodBuilder<TResult> {
  public: ValueTask<TResult> get_Task();
  private: AsyncTaskMethodBuilder<TResult> _methodBuilder;
  private: TResult _result;
  private: Boolean _haveResult;
  private: Boolean _useBuilder;
};
} // namespace AsyncValueTaskMethodBuilderNamespace
template <class T1 = void, class T2 = void>
using AsyncValueTaskMethodBuilder = AsyncValueTaskMethodBuilderNamespace::AsyncValueTaskMethodBuilder<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
