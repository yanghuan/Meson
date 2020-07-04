#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
namespace UnmanagedCallersOnlyAttributeNamespace {
CLASS(UnmanagedCallersOnlyAttribute) {
  public: CallingConvention CallingConvention;
  public: String EntryPoint;
};
} // namespace UnmanagedCallersOnlyAttributeNamespace
using UnmanagedCallersOnlyAttribute = UnmanagedCallersOnlyAttributeNamespace::UnmanagedCallersOnlyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
