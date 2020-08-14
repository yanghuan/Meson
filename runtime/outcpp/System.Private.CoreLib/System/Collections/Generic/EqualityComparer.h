#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
namespace EqualityComparerNamespace {
using IEqualityComparer = Collections::IEqualityComparer;
template <class T>
using IEqualityComparer_ = Generic::IEqualityComparer<T>;
CLASS(EqualityComparer, T) : public Object::in {
  public: using interface = rt::TypeList<IEqualityComparer, IEqualityComparer_<T>>;
  public: static EqualityComparer<T> get_Default() { return Default; }
  public: Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
  protected: void ctor();
  private: static void cctor();
  private: static EqualityComparer<T> Default;
};
} // namespace EqualityComparerNamespace
template <class T>
using EqualityComparer = EqualityComparerNamespace::EqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
