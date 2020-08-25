#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandleInternal.h>

namespace System::Private::CoreLib::System {
FORWARD(IRuntimeFieldInfo)
namespace RuntimeFieldInfoStubNamespace {
CLASS(RuntimeFieldInfoStub) : public object {
  public: using interface = rt::TypeList<IRuntimeFieldInfo>;
  private: RuntimeFieldHandleInternal get_ValueOfIRuntimeFieldInfo();
  public: void ctor();
  private: Object m_keepalive;
  private: Object m_c;
  private: Object m_d;
  private: Int32 m_b;
  private: Object m_e;
  private: RuntimeFieldHandleInternal m_fieldHandle;
};
} // namespace RuntimeFieldInfoStubNamespace
using RuntimeFieldInfoStub = RuntimeFieldInfoStubNamespace::RuntimeFieldInfoStub;
} // namespace System::Private::CoreLib::System
