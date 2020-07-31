#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CompilerGlobalScopeAttributeNamespace {
CLASS(CompilerGlobalScopeAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace CompilerGlobalScopeAttributeNamespace
using CompilerGlobalScopeAttribute = CompilerGlobalScopeAttributeNamespace::CompilerGlobalScopeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
