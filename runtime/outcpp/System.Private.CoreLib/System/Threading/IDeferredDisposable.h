#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace IDeferredDisposableNamespace {
CLASS(IDeferredDisposable) : public Object::in {
  public: void OnFinalRelease(Boolean disposed);
};
} // namespace IDeferredDisposableNamespace
using IDeferredDisposable = IDeferredDisposableNamespace::IDeferredDisposable;
} // namespace System::Private::CoreLib::System::Threading
