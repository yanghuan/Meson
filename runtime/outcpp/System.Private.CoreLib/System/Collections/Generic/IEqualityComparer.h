#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEqualityComparerNamespace {
CLASS(IEqualityComparer, T) : public object {
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEqualityComparerNamespace
template <class T>
using IEqualityComparer = IEqualityComparerNamespace::IEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
