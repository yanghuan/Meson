#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IAsyncLocal)
namespace IAsyncLocalValueMapNamespace {
CLASS(IAsyncLocalValueMap) {
  public: Boolean TryGetValue(IAsyncLocal key, Object& value);
  public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
};
} // namespace IAsyncLocalValueMapNamespace
using IAsyncLocalValueMap = IAsyncLocalValueMapNamespace::IAsyncLocalValueMap;
} // namespace System::Private::CoreLib::System::Threading
