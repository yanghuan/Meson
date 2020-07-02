#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomMarshaler)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumeratorToEnumVariantMarshalerNamespace {
CLASS(EnumeratorToEnumVariantMarshaler) {
  public: static ICustomMarshaler GetInstance(String cookie);
  public: void CleanUpManagedData(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: Int32 GetNativeDataSize();
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  private: static EnumeratorToEnumVariantMarshaler s_enumeratorToEnumVariantMarshaler;
};
} // namespace EnumeratorToEnumVariantMarshalerNamespace
using EnumeratorToEnumVariantMarshaler = EnumeratorToEnumVariantMarshalerNamespace::EnumeratorToEnumVariantMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
