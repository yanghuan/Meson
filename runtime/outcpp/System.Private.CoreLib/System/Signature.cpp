#include "Signature-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>

namespace System::Private::CoreLib::System::SignatureNamespace {
CallingConventions Signature___::get_CallingConvention() {
  return (CallingConventions)(Byte)m_managedCallingConventionAndArgIteratorFlags;
}

Array<RuntimeType> Signature___::get_Arguments() {
  return m_arguments;
}

RuntimeType Signature___::get_ReturnType() {
  return m_returnTypeORfieldType;
}

RuntimeType Signature___::get_FieldType() {
  return m_returnTypeORfieldType;
}

void Signature___::ctor(IRuntimeMethodInfo method, Array<RuntimeType> arguments, RuntimeType returnType, CallingConventions callingConvention) {
  m_pMethod = method->get_Value();
  m_arguments = arguments;
  m_returnTypeORfieldType = returnType;
  m_managedCallingConventionAndArgIteratorFlags = (Byte)callingConvention;
  GetSignature(nullptr, 0, RuntimeFieldHandleInternal(), method, nullptr);
}

void Signature___::ctor(IRuntimeMethodInfo methodHandle, RuntimeType declaringType) {
  GetSignature(nullptr, 0, RuntimeFieldHandleInternal(), methodHandle, declaringType);
}

void Signature___::ctor(IRuntimeFieldInfo fieldHandle, RuntimeType declaringType) {
  GetSignature(nullptr, 0, fieldHandle->get_Value(), nullptr, declaringType);
  GC::KeepAlive(fieldHandle);
}

void Signature___::ctor(void* pCorSig, Int32 cCorSig, RuntimeType declaringType) {
  GetSignature(pCorSig, cCorSig, RuntimeFieldHandleInternal(), nullptr, declaringType);
}

} // namespace System::Private::CoreLib::System::SignatureNamespace
