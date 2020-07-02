#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ByteEqualityComparerNamespace {
CLASS(ByteEqualityComparer) {
  public: Boolean Equals(Byte x, Byte y);
  public: Int32 GetHashCode(Byte b);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace ByteEqualityComparerNamespace
using ByteEqualityComparer = ByteEqualityComparerNamespace::ByteEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
