#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ModuleInitializerAttributeNamespace {
CLASS(ModuleInitializerAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ModuleInitializerAttributeNamespace
using ModuleInitializerAttribute = ModuleInitializerAttributeNamespace::ModuleInitializerAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
