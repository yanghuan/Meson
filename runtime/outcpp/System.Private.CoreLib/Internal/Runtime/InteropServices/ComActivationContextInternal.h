#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace ComActivationContextInternalNamespace {
using namespace ::System::Private::CoreLib::System;
struct ComActivationContextInternal {
  public: Guid ClassId;
  public: Guid InterfaceId;
  public: Char* AssemblyPathBuffer;
  public: Char* AssemblyNameBuffer;
  public: Char* TypeNameBuffer;
  public: IntPtr ClassFactoryDest;
};
} // namespace ComActivationContextInternalNamespace
using ComActivationContextInternal = ComActivationContextInternalNamespace::ComActivationContextInternal;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
