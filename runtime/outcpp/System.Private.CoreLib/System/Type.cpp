#include "Type-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Comparer-dep.h>
#include <System.Private.CoreLib/System/Collections/IComparer.h>
#include <System.Private.CoreLib/System/DefaultBinder-dep.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/FieldAttributes.h>
#include <System.Private.CoreLib/System/Reflection/InvalidFilterCriteriaException-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/Reflection/Missing-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureConstructedGenericType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureGenericMethodParameterType-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeAttributes.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypedReference-dep.h>
#include <System.Private.CoreLib/System/TypeNameParser-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>

namespace System::Private::CoreLib::System::TypeNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Threading;

void Type___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void Type___::__c___::ctor() {
}

Boolean Type___::__c___::_cctor_b__272_0(MemberInfo m, Object c) {
  return FilterNameImpl(m, c, StringComparison::Ordinal);
}

Boolean Type___::__c___::_cctor_b__272_1(MemberInfo m, Object c) {
  return FilterNameImpl(m, c, StringComparison::OrdinalIgnoreCase);
}

Boolean Type___::get_IsInterface() {
  RuntimeType runtimeType = rt::as<RuntimeType>((Type)this);
  if ((Object)runtimeType != nullptr) {
    return RuntimeTypeHandle::IsInterface(runtimeType);
  }
  return (GetAttributeFlagsImpl() & TypeAttributes::ClassSemanticsMask) == TypeAttributes::ClassSemanticsMask;
}

MemberTypes Type___::get_MemberType() {
  return MemberTypes::TypeInfo;
}

Boolean Type___::get_IsNested() {
  return get_DeclaringType() != nullptr;
}

Type Type___::get_DeclaringType() {
  return nullptr;
}

MethodBase Type___::get_DeclaringMethod() {
  return nullptr;
}

Type Type___::get_ReflectedType() {
  return nullptr;
}

Boolean Type___::get_IsTypeDefinition() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Type___::get_IsArray() {
  return IsArrayImpl();
}

Boolean Type___::get_IsByRef() {
  return IsByRefImpl();
}

Boolean Type___::get_IsPointer() {
  return IsPointerImpl();
}

Boolean Type___::get_IsConstructedGenericType() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Type___::get_IsGenericParameter() {
  return false;
}

Boolean Type___::get_IsGenericTypeParameter() {
  if (get_IsGenericParameter()) {
    return (Object)get_DeclaringMethod() == nullptr;
  }
  return false;
}

Boolean Type___::get_IsGenericMethodParameter() {
  if (get_IsGenericParameter()) {
    return get_DeclaringMethod() != nullptr;
  }
  return false;
}

Boolean Type___::get_IsGenericType() {
  return false;
}

Boolean Type___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean Type___::get_IsSZArray() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Type___::get_IsVariableBoundArray() {
  if (get_IsArray()) {
    return !get_IsSZArray();
  }
  return false;
}

Boolean Type___::get_IsByRefLike() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Boolean Type___::get_HasElementType() {
  return HasElementTypeImpl();
}

Array<Type> Type___::get_GenericTypeArguments() {
  if (!get_IsGenericType() || get_IsGenericTypeDefinition()) {
    return Array<>::in::Empty<Type>();
  }
  return GetGenericArguments();
}

Int32 Type___::get_GenericParameterPosition() {
  rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
}

GenericParameterAttributes Type___::get_GenericParameterAttributes() {
  rt::throw_exception<NotSupportedException>();
}

TypeAttributes Type___::get_Attributes() {
  return GetAttributeFlagsImpl();
}

Boolean Type___::get_IsAbstract() {
  return (GetAttributeFlagsImpl() & TypeAttributes::Abstract) != 0;
}

Boolean Type___::get_IsImport() {
  return (GetAttributeFlagsImpl() & TypeAttributes::Import) != 0;
}

Boolean Type___::get_IsSealed() {
  return (GetAttributeFlagsImpl() & TypeAttributes::Sealed) != 0;
}

Boolean Type___::get_IsSpecialName() {
  return (GetAttributeFlagsImpl() & TypeAttributes::SpecialName) != 0;
}

Boolean Type___::get_IsClass() {
  if ((GetAttributeFlagsImpl() & TypeAttributes::ClassSemanticsMask) == 0) {
    return !get_IsValueType();
  }
  return false;
}

Boolean Type___::get_IsNestedAssembly() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::NestedAssembly;
}

Boolean Type___::get_IsNestedFamANDAssem() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::NestedFamANDAssem;
}

Boolean Type___::get_IsNestedFamily() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::NestedFamily;
}

Boolean Type___::get_IsNestedFamORAssem() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::VisibilityMask;
}

Boolean Type___::get_IsNestedPrivate() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::NestedPrivate;
}

Boolean Type___::get_IsNestedPublic() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::NestedPublic;
}

Boolean Type___::get_IsNotPublic() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == 0;
}

Boolean Type___::get_IsPublic() {
  return (GetAttributeFlagsImpl() & TypeAttributes::VisibilityMask) == TypeAttributes::Public;
}

Boolean Type___::get_IsAutoLayout() {
  return (GetAttributeFlagsImpl() & TypeAttributes::LayoutMask) == 0;
}

Boolean Type___::get_IsExplicitLayout() {
  return (GetAttributeFlagsImpl() & TypeAttributes::LayoutMask) == TypeAttributes::ExplicitLayout;
}

Boolean Type___::get_IsLayoutSequential() {
  return (GetAttributeFlagsImpl() & TypeAttributes::LayoutMask) == TypeAttributes::SequentialLayout;
}

Boolean Type___::get_IsAnsiClass() {
  return (GetAttributeFlagsImpl() & TypeAttributes::StringFormatMask) == 0;
}

Boolean Type___::get_IsAutoClass() {
  return (GetAttributeFlagsImpl() & TypeAttributes::StringFormatMask) == TypeAttributes::AutoClass;
}

Boolean Type___::get_IsUnicodeClass() {
  return (GetAttributeFlagsImpl() & TypeAttributes::StringFormatMask) == TypeAttributes::UnicodeClass;
}

Boolean Type___::get_IsCOMObject() {
  return IsCOMObjectImpl();
}

Boolean Type___::get_IsContextful() {
  return IsContextfulImpl();
}

Boolean Type___::get_IsEnum() {
  return IsSubclassOf(typeof<Enum>());
}

Boolean Type___::get_IsMarshalByRef() {
  return IsMarshalByRefImpl();
}

Boolean Type___::get_IsPrimitive() {
  return IsPrimitiveImpl();
}

Boolean Type___::get_IsValueType() {
  return IsValueTypeImpl();
}

Boolean Type___::get_IsSignatureType() {
  return false;
}

Boolean Type___::get_IsSecurityCritical() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Type___::get_IsSecuritySafeCritical() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Type___::get_IsSecurityTransparent() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

StructLayoutAttribute Type___::get_StructLayoutAttribute() {
  rt::throw_exception<NotSupportedException>();
}

ConstructorInfo Type___::get_TypeInitializer() {
  return GetConstructorImpl(BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic, nullptr, CallingConventions::Any, EmptyTypes, nullptr);
}

RuntimeTypeHandle Type___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>();
}

Binder Type___::get_DefaultBinder() {
  if (s_defaultBinder == nullptr) {
    DefaultBinder value = rt::newobj<DefaultBinder>();
    Interlocked::CompareExchange(s_defaultBinder, value, (Binder)nullptr);
  }
  return s_defaultBinder;
}

Boolean Type___::get_IsSerializable() {
  if ((GetAttributeFlagsImpl() & TypeAttributes::Serializable) != 0) {
    return true;
  }
  Type type = get_UnderlyingSystemType();
  if (type->IsRuntimeImplemented()) {
    do {
      if (type == typeof<Delegate>() || type == typeof<Enum>()) {
        return true;
      }
      type = type->get_BaseType();
    } while (type != nullptr)
  }
  return false;
}

Boolean Type___::get_ContainsGenericParameters() {
  if (get_HasElementType()) {
    return GetRootElementType()->get_ContainsGenericParameters();
  }
  if (get_IsGenericParameter()) {
    return true;
  }
  if (!get_IsGenericType()) {
    return false;
  }
  Array<Type> genericArguments = GetGenericArguments();
  for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
    if (genericArguments[i]->get_ContainsGenericParameters()) {
      return true;
    }
  }
  return false;
}

Boolean Type___::get_IsVisible() {
  RuntimeType runtimeType = rt::as<RuntimeType>((Type)this);
  if ((Object)runtimeType != nullptr) {
    return RuntimeTypeHandle::IsVisible(runtimeType);
  }
  if (get_IsGenericParameter()) {
    return true;
  }
  if (get_HasElementType()) {
    return GetElementType()->get_IsVisible();
  }
  Type type = (Type)this;
  while (type->get_IsNested()) {
    if (!type->get_IsNestedPublic()) {
      return false;
    }
    type = type->get_DeclaringType();
  }
  if (!type->get_IsPublic()) {
    return false;
  }
  if (get_IsGenericType() && !get_IsGenericTypeDefinition()) {
    Array<Type> genericArguments = GetGenericArguments();
    for (Type&& type2 : *genericArguments) {
      if (!type2->get_IsVisible()) {
        return false;
      }
    }
  }
  return true;
}

Type Type___::GetType(String typeName, Boolean throwOnError, Boolean ignoreCase) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeType::in::GetType(typeName, throwOnError, ignoreCase, stackMark);
}

Type Type___::GetType(String typeName, Boolean throwOnError) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeType::in::GetType(typeName, throwOnError, false, stackMark);
}

Type Type___::GetType(String typeName) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeType::in::GetType(typeName, false, false, stackMark);
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return TypeNameParser::in::GetType(typeName, assemblyResolver, typeResolver, false, false, stackMark);
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return TypeNameParser::in::GetType(typeName, assemblyResolver, typeResolver, throwOnError, false, stackMark);
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return TypeNameParser::in::GetType(typeName, assemblyResolver, typeResolver, throwOnError, ignoreCase, stackMark);
}

Type Type___::GetTypeFromProgID(String progID, String server, Boolean throwOnError) {
  return RuntimeType::in::GetTypeFromProgIDImpl(progID, server, throwOnError);
}

Type Type___::GetTypeFromCLSID(Guid clsid, String server, Boolean throwOnError) {
  return RuntimeType::in::GetTypeFromCLSIDImpl(clsid, server, throwOnError);
}

RuntimeTypeHandle Type___::GetTypeHandleInternal() {
  return get_TypeHandle();
}

Boolean Type___::IsRuntimeImplemented() {
  return rt::is<RuntimeType>((Type)this);
}

void Type___::ctor() {
}

Type Type___::GetType() {
  return Object::in::GetType();
}

Int32 Type___::GetArrayRank() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Type Type___::GetGenericTypeDefinition() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Array<Type> Type___::GetGenericArguments() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Array<Type> Type___::GetGenericParameterConstraints() {
  if (!get_IsGenericParameter()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  rt::throw_exception<InvalidOperationException>();
}

Boolean Type___::IsContextfulImpl() {
  return false;
}

Boolean Type___::IsMarshalByRefImpl() {
  return false;
}

Boolean Type___::IsValueTypeImpl() {
  return IsSubclassOf(typeof<ValueType>());
}

ConstructorInfo Type___::GetConstructor(Array<Type> types) {
  return GetConstructor(BindingFlags::Instance | BindingFlags::Public, nullptr, types, nullptr);
}

ConstructorInfo Type___::GetConstructor(BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetConstructor(bindingAttr, binder, CallingConventions::Any, types, modifiers);
}

ConstructorInfo Type___::GetConstructor(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (types[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("types");
    }
  }
  return GetConstructorImpl(bindingAttr, binder, callConvention, types, modifiers);
}

Array<ConstructorInfo> Type___::GetConstructors() {
  return GetConstructors(BindingFlags::Instance | BindingFlags::Public);
}

EventInfo Type___::GetEvent(String name) {
  return GetEvent(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<EventInfo> Type___::GetEvents() {
  return GetEvents(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

FieldInfo Type___::GetField(String name) {
  return GetField(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<FieldInfo> Type___::GetFields() {
  return GetFields(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<MemberInfo> Type___::GetMember(String name) {
  return GetMember(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<MemberInfo> Type___::GetMember(String name, BindingFlags bindingAttr) {
  return GetMember(name, MemberTypes::All, bindingAttr);
}

Array<MemberInfo> Type___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Array<MemberInfo> Type___::GetMembers() {
  return GetMembers(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

MethodInfo Type___::GetMethod(String name) {
  return GetMethod(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return GetMethodImpl(name, bindingAttr, nullptr, CallingConventions::Any, nullptr, nullptr);
}

MethodInfo Type___::GetMethod(String name, Array<Type> types) {
  return GetMethod(name, types, nullptr);
}

MethodInfo Type___::GetMethod(String name, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethod(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, types, modifiers);
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethod(name, bindingAttr, binder, CallingConventions::Any, types, modifiers);
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (types[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("types");
    }
  }
  return GetMethodImpl(name, bindingAttr, binder, callConvention, types, modifiers);
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, Array<Type> types) {
  return GetMethod(name, genericParameterCount, types, nullptr);
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethod(name, genericParameterCount, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, types, modifiers);
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetMethod(name, genericParameterCount, bindingAttr, binder, CallingConventions::Any, types, modifiers);
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (genericParameterCount < 0) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_NeedNonNegNum(), "genericParameterCount");
  }
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (types[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("types");
    }
  }
  return GetMethodImpl(name, genericParameterCount, bindingAttr, binder, callConvention, types, modifiers);
}

MethodInfo Type___::GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>();
}

Array<MethodInfo> Type___::GetMethods() {
  return GetMethods(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Type Type___::GetNestedType(String name) {
  return GetNestedType(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<Type> Type___::GetNestedTypes() {
  return GetNestedTypes(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

PropertyInfo Type___::GetProperty(String name) {
  return GetProperty(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

PropertyInfo Type___::GetProperty(String name, BindingFlags bindingAttr) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return GetPropertyImpl(name, bindingAttr, nullptr, nullptr, nullptr, nullptr);
}

PropertyInfo Type___::GetProperty(String name, Type returnType) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return GetPropertyImpl(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, returnType, nullptr, nullptr);
}

PropertyInfo Type___::GetProperty(String name, Array<Type> types) {
  return GetProperty(name, nullptr, types);
}

PropertyInfo Type___::GetProperty(String name, Type returnType, Array<Type> types) {
  return GetProperty(name, returnType, types, nullptr);
}

PropertyInfo Type___::GetProperty(String name, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return GetProperty(name, BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public, nullptr, returnType, types, modifiers);
}

PropertyInfo Type___::GetProperty(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  return GetPropertyImpl(name, bindingAttr, binder, returnType, types, modifiers);
}

Array<PropertyInfo> Type___::GetProperties() {
  return GetProperties(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public);
}

Array<MemberInfo> Type___::GetDefaultMembers() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

RuntimeTypeHandle Type___::GetTypeHandle(Object o) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>(nullptr, SR::get_Arg_InvalidHandle());
  }
  Type type = o->GetType();
  return type->get_TypeHandle();
}

Array<Type> Type___::GetTypeArray(Array<Object> args) {
  if (args == nullptr) {
    rt::throw_exception<ArgumentNullException>("args");
  }
  Array<Type> array = rt::newarr<Array<Type>>(args->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    if (args[i] == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_ArgumentNull_ArrayValue(), "args");
    }
    array[i] = args[i]->GetType();
  }
  return array;
}

TypeCode Type___::GetTypeCode(Type type) {
  if (type == nullptr) {
    return TypeCode::Empty;
  }
  return type->GetTypeCodeImpl();
}

TypeCode Type___::GetTypeCodeImpl() {
  Type underlyingSystemType = get_UnderlyingSystemType();
  if ((Type)this != underlyingSystemType && underlyingSystemType != nullptr) {
    return GetTypeCode(underlyingSystemType);
  }
  return TypeCode::Object;
}

Type Type___::GetTypeFromCLSID(Guid clsid) {
  return GetTypeFromCLSID(clsid, nullptr, false);
}

Type Type___::GetTypeFromCLSID(Guid clsid, Boolean throwOnError) {
  return GetTypeFromCLSID(clsid, nullptr, throwOnError);
}

Type Type___::GetTypeFromCLSID(Guid clsid, String server) {
  return GetTypeFromCLSID(clsid, server, false);
}

Type Type___::GetTypeFromProgID(String progID) {
  return GetTypeFromProgID(progID, nullptr, false);
}

Type Type___::GetTypeFromProgID(String progID, Boolean throwOnError) {
  return GetTypeFromProgID(progID, nullptr, throwOnError);
}

Type Type___::GetTypeFromProgID(String progID, String server) {
  return GetTypeFromProgID(progID, server, false);
}

Object Type___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args) {
  return InvokeMember(name, invokeAttr, binder, target, args, nullptr, nullptr, nullptr);
}

Object Type___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, CultureInfo culture) {
  return InvokeMember(name, invokeAttr, binder, target, args, nullptr, culture, nullptr);
}

Type Type___::GetInterface(String name) {
  return GetInterface(name, false);
}

InterfaceMapping Type___::GetInterfaceMap(Type interfaceType) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Boolean Type___::IsInstanceOfType(Object o) {
  if (o != nullptr) {
    return IsAssignableFrom(o->GetType());
  }
  return false;
}

Boolean Type___::IsEquivalentTo(Type other) {
  return (Type)this == other;
}

Type Type___::GetEnumUnderlyingType() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  Array<FieldInfo> fields = GetFields(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  if (fields == nullptr || fields->get_Length() != 1) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidEnum(), "enumType");
  }
  return fields[0]->get_FieldType();
}

Array<> Type___::GetEnumValues() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Type Type___::MakeArrayType() {
  rt::throw_exception<NotSupportedException>();
}

Type Type___::MakeArrayType(Int32 rank) {
  rt::throw_exception<NotSupportedException>();
}

Type Type___::MakeByRefType() {
  rt::throw_exception<NotSupportedException>();
}

Type Type___::MakeGenericType(Array<Type> typeArguments) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Type Type___::MakePointerType() {
  rt::throw_exception<NotSupportedException>();
}

Type Type___::MakeGenericSignatureType(Type genericTypeDefinition, Array<Type> typeArguments) {
  return rt::newobj<SignatureConstructedGenericType>(genericTypeDefinition, typeArguments);
}

Type Type___::MakeGenericMethodParameter(Int32 position) {
  if (position < 0) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_NeedNonNegNum(), "position");
  }
  return rt::newobj<SignatureGenericMethodParameterType>(position);
}

String Type___::FormatTypeName() {
  Type rootElementType = GetRootElementType();
  if (rootElementType->get_IsPrimitive() || rootElementType->get_IsNested() || rootElementType == typeof<void>() || rootElementType == typeof<TypedReference>()) {
    return get_Name();
  }
  return ToString();
}

String Type___::ToString() {
  return "Type: " + get_Name();
}

Boolean Type___::Equals(Object o) {
  if (o != nullptr) {
    return Equals(rt::as<Type>(o));
  }
  return false;
}

Int32 Type___::GetHashCode() {
  Type underlyingSystemType = get_UnderlyingSystemType();
  if ((Object)underlyingSystemType != (Type)this) {
    return underlyingSystemType->GetHashCode();
  }
  return MemberInfo::in::GetHashCode();
}

Boolean Type___::Equals(Type o) {
  if (!(o == nullptr)) {
    return (Object)get_UnderlyingSystemType() == o->get_UnderlyingSystemType();
  }
  return false;
}

Type Type___::ReflectionOnlyGetType(String typeName, Boolean throwIfNotFound, Boolean ignoreCase) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ReflectionOnly());
}

Boolean Type___::IsEnumDefined(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "value");
  }
  Type type = value->GetType();
  if (type->get_IsEnum()) {
    if (!type->IsEquivalentTo((Type)this)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumAndObjectMustBeSameType(), type, (Type)this));
    }
    type = type->GetEnumUnderlyingType();
  }
  if (type == typeof<String>()) {
    Array<String> enumNames = GetEnumNames();
    Array<Object> array = enumNames;
    if (Array<>::in::IndexOf(array, value) >= 0) {
      return true;
    }
    return false;
  }
  if (IsIntegerType(type)) {
    Type enumUnderlyingType = GetEnumUnderlyingType();
    if (enumUnderlyingType->GetTypeCodeImpl() != type->GetTypeCodeImpl()) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumUnderlyingTypeAndObjectMustBeSameType(), type, enumUnderlyingType));
    }
    Array<> enumRawConstantValues = GetEnumRawConstantValues();
    return BinarySearch(enumRawConstantValues, value) >= 0;
  }
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
}

String Type___::GetEnumName(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "value");
  }
  Type type = value->GetType();
  if (!type->get_IsEnum() && !IsIntegerType(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnumBaseTypeOrEnum(), "value");
  }
  Array<> enumRawConstantValues = GetEnumRawConstantValues();
  Int32 num = BinarySearch(enumRawConstantValues, value);
  if (num >= 0) {
    Array<String> enumNames = GetEnumNames();
    return enumNames[num];
  }
  return nullptr;
}

Array<String> Type___::GetEnumNames() {
  if (!get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  Array<String> enumNames;
  Array<> enumValues;
  GetEnumData(enumNames, enumValues);
  return enumNames;
}

Array<> Type___::GetEnumRawConstantValues() {
  Array<String> enumNames;
  Array<> enumValues;
  GetEnumData(enumNames, enumValues);
  return enumValues;
}

void Type___::GetEnumData(Array<String>& enumNames, Array<>& enumValues) {
  Array<FieldInfo> fields = GetFields(BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
  Array<Object> array = rt::newarr<Array<Object>>(fields->get_Length());
  Array<String> array2 = rt::newarr<Array<String>>(fields->get_Length());
  for (Int32 i = 0; i < fields->get_Length(); i++) {
    array2[i] = fields[i]->get_Name();
    array[i] = fields[i]->GetRawConstantValue();
  }
  IComparer default一 = Comparer<Object>::in::get_Default();
  for (Int32 j = 1; j < array->get_Length(); j++) {
    Int32 num = j;
    String text = array2[j];
    Object obj = array[j];
    Boolean flag = false;
    while (default一->Compare(array[num - 1], obj) > 0) {
      array2[num] = array2[num - 1];
      array[num] = array[num - 1];
      num--;
      flag = true;
      if (num == 0) {
        break;
      }
    }
    if (flag) {
      array2[num] = text;
      array[num] = obj;
    }
  }
  enumNames = array2;
  enumValues = array;
}

Int32 Type___::BinarySearch(Array<> array, Object value) {
  Array<UInt64> array2 = rt::newarr<Array<UInt64>>(array->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array2[i] = Enum::in::ToUInt64(array->GetValue(i));
  }
  UInt64 value2 = Enum::in::ToUInt64(value);
  return Array<>::in::BinarySearch(array2, value2);
}

Boolean Type___::IsIntegerType(Type t) {
  if (!(t == typeof<Int32>()) && !(t == typeof<Int16>()) && !(t == typeof<UInt16>()) && !(t == typeof<Byte>()) && !(t == typeof<SByte>()) && !(t == typeof<UInt32>()) && !(t == typeof<Int64>()) && !(t == typeof<UInt64>()) && !(t == typeof<Char>())) {
    return t == typeof<Boolean>();
  }
  return true;
}

Type Type___::GetRootElementType() {
  Type type = (Type)this;
  while (type->get_HasElementType()) {
    type = type->GetElementType();
  }
  return type;
}

Array<Type> Type___::FindInterfaces(TypeFilter filter, Object filterCriteria) {
  if (filter == nullptr) {
    rt::throw_exception<ArgumentNullException>("filter");
  }
  Array<Type> interfaces = GetInterfaces();
  Int32 num = 0;
  for (Int32 i = 0; i < interfaces->get_Length(); i++) {
    if (!filter(interfaces[i], filterCriteria)) {
      interfaces[i] = nullptr;
    } else {
      num++;
    }
  }
  if (num == interfaces->get_Length()) {
    return interfaces;
  }
  Array<Type> array = rt::newarr<Array<Type>>(num);
  num = 0;
  for (Int32 j = 0; j < interfaces->get_Length(); j++) {
    if (interfaces[j] != nullptr) {
      array[num++] = interfaces[j];
    }
  }
  return array;
}

Array<MemberInfo> Type___::FindMembers(MemberTypes memberType, BindingFlags bindingAttr, MemberFilter filter, Object filterCriteria) {
  Array<MethodInfo> array = nullptr;
  Array<ConstructorInfo> array2 = nullptr;
  Array<FieldInfo> array3 = nullptr;
  Array<PropertyInfo> array4 = nullptr;
  Array<EventInfo> array5 = nullptr;
  Array<Type> array6 = nullptr;
  Int32 num = 0;
  if ((memberType & MemberTypes::Method) != 0) {
    array = GetMethods(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array->get_Length(); i++) {
        if (!filter(array[i], filterCriteria)) {
          array[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array->get_Length();
    }
  }
  if ((memberType & MemberTypes::Constructor) != 0) {
    array2 = GetConstructors(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array2->get_Length(); i++) {
        if (!filter(array2[i], filterCriteria)) {
          array2[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array2->get_Length();
    }
  }
  if ((memberType & MemberTypes::Field) != 0) {
    array3 = GetFields(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array3->get_Length(); i++) {
        if (!filter(array3[i], filterCriteria)) {
          array3[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array3->get_Length();
    }
  }
  if ((memberType & MemberTypes::Property) != 0) {
    array4 = GetProperties(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array4->get_Length(); i++) {
        if (!filter(array4[i], filterCriteria)) {
          array4[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array4->get_Length();
    }
  }
  if ((memberType & MemberTypes::Event) != 0) {
    array5 = GetEvents(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array5->get_Length(); i++) {
        if (!filter(array5[i], filterCriteria)) {
          array5[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array5->get_Length();
    }
  }
  if ((memberType & MemberTypes::NestedType) != 0) {
    array6 = GetNestedTypes(bindingAttr);
    if (filter != nullptr) {
      for (Int32 i = 0; i < array6->get_Length(); i++) {
        if (!filter(array6[i], filterCriteria)) {
          array6[i] = nullptr;
        } else {
          num++;
        }
      }
    } else {
      num += array6->get_Length();
    }
  }
  Array<MemberInfo> array7 = rt::newarr<Array<MemberInfo>>(num);
  num = 0;
  if (array != nullptr) {
    for (Int32 i = 0; i < array->get_Length(); i++) {
      if (array[i] != nullptr) {
        array7[num++] = array[i];
      }
    }
  }
  if (array2 != nullptr) {
    for (Int32 i = 0; i < array2->get_Length(); i++) {
      if (array2[i] != nullptr) {
        array7[num++] = array2[i];
      }
    }
  }
  if (array3 != nullptr) {
    for (Int32 i = 0; i < array3->get_Length(); i++) {
      if (array3[i] != nullptr) {
        array7[num++] = array3[i];
      }
    }
  }
  if (array4 != nullptr) {
    for (Int32 i = 0; i < array4->get_Length(); i++) {
      if (array4[i] != nullptr) {
        array7[num++] = array4[i];
      }
    }
  }
  if (array5 != nullptr) {
    for (Int32 i = 0; i < array5->get_Length(); i++) {
      if (array5[i] != nullptr) {
        array7[num++] = array5[i];
      }
    }
  }
  if (array6 != nullptr) {
    for (Int32 i = 0; i < array6->get_Length(); i++) {
      if (array6[i] != nullptr) {
        array7[num++] = array6[i];
      }
    }
  }
  return array7;
}

Boolean Type___::IsSubclassOf(Type c) {
  Type type = (Type)this;
  if (type == c) {
    return false;
  }
  while (type != nullptr) {
    if (type == c) {
      return true;
    }
    type = type->get_BaseType();
  }
  return false;
}

Boolean Type___::IsAssignableFrom(Type c) {
  if (c == nullptr) {
    return false;
  }
  if ((Type)this == c) {
    return true;
  }
  Type underlyingSystemType = get_UnderlyingSystemType();
  if ((Object)underlyingSystemType != nullptr && underlyingSystemType->IsRuntimeImplemented()) {
    return underlyingSystemType->IsAssignableFrom(c);
  }
  if (c->IsSubclassOf((Type)this)) {
    return true;
  }
  if (get_IsInterface()) {
    return c->ImplementInterface((Type)this);
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
  return false;
}

Boolean Type___::ImplementInterface(Type ifaceType) {
  Type type = (Type)this;
  while (type != nullptr) {
    Array<Type> interfaces = type->GetInterfaces();
    if (interfaces != nullptr) {
      for (Int32 i = 0; i < interfaces->get_Length(); i++) {
        if (interfaces[i] == ifaceType || (interfaces[i] != nullptr && interfaces[i]->ImplementInterface(ifaceType))) {
          return true;
        }
      }
    }
    type = type->get_BaseType();
  }
  return false;
}

Boolean Type___::FilterAttributeImpl(MemberInfo m, Object filterCriteria) {
  if (filterCriteria == nullptr) {
    rt::throw_exception<InvalidFilterCriteriaException>(SR::get_InvalidFilterCriteriaException_CritInt());
  }
  switch (m->get_MemberType()) {
    case MemberTypes::Constructor:
    case MemberTypes::Method:
      {
        MethodAttributes methodAttributes;
        try {
          Int32 num2 = (Int32)filterCriteria;
          methodAttributes = (MethodAttributes)num2;
        } catch (...) {
          rt::throw_exception<InvalidFilterCriteriaException>(SR::get_InvalidFilterCriteriaException_CritInt());
        }
        MethodAttributes methodAttributes2 = (m->get_MemberType() != MemberTypes::Method) ? ((ConstructorInfo)m)->get_Attributes() : ((MethodInfo)m)->get_Attributes();
        if ((methodAttributes & MethodAttributes::MemberAccessMask) != 0 && (methodAttributes2 & MethodAttributes::MemberAccessMask) != (methodAttributes & MethodAttributes::MemberAccessMask)) {
          return false;
        }
        if ((methodAttributes & MethodAttributes::Static) != 0 && (methodAttributes2 & MethodAttributes::Static) == 0) {
          return false;
        }
        if ((methodAttributes & MethodAttributes::Final) != 0 && (methodAttributes2 & MethodAttributes::Final) == 0) {
          return false;
        }
        if ((methodAttributes & MethodAttributes::Virtual) != 0 && (methodAttributes2 & MethodAttributes::Virtual) == 0) {
          return false;
        }
        if ((methodAttributes & MethodAttributes::Abstract) != 0 && (methodAttributes2 & MethodAttributes::Abstract) == 0) {
          return false;
        }
        if ((methodAttributes & MethodAttributes::SpecialName) != 0 && (methodAttributes2 & MethodAttributes::SpecialName) == 0) {
          return false;
        }
        return true;
      }case MemberTypes::Field:
      {
        FieldAttributes fieldAttributes;
        try {
          Int32 num = (Int32)filterCriteria;
          fieldAttributes = (FieldAttributes)num;
        } catch (...) {
          rt::throw_exception<InvalidFilterCriteriaException>(SR::get_InvalidFilterCriteriaException_CritInt());
        }
        FieldAttributes attributes = ((FieldInfo)m)->get_Attributes();
        if ((fieldAttributes & FieldAttributes::FieldAccessMask) != 0 && (attributes & FieldAttributes::FieldAccessMask) != (fieldAttributes & FieldAttributes::FieldAccessMask)) {
          return false;
        }
        if ((fieldAttributes & FieldAttributes::Static) != 0 && (attributes & FieldAttributes::Static) == 0) {
          return false;
        }
        if ((fieldAttributes & FieldAttributes::InitOnly) != 0 && (attributes & FieldAttributes::InitOnly) == 0) {
          return false;
        }
        if ((fieldAttributes & FieldAttributes::Literal) != 0 && (attributes & FieldAttributes::Literal) == 0) {
          return false;
        }
        if ((fieldAttributes & FieldAttributes::NotSerialized) != 0 && (attributes & FieldAttributes::NotSerialized) == 0) {
          return false;
        }
        if ((fieldAttributes & FieldAttributes::PinvokeImpl) != 0 && (attributes & FieldAttributes::PinvokeImpl) == 0) {
          return false;
        }
        return true;
      }default:
      return false;
  }
}

Boolean Type___::FilterNameImpl(MemberInfo m, Object filterCriteria, StringComparison comparison) {
  String text = rt::as<String>(filterCriteria);
  if (text == nullptr) {
    rt::throw_exception<InvalidFilterCriteriaException>(SR::get_InvalidFilterCriteriaException_CritString());
  }
  ReadOnlySpan<Char> readOnlySpan = MemoryExtensions::Trim(MemoryExtensions::AsSpan(text));
  ReadOnlySpan<Char> span = m->get_Name();
  if (m->get_MemberType() == MemberTypes::NestedType) {
    span = span.Slice(MemoryExtensions::LastIndexOf(span, 43) + 1);
  }
  if (readOnlySpan.get_Length() > 0 && readOnlySpan[readOnlySpan.get_Length() - 1] == 42) {
    readOnlySpan = readOnlySpan.Slice(0, readOnlySpan.get_Length() - 1);
    return MemoryExtensions::StartsWith(span, readOnlySpan, comparison);
  }
  return MemoryExtensions::Equals(MemoryExtensions, span, readOnlySpan, comparison);
}

void Type___::cctor() {
  Delimiter = 46;
  EmptyTypes = Array<>::in::Empty<Type>();
  Missing = Missing::in::Value;
  FilterAttribute = rt::newobj<MemberFilter>(&FilterAttributeImpl);
  FilterName = rt::newobj<MemberFilter>(&_cctor_b__272_0);
  FilterNameIgnoreCase = rt::newobj<MemberFilter>(&_cctor_b__272_1);
}

} // namespace System::Private::CoreLib::System::TypeNamespace
