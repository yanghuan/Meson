#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace PointerNamespace {
using namespace System::Runtime::Serialization;
CLASS(Pointer) : public object {
  public: using interface = rt::TypeList<ISerializable>;
  public: void ctor(void* ptr, Type ptrType);
  public: static Object Box(void* ptr, Type type);
  public: static void* Unbox(Object ptr);
  private: void GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context);
  public: Type GetPointerType();
  public: IntPtr GetPointerValue();
  private: void* _ptr;
  private: Type _ptrType;
};
} // namespace PointerNamespace
using Pointer = PointerNamespace::Pointer;
} // namespace System::Private::CoreLib::System::Reflection
