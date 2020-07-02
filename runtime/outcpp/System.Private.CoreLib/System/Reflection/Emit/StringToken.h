#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace StringTokenNamespace {
struct StringToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(StringToken obj);
};
} // namespace StringTokenNamespace
using StringToken = StringTokenNamespace::StringToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
