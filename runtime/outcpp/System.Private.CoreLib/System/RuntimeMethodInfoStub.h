#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Object)
namespace RuntimeMethodInfoStubNamespace {
CLASS(RuntimeMethodInfoStub) {
  private: RuntimeMethodHandleInternal get_ValueOfIRuntimeMethodInfo();
  public: void Ctor(RuntimeMethodHandleInternal methodHandleValue, Object keepalive);
  public: void Ctor(IntPtr methodHandleValue, Object keepalive);
  private: Object m_keepalive;
  private: Object m_a;
  private: Object m_b;
  private: Object m_c;
  private: Object m_d;
  private: Object m_e;
  private: Object m_f;
  private: Object m_g;
  public: RuntimeMethodHandleInternal m_value;
};
} // namespace RuntimeMethodInfoStubNamespace
using RuntimeMethodInfoStub = RuntimeMethodInfoStubNamespace::RuntimeMethodInfoStub;
} // namespace System::Private::CoreLib::System
