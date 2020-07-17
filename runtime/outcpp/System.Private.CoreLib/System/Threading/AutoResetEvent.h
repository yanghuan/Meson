#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace AutoResetEventNamespace {
CLASS(AutoResetEvent) {
  public: void Ctor(Boolean initialState);
};
} // namespace AutoResetEventNamespace
using AutoResetEvent = AutoResetEventNamespace::AutoResetEvent;
} // namespace System::Private::CoreLib::System::Threading
