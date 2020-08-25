#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
namespace ReferenceEqualityComparerNamespace {
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
using IEqualityComparer_ = Collections::IEqualityComparer;
CLASS(ReferenceEqualityComparer) : public object {
  public: using interface = rt::TypeList<IEqualityComparer<Object>, IEqualityComparer_>;
  public: static ReferenceEqualityComparer get_Instance() { return Instance; }
  private: void ctor();
  public: Boolean Equals(Object x, Object y);
  public: Int32 GetHashCode(Object obj);
  private: static void cctor();
  private: static ReferenceEqualityComparer Instance;
};
} // namespace ReferenceEqualityComparerNamespace
using ReferenceEqualityComparer = ReferenceEqualityComparerNamespace::ReferenceEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
