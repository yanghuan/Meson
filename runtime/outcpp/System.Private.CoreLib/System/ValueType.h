#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
namespace ValueTypeNamespace {
CLASS(ValueType) : public Object::in {
  public: Boolean Equals(Object obj);
  private: static Boolean CanCompareBits(Object obj);
  private: static Boolean FastEqualsCheck(Object a, Object b);
  public: Int32 GetHashCode();
  public: static Int32 GetHashCodeOfPtr(IntPtr ptr);
  public: String ToString();
  protected: void ctor();
};
} // namespace ValueTypeNamespace
using ValueType = ValueTypeNamespace::ValueType;
template <class T, rt::TypeCode code = rt::TypeCode::None>
struct valueType : public rt::ValueType<T, ValueType::in, code> {
};
} // namespace System::Private::CoreLib::System
