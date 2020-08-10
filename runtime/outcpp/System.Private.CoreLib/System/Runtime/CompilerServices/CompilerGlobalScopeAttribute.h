#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CompilerGlobalScopeAttributeNamespace {
CLASS(CompilerGlobalScopeAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace CompilerGlobalScopeAttributeNamespace
using CompilerGlobalScopeAttribute = CompilerGlobalScopeAttributeNamespace::CompilerGlobalScopeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
