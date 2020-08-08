#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(HashSet, T)
FORWARD(IEqualityComparer, T)
namespace HashSetEqualityComparerNamespace {
CLASS(HashSetEqualityComparer, T) : public Object::in {
  using interface = rt::TypeList<IEqualityComparer<HashSet<T>>>;
  public: Boolean Equals(HashSet<T> x, HashSet<T> y);
  public: Int32 GetHashCode(HashSet<T> obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
};
} // namespace HashSetEqualityComparerNamespace
template <class T>
using HashSetEqualityComparer = HashSetEqualityComparerNamespace::HashSetEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
