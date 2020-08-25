#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ICustomMarshalerNamespace {
CLASS(ICustomMarshaler) : public object {
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: void CleanUpManagedData(Object ManagedObj);
  public: Int32 GetNativeDataSize();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomMarshalerNamespace
using ICustomMarshaler = ICustomMarshalerNamespace::ICustomMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
