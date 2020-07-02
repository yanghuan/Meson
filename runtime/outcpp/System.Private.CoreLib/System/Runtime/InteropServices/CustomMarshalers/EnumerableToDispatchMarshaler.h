#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Object)
FORWARDS(IntPtr)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomMarshaler)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumerableToDispatchMarshalerNamespace {
CLASS(EnumerableToDispatchMarshaler) {
  public: static ICustomMarshaler GetInstance(String cookie);
  public: void CleanUpManagedData(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: Int32 GetNativeDataSize();
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  private: static EnumerableToDispatchMarshaler s_enumerableToDispatchMarshaler;
};
} // namespace EnumerableToDispatchMarshalerNamespace
using EnumerableToDispatchMarshaler = EnumerableToDispatchMarshalerNamespace::EnumerableToDispatchMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
