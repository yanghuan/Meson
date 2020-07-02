#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace MethodTokenNamespace {
struct MethodToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(MethodToken obj);
  public: static MethodToken Empty;
};
} // namespace MethodTokenNamespace
using MethodToken = MethodTokenNamespace::MethodToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
