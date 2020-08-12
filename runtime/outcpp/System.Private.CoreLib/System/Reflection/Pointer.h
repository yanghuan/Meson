#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace PointerNamespace {
using namespace System::Runtime::Serialization;
CLASS(Pointer) : public Object::in {
  public: using interface = rt::TypeList<ISerializable>;
  private: void ctor(void* ptr, Type ptrType);
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
