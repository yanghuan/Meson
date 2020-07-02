#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle.h>

namespace System::Private::CoreLib::System::Reflection::Emit {
namespace GenericMethodInfoNamespace {
CLASS(GenericMethodInfo) {
  public: RuntimeMethodHandle m_methodHandle;
  public: RuntimeTypeHandle m_context;
};
} // namespace GenericMethodInfoNamespace
using GenericMethodInfo = GenericMethodInfoNamespace::GenericMethodInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
