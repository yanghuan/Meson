#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace PropertyTokenNamespace {
struct PropertyToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(PropertyToken obj);
  public: static PropertyToken Empty;
};
} // namespace PropertyTokenNamespace
using PropertyToken = PropertyTokenNamespace::PropertyToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
