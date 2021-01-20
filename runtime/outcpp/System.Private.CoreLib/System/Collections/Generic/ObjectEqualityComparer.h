#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ObjectEqualityComparerNamespace {
CLASS(ObjectEqualityComparer, T) : public EqualityComparer<T>::in {
  public: Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void ctor();
};
} // namespace ObjectEqualityComparerNamespace
template <class T>
using ObjectEqualityComparer = ObjectEqualityComparerNamespace::ObjectEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
