#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace EqualityComparerNamespace {
CLASS(EqualityComparer, T) : public Object::in {
  public: static EqualityComparer<T> get_Default() { return Default; }
  public: Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
  protected: void Ctor();
  private: static void SCtor();
  private: static EqualityComparer<T> Default;
};
} // namespace EqualityComparerNamespace
template <class T>
using EqualityComparer = EqualityComparerNamespace::EqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
