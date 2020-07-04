#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace FieldTokenNamespace {
struct FieldToken {
  public: Int32 get_Token() { return Token; }
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(FieldToken obj);
  public: static FieldToken Empty;
  private: Object _class;
  private: Int32 Token;
};
} // namespace FieldTokenNamespace
using FieldToken = FieldTokenNamespace::FieldToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
