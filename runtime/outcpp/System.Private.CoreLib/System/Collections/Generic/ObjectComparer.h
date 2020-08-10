#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/Comparer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ObjectComparerNamespace {
CLASS(ObjectComparer, T) : public Comparer<T>::in {
  public: Int32 Compare(T x, T y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void ctor();
};
} // namespace ObjectComparerNamespace
template <class T>
using ObjectComparer = ObjectComparerNamespace::ObjectComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
