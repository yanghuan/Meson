#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(Comparison, T)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
namespace ComparerNamespace {
using IComparer = Collections::IComparer;
template <class T>
using IComparer_ = Generic::IComparer<T>;
CLASS(Comparer, T) : public object {
  public: using interface = rt::TypeList<IComparer, IComparer_<T>>;
  public: static Comparer<T> get_Default() { return Default; }
  public: static Comparer<T> Create(Comparison<T> comparison);
  public: Int32 Compare(T x, T y);
  protected: void ctor();
  private: static void cctor();
  private: static Comparer<T> Default;
};
} // namespace ComparerNamespace
template <class T>
using Comparer = ComparerNamespace::Comparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
