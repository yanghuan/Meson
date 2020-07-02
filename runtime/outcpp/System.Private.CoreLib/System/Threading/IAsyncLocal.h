#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace IAsyncLocalNamespace {
CLASS(IAsyncLocal) {
  public: void OnValueChanged(Object previousValue, Object currentValue, Boolean contextChanged);
};
} // namespace IAsyncLocalNamespace
using IAsyncLocal = IAsyncLocalNamespace::IAsyncLocal;
} // namespace System::Private::CoreLib::System::Threading
