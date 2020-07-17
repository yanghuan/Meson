#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandleInternal.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
namespace RuntimeFieldInfoStubNamespace {
CLASS(RuntimeFieldInfoStub) {
  private: RuntimeFieldHandleInternal get_ValueOfIRuntimeFieldInfo();
  public: void Ctor();
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
