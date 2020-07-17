#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ReferenceEqualityComparerNamespace {
CLASS(ReferenceEqualityComparer) {
  public: static ReferenceEqualityComparer get_Instance() { return Instance; }
  private: void Ctor();
  public: Boolean Equals(Object x, Object y);
  public: Int32 GetHashCode(Object obj);
  private: static void SCtor();
  private: static ReferenceEqualityComparer Instance;
};
} // namespace ReferenceEqualityComparerNamespace
using ReferenceEqualityComparer = ReferenceEqualityComparerNamespace::ReferenceEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
