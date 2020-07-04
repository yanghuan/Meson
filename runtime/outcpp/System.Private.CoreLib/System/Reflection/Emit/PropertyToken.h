#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace PropertyTokenNamespace {
struct PropertyToken {
  public: Int32 get_Token() { return Token; }
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(PropertyToken obj);
  public: static PropertyToken Empty;
  private: Int32 Token;
};
} // namespace PropertyTokenNamespace
using PropertyToken = PropertyTokenNamespace::PropertyToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
