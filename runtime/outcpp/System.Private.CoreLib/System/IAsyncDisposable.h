#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
namespace IAsyncDisposableNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(IAsyncDisposable) {
  public: ValueTask<> DisposeAsync();
};
} // namespace IAsyncDisposableNamespace
using IAsyncDisposable = IAsyncDisposableNamespace::IAsyncDisposable;
} // namespace System::Private::CoreLib::System
