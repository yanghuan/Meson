#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace IDeferredDisposableNamespace {
CLASS(IDeferredDisposable) : public object {
  public: void OnFinalRelease(Boolean disposed);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDeferredDisposableNamespace
using IDeferredDisposable = IDeferredDisposableNamespace::IDeferredDisposable;
} // namespace System::Private::CoreLib::System::Threading
