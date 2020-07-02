#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace SignatureTokenNamespace {
struct SignatureToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SignatureToken obj);
  public: static SignatureToken Empty;
};
} // namespace SignatureTokenNamespace
using SignatureToken = SignatureTokenNamespace::SignatureToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
