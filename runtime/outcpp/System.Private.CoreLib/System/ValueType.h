#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
namespace ValueTypeNamespace {
CLASS(ValueType) {
  public: Boolean Equals(Object obj);
  private: static Boolean CanCompareBits(Object obj);
  private: static Boolean FastEqualsCheck(Object a, Object b);
  public: Int32 GetHashCode();
  public: static Int32 GetHashCodeOfPtr(IntPtr ptr);
  public: String ToString();
};
} // namespace ValueTypeNamespace
using ValueType = ValueTypeNamespace::ValueType;
} // namespace System::Private::CoreLib::System
