#include "RuntimeType-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgIterator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/CtorDelegate-dep.h>
#include <System.Private.CoreLib/System/DefaultBinder-dep.h>
#include <System.Private.CoreLib/System/Empty-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IConvertible.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MdUtf8String-dep.h>
#include <System.Private.CoreLib/System/MissingFieldException-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Reflection/AmbiguousMatchException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/ConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeData-dep.h>
#include <System.Private.CoreLib/System/Reflection/DefaultMemberAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/LoaderAllocator-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Pointer-dep.h>
#include <System.Private.CoreLib/System/Reflection/PseudoCustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureConstructedGenericType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureTypeExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetInvocationException-dep.h>
#include <System.Private.CoreLib/System/Resolver-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallTypeHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/BStrWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CurrencyWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DispatchWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ErrorWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/UnknownWrapper-dep.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/SystemException-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Monitor-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypedReference-dep.h>
#include <System.Private.CoreLib/System/TypeLoadException-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::RuntimeTypeNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

RuntimeType___::RuntimeTypeCache___::Filter::Filter(Byte* pUtf8Name, Int32 cUtf8Name, MemberListType listType) {
  m_name = MdUtf8String(pUtf8Name, cUtf8Name);
  m_listType = listType;
  m_nameHash = 0u;
  if (RequiresStringComparison()) {
    m_nameHash = m_name.HashCaseInsensitive();
  }
}

Boolean RuntimeType___::RuntimeTypeCache___::Filter::Match(MdUtf8String name) {
  Boolean result = true;
  if (m_listType == MemberListType::CaseSensitive) {
    result = m_name.Equals(name);
  } else if (m_listType == MemberListType::CaseInsensitive) {
    result = m_name.EqualsCaseInsensitive(name);
  }

  return result;
}

Boolean RuntimeType___::RuntimeTypeCache___::Filter::RequiresStringComparison() {
  if (m_listType != MemberListType::CaseSensitive) {
    return m_listType == MemberListType::CaseInsensitive;
  }
  return true;
}

Boolean RuntimeType___::RuntimeTypeCache___::Filter::CaseSensitive() {
  return m_listType == MemberListType::CaseSensitive;
}

UInt32 RuntimeType___::RuntimeTypeCache___::Filter::GetHashToMatch() {
  return m_nameHash;
}

Object RuntimeType___::RuntimeTypeCache___::get_GenericCache() {
  return m_genericCache;
}

void RuntimeType___::RuntimeTypeCache___::set_GenericCache(Object value) {
  m_genericCache = value;
}

Boolean RuntimeType___::RuntimeTypeCache___::get_DomainInitialized() {
  return m_bIsDomainInitialized;
}

void RuntimeType___::RuntimeTypeCache___::set_DomainInitialized(Boolean value) {
  m_bIsDomainInitialized = value;
}

TypeCode RuntimeType___::RuntimeTypeCache___::get_TypeCode() {
  return m_typeCode;
}

void RuntimeType___::RuntimeTypeCache___::set_TypeCode(TypeCode value) {
  m_typeCode = value;
}

Boolean RuntimeType___::RuntimeTypeCache___::get_IsGlobal() {
  return m_isGlobal;
}

void RuntimeType___::RuntimeTypeCache___::ctor(RuntimeType runtimeType) {
  m_typeCode = TypeCode::Empty;
  m_runtimeType = runtimeType;
  m_isGlobal = (RuntimeTypeHandle::GetModule(runtimeType)->get_RuntimeType() == runtimeType);
}

String RuntimeType___::RuntimeTypeCache___::ConstructName(String& name, TypeNameFormatFlags formatFlags) {
  String as = name;
  return as != nullptr ? as : (name = RuntimeTypeHandle(m_runtimeType).ConstructName(formatFlags));
}

String RuntimeType___::RuntimeTypeCache___::GetName(TypeNameKind kind) {
  switch (kind) {
    case TypeNameKind::Name:
      return ConstructName(m_name, TypeNameFormatFlags::FormatBasic);
    case TypeNameKind::FullName:
      if (!m_runtimeType->GetRootElementType()->get_IsGenericTypeDefinition() && m_runtimeType->get_ContainsGenericParameters()) {
        return nullptr;
      }
      return ConstructName(m_fullname, (TypeNameFormatFlags)3);
    case TypeNameKind::ToString:
      return ConstructName(m_toString, TypeNameFormatFlags::FormatNamespace);
    default:
      rt::throw_exception<InvalidOperationException>();
  }
}

String RuntimeType___::RuntimeTypeCache___::GetNameSpace() {
  if (m_namespace == nullptr) {
    Type runtimeType = m_runtimeType;
    runtimeType = runtimeType->GetRootElementType();
    while (runtimeType->get_IsNested()) {
      runtimeType = runtimeType->get_DeclaringType();
    }
    m_namespace = RuntimeTypeHandle::GetMetadataImport((RuntimeType)runtimeType).GetNamespace(runtimeType->get_MetadataToken()).ToString();
  }
  return m_namespace;
}

RuntimeType RuntimeType___::RuntimeTypeCache___::GetEnclosingType() {
  if (m_enclosingType == nullptr) {
    RuntimeType declaringType = RuntimeTypeHandle::GetDeclaringType(GetRuntimeType());
    RuntimeType as = declaringType;
    m_enclosingType = (as != nullptr ? as : ((RuntimeType)typeof<void>()));
  }
  if (!(m_enclosingType == typeof<void>())) {
    return m_enclosingType;
  }
  return nullptr;
}

RuntimeType RuntimeType___::RuntimeTypeCache___::GetRuntimeType() {
  return m_runtimeType;
}

void RuntimeType___::RuntimeTypeCache___::InvalidateCachedNestedType() {
  m_nestedClassesCache = nullptr;
}

String RuntimeType___::RuntimeTypeCache___::GetDefaultMemberName() {
  if (m_defaultMemberName == nullptr) {
    CustomAttributeData customAttributeData = nullptr;
    Type typeFromHandle = typeof<DefaultMemberAttribute>();
    RuntimeType runtimeType = m_runtimeType;
    while (runtimeType != nullptr) {
      IList<CustomAttributeData> customAttributes = CustomAttributeData::in::GetCustomAttributes(runtimeType);
      for (Int32 i = 0; i < customAttributes->get_Count(); i++) {
        if ((Object)customAttributes[i]->get_Constructor()->get_DeclaringType() == typeFromHandle) {
          customAttributeData = customAttributes[i];
          break;
        }
      }
      if (customAttributeData != nullptr) {
        m_defaultMemberName = (rt::as<String>(customAttributeData->get_ConstructorArguments()[0].get_Value()));
        break;
      }
      runtimeType = runtimeType->GetBaseType();
    }
  }
  return m_defaultMemberName;
}

Array<Object> RuntimeType___::RuntimeTypeCache___::GetEmptyArray() {
  Array<Object> as = _emptyArray;
  return as != nullptr ? as : (_emptyArray = (Array<Object>)Array<>::in::CreateInstance(m_runtimeType, 0));
}

MethodInfo RuntimeType___::RuntimeTypeCache___::GetGenericMethodInfo(RuntimeMethodHandleInternal genericMethod) {
  LoaderAllocator loaderAllocator = RuntimeMethodHandle::GetLoaderAllocator(genericMethod);
  RuntimeMethodInfo runtimeMethodInfo = rt::newobj<RuntimeMethodInfo>(genericMethod, RuntimeMethodHandle::GetDeclaringType(genericMethod), (RuntimeTypeCache)this, RuntimeMethodHandle::GetAttributes(genericMethod), (BindingFlags)(-1), loaderAllocator);
  RuntimeMethodInfo runtimeMethodInfo2 = (loaderAllocator == nullptr) ? s_methodInstantiations[runtimeMethodInfo] : loaderAllocator->m_methodInstantiations[runtimeMethodInfo];
  if (runtimeMethodInfo2 != nullptr) {
    return runtimeMethodInfo2;
  }
  if (s_methodInstantiationsLock == nullptr) {
    Interlocked::CompareExchange(s_methodInstantiationsLock, rt::newobj<Object>(), nullptr);
  }
  Boolean lockTaken = false;
  try {
    Monitor::Enter(s_methodInstantiationsLock, lockTaken);
    if (loaderAllocator != nullptr) {
      runtimeMethodInfo2 = loaderAllocator->m_methodInstantiations[runtimeMethodInfo];
      if (runtimeMethodInfo2 != nullptr) {
        return runtimeMethodInfo2;
      }
      loaderAllocator->m_methodInstantiations[runtimeMethodInfo] = runtimeMethodInfo;
      return runtimeMethodInfo;
    }
    runtimeMethodInfo2 = s_methodInstantiations[runtimeMethodInfo];
    if (runtimeMethodInfo2 != nullptr) {
      return runtimeMethodInfo2;
    }
    s_methodInstantiations[runtimeMethodInfo] = runtimeMethodInfo;
    return runtimeMethodInfo;
  } catch (...) {
  } finally: {
    if (lockTaken) {
      Monitor::Exit(s_methodInstantiationsLock);
    }
  }
}

Array<RuntimeMethodInfo> RuntimeType___::RuntimeTypeCache___::GetMethodList(MemberListType listType, String name) {
  return GetMemberList(m_methodInfoCache, listType, name, CacheType::Method);
}

Array<RuntimeConstructorInfo> RuntimeType___::RuntimeTypeCache___::GetConstructorList(MemberListType listType, String name) {
  return GetMemberList(m_constructorInfoCache, listType, name, CacheType::Constructor);
}

Array<RuntimePropertyInfo> RuntimeType___::RuntimeTypeCache___::GetPropertyList(MemberListType listType, String name) {
  return GetMemberList(m_propertyInfoCache, listType, name, CacheType::Property);
}

Array<RuntimeEventInfo> RuntimeType___::RuntimeTypeCache___::GetEventList(MemberListType listType, String name) {
  return GetMemberList(m_eventInfoCache, listType, name, CacheType::Event);
}

Array<RuntimeFieldInfo> RuntimeType___::RuntimeTypeCache___::GetFieldList(MemberListType listType, String name) {
  return GetMemberList(m_fieldInfoCache, listType, name, CacheType::Field);
}

Array<RuntimeType> RuntimeType___::RuntimeTypeCache___::GetInterfaceList(MemberListType listType, String name) {
  return GetMemberList(m_interfaceCache, listType, name, CacheType::Interface);
}

Array<RuntimeType> RuntimeType___::RuntimeTypeCache___::GetNestedTypeList(MemberListType listType, String name) {
  return GetMemberList(m_nestedClassesCache, listType, name, CacheType::NestedType);
}

MethodBase RuntimeType___::RuntimeTypeCache___::GetMethod(RuntimeType declaringType, RuntimeMethodHandleInternal method) {
  GetMemberCache(m_methodInfoCache);
  return m_methodInfoCache->AddMethod(declaringType, method, CacheType::Method);
}

MethodBase RuntimeType___::RuntimeTypeCache___::GetConstructor(RuntimeType declaringType, RuntimeMethodHandleInternal constructor) {
  GetMemberCache(m_constructorInfoCache);
  return m_constructorInfoCache->AddMethod(declaringType, constructor, CacheType::Constructor);
}

FieldInfo RuntimeType___::RuntimeTypeCache___::GetField(RuntimeFieldHandleInternal field) {
  GetMemberCache(m_fieldInfoCache);
  return m_fieldInfoCache->AddField(field);
}

void RuntimeType___::ActivatorCache___::ctor(RuntimeMethodHandleInternal rmh) {
  _hCtorMethodHandle = rmh;
}

void RuntimeType___::ActivatorCache___::Initialize() {
  if (!_hCtorMethodHandle.IsNullHandle()) {
    _ctorAttributes = RuntimeMethodHandle::GetAttributes(_hCtorMethodHandle);
    ConstructorInfo as = s_delegateCtorInfo;
    ConstructorInfo constructorInfo = as != nullptr ? as : (s_delegateCtorInfo = typeof<CtorDelegate>()->GetConstructor(rt::newarr<Array<Type>>(2)));
    _ctor = &(CtorDelegate)constructorInfo->Invoke(rt::newarr<Array<Object>>(2));
  }
  _isFullyInitialized = true;
}

void RuntimeType___::ActivatorCache___::EnsureInitialized() {
  if (!_isFullyInitialized) {
    Initialize();
  }
}

Object RuntimeType___::get_GenericCache() {
  RuntimeTypeCache cacheIfExists = get_CacheIfExists();
  if (cacheIfExists == nullptr) {
    return nullptr;
  }
  return cacheIfExists->get_GenericCache();
}

void RuntimeType___::set_GenericCache(Object value) {
  get_Cache()->set_GenericCache(value);
}

Boolean RuntimeType___::get_DomainInitialized() {
  return get_Cache()->get_DomainInitialized();
}

void RuntimeType___::set_DomainInitialized(Boolean value) {
  get_Cache()->set_DomainInitialized(value);
}

RuntimeType::in::RuntimeTypeCache RuntimeType___::get_CacheIfExists() {
  if (m_cache != IntPtr::Zero) {
    Object value = GCHandle::InternalGet(m_cache);
    return Unsafe::As<RuntimeTypeCache>(value);
  }
  return nullptr;
}

RuntimeType::in::RuntimeTypeCache RuntimeType___::get_Cache() {
  if (m_cache != IntPtr::Zero) {
    Object obj = GCHandle::InternalGet(m_cache);
    if (obj != nullptr) {
      return Unsafe::As<RuntimeTypeCache>(obj);
    }
  }
  return InitializeCache();
}

Boolean RuntimeType___::get_IsCollectible() {
  RuntimeType type = (RuntimeType)this;
  return RuntimeTypeHandle::IsCollectible(QCallTypeHandle(type)) != Interop::BOOL::FALSE;
}

MethodBase RuntimeType___::get_DeclaringMethod() {
  if (!get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  IRuntimeMethodInfo declaringMethod = RuntimeTypeHandle::GetDeclaringMethod((RuntimeType)this);
  if (declaringMethod == nullptr) {
    return nullptr;
  }
  return GetMethodBase(RuntimeMethodHandle::GetDeclaringType(declaringMethod), declaringMethod);
}

String RuntimeType___::get_FullName() {
  return GetCachedName(TypeNameKind::FullName);
}

String RuntimeType___::get_AssemblyQualifiedName() {
  String fullName = get_FullName();
  if (fullName == nullptr) {
    return nullptr;
  }
  return Assembly::in::CreateQualifiedName(get_Assembly()->get_FullName(), fullName);
}

String RuntimeType___::get_Namespace() {
  String nameSpace = get_Cache()->GetNameSpace();
  if (String::in::IsNullOrEmpty(nameSpace)) {
    return nullptr;
  }
  return nameSpace;
}

Guid RuntimeType___::get_GUID() {
  Guid result = Guid();
  GetGUID(result);
  return result;
}

GenericParameterAttributes RuntimeType___::get_GenericParameterAttributes() {
  if (!get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  GenericParameterAttributes attributes;
  RuntimeTypeHandle::GetMetadataImport((RuntimeType)this).GetGenericParamProps(get_MetadataToken(), attributes);
  return attributes;
}

Boolean RuntimeType___::get_IsSZArray() {
  return RuntimeTypeHandle::IsSZArray((RuntimeType)this);
}

Int32 RuntimeType___::get_GenericParameterPosition() {
  if (!get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  return RuntimeTypeHandle((RuntimeType)this).GetGenericVariableIndex();
}

Boolean RuntimeType___::get_ContainsGenericParameters() {
  return GetRootElementType()->GetTypeHandleInternal().ContainsGenericVariables();
}

StructLayoutAttribute RuntimeType___::get_StructLayoutAttribute() {
  return PseudoCustomAttribute::GetStructLayoutCustomAttribute((RuntimeType)this);
}

String RuntimeType___::get_Name() {
  return GetCachedName(TypeNameKind::Name);
}

Type RuntimeType___::get_DeclaringType() {
  return get_Cache()->GetEnclosingType();
}

OleAutBinder RuntimeType___::get_ForwardCallBinder() {
  OleAutBinder as = s_ForwardCallBinder;
  return as != nullptr ? as : (s_ForwardCallBinder = rt::newobj<OleAutBinder>());
}

Assembly RuntimeType___::get_Assembly() {
  return RuntimeTypeHandle::GetAssembly((RuntimeType)this);
}

Type RuntimeType___::get_BaseType() {
  return GetBaseType();
}

Boolean RuntimeType___::get_IsByRefLike() {
  return RuntimeTypeHandle::IsByRefLike((RuntimeType)this);
}

Boolean RuntimeType___::get_IsConstructedGenericType() {
  if (get_IsGenericType()) {
    return !get_IsGenericTypeDefinition();
  }
  return false;
}

Boolean RuntimeType___::get_IsGenericType() {
  return RuntimeTypeHandle::HasInstantiation((RuntimeType)this);
}

Boolean RuntimeType___::get_IsGenericTypeDefinition() {
  return RuntimeTypeHandle::IsGenericTypeDefinition((RuntimeType)this);
}

Boolean RuntimeType___::get_IsGenericParameter() {
  return RuntimeTypeHandle::IsGenericVariable((RuntimeType)this);
}

Boolean RuntimeType___::get_IsTypeDefinition() {
  return RuntimeTypeHandle::IsTypeDefinition((RuntimeType)this);
}

Boolean RuntimeType___::get_IsSecurityCritical() {
  return true;
}

Boolean RuntimeType___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean RuntimeType___::get_IsSecurityTransparent() {
  return false;
}

MemberTypes RuntimeType___::get_MemberType() {
  if (!Type::in::get_IsPublic() && !Type::in::get_IsNotPublic()) {
    return MemberTypes::NestedType;
  }
  return MemberTypes::TypeInfo;
}

Int32 RuntimeType___::get_MetadataToken() {
  return RuntimeTypeHandle::GetToken((RuntimeType)this);
}

Module RuntimeType___::get_Module() {
  return GetRuntimeModule();
}

Type RuntimeType___::get_ReflectedType() {
  return get_DeclaringType();
}

RuntimeTypeHandle RuntimeType___::get_TypeHandle() {
  return RuntimeTypeHandle((RuntimeType)this);
}

Type RuntimeType___::get_UnderlyingSystemType() {
  return (RuntimeType)this;
}

RuntimeType RuntimeType___::GetType(String typeName, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  if (typeName == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeName");
  }
  return RuntimeTypeHandle::GetTypeByName(typeName, throwOnError, ignoreCase, stackMark);
}

MethodBase RuntimeType___::GetMethodBase(RuntimeModule scope, Int32 typeMetadataToken) {
  return GetMethodBase(ModuleHandle::ResolveMethodHandleInternal(scope, typeMetadataToken));
}

MethodBase RuntimeType___::GetMethodBase(IRuntimeMethodInfo methodHandle) {
  return GetMethodBase(nullptr, methodHandle);
}

MethodBase RuntimeType___::GetMethodBase(RuntimeType reflectedType, IRuntimeMethodInfo methodHandle) {
  MethodBase methodBase = GetMethodBase(reflectedType, methodHandle->get_Value());
  GC::KeepAlive(methodHandle);
  return methodBase;
}

MethodBase RuntimeType___::GetMethodBase(RuntimeType reflectedType, RuntimeMethodHandleInternal methodHandle) {
  if (RuntimeMethodHandle::IsDynamicMethod(methodHandle)) {
    Resolver resolver = RuntimeMethodHandle::GetResolver(methodHandle);
    if (resolver != nullptr) {
      return resolver->GetDynamicMethod();
    }
    return nullptr;
  }
  RuntimeType runtimeType = RuntimeMethodHandle::GetDeclaringType(methodHandle);
  Array<RuntimeType> array = nullptr;
  if ((Object)reflectedType == nullptr) {
    reflectedType = runtimeType;
  }
  if (reflectedType != runtimeType && !reflectedType->IsSubclassOf(runtimeType)) {
    if (reflectedType->get_IsArray()) {
      Array<MethodBase> array2 = rt::as<Array<MethodBase>>(reflectedType->GetMember(RuntimeMethodHandle::GetName(methodHandle), MemberTypes::Constructor | MemberTypes::Method, BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic));
      Boolean flag = false;
      for (Int32 i = 0; i < array2->get_Length(); i++) {
        IRuntimeMethodInfo runtimeMethodInfo = (IRuntimeMethodInfo)array2[i];
        if (runtimeMethodInfo->get_Value().get_Value() == methodHandle.get_Value()) {
          flag = true;
        }
      }
      if (!flag) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveMethodHandle(), reflectedType, runtimeType));
      }
    } else if (runtimeType->get_IsGenericType()) {
      RuntimeType right = (RuntimeType)runtimeType->GetGenericTypeDefinition();
      RuntimeType runtimeType2 = reflectedType;
      while (runtimeType2 != nullptr) {
        RuntimeType runtimeType3 = runtimeType2;
        if (runtimeType3->get_IsGenericType() && !runtimeType2->get_IsGenericTypeDefinition()) {
          runtimeType3 = (RuntimeType)runtimeType3->GetGenericTypeDefinition();
        }
        if (runtimeType3 == right) {
          break;
        }
        runtimeType2 = runtimeType2->GetBaseType();
      }
      if (runtimeType2 == nullptr) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveMethodHandle(), reflectedType, runtimeType));
      }
      runtimeType = runtimeType2;
      if (!RuntimeMethodHandle::IsGenericMethodDefinition(methodHandle)) {
        array = RuntimeMethodHandle::GetMethodInstantiationInternal(methodHandle);
      }
      methodHandle = RuntimeMethodHandle::GetMethodFromCanonical(methodHandle, runtimeType);
    } else if (!runtimeType->IsAssignableFrom(reflectedType)) {
      rt::throw_exception<ArgumentException>(String::in::Format(CultureInfo::in::get_CurrentCulture(), SR::get_Argument_ResolveMethodHandle(), reflectedType->ToString(), runtimeType->ToString()));
    }


  }
  methodHandle = RuntimeMethodHandle::GetStubIfNeeded(methodHandle, runtimeType, array);
  MethodBase result = RuntimeMethodHandle::IsConstructor(methodHandle) ? reflectedType->get_Cache()->GetConstructor(runtimeType, methodHandle) : ((!RuntimeMethodHandle::HasMethodInstantiation(methodHandle) || RuntimeMethodHandle::IsGenericMethodDefinition(methodHandle)) ? reflectedType->get_Cache()->GetMethod(runtimeType, methodHandle) : reflectedType->get_Cache()->GetGenericMethodInfo(methodHandle));
  GC::KeepAlive(array);
  return result;
}

FieldInfo RuntimeType___::GetFieldInfo(IRuntimeFieldInfo fieldHandle) {
  return GetFieldInfo(RuntimeFieldHandle::GetApproxDeclaringType(fieldHandle), fieldHandle);
}

FieldInfo RuntimeType___::GetFieldInfo(RuntimeType reflectedType, IRuntimeFieldInfo field) {
  RuntimeFieldHandleInternal value = field->get_Value();
  if (reflectedType == nullptr) {
    reflectedType = RuntimeFieldHandle::GetApproxDeclaringType(value);
  } else {
    RuntimeType approxDeclaringType = RuntimeFieldHandle::GetApproxDeclaringType(value);
    if (reflectedType != approxDeclaringType && (!RuntimeFieldHandle::AcquiresContextFromThis(value) || !RuntimeTypeHandle::CompareCanonicalHandles(approxDeclaringType, reflectedType))) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResolveFieldHandle(), reflectedType, approxDeclaringType));
    }
  }
  FieldInfo field2 = reflectedType->get_Cache()->GetField(value);
  GC::KeepAlive(field);
  return field2;
}

PropertyInfo RuntimeType___::GetPropertyInfo(RuntimeType reflectedType, Int32 tkProperty) {
  Array<RuntimePropertyInfo> propertyList = reflectedType->get_Cache()->GetPropertyList(MemberListType::All, nullptr);
  for (RuntimePropertyInfo& runtimePropertyInfo : propertyList) {
    if (runtimePropertyInfo->get_MetadataToken() == tkProperty) {
      return runtimePropertyInfo;
    }
  }
  rt::throw_exception<SystemException>();
}

void RuntimeType___::ThrowIfTypeNeverValidGenericArgument(RuntimeType type) {
  if (type->get_IsPointer() || type->get_IsByRef() || type == typeof<void>()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_NeverValidGenericArgument(), type));
  }
}

void RuntimeType___::SanityCheckGenericArguments(Array<RuntimeType> genericArguments, Array<RuntimeType> genericParamters) {
  if (genericArguments == nullptr) {
    rt::throw_exception<ArgumentNullException>();
  }
  for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
    if (genericArguments[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>();
    }
    ThrowIfTypeNeverValidGenericArgument(genericArguments[i]);
  }
  if (genericArguments->get_Length() != genericParamters->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_NotEnoughGenArguments(), genericArguments->get_Length(), genericParamters->get_Length()));
  }
}

void RuntimeType___::ValidateGenericArguments(MemberInfo definition, Array<RuntimeType> genericArguments, Exception e) {
  Array<RuntimeType> typeContext = nullptr;
  Array<RuntimeType> methodContext = nullptr;
  Array<RuntimeType> genericArgumentsInternal;
  if (rt::is<Type>(definition)) {
    RuntimeType runtimeType = (RuntimeType)definition;
    genericArgumentsInternal = runtimeType->GetGenericArgumentsInternal();
    typeContext = genericArguments;
  } else {
    RuntimeMethodInfo runtimeMethodInfo = (RuntimeMethodInfo)definition;
    genericArgumentsInternal = runtimeMethodInfo->GetGenericArgumentsInternal();
    methodContext = genericArguments;
    RuntimeType runtimeType2 = (RuntimeType)runtimeMethodInfo->get_DeclaringType();
    if (runtimeType2 != nullptr) {
      typeContext = runtimeType2->GetTypeHandleInternal().GetInstantiationInternal();
    }
  }
  for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
    Type type = genericArguments[i];
    Type type2 = genericArgumentsInternal[i];
    if (!RuntimeTypeHandle::SatisfiesConstraints(type2->GetTypeHandleInternal().GetTypeChecked(), typeContext, methodContext, type->GetTypeHandleInternal().GetTypeChecked())) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_GenConstraintViolation(), rt::newarr<Array<Object>>(4, i.ToString(), type, definition, type2)), e);
    }
  }
}

void RuntimeType___::SplitName(String fullname, String& name, String& ns) {
  name = nullptr;
  ns = nullptr;
  if (fullname == nullptr) {
    return;
  }
  Int32 num = fullname->LastIndexOf(".", StringComparison::Ordinal);
  if (num != -1) {
    ns = fullname->Substring(0, num);
    Int32 num2 = fullname->get_Length() - ns->get_Length() - 1;
    if (num2 != 0) {
      name = fullname->Substring(num + 1, num2);
    } else {
      name = "";
    }
  } else {
    name = fullname;
  }
}

BindingFlags RuntimeType___::FilterPreCalculate(Boolean isPublic, Boolean isInherited, Boolean isStatic) {
  BindingFlags bindingFlags = isPublic ? BindingFlags::Public : BindingFlags::NonPublic;
  if (isInherited) {
    bindingFlags |= BindingFlags::DeclaredOnly;
    if (isStatic) {
      return bindingFlags | (BindingFlags::Static | BindingFlags::FlattenHierarchy);
    }
    return bindingFlags | BindingFlags::Instance;
  }
  if (isStatic) {
    return bindingFlags | BindingFlags::Static;
  }
  return bindingFlags | BindingFlags::Instance;
}

void RuntimeType___::FilterHelper(BindingFlags bindingFlags, String& name, Boolean allowPrefixLookup, Boolean& prefixLookup, Boolean& ignoreCase, MemberListType& listType) {
  prefixLookup = false;
  ignoreCase = false;
  if (name != nullptr) {
    if ((bindingFlags & BindingFlags::IgnoreCase) != 0) {
      name = name->ToLowerInvariant();
      ignoreCase = true;
      listType = MemberListType::CaseInsensitive;
    } else {
      listType = MemberListType::CaseSensitive;
    }
    if (allowPrefixLookup && name->EndsWith("*", StringComparison::Ordinal)) {
    }
  } else {
    listType = MemberListType::All;
  }
}

void RuntimeType___::FilterHelper(BindingFlags bindingFlags, String& name, Boolean& ignoreCase, MemberListType& listType) {
  Boolean prefixLookup;
  FilterHelper(bindingFlags, name, false, prefixLookup, ignoreCase, listType);
}

Boolean RuntimeType___::FilterApplyPrefixLookup(MemberInfo memberInfo, String name, Boolean ignoreCase) {
  if (ignoreCase) {
    if (!memberInfo->get_Name()->StartsWith(name, StringComparison::OrdinalIgnoreCase)) {
      return false;
    }
  } else if (!memberInfo->get_Name()->StartsWith(name, StringComparison::Ordinal)) {
    return false;
  }

  return true;
}

Boolean RuntimeType___::FilterApplyBase(MemberInfo memberInfo, BindingFlags bindingFlags, Boolean isPublic, Boolean isNonProtectedInternal, Boolean isStatic, String name, Boolean prefixLookup) {
  if (isPublic) {
    if ((bindingFlags & BindingFlags::Public) == 0) {
      return false;
    }
  } else if ((bindingFlags & BindingFlags::NonPublic) == 0) {
    return false;
  }

  Boolean flag = (Object)memberInfo->get_DeclaringType() != memberInfo->get_ReflectedType();
  if ((bindingFlags & BindingFlags::DeclaredOnly) != 0 && flag) {
    return false;
  }
  if (memberInfo->get_MemberType() != MemberTypes::TypeInfo && memberInfo->get_MemberType() != MemberTypes::NestedType) {
    if (isStatic) {
      if ((bindingFlags & BindingFlags::FlattenHierarchy) == 0 && flag) {
        return false;
      }
      if ((bindingFlags & BindingFlags::Static) == 0) {
        return false;
      }
    } else if ((bindingFlags & BindingFlags::Instance) == 0) {
      return false;
    }

  }
  if (prefixLookup && !FilterApplyPrefixLookup(memberInfo, name, (bindingFlags & BindingFlags::IgnoreCase) != 0)) {
    return false;
  }
  if ((bindingFlags & BindingFlags::DeclaredOnly) == 0 && flag && isNonProtectedInternal && (bindingFlags & BindingFlags::NonPublic) != 0 && !isStatic && (bindingFlags & BindingFlags::Instance) != 0) {
    MethodInfo methodInfo = rt::as<MethodInfo>(memberInfo);
    if (methodInfo == nullptr) {
      return false;
    }
    if (!methodInfo->get_IsVirtual() && !methodInfo->get_IsAbstract()) {
      return false;
    }
  }
  return true;
}

Boolean RuntimeType___::FilterApplyType(Type type, BindingFlags bindingFlags, String name, Boolean prefixLookup, String ns) {
  Boolean isPublic = type->get_IsNestedPublic() || type->get_IsPublic();
  if (!FilterApplyBase(type, bindingFlags, isPublic, type->get_IsNestedAssembly(), false, name, prefixLookup)) {
    return false;
  }
  if (ns != nullptr && ns != type->get_Namespace()) {
    return false;
  }
  return true;
}

Boolean RuntimeType___::FilterApplyMethodInfo(RuntimeMethodInfo method, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  return FilterApplyMethodBase(method, method->get_BindingFlags(), bindingFlags, callConv, argumentTypes);
}

Boolean RuntimeType___::FilterApplyConstructorInfo(RuntimeConstructorInfo constructor, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  return FilterApplyMethodBase(constructor, constructor->get_BindingFlags(), bindingFlags, callConv, argumentTypes);
}

Boolean RuntimeType___::FilterApplyMethodBase(MethodBase methodBase, BindingFlags methodFlags, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  bindingFlags ^= BindingFlags::DeclaredOnly;
  if ((bindingFlags & methodFlags) != methodFlags) {
    return false;
  }
  if ((callConv & CallingConventions::Any) == 0) {
    if ((callConv & CallingConventions::VarArgs) != 0 && (methodBase->get_CallingConvention() & CallingConventions::VarArgs) == 0) {
      return false;
    }
    if ((callConv & CallingConventions::Standard) != 0 && (methodBase->get_CallingConvention() & CallingConventions::Standard) == 0) {
      return false;
    }
  }
  if (argumentTypes != nullptr) {
    Array<ParameterInfo> parametersNoCopy = methodBase->GetParametersNoCopy();
    if (argumentTypes->get_Length() != parametersNoCopy->get_Length()) {
      if ((bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::CreateInstance | BindingFlags::GetProperty | BindingFlags::SetProperty)) == 0) {
        return false;
      }
      Boolean flag = false;
      if (argumentTypes->get_Length() > parametersNoCopy->get_Length()) {
        if ((methodBase->get_CallingConvention() & CallingConventions::VarArgs) == 0) {
          flag = true;
        }
      } else if ((bindingFlags & BindingFlags::OptionalParamBinding) == 0) {
        flag = true;
      } else if (!parametersNoCopy[argumentTypes->get_Length()]->get_IsOptional()) {
        flag = true;
      }


      if (flag) {
        if (parametersNoCopy->get_Length() == 0) {
          return false;
        }
        if (argumentTypes->get_Length() < parametersNoCopy->get_Length() - 1) {
          return false;
        }
      }
    } else if ((bindingFlags & BindingFlags::ExactBinding) != 0 && (bindingFlags & BindingFlags::InvokeMethod) == 0) {
      for (Int32 i = 0; i < parametersNoCopy->get_Length(); i++) {
        if ((Object)argumentTypes[i] != nullptr && !SignatureTypeExtensions::MatchesParameterTypeExactly(argumentTypes[i], parametersNoCopy[i])) {
          return false;
        }
      }
    }

  }
  return true;
}

void RuntimeType___::ctor() {
  rt::throw_exception<NotSupportedException>();
}

Boolean RuntimeType___::CacheEquals(Object o) {
  RuntimeType runtimeType = rt::as<RuntimeType>(o);
  if ((Object)runtimeType != nullptr) {
    return runtimeType->m_handle == m_handle;
  }
  return false;
}

RuntimeType::in::RuntimeTypeCache RuntimeType___::InitializeCache() {
  if (m_cache == IntPtr::Zero) {
    RuntimeTypeHandle runtimeTypeHandle = RuntimeTypeHandle((RuntimeType)this);
    IntPtr gCHandle = runtimeTypeHandle.GetGCHandle(GCHandleType::WeakTrackResurrection);
    IntPtr value = Interlocked::CompareExchange(m_cache, gCHandle, IntPtr::Zero);
    if (value != IntPtr::Zero) {
      runtimeTypeHandle.FreeGCHandle(gCHandle);
    }
  }
  RuntimeTypeCache runtimeTypeCache = (RuntimeTypeCache)GCHandle::InternalGet(m_cache);
  if (runtimeTypeCache == nullptr) {
    runtimeTypeCache = rt::newobj<RuntimeTypeCache>((RuntimeType)this);
    RuntimeTypeCache runtimeTypeCache2 = (RuntimeTypeCache)GCHandle::InternalCompareExchange(m_cache, runtimeTypeCache, nullptr);
    if (runtimeTypeCache2 != nullptr) {
      runtimeTypeCache = runtimeTypeCache2;
    }
  }
  return runtimeTypeCache;
}

String RuntimeType___::GetDefaultMemberName() {
  return get_Cache()->GetDefaultMemberName();
}

RuntimeType::in::ListBuilder<MethodInfo> RuntimeType___::GetMethodCandidates(String name, Int32 genericParameterCount, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup) {
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimeMethodInfo> methodList = get_Cache()->GetMethodList(listType, name);
  ListBuilder<MethodInfo> result = ListBuilder<MethodInfo>(methodList->get_Length());
  for (RuntimeMethodInfo& runtimeMethodInfo : methodList) {
    if ((genericParameterCount == -1 || genericParameterCount == runtimeMethodInfo->get_GenericParameterCount()) && FilterApplyMethodInfo(runtimeMethodInfo, bindingAttr, callConv, types) && (!prefixLookup || FilterApplyPrefixLookup(runtimeMethodInfo, name, ignoreCase))) {
      result.Add(runtimeMethodInfo);
    }
  }
  return result;
}

RuntimeType::in::ListBuilder<ConstructorInfo> RuntimeType___::GetConstructorCandidates(String name, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup) {
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimeConstructorInfo> constructorList = get_Cache()->GetConstructorList(listType, name);
  ListBuilder<ConstructorInfo> result = ListBuilder<ConstructorInfo>(constructorList->get_Length());
  for (RuntimeConstructorInfo& runtimeConstructorInfo : constructorList) {
    if (FilterApplyConstructorInfo(runtimeConstructorInfo, bindingAttr, callConv, types) && (!prefixLookup || FilterApplyPrefixLookup(runtimeConstructorInfo, name, ignoreCase))) {
      result.Add(runtimeConstructorInfo);
    }
  }
  return result;
}

RuntimeType::in::ListBuilder<PropertyInfo> RuntimeType___::GetPropertyCandidates(String name, BindingFlags bindingAttr, Array<Type> types, Boolean allowPrefixLookup) {
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimePropertyInfo> propertyList = get_Cache()->GetPropertyList(listType, name);
  bindingAttr ^= BindingFlags::DeclaredOnly;
  ListBuilder<PropertyInfo> result = ListBuilder<PropertyInfo>(propertyList->get_Length());
  for (RuntimePropertyInfo& runtimePropertyInfo : propertyList) {
    if ((bindingAttr & runtimePropertyInfo->get_BindingFlags()) == runtimePropertyInfo->get_BindingFlags() && (!prefixLookup || FilterApplyPrefixLookup(runtimePropertyInfo, name, ignoreCase)) && (types == nullptr || runtimePropertyInfo->GetIndexParameters()->get_Length() == types->get_Length())) {
      result.Add(runtimePropertyInfo);
    }
  }
  return result;
}

RuntimeType::in::ListBuilder<EventInfo> RuntimeType___::GetEventCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimeEventInfo> eventList = get_Cache()->GetEventList(listType, name);
  bindingAttr ^= BindingFlags::DeclaredOnly;
  ListBuilder<EventInfo> result = ListBuilder<EventInfo>(eventList->get_Length());
  for (RuntimeEventInfo& runtimeEventInfo : eventList) {
    if ((bindingAttr & runtimeEventInfo->get_BindingFlags()) == runtimeEventInfo->get_BindingFlags() && (!prefixLookup || FilterApplyPrefixLookup(runtimeEventInfo, name, ignoreCase))) {
      result.Add(runtimeEventInfo);
    }
  }
  return result;
}

RuntimeType::in::ListBuilder<FieldInfo> RuntimeType___::GetFieldCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimeFieldInfo> fieldList = get_Cache()->GetFieldList(listType, name);
  bindingAttr ^= BindingFlags::DeclaredOnly;
  ListBuilder<FieldInfo> result = ListBuilder<FieldInfo>(fieldList->get_Length());
  for (RuntimeFieldInfo& runtimeFieldInfo : fieldList) {
    if ((bindingAttr & runtimeFieldInfo->get_BindingFlags()) == runtimeFieldInfo->get_BindingFlags() && (!prefixLookup || FilterApplyPrefixLookup(runtimeFieldInfo, name, ignoreCase))) {
      result.Add(runtimeFieldInfo);
    }
  }
  return result;
}

RuntimeType::in::ListBuilder<Type> RuntimeType___::GetNestedTypeCandidates(String fullname, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  bindingAttr &= ~BindingFlags::Static;
  String name;
  String ns;
  SplitName(fullname, name, ns);
  Boolean prefixLookup;
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, allowPrefixLookup, prefixLookup, ignoreCase, listType);
  Array<RuntimeType> nestedTypeList = get_Cache()->GetNestedTypeList(listType, name);
  ListBuilder<Type> result = ListBuilder<Type>(nestedTypeList->get_Length());
  for (RuntimeType& runtimeType : nestedTypeList) {
    if (FilterApplyType(runtimeType, bindingAttr, name, prefixLookup, ns)) {
      result.Add(runtimeType);
    }
  }
  return result;
}

Array<MethodInfo> RuntimeType___::GetMethods(BindingFlags bindingAttr) {
  return GetMethodCandidates(nullptr, -1, bindingAttr, CallingConventions::Any, nullptr, false).ToArray();
}

Array<ConstructorInfo> RuntimeType___::GetConstructors(BindingFlags bindingAttr) {
  return GetConstructorCandidates(nullptr, bindingAttr, CallingConventions::Any, nullptr, false).ToArray();
}

Array<PropertyInfo> RuntimeType___::GetProperties(BindingFlags bindingAttr) {
  return GetPropertyCandidates(nullptr, bindingAttr, nullptr, false).ToArray();
}

Array<EventInfo> RuntimeType___::GetEvents(BindingFlags bindingAttr) {
  return GetEventCandidates(nullptr, bindingAttr, false).ToArray();
}

Array<FieldInfo> RuntimeType___::GetFields(BindingFlags bindingAttr) {
  return GetFieldCandidates(nullptr, bindingAttr, false).ToArray();
}

Array<Type> RuntimeType___::GetInterfaces() {
  Array<RuntimeType> interfaceList = get_Cache()->GetInterfaceList(MemberListType::All, nullptr);
  Array<Type> array = interfaceList;
  return ReadOnlySpan<Type>(array).ToArray();
}

Array<Type> RuntimeType___::GetNestedTypes(BindingFlags bindingAttr) {
  return GetNestedTypeCandidates(nullptr, bindingAttr, false).ToArray();
}

Array<MemberInfo> RuntimeType___::GetMembers(BindingFlags bindingAttr) {
  ListBuilder<MethodInfo> methodCandidates = GetMethodCandidates(nullptr, -1, bindingAttr, CallingConventions::Any, nullptr, false);
  ListBuilder<ConstructorInfo> constructorCandidates = GetConstructorCandidates(nullptr, bindingAttr, CallingConventions::Any, nullptr, false);
  ListBuilder<PropertyInfo> propertyCandidates = GetPropertyCandidates(nullptr, bindingAttr, nullptr, false);
  ListBuilder<EventInfo> eventCandidates = GetEventCandidates(nullptr, bindingAttr, false);
  ListBuilder<FieldInfo> fieldCandidates = GetFieldCandidates(nullptr, bindingAttr, false);
  ListBuilder<Type> nestedTypeCandidates = GetNestedTypeCandidates(nullptr, bindingAttr, false);
  Array<MemberInfo> array = rt::newarr<Array<MemberInfo>>(methodCandidates.get_Count() + constructorCandidates.get_Count() + propertyCandidates.get_Count() + eventCandidates.get_Count() + fieldCandidates.get_Count() + nestedTypeCandidates.get_Count());
  Int32 num = 0;
  Array<Object> array2 = array;
  methodCandidates.CopyTo(array2, num);
  num += methodCandidates.get_Count();
  array2 = array;
  constructorCandidates.CopyTo(array2, num);
  num += constructorCandidates.get_Count();
  array2 = array;
  propertyCandidates.CopyTo(array2, num);
  num += propertyCandidates.get_Count();
  array2 = array;
  eventCandidates.CopyTo(array2, num);
  num += eventCandidates.get_Count();
  array2 = array;
  fieldCandidates.CopyTo(array2, num);
  num += fieldCandidates.get_Count();
  array2 = array;
  nestedTypeCandidates.CopyTo(array2, num);
  num += nestedTypeCandidates.get_Count();
  return array;
}

InterfaceMapping RuntimeType___::GetInterfaceMap(Type ifaceType) {
  if (get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_GenericParameter());
  }
  if ((Object)ifaceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("ifaceType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(ifaceType);
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "ifaceType");
  }
  RuntimeTypeHandle typeHandleInternal = runtimeType->GetTypeHandleInternal();
  GetTypeHandleInternal().VerifyInterfaceIsImplemented(typeHandleInternal);
  if (get_IsSZArray() && ifaceType->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ArrayGetInterfaceMap());
  }
  Int32 numVirtuals = RuntimeTypeHandle::GetNumVirtuals(runtimeType);
  InterfaceMapping result;
  result.InterfaceType = ifaceType;
  result.TargetType = (RuntimeType)this;
  result.InterfaceMethods = rt::newarr<Array<MethodInfo>>(numVirtuals);
  result.TargetMethods = rt::newarr<Array<MethodInfo>>(numVirtuals);
  for (Int32 i = 0; i < numVirtuals; i++) {
    RuntimeMethodHandleInternal methodAt = RuntimeTypeHandle::GetMethodAt(runtimeType, i);
    MethodBase methodBase = GetMethodBase(runtimeType, methodAt);
    result.InterfaceMethods[i] = (MethodInfo)methodBase;
    RuntimeMethodHandleInternal interfaceMethodImplementation = GetTypeHandleInternal().GetInterfaceMethodImplementation(typeHandleInternal, methodAt);
    if (!interfaceMethodImplementation.IsNullHandle()) {
      RuntimeType runtimeType2 = RuntimeMethodHandle::GetDeclaringType(interfaceMethodImplementation);
      if (!runtimeType2->get_IsInterface()) {
        runtimeType2 = (RuntimeType)this;
      }
      MethodBase methodBase2 = GetMethodBase(runtimeType2, interfaceMethodImplementation);
      result.TargetMethods[i] = (MethodInfo)methodBase2;
    }
  }
  return result;
}

MethodInfo RuntimeType___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethodImplCommon(name, -1, bindingAttr, binder, callConv, types, modifiers);
}

MethodInfo RuntimeType___::GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethodImplCommon(name, genericParameterCount, bindingAttr, binder, callConv, types, modifiers);
}

MethodInfo RuntimeType___::GetMethodImplCommon(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  ListBuilder<MethodInfo> methodCandidates = GetMethodCandidates(name, genericParameterCount, bindingAttr, callConv, types, false);
  if (methodCandidates.get_Count() == 0) {
    return nullptr;
  }
  Array<MethodBase> match;
  if (types == nullptr || types->get_Length() == 0) {
    MethodInfo methodInfo = methodCandidates[0];
    if (methodCandidates.get_Count() == 1) {
      return methodInfo;
    }
    if (types == nullptr) {
      for (Int32 i = 1; i < methodCandidates.get_Count(); i++) {
        MethodInfo m = methodCandidates[i];
        if (!DefaultBinder::in::CompareMethodSig(m, methodInfo)) {
          rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
        }
      }
      match = methodCandidates.ToArray();
      return rt::as<MethodInfo>(DefaultBinder::in::FindMostDerivedNewSlotMeth(match, methodCandidates.get_Count()));
    }
  }
  if (binder == nullptr) {
    binder = Type::in::get_DefaultBinder();
  }
  Binder binder2 = binder;
  match = methodCandidates.ToArray();
  return rt::as<MethodInfo>(binder2->SelectMethod(bindingAttr, match, types, modifiers));
}

ConstructorInfo RuntimeType___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  ListBuilder<ConstructorInfo> constructorCandidates = GetConstructorCandidates(nullptr, bindingAttr, CallingConventions::Any, types, false);
  if (constructorCandidates.get_Count() == 0) {
    return nullptr;
  }
  if (types->get_Length() == 0 && constructorCandidates.get_Count() == 1) {
    ConstructorInfo constructorInfo = constructorCandidates[0];
    Array<ParameterInfo> parametersNoCopy = constructorInfo->GetParametersNoCopy();
    if (parametersNoCopy == nullptr || parametersNoCopy->get_Length() == 0) {
      return constructorInfo;
    }
  }
  Array<MethodBase> match;
  if ((bindingAttr & BindingFlags::ExactBinding) != 0) {
    match = constructorCandidates.ToArray();
    return rt::as<ConstructorInfo>(DefaultBinder::in::ExactBinding(match, types, modifiers));
  }
  if (binder == nullptr) {
    binder = Type::in::get_DefaultBinder();
  }
  Binder binder2 = binder;
  match = constructorCandidates.ToArray();
  return rt::as<ConstructorInfo>(binder2->SelectMethod(bindingAttr, match, types, modifiers));
}

PropertyInfo RuntimeType___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  ListBuilder<PropertyInfo> propertyCandidates = GetPropertyCandidates(name, bindingAttr, types, false);
  if (propertyCandidates.get_Count() == 0) {
    return nullptr;
  }
  if (types == nullptr || types->get_Length() == 0) {
    if (propertyCandidates.get_Count() == 1) {
      PropertyInfo propertyInfo = propertyCandidates[0];
      if ((Object)returnType != nullptr && !returnType->IsEquivalentTo(propertyInfo->get_PropertyType())) {
        return nullptr;
      }
      return propertyInfo;
    }
    if ((Object)returnType == nullptr) {
      rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
    }
  }
  if ((bindingAttr & BindingFlags::ExactBinding) != 0) {
    return DefaultBinder::in::ExactPropertyBinding(propertyCandidates.ToArray(), returnType, types, modifiers);
  }
  if (binder == nullptr) {
    binder = Type::in::get_DefaultBinder();
  }
  return binder->SelectProperty(bindingAttr, propertyCandidates.ToArray(), returnType, types, modifiers);
}

EventInfo RuntimeType___::GetEvent(String name, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, ignoreCase, listType);
  Array<RuntimeEventInfo> eventList = get_Cache()->GetEventList(listType, name);
  EventInfo eventInfo = nullptr;
  bindingAttr ^= BindingFlags::DeclaredOnly;
  for (RuntimeEventInfo& runtimeEventInfo : eventList) {
    if ((bindingAttr & runtimeEventInfo->get_BindingFlags()) == runtimeEventInfo->get_BindingFlags()) {
      if (eventInfo != nullptr) {
        rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
      }
      eventInfo = runtimeEventInfo;
    }
  }
  return eventInfo;
}

FieldInfo RuntimeType___::GetField(String name, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>();
  }
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, ignoreCase, listType);
  Array<RuntimeFieldInfo> fieldList = get_Cache()->GetFieldList(listType, name);
  FieldInfo fieldInfo = nullptr;
  bindingAttr ^= BindingFlags::DeclaredOnly;
  Boolean flag = false;
  for (RuntimeFieldInfo& runtimeFieldInfo : fieldList) {
    if ((bindingAttr & runtimeFieldInfo->get_BindingFlags()) != runtimeFieldInfo->get_BindingFlags()) {
      continue;
    }
    if (fieldInfo != nullptr) {
      if ((Object)runtimeFieldInfo->get_DeclaringType() == fieldInfo->get_DeclaringType()) {
        rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
      }
      if (fieldInfo->get_DeclaringType()->get_IsInterface() && runtimeFieldInfo->get_DeclaringType()->get_IsInterface()) {
        flag = true;
      }
    }
    if (fieldInfo == nullptr || runtimeFieldInfo->get_DeclaringType()->IsSubclassOf(fieldInfo->get_DeclaringType()) || fieldInfo->get_DeclaringType()->get_IsInterface()) {
      fieldInfo = runtimeFieldInfo;
    }
  }
  if (flag && fieldInfo->get_DeclaringType()->get_IsInterface()) {
    rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
  }
  return fieldInfo;
}

Type RuntimeType___::GetInterface(String fullname, Boolean ignoreCase) {
  if (fullname == nullptr) {
    rt::throw_exception<ArgumentNullException>("fullname");
  }
  BindingFlags bindingFlags = BindingFlags::Public | BindingFlags::NonPublic;
  bindingFlags &= ~BindingFlags::Static;
  if (ignoreCase) {
    bindingFlags |= BindingFlags::IgnoreCase;
  }
  String name;
  String ns;
  SplitName(fullname, name, ns);
  Boolean ignoreCase2;
  MemberListType listType;
  FilterHelper(bindingFlags, name, ignoreCase2, listType);
  Array<RuntimeType> interfaceList = get_Cache()->GetInterfaceList(listType, name);
  RuntimeType runtimeType = nullptr;
  for (RuntimeType& runtimeType2 : interfaceList) {
    if (FilterApplyType(runtimeType2, bindingFlags, name, false, ns)) {
      if (runtimeType != nullptr) {
        rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
      }
      runtimeType = runtimeType2;
    }
  }
  return runtimeType;
}

Type RuntimeType___::GetNestedType(String fullname, BindingFlags bindingAttr) {
  if (fullname == nullptr) {
    rt::throw_exception<ArgumentNullException>("fullname");
  }
  bindingAttr &= ~BindingFlags::Static;
  String name;
  String ns;
  SplitName(fullname, name, ns);
  Boolean ignoreCase;
  MemberListType listType;
  FilterHelper(bindingAttr, name, ignoreCase, listType);
  Array<RuntimeType> nestedTypeList = get_Cache()->GetNestedTypeList(listType, name);
  RuntimeType runtimeType = nullptr;
  for (RuntimeType& runtimeType2 : nestedTypeList) {
    if (FilterApplyType(runtimeType2, bindingAttr, name, false, ns)) {
      if (runtimeType != nullptr) {
        rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
      }
      runtimeType = runtimeType2;
    }
  }
  return runtimeType;
}

Array<MemberInfo> RuntimeType___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  ListBuilder<MethodInfo> listBuilder = ListBuilder<T>();
  ListBuilder<ConstructorInfo> listBuilder2 = ListBuilder<T>();
  ListBuilder<PropertyInfo> listBuilder3 = ListBuilder<T>();
  ListBuilder<EventInfo> listBuilder4 = ListBuilder<T>();
  ListBuilder<FieldInfo> listBuilder5 = ListBuilder<T>();
  ListBuilder<Type> listBuilder6 = ListBuilder<T>();
  Int32 num = 0;
  if ((type & MemberTypes::Method) != 0) {
    listBuilder = GetMethodCandidates(name, -1, bindingAttr, CallingConventions::Any, nullptr, true);
    if (type == MemberTypes::Method) {
      return listBuilder.ToArray();
    }
    num += listBuilder.get_Count();
  }
  if ((type & MemberTypes::Constructor) != 0) {
    listBuilder2 = GetConstructorCandidates(name, bindingAttr, CallingConventions::Any, nullptr, true);
    if (type == MemberTypes::Constructor) {
      return listBuilder2.ToArray();
    }
    num += listBuilder2.get_Count();
  }
  if ((type & MemberTypes::Property) != 0) {
    listBuilder3 = GetPropertyCandidates(name, bindingAttr, nullptr, true);
    if (type == MemberTypes::Property) {
      return listBuilder3.ToArray();
    }
    num += listBuilder3.get_Count();
  }
  if ((type & MemberTypes::Event) != 0) {
    listBuilder4 = GetEventCandidates(name, bindingAttr, true);
    if (type == MemberTypes::Event) {
      return listBuilder4.ToArray();
    }
    num += listBuilder4.get_Count();
  }
  if ((type & MemberTypes::Field) != 0) {
    listBuilder5 = GetFieldCandidates(name, bindingAttr, true);
    if (type == MemberTypes::Field) {
      return listBuilder5.ToArray();
    }
    num += listBuilder5.get_Count();
  }
  if ((type & (MemberTypes::TypeInfo | MemberTypes::NestedType)) != 0) {
    listBuilder6 = GetNestedTypeCandidates(name, bindingAttr, true);
    if (type == MemberTypes::NestedType || type == MemberTypes::TypeInfo) {
      return listBuilder6.ToArray();
    }
    num += listBuilder6.get_Count();
  }
  Array<MemberInfo> array;
  if (type != (MemberTypes::Constructor | MemberTypes::Method)) {
    array = rt::newarr<Array<MemberInfo>>(num);
  } else {
    Array<MemberInfo> array2 = rt::newarr<Array<MethodBase>>(num);
    array = array2;
  }
  Array<MemberInfo> array3 = array;
  Int32 num2 = 0;
  Array<Object> array4 = array3;
  listBuilder.CopyTo(array4, num2);
  num2 += listBuilder.get_Count();
  array4 = array3;
  listBuilder2.CopyTo(array4, num2);
  num2 += listBuilder2.get_Count();
  array4 = array3;
  listBuilder3.CopyTo(array4, num2);
  num2 += listBuilder3.get_Count();
  array4 = array3;
  listBuilder4.CopyTo(array4, num2);
  num2 += listBuilder4.get_Count();
  array4 = array3;
  listBuilder5.CopyTo(array4, num2);
  num2 += listBuilder5.get_Count();
  array4 = array3;
  listBuilder6.CopyTo(array4, num2);
  num2 += listBuilder6.get_Count();
  return array3;
}

Boolean RuntimeType___::IsSubclassOf(Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if (runtimeType == nullptr) {
    return false;
  }
  RuntimeType baseType = GetBaseType();
  while (baseType != nullptr) {
    if (baseType == runtimeType) {
      return true;
    }
    baseType = baseType->GetBaseType();
  }
  if (runtimeType == ObjectType && runtimeType != (RuntimeType)this) {
    return true;
  }
  return false;
}

Boolean RuntimeType___::IsEquivalentTo(Type other) {
  RuntimeType runtimeType = rt::as<RuntimeType>(other);
  if ((Object)runtimeType == nullptr) {
    return false;
  }
  if (runtimeType == (RuntimeType)this) {
    return true;
  }
  return RuntimeTypeHandle::IsEquivalentTo((RuntimeType)this, runtimeType);
}

Boolean RuntimeType___::IsDelegate() {
  return GetBaseType() == typeof<MulticastDelegate>();
}

Array<Object> RuntimeType___::GetEmptyArray() {
  return get_Cache()->GetEmptyArray();
}

Array<RuntimeType> RuntimeType___::GetGenericArgumentsInternal() {
  return GetRootElementType()->GetTypeHandleInternal().GetInstantiationInternal();
}

Array<Type> RuntimeType___::GetGenericArguments() {
  Array<Type> instantiationPublic = GetRootElementType()->GetTypeHandleInternal().GetInstantiationPublic();
  Array<Type> as = instantiationPublic;
  return as != nullptr ? as : Array<>::in::Empty<Type>();
}

Type RuntimeType___::MakeGenericType(Array<Type> instantiation) {
  if (instantiation == nullptr) {
    rt::throw_exception<ArgumentNullException>("instantiation");
  }
  Array<RuntimeType> array = rt::newarr<Array<RuntimeType>>(instantiation->get_Length());
  if (!get_IsGenericTypeDefinition()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericTypeDefinition(), (RuntimeType)this));
  }
  if (GetGenericArguments()->get_Length() != instantiation->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_GenericArgsCount(), "instantiation");
  }
  Boolean flag = false;
  Boolean flag2 = false;
  for (Int32 i = 0; i < instantiation->get_Length(); i++) {
    Type type = instantiation[i];
    if (type == nullptr) {
      rt::throw_exception<ArgumentNullException>();
    }
    RuntimeType runtimeType = rt::as<RuntimeType>(type);
    if (runtimeType == nullptr) {
      flag2 = true;
      if (type->get_IsSignatureType()) {
        flag = true;
      }
    }
    array[i] = runtimeType;
  }
  if (flag2) {
    if (flag) {
      return rt::newobj<SignatureConstructedGenericType>((RuntimeType)this, instantiation);
    }
    return TypeBuilderInstantiation::in::MakeGenericType((RuntimeType)this, (Array<Type>)instantiation->Clone());
  }
  Array<RuntimeType> genericArgumentsInternal = GetGenericArgumentsInternal();
  SanityCheckGenericArguments(array, genericArgumentsInternal);
  try {
    RuntimeTypeHandle runtimeTypeHandle = RuntimeTypeHandle((RuntimeType)this);
    Array<Type> inst = array;
    return runtimeTypeHandle.Instantiate(inst);
  } catch (TypeLoadException e) {
  }
}

Array<Type> RuntimeType___::GetGenericParameterConstraints() {
  if (!get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  Array<Type> constraints = RuntimeTypeHandle((RuntimeType)this).GetConstraints();
  Array<Type> as = constraints;
  return as != nullptr ? as : Array<>::in::Empty<Type>();
}

Boolean RuntimeType___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimeType>(other);
}

Type RuntimeType___::MakePointerType() {
  return RuntimeTypeHandle((RuntimeType)this).MakePointer();
}

Type RuntimeType___::MakeByRefType() {
  return RuntimeTypeHandle((RuntimeType)this).MakeByRef();
}

Type RuntimeType___::MakeArrayType() {
  return RuntimeTypeHandle((RuntimeType)this).MakeSZArray();
}

Type RuntimeType___::MakeArrayType(Int32 rank) {
  if (rank <= 0) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  return RuntimeTypeHandle((RuntimeType)this).MakeArray(rank);
}

Object RuntimeType___::CheckValue(Object value, Binder binder, CultureInfo culture, BindingFlags invokeAttr) {
  if (IsInstanceOfType(value)) {
    Type type = value->GetType();
    if ((Object)type != (RuntimeType)this && RuntimeTypeHandle::IsValueType((RuntimeType)this)) {
      return AllocateValueType((RuntimeType)this, value, true);
    }
    return value;
  }
  if (Type::in::get_IsByRef()) {
    RuntimeType elementType = RuntimeTypeHandle::GetElementType((RuntimeType)this);
    if (elementType->IsInstanceOfType(value) || value == nullptr) {
      return AllocateValueType(elementType, value, false);
    }
  } else {
    if (value == nullptr) {
      return value;
    }
    if ((RuntimeType)this == s_typedRef) {
      return value;
    }
  }
  Boolean flag = Type::in::get_IsPointer() || get_IsEnum() || Type::in::get_IsPrimitive();
  if (flag) {
    Pointer pointer = rt::as<Pointer>(value);
    RuntimeType valueType = (pointer == nullptr) ? ((RuntimeType)value->GetType()) : ((RuntimeType)pointer->GetPointerType());
    if (CanValueSpecialCast(valueType, (RuntimeType)this)) {
      if (pointer != nullptr) {
        return pointer->GetPointerValue();
      }
      return value;
    }
  }
  if ((invokeAttr & BindingFlags::ExactBinding) == BindingFlags::ExactBinding) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ObjObjEx(), value->GetType(), (RuntimeType)this));
  }
  return TryChangeType(value, binder, culture, flag);
}

Object RuntimeType___::TryChangeType(Object value, Binder binder, CultureInfo culture, Boolean needsSpecialCast) {
  if (binder != nullptr && binder != Type::in::get_DefaultBinder()) {
    value = binder->ChangeType(value, (RuntimeType)this, culture);
    if (IsInstanceOfType(value)) {
      return value;
    }
    if (Type::in::get_IsByRef()) {
      RuntimeType elementType = RuntimeTypeHandle::GetElementType((RuntimeType)this);
      if (elementType->IsInstanceOfType(value) || value == nullptr) {
        return AllocateValueType(elementType, value, false);
      }
    } else if (value == nullptr) {
      return value;
    }

    if (needsSpecialCast) {
      Pointer pointer = rt::as<Pointer>(value);
      RuntimeType valueType = (pointer == nullptr) ? ((RuntimeType)value->GetType()) : ((RuntimeType)pointer->GetPointerType());
      if (CanValueSpecialCast(valueType, (RuntimeType)this)) {
        if (pointer != nullptr) {
          return pointer->GetPointerValue();
        }
        return value;
      }
    }
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ObjObjEx(), value->GetType(), (RuntimeType)this));
}

Object RuntimeType___::InvokeMember(String name, BindingFlags bindingFlags, Binder binder, Object target, Array<Object> providedArgs, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParams) {
  if (get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_GenericParameter());
  }
  if ((bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::CreateInstance | BindingFlags::GetField | BindingFlags::SetField | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty)) == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_NoAccessSpec(), "bindingFlags");
  }
  if ((bindingFlags & (BindingFlags)255) == 0) {
    bindingFlags |= (BindingFlags::Instance | BindingFlags::Public);
    if ((bindingFlags & BindingFlags::CreateInstance) == 0) {
      bindingFlags |= BindingFlags::Static;
    }
  }
  if (namedParams != nullptr) {
    if (providedArgs != nullptr) {
      if (namedParams->get_Length() > providedArgs->get_Length()) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_NamedParamTooBig(), "namedParams");
      }
    } else if (namedParams->get_Length() != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_NamedParamTooBig(), "namedParams");
    }

  }
  if (target != nullptr && target->GetType()->get_IsCOMObject()) {
    if ((bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty)) == 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_COMAccess(), "bindingFlags");
    }
    if ((bindingFlags & BindingFlags::GetProperty) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty) & ~(BindingFlags::InvokeMethod | BindingFlags::GetProperty)) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_PropSetGet(), "bindingFlags");
    }
    if ((bindingFlags & BindingFlags::InvokeMethod) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty) & ~(BindingFlags::InvokeMethod | BindingFlags::GetProperty)) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_PropSetInvoke(), "bindingFlags");
    }
    if ((bindingFlags & BindingFlags::SetProperty) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty) & ~BindingFlags::SetProperty) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_COMPropSetPut(), "bindingFlags");
    }
    if ((bindingFlags & BindingFlags::PutDispProperty) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty) & ~BindingFlags::PutDispProperty) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_COMPropSetPut(), "bindingFlags");
    }
    if ((bindingFlags & BindingFlags::PutRefDispProperty) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetProperty | BindingFlags::SetProperty | BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty) & ~BindingFlags::PutRefDispProperty) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_COMPropSetPut(), "bindingFlags");
    }
    if (name == nullptr) {
      rt::throw_exception<ArgumentNullException>("name");
    }
    Array<Boolean> byrefModifiers = (modifiers != nullptr) ? modifiers[0].get_IsByRefArray() : nullptr;
    Int32 culture2 = (culture == nullptr) ? 1033 : culture->get_LCID();
    Boolean flag = (bindingFlags & BindingFlags::DoNotWrapExceptions) != 0;
    try {
      return InvokeDispMethod(name, bindingFlags, target, providedArgs, byrefModifiers, culture2, namedParams);
    } catch (TargetInvocationException ex) {
    }
  }
  if (namedParams != nullptr && Array<>::in::IndexOf(namedParams, (String)nullptr) != -1) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_NamedParamNull(), "namedParams");
  }
  Int32 num = (providedArgs != nullptr) ? providedArgs->get_Length() : 0;
  if (binder == nullptr) {
    binder = Type::in::get_DefaultBinder();
  }
  if ((bindingFlags & BindingFlags::CreateInstance) != 0) {
    if ((bindingFlags & BindingFlags::CreateInstance) != 0 && (bindingFlags & (BindingFlags::InvokeMethod | BindingFlags::GetField | BindingFlags::SetField | BindingFlags::GetProperty | BindingFlags::SetProperty)) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CreatInstAccess(), "bindingFlags");
    }
    return Activator::CreateInstance((RuntimeType)this, bindingFlags, binder, providedArgs, culture);
  }
  if ((bindingFlags & (BindingFlags::PutDispProperty | BindingFlags::PutRefDispProperty)) != 0) {
    bindingFlags |= BindingFlags::SetProperty;
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0 || name->Equals("[DISPID=0]")) {
    String as = GetDefaultMemberName();
    name = (as != nullptr ? as : "ToString");
  }
  Boolean flag2 = (bindingFlags & BindingFlags::GetField) != 0;
  Boolean flag3 = (bindingFlags & BindingFlags::SetField) != 0;
  if (flag2 || flag3) {
    if (flag2) {
      if (flag3) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_FldSetGet(), "bindingFlags");
      }
      if ((bindingFlags & BindingFlags::SetProperty) != 0) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_FldGetPropSet(), "bindingFlags");
      }
    } else {
      if (providedArgs == nullptr) {
        rt::throw_exception<ArgumentNullException>("providedArgs");
      }
      if ((bindingFlags & BindingFlags::GetProperty) != 0) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_FldSetPropGet(), "bindingFlags");
      }
      if ((bindingFlags & BindingFlags::InvokeMethod) != 0) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_FldSetInvoke(), "bindingFlags");
      }
    }
    FieldInfo fieldInfo = nullptr;
    Array<FieldInfo> array = rt::as<Array<FieldInfo>>(GetMember(name, MemberTypes::Field, bindingFlags));
    if (array->get_Length() == 1) {
      fieldInfo = array[0];
    } else if (array->get_Length() != 0) {
      fieldInfo = binder->BindToField(bindingFlags, array, flag2 ? Empty::in::Value : providedArgs[0], culture);
    }

    if (fieldInfo != nullptr) {
      if (fieldInfo->get_FieldType()->get_IsArray() || (Object)fieldInfo->get_FieldType() == typeof<Array<>>()) {
        Int32 num2 = ((bindingFlags & BindingFlags::GetField) == 0) ? (num - 1) : num;
        if (num2 > 0) {
          Array<Int32> array2 = rt::newarr<Array<Int32>>(num2);
          for (Int32 i = 0; i < num2; i++) {
            try {
              array2[i] = ((IConvertible)providedArgs[i])->ToInt32(nullptr);
            } catch (InvalidCastException) {
            }
          }
          Array<> array3 = (Array<>)fieldInfo->GetValue(target);
          if ((bindingFlags & BindingFlags::GetField) != 0) {
            return array3->GetValue(array2);
          }
          array3->SetValue(providedArgs[num2], array2);
          return nullptr;
        }
      }
      if (flag2) {
        if (num != 0) {
          rt::throw_exception<ArgumentException>(SR::get_Arg_FldGetArgErr(), "bindingFlags");
        }
        return fieldInfo->GetValue(target);
      }
      if (num != 1) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_FldSetArgErr(), "bindingFlags");
      }
      fieldInfo->SetValue(target, providedArgs[0], bindingFlags, binder, culture);
      return nullptr;
    }
    if ((bindingFlags & (BindingFlags)16773888) == 0) {
      rt::throw_exception<MissingFieldException>(get_FullName(), name);
    }
  }
  Boolean flag4 = (bindingFlags & BindingFlags::GetProperty) != 0;
  Boolean flag5 = (bindingFlags & BindingFlags::SetProperty) != 0;
  if (flag4 || flag5) {
    if (flag4) {
      if (flag5) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_PropSetGet(), "bindingFlags");
      }
    } else if ((bindingFlags & BindingFlags::InvokeMethod) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_PropSetInvoke(), "bindingFlags");
    }

  }
  Array<MethodInfo> array4 = nullptr;
  MethodInfo methodInfo = nullptr;
  if ((bindingFlags & BindingFlags::InvokeMethod) != 0) {
    Array<MethodInfo> array5 = rt::as<Array<MethodInfo>>(GetMember(name, MemberTypes::Method, bindingFlags));
    List<MethodInfo> list = nullptr;
    for (MethodInfo& methodInfo2 : array5) {
      if (!FilterApplyMethodInfo((RuntimeMethodInfo)methodInfo2, bindingFlags, CallingConventions::Any, rt::newarr<Array<Type>>(num))) {
        continue;
      }
      if (methodInfo == nullptr) {
        methodInfo = methodInfo2;
        continue;
      }
      if (list == nullptr) {
        list = rt::newobj<List<MethodInfo>>(array5->get_Length());
      }
      list->Add(methodInfo2);
    }
    if (list != nullptr) {
      array4 = list->ToArray();
    }
  }
  if ((methodInfo == nullptr && flag4) || flag5) {
    Array<PropertyInfo> array6 = rt::as<Array<PropertyInfo>>(GetMember(name, MemberTypes::Property, bindingFlags));
    List<MethodInfo> list2 = nullptr;
    for (Int32 k = 0; k < array6->get_Length(); k++) {
      MethodInfo methodInfo3 = nullptr;
      methodInfo3 = ((!flag5) ? array6[k]->GetGetMethod(true) : array6[k]->GetSetMethod(true));
      if (methodInfo3 == nullptr || !FilterApplyMethodInfo((RuntimeMethodInfo)methodInfo3, bindingFlags, CallingConventions::Any, rt::newarr<Array<Type>>(num))) {
        continue;
      }
      if (methodInfo == nullptr) {
        methodInfo = methodInfo3;
        continue;
      }
      if (list2 == nullptr) {
        list2 = rt::newobj<List<MethodInfo>>(array6->get_Length());
      }
      list2->Add(methodInfo3);
    }
    if (list2 != nullptr) {
      array4 = list2->ToArray();
    }
  }
  if (methodInfo != nullptr) {
    if (array4 == nullptr && num == 0 && methodInfo->GetParametersNoCopy()->get_Length() == 0 && (bindingFlags & BindingFlags::OptionalParamBinding) == 0) {
      return methodInfo->Invoke(target, bindingFlags, binder, providedArgs, culture);
    }
    if (array4 == nullptr) {
      array4 = rt::newarr<Array<MethodInfo>>(1);
    }
    if (providedArgs == nullptr) {
      providedArgs = Array<>::in::Empty<Object>();
    }
    Object state = nullptr;
    MethodBase methodBase = nullptr;
    try {
      Binder binder2 = binder;
      BindingFlags bindingAttr = bindingFlags;
      Array<MethodBase> match = array4;
      methodBase = binder2->BindToMethod(bindingAttr, match, providedArgs, modifiers, culture, namedParams, state);
    } catch (MissingMethodException) {
    }
    if (methodBase == nullptr) {
      rt::throw_exception<MissingMethodException>(get_FullName(), name);
    }
    Object result = ((MethodInfo)methodBase)->Invoke(target, bindingFlags, binder, providedArgs, culture);
    if (state != nullptr) {
      binder->ReorderArgumentArray(providedArgs, state);
    }
    return result;
  }
  rt::throw_exception<MissingMethodException>(get_FullName(), name);
}

String RuntimeType___::ToString() {
  return GetCachedName(TypeNameKind::ToString);
}

String RuntimeType___::GetCachedName(TypeNameKind kind) {
  return get_Cache()->GetName(kind);
}

void RuntimeType___::CreateInstanceCheckThis() {
  if (get_ContainsGenericParameters()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Acc_CreateGenericEx(), (RuntimeType)this));
  }
  Type rootElementType = GetRootElementType();
  if ((Object)rootElementType == typeof<ArgIterator>()) {
    rt::throw_exception<NotSupportedException>(SR::get_Acc_CreateArgIterator());
  }
  if ((Object)rootElementType == typeof<void>()) {
    rt::throw_exception<NotSupportedException>(SR::get_Acc_CreateVoid());
  }
}

Object RuntimeType___::CreateInstanceImpl(BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture) {
  CreateInstanceCheckThis();
  if (args == nullptr) {
    args = Array<>::in::Empty<Object>();
  }
  if (binder == nullptr) {
    binder = Type::in::get_DefaultBinder();
  }
  Boolean publicOnly = (bindingAttr & BindingFlags::NonPublic) == 0;
  Boolean wrapExceptions = (bindingAttr & BindingFlags::DoNotWrapExceptions) == 0;
  Object result;
  if (args->get_Length() == 0 && (bindingAttr & BindingFlags::Public) != 0 && (bindingAttr & BindingFlags::Instance) != 0 && (IsGenericCOMObjectImpl() || Type::in::get_IsValueType())) {
    result = CreateInstanceDefaultCtor(publicOnly, false, true, wrapExceptions);
  } else {
    Array<ConstructorInfo> constructors = GetConstructors(bindingAttr);
    List<MethodBase> list = rt::newobj<List<MethodBase>>(constructors->get_Length());
    Array<Type> array = rt::newarr<Array<Type>>(args->get_Length());
    for (Int32 i = 0; i < args->get_Length(); i++) {
      if (args[i] != nullptr) {
        array[i] = args[i]->GetType();
      }
    }
    for (Int32 j = 0; j < constructors->get_Length(); j++) {
      if (FilterApplyConstructorInfo((RuntimeConstructorInfo)constructors[j], bindingAttr, CallingConventions::Any, array)) {
        list->Add(constructors[j]);
      }
    }
    if (list->get_Count() == 0) {
      rt::throw_exception<MissingMethodException>(SR::Format(SR::get_MissingConstructor_Name(), get_FullName()));
    }
    Array<MethodBase> match = list->ToArray();
    Object state = nullptr;
    MethodBase methodBase;
    try {
      methodBase = binder->BindToMethod(bindingAttr, match, args, nullptr, culture, nullptr, state);
    } catch (MissingMethodException) {
    }
    if ((Object)methodBase == nullptr) {
      rt::throw_exception<MissingMethodException>(SR::Format(SR::get_MissingConstructor_Name(), get_FullName()));
    }
    if (methodBase->GetParametersNoCopy()->get_Length() == 0) {
      if (args->get_Length() != 0) {
        rt::throw_exception<NotSupportedException>(SR::get_NotSupported_CallToVarArg());
      }
      result = Activator::CreateInstance((RuntimeType)this, true, wrapExceptions);
    } else {
      result = ((ConstructorInfo)methodBase)->Invoke(bindingAttr, binder, args, culture);
      if (state != nullptr) {
        binder->ReorderArgumentArray(args, state);
      }
    }
  }
  return result;
}

Object RuntimeType___::CreateInstanceDefaultCtorSlow(Boolean publicOnly, Boolean wrapExceptions, Boolean fillCache) {
  RuntimeMethodHandleInternal ctor = RuntimeMethodHandleInternal();
  Boolean canBeCached = false;
  Boolean hasNoDefaultCtor = false;
  Object result = RuntimeTypeHandle::CreateInstance((RuntimeType)this, publicOnly, wrapExceptions, canBeCached, ctor, hasNoDefaultCtor);
  if (hasNoDefaultCtor) {
    rt::throw_exception<MissingMethodException>(SR::Format(SR::get_Arg_NoDefCTor(), (RuntimeType)this));
  }
  if (canBeCached && fillCache) {
    get_GenericCache(rt::newobj<ActivatorCache>(ctor));
  }
  return result;
}

Object RuntimeType___::CreateInstanceDefaultCtor(Boolean publicOnly, Boolean skipCheckThis, Boolean fillCache, Boolean wrapExceptions) {
  ActivatorCache activatorCache = rt::as<ActivatorCache>(get_GenericCache());
  if (activatorCache != nullptr) {
    activatorCache->EnsureInitialized();
    if (publicOnly && activatorCache->_ctor != nullptr && (activatorCache->_ctorAttributes & MethodAttributes::MemberAccessMask) != MethodAttributes::Public) {
      rt::throw_exception<MissingMethodException>(SR::Format(SR::get_Arg_NoDefCTor(), (RuntimeType)this));
    }
    Object obj = RuntimeTypeHandle::Allocate((RuntimeType)this);
    if (activatorCache->_ctor != nullptr) {
      try {
        activatorCache->_ctor(obj);
        return obj;
      } catch (Exception inner) {
      }
    }
    return obj;
  }
  if (!skipCheckThis) {
    CreateInstanceCheckThis();
  }
  return CreateInstanceDefaultCtorSlow(publicOnly, wrapExceptions, fillCache);
}

void RuntimeType___::InvalidateCachedNestedType() {
  get_Cache()->InvalidateCachedNestedType();
}

Boolean RuntimeType___::IsGenericCOMObjectImpl() {
  return RuntimeTypeHandle::IsComObject((RuntimeType)this, true);
}

Object RuntimeType___::CreateEnum(RuntimeType enumType, Int64 value) {
  return _CreateEnum(enumType, value);
}

Object RuntimeType___::ForwardCallToInvokeMember(String memberName, BindingFlags flags, Object target, Array<Object> aArgs, Array<Boolean> aArgsIsByRef, Array<Int32> aArgsWrapperTypes, Array<Type> aArgsTypes, Type retType) {
  Int32 num = aArgs->get_Length();
  Array<ParameterModifier> array = nullptr;
  if (num > 0) {
    ParameterModifier parameterModifier = ParameterModifier(num);
    for (Int32 i = 0; i < num; i++) {
      parameterModifier[i] = aArgsIsByRef[i];
    }
    array = rt::newarr<Array<ParameterModifier>>(1);
    if (aArgsWrapperTypes != nullptr) {
      WrapArgsForInvokeCall(aArgs, aArgsWrapperTypes);
    }
  }
  flags |= BindingFlags::DoNotWrapExceptions;
  Object obj = InvokeMember(memberName, flags, nullptr, target, aArgs, array, nullptr, nullptr);
  for (Int32 j = 0; j < num; j++) {
    if (array[0][j] && aArgs[j] != nullptr) {
      Type type = aArgsTypes[j];
      if ((Object)type != aArgs[j]->GetType()) {
        aArgs[j] = get_ForwardCallBinder()->ChangeType(aArgs[j], type, nullptr);
      }
    }
  }
  if (obj != nullptr && (Object)retType != obj->GetType()) {
    obj = get_ForwardCallBinder()->ChangeType(obj, retType, nullptr);
  }
  return obj;
}

void RuntimeType___::WrapArgsForInvokeCall(Array<Object> aArgs, Array<Int32> aArgsWrapperTypes) {
  Int32 num = aArgs->get_Length();
  for (Int32 i = 0; i < num; i++) {
    if (aArgsWrapperTypes[i] == 0) {
      continue;
    }
    if (((DispatchWrapperType)aArgsWrapperTypes[i])->HasFlag(DispatchWrapperType::SafeArray)) {
      Type type = nullptr;
      Boolean flag = false;
      switch (aArgsWrapperTypes[i] & -65537.get()) {
        case 1:
          type = typeof<UnknownWrapper>();
          break;
        case 2:
          type = typeof<DispatchWrapper>();
          break;
        case 8:
          type = typeof<ErrorWrapper>();
          break;
        case 16:
          type = typeof<CurrencyWrapper>();
          break;
        case 32:
          type = typeof<BStrWrapper>();
          flag = true;
          break;
      }
      Array<> array = (Array<>)aArgs[i];
      Int32 length = array->get_Length();
      Array<Object> array2 = (Array<Object>)Array<>::in::CreateInstance(type, length);
      ConstructorInfo constructorInfo = (!flag) ? type->GetConstructor(rt::newarr<Array<Type>>(1)) : type->GetConstructor(rt::newarr<Array<Type>>(1));
      for (Int32 j = 0; j < length; j++) {
        if (flag) {
          array2[j] = constructorInfo->Invoke(rt::newarr<Array<Object>>(1));
        } else {
          array2[j] = constructorInfo->Invoke(rt::newarr<Array<Object>>(1));
        }
      }
      aArgs[i] = array2;
    } else {
      switch (aArgsWrapperTypes[i].get()) {
        case 1:
          aArgs[i] = rt::newobj<UnknownWrapper>(aArgs[i]);
          break;
        case 2:
          aArgs[i] = rt::newobj<DispatchWrapper>(aArgs[i]);
          break;
        case 8:
          aArgs[i] = rt::newobj<ErrorWrapper>(aArgs[i]);
          break;
        case 16:
          aArgs[i] = rt::newobj<CurrencyWrapper>(aArgs[i]);
          break;
        case 32:
          aArgs[i] = rt::newobj<BStrWrapper>((String)aArgs[i]);
          break;
      }
    }
  }
}

Object RuntimeType___::Clone() {
  return (RuntimeType)this;
}

Boolean RuntimeType___::Equals(Object obj) {
  return obj == (RuntimeType)this;
}

Int32 RuntimeType___::GetArrayRank() {
  if (!IsArrayImpl()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
  }
  return RuntimeTypeHandle::GetArrayRank((RuntimeType)this);
}

TypeAttributes RuntimeType___::GetAttributeFlagsImpl() {
  return RuntimeTypeHandle::GetAttributes((RuntimeType)this);
}

Array<Object> RuntimeType___::GetCustomAttributes(Boolean inherit) {
  return CustomAttribute::GetCustomAttributes((RuntimeType)this, ObjectType, inherit);
}

Array<Object> RuntimeType___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if ((Object)attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeType)this, runtimeType, inherit);
}

IList<CustomAttributeData> RuntimeType___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeType)this);
}

Array<MemberInfo> RuntimeType___::GetDefaultMembers() {
  Array<MemberInfo> array = nullptr;
  String defaultMemberName = GetDefaultMemberName();
  if (defaultMemberName != nullptr) {
    array = GetMember(defaultMemberName);
  }
  Array<MemberInfo> as = array;
  return as != nullptr ? as : Array<>::in::Empty<MemberInfo>();
}

Type RuntimeType___::GetElementType() {
  return RuntimeTypeHandle::GetElementType((RuntimeType)this);
}

String RuntimeType___::GetEnumName(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  Type type = value->GetType();
  if (!type->get_IsEnum() && !Type::in::IsIntegerType(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnumBaseTypeOrEnum(), "value");
  }
  UInt64 ulValue = Enum::in::ToUInt64(value);
  return Enum::in::GetEnumName((RuntimeType)this, ulValue);
}

Array<String> RuntimeType___::GetEnumNames() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  Array<String> array = Enum::in::InternalGetNames((RuntimeType)this);
  return ReadOnlySpan<String>(array).ToArray();
}

Array<> RuntimeType___::GetEnumValues() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  Array<UInt64> array = Enum::in::InternalGetValues((RuntimeType)this);
  Array<> array2 = Array<>::in::CreateInstance((RuntimeType)this, array->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Object value = Enum::in::ToObject((RuntimeType)this, array[i]);
    array2->SetValue(value, i);
  }
  return array2;
}

Type RuntimeType___::GetEnumUnderlyingType() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  return Enum::in::InternalGetUnderlyingType((RuntimeType)this);
}

Type RuntimeType___::GetGenericTypeDefinition() {
  if (!get_IsGenericType()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotGenericType());
  }
  return RuntimeTypeHandle::GetGenericTypeDefinition((RuntimeType)this);
}

Int32 RuntimeType___::GetHashCode() {
  return RuntimeHelpers::GetHashCode((RuntimeType)this);
}

RuntimeModule RuntimeType___::GetRuntimeModule() {
  return RuntimeTypeHandle::GetModule((RuntimeType)this);
}

TypeCode RuntimeType___::GetTypeCodeImpl() {
  TypeCode typeCode = get_Cache()->get_TypeCode();
  if (typeCode != 0) {
    return typeCode;
  }
  switch (RuntimeTypeHandle::GetCorElementType((RuntimeType)this)) {
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      typeCode = TypeCode::Boolean;
      break;
    case CorElementType::ELEMENT_TYPE_CHAR:
      typeCode = TypeCode::Char;
      break;
    case CorElementType::ELEMENT_TYPE_I1:
      typeCode = TypeCode::SByte;
      break;
    case CorElementType::ELEMENT_TYPE_U1:
      typeCode = TypeCode::Byte;
      break;
    case CorElementType::ELEMENT_TYPE_I2:
      typeCode = TypeCode::Int16;
      break;
    case CorElementType::ELEMENT_TYPE_U2:
      typeCode = TypeCode::UInt16;
      break;
    case CorElementType::ELEMENT_TYPE_I4:
      typeCode = TypeCode::Int32;
      break;
    case CorElementType::ELEMENT_TYPE_U4:
      typeCode = TypeCode::UInt32;
      break;
    case CorElementType::ELEMENT_TYPE_I8:
      typeCode = TypeCode::Int64;
      break;
    case CorElementType::ELEMENT_TYPE_U8:
      typeCode = TypeCode::UInt64;
      break;
    case CorElementType::ELEMENT_TYPE_R4:
      typeCode = TypeCode::Single;
      break;
    case CorElementType::ELEMENT_TYPE_R8:
      typeCode = TypeCode::Double;
      break;
    case CorElementType::ELEMENT_TYPE_VALUETYPE:
      typeCode = ((!((RuntimeType)this == Convert::ConvertTypes[15])) ? ((!((RuntimeType)this == Convert::ConvertTypes[16])) ? ((!get_IsEnum()) ? TypeCode::Object : Type::in::GetTypeCode(Enum::in::GetUnderlyingType((RuntimeType)this))) : TypeCode::DateTime) : TypeCode::Decimal);
      break;
    default:
      typeCode = ((!((RuntimeType)this == Convert::ConvertTypes[2])) ? ((!((RuntimeType)this == Convert::ConvertTypes[18])) ? TypeCode::Object : TypeCode::String) : TypeCode::DBNull);
      break;
  }
  get_Cache()->set_TypeCode(typeCode);
  return typeCode;
}

Boolean RuntimeType___::HasElementTypeImpl() {
  return RuntimeTypeHandle::HasElementType((RuntimeType)this);
}

Boolean RuntimeType___::IsArrayImpl() {
  return RuntimeTypeHandle::IsArray((RuntimeType)this);
}

Boolean RuntimeType___::IsContextfulImpl() {
  return false;
}

Boolean RuntimeType___::IsDefined(Type attributeType, Boolean inherit) {
  if ((Object)attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeType)this, runtimeType, inherit);
}

Boolean RuntimeType___::IsEnumDefined(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  RuntimeType runtimeType = (RuntimeType)value->GetType();
  if (runtimeType->get_IsEnum()) {
    if (!runtimeType->IsEquivalentTo((RuntimeType)this)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumAndObjectMustBeSameType(), runtimeType, (RuntimeType)this));
    }
    runtimeType = (RuntimeType)runtimeType->GetEnumUnderlyingType();
  }
  if (runtimeType == StringType) {
    Array<String> array = Enum::in::InternalGetNames((RuntimeType)this);
    Array<Object> array2 = array;
    return Array<>::in::IndexOf(array2, value) >= 0;
  }
  if (Type::in::IsIntegerType(runtimeType)) {
    RuntimeType runtimeType2 = Enum::in::InternalGetUnderlyingType((RuntimeType)this);
    if (runtimeType2 != runtimeType) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumUnderlyingTypeAndObjectMustBeSameType(), runtimeType, runtimeType2));
    }
    Array<UInt64> array3 = Enum::in::InternalGetValues((RuntimeType)this);
    UInt64 value2 = Enum::in::ToUInt64(value);
    return Array<>::in::BinarySearch(array3, value2) >= 0;
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
}

Boolean RuntimeType___::IsValueTypeImpl() {
  if ((RuntimeType)this == typeof<ValueType>() || (RuntimeType)this == typeof<Enum>()) {
    return false;
  }
  return IsSubclassOf(typeof<ValueType>());
}

Boolean RuntimeType___::IsByRefImpl() {
  return RuntimeTypeHandle::IsByRef((RuntimeType)this);
}

Boolean RuntimeType___::IsPrimitiveImpl() {
  return RuntimeTypeHandle::IsPrimitive((RuntimeType)this);
}

Boolean RuntimeType___::IsPointerImpl() {
  return RuntimeTypeHandle::IsPointer((RuntimeType)this);
}

Boolean RuntimeType___::IsCOMObjectImpl() {
  return RuntimeTypeHandle::IsComObject((RuntimeType)this, false);
}

Boolean RuntimeType___::IsInstanceOfType(Object o) {
  return RuntimeTypeHandle::IsInstanceOfType((RuntimeType)this, o);
}

Boolean RuntimeType___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

Boolean RuntimeType___::IsAssignableFrom(Type c) {
  if ((Object)c == nullptr) {
    return false;
  }
  if ((Object)c == (RuntimeType)this) {
    return true;
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(c->get_UnderlyingSystemType());
  if ((Object)runtimeType != nullptr) {
    return RuntimeTypeHandle::CanCastTo(runtimeType, (RuntimeType)this);
  }
  if (rt::is<TypeBuilder>(c)) {
    if (c->IsSubclassOf((RuntimeType)this)) {
      return true;
    }
    if (Type::in::get_IsInterface()) {
      return c->ImplementInterface((RuntimeType)this);
    }
    if (get_IsGenericParameter()) {
      Array<Type> genericParameterConstraints = GetGenericParameterConstraints();
      for (Int32 i = 0; i < genericParameterConstraints->get_Length(); i++) {
        if (!genericParameterConstraints[i]->IsAssignableFrom(c)) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}

RuntimeType RuntimeType___::GetBaseType() {
  if (Type::in::get_IsInterface()) {
    return nullptr;
  }
  if (RuntimeTypeHandle::IsGenericVariable((RuntimeType)this)) {
    Array<Type> genericParameterConstraints = GetGenericParameterConstraints();
    RuntimeType runtimeType = ObjectType;
    for (Int32 i = 0; i < genericParameterConstraints->get_Length(); i++) {
      RuntimeType runtimeType2 = (RuntimeType)genericParameterConstraints[i];
      if (runtimeType2->get_IsInterface()) {
        continue;
      }
      if (runtimeType2->get_IsGenericParameter()) {
        GenericParameterAttributes genericParameterAttributes = runtimeType2->get_GenericParameterAttributes() & GenericParameterAttributes::SpecialConstraintMask;
        if ((genericParameterAttributes & GenericParameterAttributes::ReferenceTypeConstraint) == 0 && (genericParameterAttributes & GenericParameterAttributes::NotNullableValueTypeConstraint) == 0) {
          continue;
        }
      }
      runtimeType = runtimeType2;
    }
    if (runtimeType == ObjectType) {
      GenericParameterAttributes genericParameterAttributes2 = get_GenericParameterAttributes() & GenericParameterAttributes::SpecialConstraintMask;
      if ((genericParameterAttributes2 & GenericParameterAttributes::NotNullableValueTypeConstraint) != 0) {
        runtimeType = ValueType;
      }
    }
    return runtimeType;
  }
  return RuntimeTypeHandle::GetBaseType((RuntimeType)this);
}

void RuntimeType___::cctor() {
  ValueType = (RuntimeType)typeof<ValueType>();
  ObjectType = (RuntimeType)typeof<Object>();
  StringType = (RuntimeType)typeof<String>();
  s_typedRef = (RuntimeType)typeof<TypedReference>();
}

} // namespace System::Private::CoreLib::System::RuntimeTypeNamespace
