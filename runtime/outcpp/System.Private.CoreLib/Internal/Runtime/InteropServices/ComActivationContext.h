#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARDS(ComActivationContextInternal)
namespace ComActivationContextNamespace {
using namespace System;
struct ComActivationContext : public valueType<ComActivationContext> {
  public: static ComActivationContext Create(ComActivationContextInternal& cxtInt);
  public: Guid ClassId;
  public: Guid InterfaceId;
  public: String AssemblyPath;
  public: String AssemblyName;
  public: String TypeName;
};
} // namespace ComActivationContextNamespace
using ComActivationContext = ComActivationContextNamespace::ComActivationContext;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
