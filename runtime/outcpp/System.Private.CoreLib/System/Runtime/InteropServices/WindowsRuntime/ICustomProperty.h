#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ICustomPropertyNamespace {
CLASS(ICustomProperty) {
  public: Type get_Type();
  public: String get_Name();
  public: Boolean get_CanWrite();
  public: Boolean get_CanRead();
  public: Object GetValue(Object target);
  public: void SetValue(Object target, Object value);
  public: Object GetValue(Object target, Object indexValue);
  public: void SetValue(Object target, Object value, Object indexValue);
};
} // namespace ICustomPropertyNamespace
using ICustomProperty = ICustomPropertyNamespace::ICustomProperty;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
