#include "RuntimeFieldHandle-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle-dep.h>

namespace System::Private::CoreLib::System::RuntimeFieldHandleNamespace {
IntPtr RuntimeFieldHandle::get_Value() {
  if (m_ptr == nullptr) {
    return IntPtr::Zero;
  }
  return m_ptr->get_Value().get_Value();
}

RuntimeFieldHandle::RuntimeFieldHandle(IRuntimeFieldInfo fieldInfo) {
  m_ptr = fieldInfo;
}

IRuntimeFieldInfo RuntimeFieldHandle::GetRuntimeFieldInfo() {
  return m_ptr;
}

Boolean RuntimeFieldHandle::IsNullHandle() {
  return m_ptr == nullptr;
}

Int32 RuntimeFieldHandle::GetHashCode() {
  return ValueType::in::GetHashCodeOfPtr(get_Value());
}

Boolean RuntimeFieldHandle::Equals(Object obj) {
  if (!rt::is<RuntimeFieldHandle>(obj)) {
    return false;
  }
  return ((RuntimeFieldHandle)obj).get_Value() == get_Value();
}

Boolean RuntimeFieldHandle::Equals(RuntimeFieldHandle handle) {
  return handle.get_Value() == get_Value();
}

Boolean RuntimeFieldHandle::op_Equality(RuntimeFieldHandle left, RuntimeFieldHandle right) {
  return left.Equals(right);
}

Boolean RuntimeFieldHandle::op_Inequality(RuntimeFieldHandle left, RuntimeFieldHandle right) {
  return !left.Equals(right);
}

MdUtf8String RuntimeFieldHandle::GetUtf8Name(RuntimeFieldHandleInternal field) {
  return MdUtf8String(_GetUtf8Name(field));
}

RuntimeType RuntimeFieldHandle::GetApproxDeclaringType(IRuntimeFieldInfo field) {
  RuntimeType approxDeclaringType = GetApproxDeclaringType(field->get_Value());
  GC::KeepAlive(field);
  return approxDeclaringType;
}

void RuntimeFieldHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

} // namespace System::Private::CoreLib::System::RuntimeFieldHandleNamespace
