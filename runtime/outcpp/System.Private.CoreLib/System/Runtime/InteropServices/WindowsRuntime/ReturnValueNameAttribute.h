#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ReturnValueNameAttributeNamespace {
CLASS(ReturnValueNameAttribute) {
  public: String get_Name();
  private: String m_Name;
};
} // namespace ReturnValueNameAttributeNamespace
using ReturnValueNameAttribute = ReturnValueNameAttributeNamespace::ReturnValueNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
