#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace StringTokenNamespace {
struct StringToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(StringToken obj);
  private: Int32 Token;
};
} // namespace StringTokenNamespace
using StringToken = StringTokenNamespace::StringToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
