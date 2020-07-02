#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace TypeTokenNamespace {
struct TypeToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(TypeToken obj);
  public: static TypeToken Empty;
};
} // namespace TypeTokenNamespace
using TypeToken = TypeTokenNamespace::TypeToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
