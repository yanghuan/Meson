#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
namespace IAsyncDisposableNamespace {
using namespace System::Threading::Tasks;
CLASS(IAsyncDisposable) : public Object::in {
  public: ValueTask<> DisposeAsync();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncDisposableNamespace
using IAsyncDisposable = IAsyncDisposableNamespace::IAsyncDisposable;
} // namespace System::Private::CoreLib::System
