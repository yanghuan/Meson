#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomMarshaler)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace ExpandoToDispatchExMarshalerNamespace {
CLASS(ExpandoToDispatchExMarshaler) : public Object::in {
  public: static ICustomMarshaler GetInstance(String cookie);
  private: void Ctor();
  public: void CleanUpManagedData(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: Int32 GetNativeDataSize();
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  private: static void SCtor();
  private: static ExpandoToDispatchExMarshaler s_ExpandoToDispatchExMarshaler;
};
} // namespace ExpandoToDispatchExMarshalerNamespace
using ExpandoToDispatchExMarshaler = ExpandoToDispatchExMarshalerNamespace::ExpandoToDispatchExMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
