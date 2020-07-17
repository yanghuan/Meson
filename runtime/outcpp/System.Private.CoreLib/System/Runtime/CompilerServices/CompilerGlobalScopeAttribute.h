#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CompilerGlobalScopeAttributeNamespace {
CLASS(CompilerGlobalScopeAttribute) {
  public: void Ctor();
};
} // namespace CompilerGlobalScopeAttributeNamespace
using CompilerGlobalScopeAttribute = CompilerGlobalScopeAttributeNamespace::CompilerGlobalScopeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
