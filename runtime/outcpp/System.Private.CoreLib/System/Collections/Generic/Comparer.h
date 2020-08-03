#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Comparison, T)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ComparerNamespace {
CLASS(Comparer, T) : public Object::in {
  public: static Comparer<T> get_Default() { return Default; }
  public: static Comparer<T> Create(Comparison<T> comparison);
  public: Int32 Compare(T x, T y);
  protected: void Ctor();
  private: static void SCtor();
  private: static Comparer<T> Default;
};
} // namespace ComparerNamespace
template <class T>
using Comparer = ComparerNamespace::Comparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
