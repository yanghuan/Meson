#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Numerics/Register.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace VectorNamespace {
template <class T1 = void, class T2 = void>
class Vector {
};
template <>
class Vector<> : public Object::in {
  public: static Boolean get_IsHardwareAccelerated();
};
template <class T>
struct Vector<T> {
  public: static Int32 get_Count();
  public: static Vector<T> get_Zero();
  public: static Vector<T> get_One();
  public: static Vector<T> get_AllBitsSet();
  public: T get_Item(Int32 index);
  private: Register register_;
  private: static Vector<T> s_zero;
  private: static Vector<T> s_one;
  private: static Vector<T> s_allBitsSet;
};
} // namespace VectorNamespace
template <class T1 = void, class T2 = void>
using Vector = VectorNamespace::Vector<T1, T2>;
} // namespace System::Private::CoreLib::System::Numerics
