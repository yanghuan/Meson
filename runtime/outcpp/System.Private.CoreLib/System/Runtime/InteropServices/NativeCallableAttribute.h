#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
namespace NativeCallableAttributeNamespace {
CLASS(NativeCallableAttribute) {
  public: CallingConvention CallingConvention;
  public: String EntryPoint;
};
} // namespace NativeCallableAttributeNamespace
using NativeCallableAttribute = NativeCallableAttributeNamespace::NativeCallableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
