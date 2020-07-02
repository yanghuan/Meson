#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace IDisposableNamespace {
CLASS(IDisposable) {
  public: void Dispose();
};
} // namespace IDisposableNamespace
using IDisposable = IDisposableNamespace::IDisposable;
} // namespace System::Private::CoreLib::System
