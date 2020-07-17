#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MaybeNullWhenAttributeNamespace {
CLASS(MaybeNullWhenAttribute) {
  public: Boolean get_ReturnValue() { return ReturnValue; }
  public: void Ctor(Boolean returnValue);
  private: Boolean ReturnValue;
};
} // namespace MaybeNullWhenAttributeNamespace
using MaybeNullWhenAttribute = MaybeNullWhenAttributeNamespace::MaybeNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
