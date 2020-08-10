#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullWhenAttributeNamespace {
CLASS(NotNullWhenAttribute) : public Attribute::in {
  public: Boolean get_ReturnValue() { return ReturnValue; }
  public: void ctor(Boolean returnValue);
  private: Boolean ReturnValue;
};
} // namespace NotNullWhenAttributeNamespace
using NotNullWhenAttribute = NotNullWhenAttributeNamespace::NotNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
