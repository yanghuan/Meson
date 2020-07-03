#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MaybeNullWhenAttributeNamespace {
CLASS(MaybeNullWhenAttribute) {
  private: Boolean ReturnValue;
};
} // namespace MaybeNullWhenAttributeNamespace
using MaybeNullWhenAttribute = MaybeNullWhenAttributeNamespace::MaybeNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
