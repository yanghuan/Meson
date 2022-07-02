#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace UnmanagedCallersOnlyAttributeNamespace {
CLASS(UnmanagedCallersOnlyAttribute) : public Attribute::in {
  public: void ctor();
  public: Array<Type> CallConvs;
  public: String EntryPoint;
};
} // namespace UnmanagedCallersOnlyAttributeNamespace
using UnmanagedCallersOnlyAttribute = UnmanagedCallersOnlyAttributeNamespace::UnmanagedCallersOnlyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
