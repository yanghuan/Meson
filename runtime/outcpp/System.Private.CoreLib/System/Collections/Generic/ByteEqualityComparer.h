#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ByteEqualityComparerNamespace {
CLASS(ByteEqualityComparer) : public EqualityComparer<Byte>::in {
  public: Boolean Equals(Byte x, Byte y);
  public: Int32 GetHashCode(Byte b);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
};
} // namespace ByteEqualityComparerNamespace
using ByteEqualityComparer = ByteEqualityComparerNamespace::ByteEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
