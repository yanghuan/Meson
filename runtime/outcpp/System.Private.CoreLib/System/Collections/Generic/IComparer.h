#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IComparerNamespace {
CLASS(IComparer, T) : public object {
  public: Int32 Compare(T x, T y);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IComparerNamespace
template <class T>
using IComparer = IComparerNamespace::IComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
