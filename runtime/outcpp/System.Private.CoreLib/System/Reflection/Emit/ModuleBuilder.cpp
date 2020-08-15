#include "ModuleBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ConstructorBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ConstructorOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/GenericTypeParameterBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilderData-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/PackingSize.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeAttributes.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderNamespace {
using namespace System::Collections::Generic;

AssemblyBuilder ModuleBuilder___::get_ContainingAssemblyBuilder() {
  return _assemblyBuilder;
}

Object ModuleBuilder___::get_SyncRoot() {
  return get_ContainingAssemblyBuilder()->get_SyncRoot();
}

InternalModuleBuilder ModuleBuilder___::get_InternalModule() {
  return _internalModuleBuilder;
}

String ModuleBuilder___::get_FullyQualifiedName() {
  return _moduleData->_moduleName;
}

Int32 ModuleBuilder___::get_MDStreamVersion() {
  return get_InternalModule()->get_MDStreamVersion();
}

Guid ModuleBuilder___::get_ModuleVersionId() {
  return get_InternalModule()->get_ModuleVersionId();
}

Int32 ModuleBuilder___::get_MetadataToken() {
  return get_InternalModule()->get_MetadataToken();
}

String ModuleBuilder___::get_ScopeName() {
  return get_InternalModule()->get_ScopeName();
}

String ModuleBuilder___::get_Name() {
  return get_InternalModule()->get_Name();
}

Assembly ModuleBuilder___::get_Assembly() {
  return _assemblyBuilder;
}

String ModuleBuilder___::UnmangleTypeName(String typeName) {
  Int32 startIndex = typeName->get_Length() - 1;
  while (true) {
    startIndex = typeName->LastIndexOf(43, startIndex);
    if (startIndex == -1) {
      break;
    }
    Boolean flag = true;
    Int32 num = startIndex;
    while (typeName[--num] == 92) {
      flag = !flag;
    }
    if (flag) {
      break;
    }
    startIndex = num;
  }
  return typeName->Substring(startIndex + 1);
}

void ModuleBuilder___::ctor(AssemblyBuilder assemblyBuilder, InternalModuleBuilder internalModuleBuilder) {
  _internalModuleBuilder = internalModuleBuilder;
  _assemblyBuilder = assemblyBuilder;
}

void ModuleBuilder___::AddType(String name, Type type) {
  _typeBuilderDict->Add(name, type);
}

void ModuleBuilder___::CheckTypeNameConflict(String strTypeName, Type enclosingType) {
  Type value;
  if (_typeBuilderDict->TryGetValue(strTypeName, value) && (Object)value->get_DeclaringType() == enclosingType) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DuplicateTypeName());
  }
}

Type ModuleBuilder___::GetType(String strFormat, Type baseType) {
  if (String::in::IsNullOrEmpty(strFormat)) {
    return baseType;
  }
  return SymbolType::in::FormCompoundType(strFormat, baseType, 0);
}

void ModuleBuilder___::CheckContext(Array<Array<Type>> typess) {
  AssemblyBuilder::in::CheckContext(rt::newarr<Array<Array<Type>>>(1, typess));
}

void ModuleBuilder___::CheckContext(Array<Type> types) {
  AssemblyBuilder::in::CheckContext(rt::newarr<Array<Type>>(1, types));
}

Int32 ModuleBuilder___::GetMemberRef(Module refedModule, Int32 tr, Int32 defToken) {
  ModuleBuilder module = (ModuleBuilder)this;
  RuntimeModule module2 = GetRuntimeModuleFromModule(refedModule);
  return GetMemberRef(QCallModule(module), QCallModule(module2), tr, defToken);
}

Int32 ModuleBuilder___::GetMemberRefFromSignature(Int32 tr, String methodName, Array<Byte> signature, Int32 length) {
  ModuleBuilder module = (ModuleBuilder)this;
  return GetMemberRefFromSignature(QCallModule(module), tr, methodName, signature, length);
}

Int32 ModuleBuilder___::GetMemberRefOfMethodInfo(Int32 tr, RuntimeMethodInfo method) {
  ModuleBuilder module = (ModuleBuilder)this;
  Int32 memberRefOfMethodInfo = GetMemberRefOfMethodInfo(QCallModule(module), tr, ((IRuntimeMethodInfo)method)->get_Value());
  GC::KeepAlive(method);
  return memberRefOfMethodInfo;
}

Int32 ModuleBuilder___::GetMemberRefOfMethodInfo(Int32 tr, RuntimeConstructorInfo method) {
  ModuleBuilder module = (ModuleBuilder)this;
  Int32 memberRefOfMethodInfo = GetMemberRefOfMethodInfo(QCallModule(module), tr, ((IRuntimeMethodInfo)method)->get_Value());
  GC::KeepAlive(method);
  return memberRefOfMethodInfo;
}

Int32 ModuleBuilder___::GetMemberRefOfFieldInfo(Int32 tkType, RuntimeTypeHandle declaringType, RuntimeFieldInfo runtimeField) {
  ModuleBuilder module = (ModuleBuilder)this;
  return GetMemberRefOfFieldInfo(QCallModule(module), tkType, QCallTypeHandle(declaringType), runtimeField->get_MetadataToken());
}

Int32 ModuleBuilder___::GetTokenFromTypeSpec(Array<Byte> signature, Int32 length) {
  ModuleBuilder module = (ModuleBuilder)this;
  return GetTokenFromTypeSpec(QCallModule(module), signature, length);
}

Type ModuleBuilder___::FindTypeBuilderWithName(String strTypeName, Boolean ignoreCase) {
  Type value;
  if (ignoreCase) {
  } else if (_typeBuilderDict->TryGetValue(strTypeName, value)) {
    return value;
  }

  return nullptr;
}

Int32 ModuleBuilder___::GetTypeRefNested(Type type, Module refedModule, String strRefedModuleFileName) {
  Type declaringType = type->get_DeclaringType();
  Int32 tkResolution = 0;
  String text = type->get_FullName();
  if (declaringType != nullptr) {
    tkResolution = GetTypeRefNested(declaringType, refedModule, strRefedModuleFileName);
    text = UnmangleTypeName(text);
  }
  ModuleBuilder module = (ModuleBuilder)this;
  RuntimeModule module2 = GetRuntimeModuleFromModule(refedModule);
  return GetTypeRef(QCallModule(module), text, QCallModule(module2), strRefedModuleFileName, tkResolution);
}

MethodToken ModuleBuilder___::InternalGetConstructorToken(ConstructorInfo con, Boolean usingRef) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  Int32 num = 0;
  ConstructorBuilder constructorBuilder = rt::as<ConstructorBuilder>(con);
  if ((Object)constructorBuilder != nullptr) {
    if (!usingRef && constructorBuilder->get_Module()->Equals((ModuleBuilder)this)) {
      return constructorBuilder->GetToken();
    }
    Int32 token = GetTypeTokenInternal(con->get_ReflectedType()).get_Token();
    num = GetMemberRef(con->get_ReflectedType()->get_Module(), token, constructorBuilder->GetToken().get_Token());
  } else {
    ConstructorOnTypeBuilderInstantiation constructorOnTypeBuilderInstantiation = rt::as<ConstructorOnTypeBuilderInstantiation>(con);
    if ((Object)constructorOnTypeBuilderInstantiation != nullptr) {
      if (usingRef) {
        rt::throw_exception<InvalidOperationException>();
      }
      Int32 token = GetTypeTokenInternal(con->get_DeclaringType()).get_Token();
      num = GetMemberRef(con->get_DeclaringType()->get_Module(), token, constructorOnTypeBuilderInstantiation->get_MetadataTokenInternal());
    } else {
      RuntimeConstructorInfo runtimeConstructorInfo = rt::as<RuntimeConstructorInfo>(con);
      if ((Object)runtimeConstructorInfo != nullptr && !con->get_ReflectedType()->get_IsArray()) {
        Int32 token = GetTypeTokenInternal(con->get_ReflectedType()).get_Token();
        num = GetMemberRefOfMethodInfo(token, runtimeConstructorInfo);
      } else {
        Array<ParameterInfo> parameters = con->GetParameters();
        if (parameters == nullptr) {
          rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidConstructorInfo());
        }
        Array<Type> array = rt::newarr<Array<Type>>(parameters->get_Length());
        Array<Type> array2 = rt::newarr<Array<Array<Type>>>(parameters->get_Length());
        Array<Type> array3 = rt::newarr<Array<Array<Type>>>(parameters->get_Length());
        for (Int32 i = 0; i < parameters->get_Length(); i++) {
          if (parameters[i] == nullptr) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidConstructorInfo());
          }
          array[i] = parameters[i]->get_ParameterType();
          array2[i] = parameters[i]->GetRequiredCustomModifiers();
          array3[i] = parameters[i]->GetOptionalCustomModifiers();
        }
        Int32 token = GetTypeTokenInternal(con->get_ReflectedType()).get_Token();
        SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper((ModuleBuilder)this, con->get_CallingConvention(), nullptr, nullptr, nullptr, array, array2, array3);
        Int32 length;
        Array<Byte> signature = methodSigHelper->InternalGetSignature(length);
        num = GetMemberRefFromSignature(token, con->get_Name(), signature, length);
      }
    }
  }
  return MethodToken(num);
}

void ModuleBuilder___::Init(String strModuleName) {
  _moduleData = rt::newobj<ModuleBuilderData>((ModuleBuilder)this, strModuleName);
  _typeBuilderDict = rt::newobj<Dictionary<String, Type>>();
}

void ModuleBuilder___::SetSymWriter(ISymbolWriter writer) {
  _iSymWriter = writer;
}

ModuleHandle ModuleBuilder___::GetModuleHandleImpl() {
  return ModuleHandle(GetNativeHandle());
}

RuntimeModule ModuleBuilder___::GetNativeHandle() {
  return get_InternalModule()->GetNativeHandle();
}

RuntimeModule ModuleBuilder___::GetRuntimeModuleFromModule(Module m) {
  ModuleBuilder moduleBuilder = rt::as<ModuleBuilder>(m);
  if (moduleBuilder != nullptr) {
    return moduleBuilder->get_InternalModule();
  }
  return rt::as<RuntimeModule>(m);
}

Int32 ModuleBuilder___::GetMemberRefToken(MethodBase method, IEnumerable<Type> optionalParameterTypes) {
  Int32 cGenericParameters = 0;
  if (method->get_IsGenericMethod()) {
    if (!method->get_IsGenericMethodDefinition()) {
      rt::throw_exception<InvalidOperationException>();
    }
    cGenericParameters = method->GetGenericArguments()->get_Length();
  }
  if (optionalParameterTypes != nullptr && (method->get_CallingConvention() & CallingConventions::VarArgs) == 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotAVarArgCallingConvention());
  }
  MethodInfo methodInfo = rt::as<MethodInfo>(method);
  Array<Type> parameterTypes;
  Type methodBaseReturnType;
  if (method->get_DeclaringType()->get_IsGenericType()) {
    MethodOnTypeBuilderInstantiation methodOnTypeBuilderInstantiation = rt::as<MethodOnTypeBuilderInstantiation>(method);
    MethodBase methodBase;
    if ((Object)methodOnTypeBuilderInstantiation != nullptr) {
      methodBase = methodOnTypeBuilderInstantiation->m_method;
    } else {
      ConstructorOnTypeBuilderInstantiation constructorOnTypeBuilderInstantiation = rt::as<ConstructorOnTypeBuilderInstantiation>(method);
      if ((Object)constructorOnTypeBuilderInstantiation != nullptr) {
        methodBase = constructorOnTypeBuilderInstantiation->m_ctor;
      } else if (rt::is<MethodBuilder>(method) || rt::is<ConstructorBuilder>(method)) {
        methodBase = method;
      } else if (method->get_IsGenericMethod()) {
        methodBase = methodInfo->GetGenericMethodDefinition();
        auto& default = methodBase->get_DeclaringType();
        methodBase = methodBase->get_Module()->ResolveMethod(method->get_MetadataToken(), default == nullptr ? nullptr : default->GetGenericArguments(), methodBase->GetGenericArguments());
      } else {
        auto& default = method->get_DeclaringType();
        methodBase = method->get_Module()->ResolveMethod(method->get_MetadataToken(), default == nullptr ? nullptr : default->GetGenericArguments(), nullptr);
      }


    }
    parameterTypes = methodBase->GetParameterTypes();
    methodBaseReturnType = MethodBuilder::in::GetMethodBaseReturnType(methodBase);
  } else {
    parameterTypes = method->GetParameterTypes();
    methodBaseReturnType = MethodBuilder::in::GetMethodBaseReturnType(method);
  }
  Int32 length;
  Array<Byte> signature = GetMemberRefSignature(method->get_CallingConvention(), methodBaseReturnType, parameterTypes, optionalParameterTypes, cGenericParameters)->InternalGetSignature(length);
  Int32 tr;
  if (!method->get_DeclaringType()->get_IsGenericType()) {
    tr = ((!method->get_Module()->Equals((ModuleBuilder)this)) ? GetTypeToken(method->get_DeclaringType()).get_Token() : ((!(methodInfo != nullptr)) ? GetConstructorToken(rt::as<ConstructorInfo>(method)).get_Token() : GetMethodToken(methodInfo).get_Token()));
  } else {
    Int32 length2;
    Array<Byte> signature2 = SignatureHelper::in::GetTypeSigToken((ModuleBuilder)this, method->get_DeclaringType())->InternalGetSignature(length2);
    tr = GetTokenFromTypeSpec(signature2, length2);
  }
  return GetMemberRefFromSignature(tr, method->get_Name(), signature, length);
}

SignatureHelper ModuleBuilder___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, IEnumerable<Type> optionalParameterTypes, Int32 cGenericParameters) {
  SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper((ModuleBuilder)this, call, returnType, cGenericParameters);
  if (parameterTypes != nullptr) {
  }
  if (optionalParameterTypes != nullptr) {
    Int32 num = 0;
    {
    }}
  return methodSigHelper;
}

Boolean ModuleBuilder___::Equals(Object obj) {
  return get_InternalModule()->Equals(obj);
}

Int32 ModuleBuilder___::GetHashCode() {
  return get_InternalModule()->GetHashCode();
}

Array<Object> ModuleBuilder___::GetCustomAttributes(Boolean inherit) {
  return get_InternalModule()->GetCustomAttributes(inherit);
}

Array<Object> ModuleBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return get_InternalModule()->GetCustomAttributes(attributeType, inherit);
}

Boolean ModuleBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return get_InternalModule()->IsDefined(attributeType, inherit);
}

IList<CustomAttributeData> ModuleBuilder___::GetCustomAttributesData() {
  return get_InternalModule()->GetCustomAttributesData();
}

Array<Type> ModuleBuilder___::GetTypes() {
  {
    rt::lock(get_SyncRoot());
    return GetTypesNoLock();
  }
}

Array<Type> ModuleBuilder___::GetTypesNoLock() {
  Array<Type> array = rt::newarr<Array<Type>>(_typeBuilderDict->get_Count());
  Int32 num = 0;
}

Type ModuleBuilder___::GetType(String className) {
  return GetType(className, false, false);
}

Type ModuleBuilder___::GetType(String className, Boolean ignoreCase) {
  return GetType(className, false, ignoreCase);
}

Type ModuleBuilder___::GetType(String className, Boolean throwOnError, Boolean ignoreCase) {
  {
    rt::lock(get_SyncRoot());
    return GetTypeNoLock(className, throwOnError, ignoreCase);
  }
}

Type ModuleBuilder___::GetTypeNoLock(String className, Boolean throwOnError, Boolean ignoreCase) {
  Type type = get_InternalModule()->GetType(className, throwOnError, ignoreCase);
  if (type != nullptr) {
    return type;
  }
  String text = nullptr;
  String text2 = nullptr;
  Int32 num = 0;
  while (num <= className->get_Length()) {
    Int32 num2 = MemoryExtensions::IndexOfAny(MemoryExtensions::AsSpan(className, num), 91, 42, 38);
    if (num2 == -1) {
      text = className;
      text2 = nullptr;
      break;
    }
    num2 += num;
    Int32 num3 = 0;
    Int32 num4 = num2 - 1;
    while (num4 >= 0 && className[num4] == 92) {
      num3++;
      num4--;
    }
    if (num3 % 2 == 1) {
      num = num2 + 1;
      continue;
    }
    text = className->Substring(0, num2);
    text2 = className->Substring(num2);
    break;
  }
  if (text == nullptr) {
    text = className;
    text2 = nullptr;
  }
  text = text->Replace("\\", "\")->Replace("\[", "[")->Replace("\*", "*")->Replace("\&", "&");
  if (text2 != nullptr) {
    type = get_InternalModule()->GetType(text, false, ignoreCase);
  }
  if (type == nullptr) {
    type = FindTypeBuilderWithName(text, ignoreCase);
    if (type == nullptr && rt::is<AssemblyBuilder>(get_Assembly())) {
      List<ModuleBuilder> moduleBuilderList = get_ContainingAssemblyBuilder()->_assemblyData->_moduleBuilderList;
      Int32 count = moduleBuilderList->get_Count();
      for (Int32 i = 0; i < count; i++) {
        if (!(type == nullptr)) {
          break;
        }
        ModuleBuilder moduleBuilder = moduleBuilderList[i];
        type = moduleBuilder->FindTypeBuilderWithName(text, ignoreCase);
      }
    }
    if (type == nullptr) {
      return nullptr;
    }
  }
  if (text2 == nullptr) {
    return type;
  }
  return GetType(text2, type);
}

Array<Byte> ModuleBuilder___::ResolveSignature(Int32 metadataToken) {
  return get_InternalModule()->ResolveSignature(metadataToken);
}

MethodBase ModuleBuilder___::ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return get_InternalModule()->ResolveMethod(metadataToken, genericTypeArguments, genericMethodArguments);
}

FieldInfo ModuleBuilder___::ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return get_InternalModule()->ResolveField(metadataToken, genericTypeArguments, genericMethodArguments);
}

Type ModuleBuilder___::ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return get_InternalModule()->ResolveType(metadataToken, genericTypeArguments, genericMethodArguments);
}

MemberInfo ModuleBuilder___::ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return get_InternalModule()->ResolveMember(metadataToken, genericTypeArguments, genericMethodArguments);
}

String ModuleBuilder___::ResolveString(Int32 metadataToken) {
  return get_InternalModule()->ResolveString(metadataToken);
}

void ModuleBuilder___::GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine) {
  get_InternalModule()->GetPEKind(peKind, machine);
}

Boolean ModuleBuilder___::IsResource() {
  return get_InternalModule()->IsResource();
}

Array<FieldInfo> ModuleBuilder___::GetFields(BindingFlags bindingFlags) {
  return get_InternalModule()->GetFields(bindingFlags);
}

FieldInfo ModuleBuilder___::GetField(String name, BindingFlags bindingAttr) {
  return get_InternalModule()->GetField(name, bindingAttr);
}

Array<MethodInfo> ModuleBuilder___::GetMethods(BindingFlags bindingFlags) {
  return get_InternalModule()->GetMethods(bindingFlags);
}

MethodInfo ModuleBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return get_InternalModule()->GetMethodInternal(name, bindingAttr, binder, callConvention, types, modifiers);
}

TypeBuilder ModuleBuilder___::DefineType(String name) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, TypeAttributes::NotPublic, nullptr, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, attr, nullptr, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent) {
  {
    rt::lock(get_SyncRoot());
    CheckContext(rt::newarr<Array<Type>>(1, parent));
    return DefineTypeNoLock(name, attr, parent, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, Int32 typesize) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, attr, parent, nullptr, PackingSize::Unspecified, typesize);
  }
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, PackingSize packingSize, Int32 typesize) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, attr, parent, nullptr, packingSize, typesize);
  }
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, attr, parent, interfaces, PackingSize::Unspecified, 0);
  }
}

TypeBuilder ModuleBuilder___::DefineTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packingSize, Int32 typesize) {
  return rt::newobj<TypeBuilder>(name, attr, parent, interfaces, (ModuleBuilder)this, packingSize, typesize, nullptr);
}

TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, PackingSize packsize) {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeNoLock(name, attr, parent, packsize);
  }
}

TypeBuilder ModuleBuilder___::DefineTypeNoLock(String name, TypeAttributes attr, Type parent, PackingSize packsize) {
  return rt::newobj<TypeBuilder>(name, attr, parent, nullptr, (ModuleBuilder)this, packsize, 0, nullptr);
}

EnumBuilder ModuleBuilder___::DefineEnum(String name, TypeAttributes visibility, Type underlyingType) {
  CheckContext(rt::newarr<Array<Type>>(1, underlyingType));
  {
    rt::lock(get_SyncRoot());
    EnumBuilder enumBuilder = DefineEnumNoLock(name, visibility, underlyingType);
    _typeBuilderDict[name] = enumBuilder;
    return enumBuilder;
  }
}

EnumBuilder ModuleBuilder___::DefineEnumNoLock(String name, TypeAttributes visibility, Type underlyingType) {
  return rt::newobj<EnumBuilder>(name, underlyingType, visibility, (ModuleBuilder)this);
}

MethodBuilder ModuleBuilder___::DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return DefinePInvokeMethod(name, dllName, name, attributes, callingConvention, returnType, parameterTypes, nativeCallConv, nativeCharSet);
}

MethodBuilder ModuleBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  {
    rt::lock(get_SyncRoot());
    if ((attributes & MethodAttributes::Static) == 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_GlobalFunctionHasToBeStatic());
    }
    CheckContext(rt::newarr<Array<Type>>(1, returnType));
    CheckContext(rt::newarr<Array<Type>>(1, parameterTypes));
    return _moduleData->_globalTypeBuilder->DefinePInvokeMethod(name, dllName, entryName, attributes, callingConvention, returnType, parameterTypes, nativeCallConv, nativeCharSet);
  }
}

MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return DefineGlobalMethod(name, attributes, CallingConventions::Standard, returnType, parameterTypes);
}

MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return DefineGlobalMethod(name, attributes, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  {
    rt::lock(get_SyncRoot());
    return DefineGlobalMethodNoLock(name, attributes, callingConvention, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers, parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
  }
}

MethodBuilder ModuleBuilder___::DefineGlobalMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  if (_moduleData->_hasGlobalBeenCreated) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_GlobalsHaveBeenCreated());
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if ((attributes & MethodAttributes::Static) == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_GlobalFunctionHasToBeStatic());
  }
  CheckContext(rt::newarr<Array<Type>>(1, returnType));
  CheckContext(rt::newarr<Array<Array<Type>>>(3, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers, parameterTypes));
  CheckContext(rt::newarr<Array<Array<Type>>>(1, requiredParameterTypeCustomModifiers));
  CheckContext(rt::newarr<Array<Array<Type>>>(1, optionalParameterTypeCustomModifiers));
  return _moduleData->_globalTypeBuilder->DefineMethod(name, attributes, callingConvention, returnType, requiredReturnTypeCustomModifiers, optionalReturnTypeCustomModifiers, parameterTypes, requiredParameterTypeCustomModifiers, optionalParameterTypeCustomModifiers);
}

void ModuleBuilder___::CreateGlobalFunctions() {
  {
    rt::lock(get_SyncRoot());
    CreateGlobalFunctionsNoLock();
  }
}

void ModuleBuilder___::CreateGlobalFunctionsNoLock() {
  if (_moduleData->_hasGlobalBeenCreated) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotADebugModule());
  }
  _moduleData->_globalTypeBuilder->CreateType();
  _moduleData->_hasGlobalBeenCreated = true;
}

FieldBuilder ModuleBuilder___::DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes) {
  {
    rt::lock(get_SyncRoot());
    return DefineInitializedDataNoLock(name, data, attributes);
  }
}

FieldBuilder ModuleBuilder___::DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes) {
  if (_moduleData->_hasGlobalBeenCreated) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_GlobalsHaveBeenCreated());
  }
  return _moduleData->_globalTypeBuilder->DefineInitializedData(name, data, attributes);
}

FieldBuilder ModuleBuilder___::DefineUninitializedData(String name, Int32 size, FieldAttributes attributes) {
  {
    rt::lock(get_SyncRoot());
    return DefineUninitializedDataNoLock(name, size, attributes);
  }
}

FieldBuilder ModuleBuilder___::DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes) {
  if (_moduleData->_hasGlobalBeenCreated) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_GlobalsHaveBeenCreated());
  }
  return _moduleData->_globalTypeBuilder->DefineUninitializedData(name, size, attributes);
}

TypeToken ModuleBuilder___::GetTypeTokenInternal(Type type) {
  return GetTypeTokenInternal(type, false);
}

TypeToken ModuleBuilder___::GetTypeTokenInternal(Type type, Boolean getGenericDefinition) {
  {
    rt::lock(get_SyncRoot());
    return GetTypeTokenWorkerNoLock(type, getGenericDefinition);
  }
}

TypeToken ModuleBuilder___::GetTypeToken(Type type) {
  return GetTypeTokenInternal(type, true);
}

TypeToken ModuleBuilder___::GetTypeTokenWorkerNoLock(Type type, Boolean getGenericDefinition) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  CheckContext(rt::newarr<Array<Type>>(1, type));
  if (type->get_IsByRef()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_CannotGetTypeTokenForByRef());
  }
  if ((type->get_IsGenericType() && (!type->get_IsGenericTypeDefinition() || !getGenericDefinition)) || type->get_IsGenericParameter() || type->get_IsArray() || type->get_IsPointer()) {
    Int32 length;
    Array<Byte> signature = SignatureHelper::in::GetTypeSigToken((ModuleBuilder)this, type)->InternalGetSignature(length);
    return TypeToken(GetTokenFromTypeSpec(signature, length));
  }
  Module module = type->get_Module();
  if (module->Equals((ModuleBuilder)this)) {
    TypeBuilder typeBuilder = nullptr;
    EnumBuilder enumBuilder = rt::as<EnumBuilder>(type);
    typeBuilder = ((enumBuilder != nullptr) ? enumBuilder->m_typeBuilder : (rt::as<TypeBuilder>(type)));
    if (typeBuilder != nullptr) {
      return typeBuilder->get_TypeToken();
    }
    GenericTypeParameterBuilder genericTypeParameterBuilder = rt::as<GenericTypeParameterBuilder>(type);
    if ((Object)genericTypeParameterBuilder != nullptr) {
      return TypeToken(genericTypeParameterBuilder->get_MetadataTokenInternal());
    }
    return TypeToken(GetTypeRefNested(type, (ModuleBuilder)this, String::in::Empty));
  }
  ModuleBuilder moduleBuilder = rt::as<ModuleBuilder>(module);
  String strRefedModuleFileName = String::in::Empty;
  if (module->get_Assembly()->Equals(get_Assembly())) {
    if (moduleBuilder == nullptr) {
      moduleBuilder = get_ContainingAssemblyBuilder()->GetModuleBuilder((InternalModuleBuilder)module);
    }
    strRefedModuleFileName = moduleBuilder->_moduleData->_moduleName;
  }
  return TypeToken(GetTypeRefNested(type, module, strRefedModuleFileName));
}

TypeToken ModuleBuilder___::GetTypeToken(String name) {
  return GetTypeToken(get_InternalModule()->GetType(name, false, true));
}

MethodToken ModuleBuilder___::GetMethodToken(MethodInfo method) {
  {
    rt::lock(get_SyncRoot());
    return GetMethodTokenNoLock(method, true);
  }
}

MethodToken ModuleBuilder___::GetMethodTokenInternal(MethodInfo method) {
  {
    rt::lock(get_SyncRoot());
    return GetMethodTokenNoLock(method, false);
  }
}

MethodToken ModuleBuilder___::GetMethodTokenNoLock(MethodInfo method, Boolean getGenericTypeDefinition) {
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  Int32 num = 0;
  MethodBuilder methodBuilder = rt::as<MethodBuilder>(method);
  if ((Object)methodBuilder != nullptr) {
    Int32 metadataTokenInternal = methodBuilder->get_MetadataTokenInternal();
    if (method->get_Module()->Equals((ModuleBuilder)this)) {
      return MethodToken(metadataTokenInternal);
    }
    if (method->get_DeclaringType() == nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotImportGlobalFromDifferentModule());
    }
    Int32 tr = getGenericTypeDefinition ? GetTypeToken(method->get_DeclaringType()).get_Token() : GetTypeTokenInternal(method->get_DeclaringType()).get_Token();
    num = GetMemberRef(method->get_DeclaringType()->get_Module(), tr, metadataTokenInternal);
  } else {
    if (rt::is<MethodOnTypeBuilderInstantiation>(method)) {
      return MethodToken(GetMemberRefToken(method, nullptr));
    }
    SymbolMethod symbolMethod = rt::as<SymbolMethod>(method);
    if ((Object)symbolMethod != nullptr) {
      if (symbolMethod->GetModule() == (ModuleBuilder)this) {
        return symbolMethod->GetToken();
      }
      return symbolMethod->GetToken((ModuleBuilder)this);
    }
    Type declaringType = method->get_DeclaringType();
    if (declaringType == nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotImportGlobalFromDifferentModule());
    }
    if (declaringType->get_IsArray()) {
      Array<ParameterInfo> parameters = method->GetParameters();
      Array<Type> array = rt::newarr<Array<Type>>(parameters->get_Length());
      for (Int32 i = 0; i < parameters->get_Length(); i++) {
        array[i] = parameters[i]->get_ParameterType();
      }
      return GetArrayMethodToken(declaringType, method->get_Name(), method->get_CallingConvention(), method->get_ReturnType(), array);
    }
    RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(method);
    if ((Object)runtimeMethodInfo != nullptr) {
      Int32 tr = getGenericTypeDefinition ? GetTypeToken(declaringType).get_Token() : GetTypeTokenInternal(declaringType).get_Token();
      num = GetMemberRefOfMethodInfo(tr, runtimeMethodInfo);
    } else {
      Array<ParameterInfo> parameters2 = method->GetParameters();
      Array<Type> array2 = rt::newarr<Array<Type>>(parameters2->get_Length());
      Array<Type> array3 = rt::newarr<Array<Array<Type>>>(array2->get_Length());
      Array<Type> array4 = rt::newarr<Array<Array<Type>>>(array2->get_Length());
      for (Int32 j = 0; j < parameters2->get_Length(); j++) {
        array2[j] = parameters2[j]->get_ParameterType();
        array3[j] = parameters2[j]->GetRequiredCustomModifiers();
        array4[j] = parameters2[j]->GetOptionalCustomModifiers();
      }
      Int32 tr = getGenericTypeDefinition ? GetTypeToken(declaringType).get_Token() : GetTypeTokenInternal(declaringType).get_Token();
      SignatureHelper methodSigHelper;
      try {
        methodSigHelper = SignatureHelper::in::GetMethodSigHelper((ModuleBuilder)this, method->get_CallingConvention(), method->get_ReturnType(), method->get_ReturnParameter()->GetRequiredCustomModifiers(), method->get_ReturnParameter()->GetOptionalCustomModifiers(), array2, array3, array4);
      } catch (NotImplementedException) {
      }
      Int32 length;
      Array<Byte> signature = methodSigHelper->InternalGetSignature(length);
      num = GetMemberRefFromSignature(tr, method->get_Name(), signature, length);
    }
  }
  return MethodToken(num);
}

Int32 ModuleBuilder___::GetMethodTokenInternal(MethodBase method, IEnumerable<Type> optionalParameterTypes, Boolean useMethodDef) {
  MethodInfo methodInfo = rt::as<MethodInfo>(method);
  if (method->get_IsGenericMethod()) {
    MethodInfo methodInfo2 = methodInfo;
    Boolean isGenericMethodDefinition = methodInfo->get_IsGenericMethodDefinition();
    if (!isGenericMethodDefinition) {
      methodInfo2 = methodInfo->GetGenericMethodDefinition();
    }
    Int32 num = (Equals(methodInfo2->get_Module()) && (!(methodInfo2->get_DeclaringType() != nullptr) || !methodInfo2->get_DeclaringType()->get_IsGenericType())) ? GetMethodTokenInternal(methodInfo2).get_Token() : GetMemberRefToken(methodInfo2, nullptr);
    if (isGenericMethodDefinition && useMethodDef) {
      return num;
    }
    Int32 length;
    Array<Byte> signature = SignatureHelper::in::GetMethodSpecSigHelper((ModuleBuilder)this, methodInfo->GetGenericArguments())->InternalGetSignature(length);
    ModuleBuilder module = (ModuleBuilder)this;
    return TypeBuilder::in::DefineMethodSpec(QCallModule(module), num, signature, length);
  }
  if ((method->get_CallingConvention() & CallingConventions::VarArgs) == 0 && (method->get_DeclaringType() == nullptr || !method->get_DeclaringType()->get_IsGenericType())) {
    if (methodInfo != nullptr) {
      return GetMethodTokenInternal(methodInfo).get_Token();
    }
    return GetConstructorToken(rt::as<ConstructorInfo>(method)).get_Token();
  }
  return GetMemberRefToken(method, optionalParameterTypes);
}

MethodToken ModuleBuilder___::GetArrayMethodToken(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  {
    rt::lock(get_SyncRoot());
    return GetArrayMethodTokenNoLock(arrayClass, methodName, callingConvention, returnType, parameterTypes);
  }
}

MethodToken ModuleBuilder___::GetArrayMethodTokenNoLock(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  if (arrayClass == nullptr) {
    rt::throw_exception<ArgumentNullException>("arrayClass");
  }
  if (methodName == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodName");
  }
  if (methodName->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "methodName");
  }
  if (!arrayClass->get_IsArray()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
  }
  CheckContext(rt::newarr<Array<Type>>(2, returnType, arrayClass));
  CheckContext(rt::newarr<Array<Type>>(1, parameterTypes));
  SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper((ModuleBuilder)this, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
  Int32 length;
  Array<Byte> signature = methodSigHelper->InternalGetSignature(length);
  TypeToken typeTokenInternal = GetTypeTokenInternal(arrayClass);
  ModuleBuilder module = (ModuleBuilder)this;
  return MethodToken(GetArrayMethodToken(QCallModule(module), typeTokenInternal.get_Token(), methodName, signature, length));
}

MethodInfo ModuleBuilder___::GetArrayMethod(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  CheckContext(rt::newarr<Array<Type>>(2, returnType, arrayClass));
  CheckContext(rt::newarr<Array<Type>>(1, parameterTypes));
  MethodToken arrayMethodToken = GetArrayMethodToken(arrayClass, methodName, callingConvention, returnType, parameterTypes);
  return rt::newobj<SymbolMethod>((ModuleBuilder)this, arrayMethodToken, arrayClass, methodName, callingConvention, returnType, parameterTypes);
}

MethodToken ModuleBuilder___::GetConstructorToken(ConstructorInfo con) {
  return InternalGetConstructorToken(con, false);
}

FieldToken ModuleBuilder___::GetFieldToken(FieldInfo field) {
  {
    rt::lock(get_SyncRoot());
    return GetFieldTokenNoLock(field);
  }
}

FieldToken ModuleBuilder___::GetFieldTokenNoLock(FieldInfo field) {
  if (field == nullptr) {
    rt::throw_exception<ArgumentNullException>("field");
  }
  Int32 num = 0;
  FieldBuilder fieldBuilder = rt::as<FieldBuilder>(field);
  if ((Object)fieldBuilder != nullptr) {
    if (field->get_DeclaringType() != nullptr && field->get_DeclaringType()->get_IsGenericType()) {
      Int32 length;
      Array<Byte> signature = SignatureHelper::in::GetTypeSigToken((ModuleBuilder)this, field->get_DeclaringType())->InternalGetSignature(length);
      Int32 tokenFromTypeSpec = GetTokenFromTypeSpec(signature, length);
      num = GetMemberRef((ModuleBuilder)this, tokenFromTypeSpec, fieldBuilder->GetToken().get_Token());
    } else {
      if (fieldBuilder->get_Module()->Equals((ModuleBuilder)this)) {
        return fieldBuilder->GetToken();
      }
      if (field->get_DeclaringType() == nullptr) {
        rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotImportGlobalFromDifferentModule());
      }
      Int32 tokenFromTypeSpec = GetTypeTokenInternal(field->get_DeclaringType()).get_Token();
      num = GetMemberRef(field->get_ReflectedType()->get_Module(), tokenFromTypeSpec, fieldBuilder->GetToken().get_Token());
    }
  } else {
    RuntimeFieldInfo runtimeFieldInfo = rt::as<RuntimeFieldInfo>(field);
    if ((Object)runtimeFieldInfo != nullptr) {
      if (field->get_DeclaringType() == nullptr) {
        rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotImportGlobalFromDifferentModule());
      }
      if (field->get_DeclaringType() != nullptr && field->get_DeclaringType()->get_IsGenericType()) {
        Int32 length2;
        Array<Byte> signature2 = SignatureHelper::in::GetTypeSigToken((ModuleBuilder)this, field->get_DeclaringType())->InternalGetSignature(length2);
        Int32 tokenFromTypeSpec = GetTokenFromTypeSpec(signature2, length2);
        num = GetMemberRefOfFieldInfo(tokenFromTypeSpec, field->get_DeclaringType()->GetTypeHandleInternal(), runtimeFieldInfo);
      } else {
        Int32 tokenFromTypeSpec = GetTypeTokenInternal(field->get_DeclaringType()).get_Token();
        num = GetMemberRefOfFieldInfo(tokenFromTypeSpec, field->get_DeclaringType()->GetTypeHandleInternal(), runtimeFieldInfo);
      }
    } else {
      FieldOnTypeBuilderInstantiation fieldOnTypeBuilderInstantiation = rt::as<FieldOnTypeBuilderInstantiation>(field);
      if ((Object)fieldOnTypeBuilderInstantiation != nullptr) {
        FieldInfo fieldInfo = fieldOnTypeBuilderInstantiation->get_FieldInfo();
        Int32 length3;
        Array<Byte> signature3 = SignatureHelper::in::GetTypeSigToken((ModuleBuilder)this, field->get_DeclaringType())->InternalGetSignature(length3);
        Int32 tokenFromTypeSpec = GetTokenFromTypeSpec(signature3, length3);
        num = GetMemberRef(fieldInfo->get_ReflectedType()->get_Module(), tokenFromTypeSpec, fieldOnTypeBuilderInstantiation->get_MetadataTokenInternal());
      } else {
        Int32 tokenFromTypeSpec = GetTypeTokenInternal(field->get_ReflectedType()).get_Token();
        SignatureHelper fieldSigHelper = SignatureHelper::in::GetFieldSigHelper((ModuleBuilder)this);
        fieldSigHelper->AddArgument(field->get_FieldType(), field->GetRequiredCustomModifiers(), field->GetOptionalCustomModifiers());
        Int32 length4;
        Array<Byte> signature4 = fieldSigHelper->InternalGetSignature(length4);
        num = GetMemberRefFromSignature(tokenFromTypeSpec, field->get_Name(), signature4, length4);
      }
    }
  }
  return FieldToken(num, field->GetType());
}

StringToken ModuleBuilder___::GetStringConstant(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  ModuleBuilder module = (ModuleBuilder)this;
  return StringToken(GetStringConstant(QCallModule(module), str, str->get_Length()));
}

SignatureToken ModuleBuilder___::GetSignatureToken(SignatureHelper sigHelper) {
  if (sigHelper == nullptr) {
    rt::throw_exception<ArgumentNullException>("sigHelper");
  }
  Int32 length;
  Array<Byte> signature = sigHelper->InternalGetSignature(length);
  ModuleBuilder module = (ModuleBuilder)this;
  return SignatureToken(TypeBuilder::in::GetTokenFromSig(QCallModule(module), signature, length));
}

SignatureToken ModuleBuilder___::GetSignatureToken(Array<Byte> sigBytes, Int32 sigLength) {
  if (sigBytes == nullptr) {
    rt::throw_exception<ArgumentNullException>("sigBytes");
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(sigBytes->get_Length());
  Buffer::BlockCopy(sigBytes, 0, array, 0, sigBytes->get_Length());
  ModuleBuilder module = (ModuleBuilder)this;
  return SignatureToken(TypeBuilder::in::GetTokenFromSig(QCallModule(module), array, sigLength));
}

void ModuleBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  TypeBuilder::in::DefineCustomAttribute((ModuleBuilder)this, 1, GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void ModuleBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  customBuilder->CreateCustomAttribute((ModuleBuilder)this, 1);
}

ISymbolWriter ModuleBuilder___::GetSymWriter() {
  return _iSymWriter;
}

ISymbolDocumentWriter ModuleBuilder___::DefineDocument(String url, Guid language, Guid languageVendor, Guid documentType) {
  if (url == nullptr) {
    rt::throw_exception<ArgumentNullException>("url");
  }
  {
    rt::lock(get_SyncRoot());
    return DefineDocumentNoLock(url, language, languageVendor, documentType);
  }
}

ISymbolDocumentWriter ModuleBuilder___::DefineDocumentNoLock(String url, Guid language, Guid languageVendor, Guid documentType) {
  if (_iSymWriter == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotADebugModule());
  }
  return _iSymWriter->DefineDocument(url, language, languageVendor, documentType);
}

Boolean ModuleBuilder___::IsTransient() {
  return get_InternalModule()->IsTransientInternal();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderNamespace
