#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace IAsyncLocalNamespace {
CLASS(IAsyncLocal) : public Object::in {
  public: void OnValueChanged(Object previousValue, Object currentValue, Boolean contextChanged);
};
} // namespace IAsyncLocalNamespace
using IAsyncLocal = IAsyncLocalNamespace::IAsyncLocal;
} // namespace System::Private::CoreLib::System::Threading
