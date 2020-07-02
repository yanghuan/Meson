#include "RuntimeFieldHandle-dep.h"

namespace System::Private::CoreLib::System::RuntimeFieldHandleNamespace {
IntPtr RuntimeFieldHandle::get_Value() {
  return IntPtr();
};
IRuntimeFieldInfo RuntimeFieldHandle::GetRuntimeFieldInfo() {
  return nullptr;
};
Boolean RuntimeFieldHandle::IsNullHandle() {
  return Boolean();
};
Int32 RuntimeFieldHandle::GetHashCode() {
  return Int32();
};
Boolean RuntimeFieldHandle::Equals(Object obj) {
  return Boolean();
};
Boolean RuntimeFieldHandle::Equals(RuntimeFieldHandle handle) {
  return Boolean();
};
MdUtf8String RuntimeFieldHandle::GetUtf8Name(RuntimeFieldHandleInternal field) {
  return MdUtf8String();
};
RuntimeType RuntimeFieldHandle::GetApproxDeclaringType(IRuntimeFieldInfo field) {
  return nullptr;
};
void RuntimeFieldHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
} // namespace System::Private::CoreLib::System::RuntimeFieldHandleNamespace
