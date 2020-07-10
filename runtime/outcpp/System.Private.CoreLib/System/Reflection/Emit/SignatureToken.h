#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace SignatureTokenNamespace {
struct SignatureToken {
  public: Int32 get_Token() { return Token; }
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SignatureToken obj);
  public: static Boolean op_Equality(SignatureToken a, SignatureToken b);
  public: static Boolean op_Inequality(SignatureToken a, SignatureToken b);
  public: static SignatureToken Empty;
  private: Int32 Token;
};
} // namespace SignatureTokenNamespace
using SignatureToken = SignatureTokenNamespace::SignatureToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
