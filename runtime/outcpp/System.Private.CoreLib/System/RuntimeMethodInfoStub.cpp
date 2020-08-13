#include "RuntimeMethodInfoStub-dep.h"

namespace System::Private::CoreLib::System::RuntimeMethodInfoStubNamespace {
RuntimeMethodHandleInternal RuntimeMethodInfoStub___::get_ValueOfIRuntimeMethodInfo() {
  return m_value;
}

void RuntimeMethodInfoStub___::ctor(RuntimeMethodHandleInternal methodHandleValue, Object keepalive) {
  m_keepalive = keepalive;
  m_value = methodHandleValue;
}

void RuntimeMethodInfoStub___::ctor(IntPtr methodHandleValue, Object keepalive) {
  m_keepalive = keepalive;
  m_value = RuntimeMethodHandleInternal(methodHandleValue);
}

} // namespace System::Private::CoreLib::System::RuntimeMethodInfoStubNamespace
