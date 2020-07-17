#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARDS(ComActivationContextInternal)
namespace ComActivationContextNamespace {
using namespace ::System::Private::CoreLib::System;
struct ComActivationContext {
  public: static ComActivationContext Create(ComActivationContextInternal& cxtInt);
  public: void Ctor();
  public: Guid ClassId;
  public: Guid InterfaceId;
  public: String AssemblyPath;
  public: String AssemblyName;
  public: String TypeName;
};
} // namespace ComActivationContextNamespace
using ComActivationContext = ComActivationContextNamespace::ComActivationContext;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
