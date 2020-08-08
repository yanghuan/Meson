#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace IAsyncLocalNamespace {
CLASS(IAsyncLocal) : public Object::in {
  public: void OnValueChanged(Object previousValue, Object currentValue, Boolean contextChanged);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncLocalNamespace
using IAsyncLocal = IAsyncLocalNamespace::IAsyncLocal;
} // namespace System::Private::CoreLib::System::Threading
