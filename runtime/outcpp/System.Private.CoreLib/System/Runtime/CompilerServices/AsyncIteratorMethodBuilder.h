#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncIteratorMethodBuilderNamespace {
struct AsyncIteratorMethodBuilder {
  public: Object get_ObjectIdForDebugger();
  public: static AsyncIteratorMethodBuilder Create();
  public: void Complete();
  private: AsyncTaskMethodBuilder<> _methodBuilder;
};
} // namespace AsyncIteratorMethodBuilderNamespace
using AsyncIteratorMethodBuilder = AsyncIteratorMethodBuilderNamespace::AsyncIteratorMethodBuilder;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices