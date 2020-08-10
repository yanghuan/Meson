#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TypeForwardedFromAttributeNamespace {
CLASS(TypeForwardedFromAttribute) : public Attribute::in {
  public: String get_AssemblyFullName() { return AssemblyFullName; }
  public: void ctor(String assemblyFullName);
  private: String AssemblyFullName;
};
} // namespace TypeForwardedFromAttributeNamespace
using TypeForwardedFromAttribute = TypeForwardedFromAttributeNamespace::TypeForwardedFromAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
