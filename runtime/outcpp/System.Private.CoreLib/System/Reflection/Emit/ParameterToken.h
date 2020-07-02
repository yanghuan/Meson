#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace ParameterTokenNamespace {
struct ParameterToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ParameterToken obj);
  public: static ParameterToken Empty;
};
} // namespace ParameterTokenNamespace
using ParameterToken = ParameterTokenNamespace::ParameterToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
