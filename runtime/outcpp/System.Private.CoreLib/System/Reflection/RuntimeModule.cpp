#include "RuntimeModule-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/IRuntimeFieldInfo.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MissingFieldException-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeModuleNamespace {
using namespace System::IO;
using namespace System::Runtime::CompilerServices;

Int32 RuntimeModule___::get_MDStreamVersion() {
  return ModuleHandle::GetMDStreamVersion(GetNativeHandle());
}

RuntimeType RuntimeModule___::get_RuntimeType() {
  RuntimeType as = m_runtimeType;
  return as != nullptr ? as : (m_runtimeType = ModuleHandle::GetModuleType((RuntimeModule)this));
}

MetadataImport RuntimeModule___::get_MetadataImport() {
  return ModuleHandle::GetMetadataImport((RuntimeModule)this);
}

String RuntimeModule___::get_FullyQualifiedName() {
  return GetFullyQualifiedName();
}

Guid RuntimeModule___::get_ModuleVersionId() {
  Guid mvid;
  get_MetadataImport().GetScopeProps(mvid);
  return mvid;
}

Int32 RuntimeModule___::get_MetadataToken() {
  return ModuleHandle::GetToken(GetNativeHandle());
}

String RuntimeModule___::get_ScopeName() {
  String s = nullptr;
  RuntimeModule module = (RuntimeModule)this;
  GetScopeName(QCallModule(module), StringHandleOnStack(s));
  return s;
}

String RuntimeModule___::get_Name() {
  String fullyQualifiedName = GetFullyQualifiedName();
  Int32 num = fullyQualifiedName->LastIndexOf(Path::DirectorySeparatorChar);
  if (num == -1) {
    return fullyQualifiedName;
  }
  return fullyQualifiedName->Substring(num + 1);
}

Assembly RuntimeModule___::get_Assembly() {
  return GetRuntimeAssembly();
}

void RuntimeModule___::ctor() {
  rt::throw_exception<NotSupportedException>();
}

Array<RuntimeType> RuntimeModule___::GetDefinedTypes() {
  return GetTypes(GetNativeHandle());
}

Array<RuntimeTypeHandle> RuntimeModule___::ConvertToTypeHandleArray(Array<Type> genericArguments) {
  if (genericArguments == nullptr) {
    return nullptr;
  }
  Int32 num = genericArguments->get_Length();
  Array<RuntimeTypeHandle> array = rt::newarr<Array<RuntimeTypeHandle>>(num);
  for (Int32 i = 0; i < num; i++) {
    Type type = genericArguments[i];
    if (type == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidGenericInstArray());
    }
    type = type->get_UnderlyingSystemType();
    if (type == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidGenericInstArray());
    }
    if (!rt::is<RuntimeType>(type)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidGenericInstArray());
    }
    array[i] = type->GetTypeHandleInternal();
  }
  return array;
}

Array<Byte> RuntimeModule___::ResolveSignature(Int32 metadataToken) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (!get_MetadataImport().IsValidToken(metadataToken2)) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  if (!metadataToken2.get_IsMemberRef() && !metadataToken2.get_IsMethodDef() && !metadataToken2.get_IsTypeSpec() && !metadataToken2.get_IsSignature() && !metadataToken2.get_IsFieldDef()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this), "metadataToken");
  }
  ConstArray constArray = ((!metadataToken2.get_IsMemberRef()) ? get_MetadataImport().GetSignatureFromToken(metadataToken) : get_MetadataImport().GetMemberRefProps(metadataToken));
  Array<Byte> array = rt::newarr<Array<Byte>>(constArray.get_Length());
  for (Int32 i = 0; i < constArray.get_Length(); i++) {
    array[i] = constArray[i];
  }
  return array;
}

MethodBase RuntimeModule___::ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (!get_MetadataImport().IsValidToken(metadataToken2)) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  Array<RuntimeTypeHandle> typeInstantiationContext = ConvertToTypeHandleArray(genericTypeArguments);
  Array<RuntimeTypeHandle> methodInstantiationContext = ConvertToTypeHandleArray(genericMethodArguments);
  try {
    if (!metadataToken2.get_IsMethodDef() && !metadataToken2.get_IsMethodSpec()) {
      if (!metadataToken2.get_IsMemberRef()) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveMethod(), metadataToken2, (RuntimeModule)this), "metadataToken");
      }
      if (*(Byte*)get_MetadataImport().GetMemberRefProps(metadataToken2).get_Signature().ToPointer() == 6) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveMethod(), metadataToken2, (RuntimeModule)this), "metadataToken");
      }
    }
    IRuntimeMethodInfo runtimeMethodInfo = ModuleHandle::ResolveMethodHandleInternal(GetNativeHandle(), metadataToken2, typeInstantiationContext, methodInstantiationContext);
    Type type = RuntimeMethodHandle::GetDeclaringType(runtimeMethodInfo);
    if (type->get_IsGenericType() || type->get_IsArray()) {
      MetadataToken token = MetadataToken(get_MetadataImport().GetParentToken(metadataToken2));
      if (metadataToken2.get_IsMethodSpec()) {
        token = MetadataToken(get_MetadataImport().GetParentToken(token));
      }
      type = ResolveType(token, genericTypeArguments, genericMethodArguments);
    }
    return RuntimeType::in::GetMethodBase(rt::as<RuntimeType>(type), runtimeMethodInfo);
  } catch (BadImageFormatException innerException) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadImageFormatExceptionResolve(), innerException);
  }
}

FieldInfo RuntimeModule___::ResolveLiteralField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (!get_MetadataImport().IsValidToken(metadataToken2) || !metadataToken2.get_IsFieldDef()) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  String name = get_MetadataImport().GetName(metadataToken2).ToString();
  Int32 parentToken = get_MetadataImport().GetParentToken(metadataToken2);
  Type type = ResolveType(parentToken, genericTypeArguments, genericMethodArguments);
  type->GetFields();
  try {
    return type->GetField(name, BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
  } catch (...) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveField(), metadataToken2, (RuntimeModule)this), "metadataToken");
  }
}

FieldInfo RuntimeModule___::ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (!get_MetadataImport().IsValidToken(metadataToken2)) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  Array<RuntimeTypeHandle> typeInstantiationContext = ConvertToTypeHandleArray(genericTypeArguments);
  Array<RuntimeTypeHandle> methodInstantiationContext = ConvertToTypeHandleArray(genericMethodArguments);
  try {
    IRuntimeFieldInfo runtimeFieldInfo;
    if (!metadataToken2.get_IsFieldDef()) {
      if (!metadataToken2.get_IsMemberRef()) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveField(), metadataToken2, (RuntimeModule)this), "metadataToken");
      }
      if (*(Byte*)get_MetadataImport().GetMemberRefProps(metadataToken2).get_Signature().ToPointer() != 6) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveField(), metadataToken2, (RuntimeModule)this), "metadataToken");
      }
      runtimeFieldInfo = ModuleHandle::ResolveFieldHandleInternal(GetNativeHandle(), metadataToken2, typeInstantiationContext, methodInstantiationContext);
    }
    runtimeFieldInfo = ModuleHandle::ResolveFieldHandleInternal(GetNativeHandle(), metadataToken, typeInstantiationContext, methodInstantiationContext);
    RuntimeType runtimeType = RuntimeFieldHandle::GetApproxDeclaringType(runtimeFieldInfo->get_Value());
    if (runtimeType->get_IsGenericType() || runtimeType->get_IsArray()) {
      Int32 parentToken = ModuleHandle::GetMetadataImport(GetNativeHandle()).GetParentToken(metadataToken);
      runtimeType = (RuntimeType)ResolveType(parentToken, genericTypeArguments, genericMethodArguments);
    }
    return RuntimeType::in::GetFieldInfo(runtimeType, runtimeFieldInfo);
  } catch (MissingFieldException) {
    return ResolveLiteralField(metadataToken2, genericTypeArguments, genericMethodArguments);
  } catch (BadImageFormatException innerException) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadImageFormatExceptionResolve(), innerException);
  }
}

Type RuntimeModule___::ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (metadataToken2.get_IsGlobalTypeDefToken()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveModuleType(), metadataToken2), "metadataToken");
  }
  if (!get_MetadataImport().IsValidToken(metadataToken2)) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  if (!metadataToken2.get_IsTypeDef() && !metadataToken2.get_IsTypeSpec() && !metadataToken2.get_IsTypeRef()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveType(), metadataToken2, (RuntimeModule)this), "metadataToken");
  }
  Array<RuntimeTypeHandle> typeInstantiationContext = ConvertToTypeHandleArray(genericTypeArguments);
  Array<RuntimeTypeHandle> methodInstantiationContext = ConvertToTypeHandleArray(genericMethodArguments);
  try {
    Type runtimeType = GetModuleHandleImpl().ResolveTypeHandle(metadataToken, typeInstantiationContext, methodInstantiationContext).GetRuntimeType();
    if (runtimeType == nullptr) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveType(), metadataToken2, (RuntimeModule)this), "metadataToken");
    }
    return runtimeType;
  } catch (BadImageFormatException innerException) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadImageFormatExceptionResolve(), innerException);
  }
}

MemberInfo RuntimeModule___::ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (metadataToken2.get_IsProperty()) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_PropertyInfoNotAvailable());
  }
  if (metadataToken2.get_IsEvent()) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_EventInfoNotAvailable());
  }
  if (metadataToken2.get_IsMethodSpec() || metadataToken2.get_IsMethodDef()) {
    return ResolveMethod(metadataToken, genericTypeArguments, genericMethodArguments);
  }
  if (metadataToken2.get_IsFieldDef()) {
    return ResolveField(metadataToken, genericTypeArguments, genericMethodArguments);
  }
  if (metadataToken2.get_IsTypeRef() || metadataToken2.get_IsTypeDef() || metadataToken2.get_IsTypeSpec()) {
    return ResolveType(metadataToken, genericTypeArguments, genericMethodArguments);
  }
  if (metadataToken2.get_IsMemberRef()) {
    if (!get_MetadataImport().IsValidToken(metadataToken2)) {
      rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
    }
    if (*(Byte*)get_MetadataImport().GetMemberRefProps(metadataToken2).get_Signature().ToPointer() == 6) {
      return ResolveField(metadataToken2, genericTypeArguments, genericMethodArguments);
    }
    return ResolveMethod(metadataToken2, genericTypeArguments, genericMethodArguments);
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveMember(), metadataToken2, (RuntimeModule)this), "metadataToken");
}

String RuntimeModule___::ResolveString(Int32 metadataToken) {
  MetadataToken metadataToken2 = MetadataToken(metadataToken);
  if (!metadataToken2.get_IsString()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveString(), metadataToken, (RuntimeModule)this));
  }
  if (!get_MetadataImport().IsValidToken(metadataToken2)) {
    rt::throw_exception<ArgumentOutOfRangeException>("metadataToken", SR::Format(SR::get_Argument_InvalidToken(), metadataToken2, (RuntimeModule)this));
  }
  String userString = get_MetadataImport().GetUserString(metadataToken);
  if (userString == nullptr) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveString(), metadataToken, (RuntimeModule)this));
  }
  return userString;
}

void RuntimeModule___::GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine) {
  ModuleHandle::GetPEKind(GetNativeHandle(), peKind, machine);
}

MethodInfo RuntimeModule___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethodInternal(name, bindingAttr, binder, callConvention, types, modifiers);
}

MethodInfo RuntimeModule___::GetMethodInternal(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (get_RuntimeType() == nullptr) {
    return nullptr;
  }
  if (types == nullptr) {
    return get_RuntimeType()->GetMethod(name, bindingAttr);
  }
  return get_RuntimeType()->GetMethod(name, bindingAttr, binder, callConvention, types, modifiers);
}

Boolean RuntimeModule___::IsTransientInternal() {
  RuntimeModule module = (RuntimeModule)this;
  return nIsTransientInternal(QCallModule(module));
}

Array<Object> RuntimeModule___::GetCustomAttributes(Boolean inherit) {
  return CustomAttribute::GetCustomAttributes((RuntimeModule)this, rt::as<RuntimeType>(typeof<Object>()));
}

Array<Object> RuntimeModule___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeModule)this, runtimeType);
}

Boolean RuntimeModule___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeModule)this, runtimeType);
}

IList<CustomAttributeData> RuntimeModule___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeModule)this);
}

void RuntimeModule___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Type RuntimeModule___::GetType(String className, Boolean throwOnError, Boolean ignoreCase) {
  if (className == nullptr) {
    rt::throw_exception<ArgumentNullException>("className");
  }
  RuntimeType o = nullptr;
  Object o2 = nullptr;
  RuntimeModule module = (RuntimeModule)this;
  GetType(QCallModule(module), className, throwOnError, ignoreCase, ObjectHandleOnStack::Create(o), ObjectHandleOnStack::Create(o2));
  GC::KeepAlive(o2);
  return o;
}

String RuntimeModule___::GetFullyQualifiedName() {
  String s = nullptr;
  RuntimeModule module = (RuntimeModule)this;
  GetFullyQualifiedName(QCallModule(module), StringHandleOnStack(s));
  return s;
}

Array<Type> RuntimeModule___::GetTypes() {
  return GetTypes(GetNativeHandle());
}

Boolean RuntimeModule___::IsResource() {
  return IsResource(GetNativeHandle());
}

Array<FieldInfo> RuntimeModule___::GetFields(BindingFlags bindingFlags) {
  if (get_RuntimeType() == nullptr) {
    return Array<>::in::Empty<FieldInfo>();
  }
  return get_RuntimeType()->GetFields(bindingFlags);
}

FieldInfo RuntimeModule___::GetField(String name, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (get_RuntimeType() == nullptr) {
    return nullptr;
  }
  return get_RuntimeType()->GetField(name, bindingAttr);
}

Array<MethodInfo> RuntimeModule___::GetMethods(BindingFlags bindingFlags) {
  if (get_RuntimeType() == nullptr) {
    return Array<>::in::Empty<MethodInfo>();
  }
  return get_RuntimeType()->GetMethods(bindingFlags);
}

RuntimeAssembly RuntimeModule___::GetRuntimeAssembly() {
  return m_runtimeAssembly;
}

ModuleHandle RuntimeModule___::GetModuleHandleImpl() {
  return ModuleHandle((RuntimeModule)this);
}

RuntimeModule RuntimeModule___::GetNativeHandle() {
  return (RuntimeModule)this;
}

IntPtr RuntimeModule___::GetUnderlyingNativeHandle() {
  return m_pData;
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeModuleNamespace
