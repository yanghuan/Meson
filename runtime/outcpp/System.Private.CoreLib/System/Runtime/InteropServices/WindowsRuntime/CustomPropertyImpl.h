#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace CustomPropertyImplNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(CustomPropertyImpl) {
  public: String get_Name();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Type get_Type();
  public: Object GetValue(Object target);
  public: Object GetValue(Object target, Object indexValue);
  public: void SetValue(Object target, Object value);
  public: void SetValue(Object target, Object value, Object indexValue);
  private: Object InvokeInternal(Object target, Array<Object> args, Boolean getValue);
  private: PropertyInfo m_property;
};
} // namespace CustomPropertyImplNamespace
using CustomPropertyImpl = CustomPropertyImplNamespace::CustomPropertyImpl;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
