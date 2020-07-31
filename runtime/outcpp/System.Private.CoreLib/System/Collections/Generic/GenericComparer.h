#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/Comparer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace GenericComparerNamespace {
CLASS(GenericComparer, T) : public Comparer<T>::in {
  public: Int32 Compare(T x, T y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
};
} // namespace GenericComparerNamespace
template <class T>
using GenericComparer = GenericComparerNamespace::GenericComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
