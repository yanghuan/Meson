#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace ComActivationContextInternalNamespace {
using namespace ::System::Private::CoreLib::System;
struct ComActivationContextInternal : public valueType<ComActivationContextInternal> {
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
