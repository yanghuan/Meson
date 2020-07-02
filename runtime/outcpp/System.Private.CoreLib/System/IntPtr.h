#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int64)
FORWARD(String)
namespace IntPtrNamespace {
struct IntPtr {
  public: static Int32 get_Size();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Int32 ToInt32();
  public: Int64 ToInt64();
  public: static IntPtr Add(IntPtr pointer, Int32 offset);
  public: static IntPtr Subtract(IntPtr pointer, Int32 offset);
  public: void* ToPointer();
  public: String ToString();
  public: String ToString(String format);
  private: void* _value;
  public: static IntPtr Zero;
};
} // namespace IntPtrNamespace
using IntPtr = IntPtrNamespace::IntPtr;
} // namespace System::Private::CoreLib::System
