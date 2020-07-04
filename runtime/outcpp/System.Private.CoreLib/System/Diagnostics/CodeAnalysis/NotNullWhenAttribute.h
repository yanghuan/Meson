#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullWhenAttributeNamespace {
CLASS(NotNullWhenAttribute) {
  public: Boolean get_ReturnValue() { return ReturnValue; }
  private: Boolean ReturnValue;
};
} // namespace NotNullWhenAttributeNamespace
using NotNullWhenAttribute = NotNullWhenAttributeNamespace::NotNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
