#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace PointerNamespace {
CLASS(Pointer) {
  private: void Ctor(void* ptr, Type ptrType);
  public: static Object Box(void* ptr, Type type);
  public: static void* Unbox(Object ptr);
  public: Type GetPointerType();
  public: IntPtr GetPointerValue();
  private: void* _ptr;
  private: Type _ptrType;
};
} // namespace PointerNamespace
using Pointer = PointerNamespace::Pointer;
} // namespace System::Private::CoreLib::System::Reflection
