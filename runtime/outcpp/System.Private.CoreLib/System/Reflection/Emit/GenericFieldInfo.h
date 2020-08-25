#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle.h>

namespace System::Private::CoreLib::System::Reflection::Emit {
namespace GenericFieldInfoNamespace {
CLASS(GenericFieldInfo) : public object {
  public: void ctor(RuntimeFieldHandle fieldHandle, RuntimeTypeHandle context);
  public: RuntimeFieldHandle m_fieldHandle;
  public: RuntimeTypeHandle m_context;
};
} // namespace GenericFieldInfoNamespace
using GenericFieldInfo = GenericFieldInfoNamespace::GenericFieldInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
