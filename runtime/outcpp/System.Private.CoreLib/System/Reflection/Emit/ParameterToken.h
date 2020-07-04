#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace ParameterTokenNamespace {
struct ParameterToken {
  public: Int32 get_Token() { return Token; }
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ParameterToken obj);
  public: static ParameterToken Empty;
  private: Int32 Token;
};
} // namespace ParameterTokenNamespace
using ParameterToken = ParameterTokenNamespace::ParameterToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
