#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomMarshaler)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace TypeToTypeInfoMarshalerNamespace {
CLASS(TypeToTypeInfoMarshaler) : public object {
  public: using interface = rt::TypeList<ICustomMarshaler>;
  public: static ICustomMarshaler GetInstance(String cookie);
  public: void ctor();
  public: void CleanUpManagedData(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: Int32 GetNativeDataSize();
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  public: static void cctor();
  private: static TypeToTypeInfoMarshaler s_typeToTypeInfoMarshaler;
};
} // namespace TypeToTypeInfoMarshalerNamespace
using TypeToTypeInfoMarshaler = TypeToTypeInfoMarshalerNamespace::TypeToTypeInfoMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
