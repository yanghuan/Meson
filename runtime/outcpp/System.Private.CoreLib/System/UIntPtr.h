#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARD(String)
namespace UIntPtrNamespace {
struct UIntPtr {
  public: static Int32 get_Size();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: UInt32 ToUInt32();
  public: UInt64 ToUInt64();
  public: static UIntPtr Add(UIntPtr pointer, Int32 offset);
  public: static UIntPtr Subtract(UIntPtr pointer, Int32 offset);
  public: void* ToPointer();
  public: String ToString();
  private: void* _value;
  public: static UIntPtr Zero;
};
} // namespace UIntPtrNamespace
using UIntPtr = UIntPtrNamespace::UIntPtr;
} // namespace System::Private::CoreLib::System
