#include "RuntimeMethodHandle-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::RuntimeMethodHandleNamespace {
IntPtr RuntimeMethodHandle::get_Value() {
  if (m_value == nullptr) {
    return IntPtr::Zero;
  }
  return m_value->get_Value().get_Value();
}

IRuntimeMethodInfo RuntimeMethodHandle::EnsureNonNullMethodInfo(IRuntimeMethodInfo method) {
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>(nullptr, SR::get_Arg_InvalidHandle());
  }
  return method;
}

RuntimeMethodHandle::RuntimeMethodHandle(IRuntimeMethodInfo method) {
  m_value = method;
}

IRuntimeMethodInfo RuntimeMethodHandle::GetMethodInfo() {
  return m_value;
}

IntPtr RuntimeMethodHandle::GetValueInternal(RuntimeMethodHandle rmh) {
  return rmh.get_Value();
}

void RuntimeMethodHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Int32 RuntimeMethodHandle::GetHashCode() {
  return ValueType::in::GetHashCodeOfPtr(get_Value());
}

Boolean RuntimeMethodHandle::Equals(Object obj) {
  if (!rt::is<RuntimeMethodHandle>(obj)) {
    return false;
  }
  return ((RuntimeMethodHandle)obj).get_Value() == get_Value();
}

Boolean RuntimeMethodHandle::op_Equality(RuntimeMethodHandle left, RuntimeMethodHandle right) {
  return left.Equals(right);
}

Boolean RuntimeMethodHandle::op_Inequality(RuntimeMethodHandle left, RuntimeMethodHandle right) {
  return !left.Equals(right);
}

Boolean RuntimeMethodHandle::Equals(RuntimeMethodHandle handle) {
  return handle.get_Value() == get_Value();
}

Boolean RuntimeMethodHandle::IsNullHandle() {
  return m_value == nullptr;
}

IntPtr RuntimeMethodHandle::GetFunctionPointer() {
  IntPtr functionPointer = GetFunctionPointer(EnsureNonNullMethodInfo(m_value)->get_Value());
  GC::KeepAlive(m_value);
  return functionPointer;
}

IRuntimeMethodInfo RuntimeMethodHandle::GetCurrentMethod(StackCrawlMark& stackMark) {
  return _GetCurrentMethod(stackMark);
}

MethodAttributes RuntimeMethodHandle::GetAttributes(IRuntimeMethodInfo method) {
  MethodAttributes attributes = GetAttributes(method->get_Value());
  GC::KeepAlive(method);
  return attributes;
}

String RuntimeMethodHandle::ConstructInstantiation(IRuntimeMethodInfo method, TypeNameFormatFlags format) {
  String s = nullptr;
  IRuntimeMethodInfo runtimeMethodInfo = EnsureNonNullMethodInfo(method);
  ConstructInstantiation(runtimeMethodInfo->get_Value(), format, StringHandleOnStack(s));
  GC::KeepAlive(runtimeMethodInfo);
  return s;
}

RuntimeType RuntimeMethodHandle::GetDeclaringType(IRuntimeMethodInfo method) {
  RuntimeType declaringType = GetDeclaringType(method->get_Value());
  GC::KeepAlive(method);
  return declaringType;
}

Int32 RuntimeMethodHandle::GetSlot(IRuntimeMethodInfo method) {
  Int32 slot = GetSlot(method->get_Value());
  GC::KeepAlive(method);
  return slot;
}

String RuntimeMethodHandle::GetName(IRuntimeMethodInfo method) {
  String name = GetName(method->get_Value());
  GC::KeepAlive(method);
  return name;
}

MdUtf8String RuntimeMethodHandle::GetUtf8Name(RuntimeMethodHandleInternal method) {
  return MdUtf8String(_GetUtf8Name(method));
}

Array<RuntimeType> RuntimeMethodHandle::GetMethodInstantiationInternal(IRuntimeMethodInfo method) {
  Array<RuntimeType> o = nullptr;
  GetMethodInstantiation(EnsureNonNullMethodInfo(method)->get_Value(), ObjectHandleOnStack::Create(o), Interop::BOOL::TRUE);
  GC::KeepAlive(method);
  return o;
}

Array<RuntimeType> RuntimeMethodHandle::GetMethodInstantiationInternal(RuntimeMethodHandleInternal method) {
  Array<RuntimeType> o = nullptr;
  GetMethodInstantiation(method, ObjectHandleOnStack::Create(o), Interop::BOOL::TRUE);
  return o;
}

Array<Type> RuntimeMethodHandle::GetMethodInstantiationPublic(IRuntimeMethodInfo method) {
  Array<RuntimeType> o = nullptr;
  GetMethodInstantiation(EnsureNonNullMethodInfo(method)->get_Value(), ObjectHandleOnStack::Create(o), Interop::BOOL::FALSE);
  GC::KeepAlive(method);
  return o;
}

Boolean RuntimeMethodHandle::HasMethodInstantiation(IRuntimeMethodInfo method) {
  Boolean result = HasMethodInstantiation(method->get_Value());
  GC::KeepAlive(method);
  return result;
}

Boolean RuntimeMethodHandle::IsGenericMethodDefinition(IRuntimeMethodInfo method) {
  Boolean result = IsGenericMethodDefinition(method->get_Value());
  GC::KeepAlive(method);
  return result;
}

IRuntimeMethodInfo RuntimeMethodHandle::GetTypicalMethodDefinition(IRuntimeMethodInfo method) {
  if (!IsTypicalMethodDefinition(method)) {
    GetTypicalMethodDefinition(method->get_Value(), ObjectHandleOnStack::Create(method));
    GC::KeepAlive(method);
  }
  return method;
}

Int32 RuntimeMethodHandle::GetGenericParameterCount(IRuntimeMethodInfo method) {
  return GetGenericParameterCount(method->get_Value());
}

IRuntimeMethodInfo RuntimeMethodHandle::StripMethodInstantiation(IRuntimeMethodInfo method) {
  IRuntimeMethodInfo o = method;
  StripMethodInstantiation(method->get_Value(), ObjectHandleOnStack::Create(o));
  GC::KeepAlive(method);
  return o;
}

} // namespace System::Private::CoreLib::System::RuntimeMethodHandleNamespace
