#include "DynamicILInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicILInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicResolver-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILInfoNamespace {
Array<Byte> DynamicILInfo___::get_LocalSignature() {
  Array<Byte> as = m_localSignature;
  return as != nullptr ? as : (m_localSignature = SignatureHelper::in::GetLocalVarSigHelper()->InternalGetSignatureArray());
}

Array<Byte> DynamicILInfo___::get_Exceptions() {
  return m_exceptions;
}

Array<Byte> DynamicILInfo___::get_Code() {
  return m_code;
}

Int32 DynamicILInfo___::get_MaxStackSize() {
  return m_maxStackSize;
}

DynamicMethod DynamicILInfo___::get_DynamicMethod() {
  return m_method;
}

DynamicScope DynamicILInfo___::get_DynamicScope() {
  return m_scope;
}

void DynamicILInfo___::ctor(DynamicMethod method, Array<Byte> methodSignature) {
  m_scope = rt::newobj<DynamicScope>();
  m_method = method;
  m_methodSignature = m_scope->GetTokenFor(methodSignature);
  m_exceptions = Array<>::in::Empty<Byte>();
  m_code = Array<>::in::Empty<Byte>();
  m_localSignature = Array<>::in::Empty<Byte>();
}

void DynamicILInfo___::GetCallableMethod(RuntimeModule module, DynamicMethod dm) {
  dm->m_methodHandle = ModuleHandle::GetDynamicMethod(dm, module, m_method->get_Name(), (Array<Byte>)m_scope[m_methodSignature], rt::newobj<DynamicResolver>((DynamicILInfo)this));
}

void DynamicILInfo___::SetCode(Array<Byte> code, Int32 maxStackSize) {
  m_code = (Array<Byte>)((code != nullptr) ? ((Object)(Array<Byte>)code->Clone()) : ((Object)Array<>::in::Empty<Byte>()));
  m_maxStackSize = maxStackSize;
}

void DynamicILInfo___::SetCode(Byte* code, Int32 codeSize, Int32 maxStackSize) {
  if (codeSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("codeSize", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (codeSize > 0 && code == nullptr) {
    rt::throw_exception<ArgumentNullException>("code");
  }
  m_code = Span<Byte>(code, codeSize).ToArray();
  m_maxStackSize = maxStackSize;
}

void DynamicILInfo___::SetExceptions(Array<Byte> exceptions) {
  m_exceptions = (Array<Byte>)((exceptions != nullptr) ? ((Object)(Array<Byte>)exceptions->Clone()) : ((Object)Array<>::in::Empty<Byte>()));
}

void DynamicILInfo___::SetExceptions(Byte* exceptions, Int32 exceptionsSize) {
  if (exceptionsSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("exceptionsSize", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (exceptionsSize > 0 && exceptions == nullptr) {
    rt::throw_exception<ArgumentNullException>("exceptions");
  }
  m_exceptions = Span<Byte>(exceptions, exceptionsSize).ToArray();
}

void DynamicILInfo___::SetLocalSignature(Array<Byte> localSignature) {
  m_localSignature = (Array<Byte>)((localSignature != nullptr) ? ((Object)(Array<Byte>)localSignature->Clone()) : ((Object)Array<>::in::Empty<Byte>()));
}

void DynamicILInfo___::SetLocalSignature(Byte* localSignature, Int32 signatureSize) {
  if (signatureSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("signatureSize", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (signatureSize > 0 && localSignature == nullptr) {
    rt::throw_exception<ArgumentNullException>("localSignature");
  }
  m_localSignature = Span<Byte>(localSignature, signatureSize).ToArray();
}

Int32 DynamicILInfo___::GetTokenFor(RuntimeMethodHandle method) {
  return get_DynamicScope()->GetTokenFor(method);
}

Int32 DynamicILInfo___::GetTokenFor(DynamicMethod method) {
  return get_DynamicScope()->GetTokenFor(method);
}

Int32 DynamicILInfo___::GetTokenFor(RuntimeMethodHandle method, RuntimeTypeHandle contextType) {
  return get_DynamicScope()->GetTokenFor(method, contextType);
}

Int32 DynamicILInfo___::GetTokenFor(RuntimeFieldHandle field) {
  return get_DynamicScope()->GetTokenFor(field);
}

Int32 DynamicILInfo___::GetTokenFor(RuntimeFieldHandle field, RuntimeTypeHandle contextType) {
  return get_DynamicScope()->GetTokenFor(field, contextType);
}

Int32 DynamicILInfo___::GetTokenFor(RuntimeTypeHandle type) {
  return get_DynamicScope()->GetTokenFor(type);
}

Int32 DynamicILInfo___::GetTokenFor(String literal) {
  return get_DynamicScope()->GetTokenFor(literal);
}

Int32 DynamicILInfo___::GetTokenFor(Array<Byte> signature) {
  return get_DynamicScope()->GetTokenFor(signature);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::DynamicILInfoNamespace
