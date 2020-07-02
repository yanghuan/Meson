#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace FieldTokenNamespace {
struct FieldToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(FieldToken obj);
  public: static FieldToken Empty;
  private: Object _class;
};
} // namespace FieldTokenNamespace
using FieldToken = FieldTokenNamespace::FieldToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
