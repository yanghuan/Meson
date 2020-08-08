#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IAsyncLocal)
namespace IAsyncLocalValueMapNamespace {
CLASS(IAsyncLocalValueMap) : public Object::in {
  public: Boolean TryGetValue(IAsyncLocal key, Object& value);
  public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncLocalValueMapNamespace
using IAsyncLocalValueMap = IAsyncLocalValueMapNamespace::IAsyncLocalValueMap;
} // namespace System::Private::CoreLib::System::Threading
