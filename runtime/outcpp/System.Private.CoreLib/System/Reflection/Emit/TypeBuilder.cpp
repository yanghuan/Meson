#include "TypeBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilderAccess.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ConstructorOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EnumBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EventToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ILGenerator-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCodes-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/PropertyToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeNameBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::CompilerServices;

void TypeBuilder___::CustAttr___::ctor(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if ((Object)con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  m_con = con;
  m_binaryAttribute = binaryAttribute;
}

void TypeBuilder___::CustAttr___::ctor(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  m_customBuilder = customBuilder;
}

void TypeBuilder___::CustAttr___::Bake(ModuleBuilder module, Int32 token) {
  if (m_customBuilder == nullptr) {
    DefineCustomAttribute(module, token, module->GetConstructorToken(m_con).get_Token(), m_binaryAttribute, false, false);
  } else {
    m_customBuilder->CreateCustomAttribute(module, token);
  }
}

Object TypeBuilder___::get_SyncRoot() {
  return m_module->get_SyncRoot();
}

RuntimeType TypeBuilder___::get_BakedRuntimeType() {
  return m_bakedRuntimeType;
}

Type TypeBuilder___::get_DeclaringType() {
  return m_DeclaringType;
}

Type TypeBuilder___::get_ReflectedType() {
  return m_DeclaringType;
}

String TypeBuilder___::get_Name() {
  return m_strName;
}

Module TypeBuilder___::get_Module() {
  return GetModuleBuilder();
}

Boolean TypeBuilder___::get_IsByRefLike() {
  return false;
}

Int32 TypeBuilder___::get_MetadataTokenInternal() {
  return m_tdType.get_Token();
}

Guid TypeBuilder___::get_GUID() {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->get_GUID();
}

Assembly TypeBuilder___::get_Assembly() {
  return m_module->get_Assembly();
}

RuntimeTypeHandle TypeBuilder___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

String TypeBuilder___::get_FullName() {
  String as = m_strFullQualName;
  return as != nullptr ? as : (m_strFullQualName = TypeNameBuilder::in::ToString((TypeBuilder)this, TypeNameBuilder::in::Format::FullName));
}

String TypeBuilder___::get_Namespace() {
  return m_strNameSpace;
}

String TypeBuilder___::get_AssemblyQualifiedName() {
  return TypeNameBuilder::in::ToString((TypeBuilder)this, TypeNameBuilder::in::Format::AssemblyQualifiedName);
}

Type TypeBuilder___::get_BaseType() {
  return m_typeParent;
}

Boolean TypeBuilder___::get_IsTypeDefinition() {
  return true;
}

Boolean TypeBuilder___::get_IsSZArray() {
  return false;
}

Boolean TypeBuilder___::get_IsSecurityCritical() {
  return true;
}

Boolean TypeBuilder___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean TypeBuilder___::get_IsSecurityTransparent() {
  return false;
}

Type TypeBuilder___::get_UnderlyingSystemType() {
  if (m_bakedRuntimeType != nullptr) {
    return m_bakedRuntimeType;
  }
  if (get_IsEnum()) {
    if (m_enumUnderlyingType == nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoUnderlyingTypeOnEnum());
    }
    return m_enumUnderlyingType;
  }
  return (TypeBuilder)this;
}

GenericParameterAttributes TypeBuilder___::get_GenericParameterAttributes() {
  return m_genParamAttributes;
}

Boolean TypeBuilder___::get_IsGenericTypeDefinition() {
  return get_IsGenericType();
}

Boolean TypeBuilder___::get_IsGenericType() {
  return m_inst != nullptr;
}

Boolean TypeBuilder___::get_IsGenericParameter() {
  return m_bIsGenParam;
}

Boolean TypeBuilder___::get_IsConstructedGenericType() {
  return false;
}

Int32 TypeBuilder___::get_GenericParameterPosition() {
  return m_genParamPos;
}

MethodBase TypeBuilder___::get_DeclaringMethod() {
  return m_declMeth;
}

Int32 TypeBuilder___::get_Size() {
  return m_iTypeSize;
}

PackingSize TypeBuilder___::get_PackingSize() {
  return m_iPackingSize;
}

TypeToken TypeBuilder___::get_TypeToken() {
  if (get_IsGenericParameter()) {
    ThrowIfCreated();
  }
  return m_tdType;
}

Boolean TypeBuilder___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

MethodInfo TypeBuilder___::GetMethod(Type type, MethodInfo method) {
  if (!rt::is<TypeBuilder>(type) && !rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeTypeBuilder());
  }
  if (method->get_IsGenericMethod() && !method->get_IsGenericMethodDefinition()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedGenericMethodDefinition(), "method");
  }
  if (method->get_DeclaringType() == nullptr || !method->get_DeclaringType()->get_IsGenericTypeDefinition()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MethodNeedGenericDeclaringType(), "method");
  }
  if (type->GetGenericTypeDefinition() != method->get_DeclaringType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidMethodDeclaringType(), "type");
  }
  if (type->get_IsGenericTypeDefinition()) {
    type = type->MakeGenericType(type->GetGenericArguments());
  }
  if (!rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "type");
  }
  return MethodOnTypeBuilderInstantiation::in::GetMethod(method, rt::as<TypeBuilderInstantiation>(type));
}

ConstructorInfo TypeBuilder___::GetConstructor(Type type, ConstructorInfo constructor) {
  if (!rt::is<TypeBuilder>(type) && !rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeTypeBuilder());
  }
  if (!constructor->get_DeclaringType()->get_IsGenericTypeDefinition()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConstructorNeedGenericDeclaringType(), "constructor");
  }
  if (!rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "type");
  }
  if (rt::is<TypeBuilder>(type) && type->get_IsGenericTypeDefinition()) {
    type = type->MakeGenericType(type->GetGenericArguments());
  }
  if (type->GetGenericTypeDefinition() != constructor->get_DeclaringType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidConstructorDeclaringType(), "type");
  }
  return ConstructorOnTypeBuilderInstantiation::in::GetConstructor(constructor, rt::as<TypeBuilderInstantiation>(type));
}

FieldInfo TypeBuilder___::GetField(Type type, FieldInfo field) {
  if (!rt::is<TypeBuilder>(type) && !rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeTypeBuilder());
  }
  if (!field->get_DeclaringType()->get_IsGenericTypeDefinition()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_FieldNeedGenericDeclaringType(), "field");
  }
  if (!rt::is<TypeBuilderInstantiation>(type)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "type");
  }
  if (rt::is<TypeBuilder>(type) && type->get_IsGenericTypeDefinition()) {
    type = type->MakeGenericType(type->GetGenericArguments());
  }
  if (type->GetGenericTypeDefinition() != field->get_DeclaringType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidFieldDeclaringType(), "type");
  }
  return FieldOnTypeBuilderInstantiation::in::GetField(field, rt::as<TypeBuilderInstantiation>(type));
}

void TypeBuilder___::DefineCustomAttribute(ModuleBuilder module, Int32 tkAssociate, Int32 tkConstructor, Array<Byte> attr, Boolean toDisk, Boolean updateCompilerFlags) {
  Array<Byte> array = nullptr;
  if (attr != nullptr) {
    array = rt::newarr<Array<Byte>>(attr->get_Length());
    Buffer::BlockCopy(attr, 0, array, 0, attr->get_Length());
  }
  DefineCustomAttribute(QCallModule(module), tkAssociate, tkConstructor, array, (array != nullptr) ? array->get_Length() : 0, toDisk, updateCompilerFlags);
}

Boolean TypeBuilder___::IsTypeEqual(Type t1, Type t2) {
  if (t1 == t2) {
    return true;
  }
  TypeBuilder typeBuilder = nullptr;
  TypeBuilder typeBuilder2 = nullptr;
  Type left;
  if (rt::is<TypeBuilder>(t1)) {
    typeBuilder = (TypeBuilder)t1;
    left = typeBuilder->m_bakedRuntimeType;
  } else {
    left = t1;
  }
  Type type;
  if (rt::is<TypeBuilder>(t2)) {
    typeBuilder2 = (TypeBuilder)t2;
    type = typeBuilder2->m_bakedRuntimeType;
  } else {
    type = t2;
  }
  if (typeBuilder != nullptr && typeBuilder2 != nullptr && (Object)typeBuilder == typeBuilder2) {
    return true;
  }
  if (left != nullptr && type != nullptr && left == type) {
    return true;
  }
  return false;
}

void TypeBuilder___::SetConstantValue(ModuleBuilder module, Int32 tk, Type destType, Object value) {
  if (value != nullptr) {
    Type type = value->GetType();
    if (destType->get_IsByRef()) {
      destType = destType->GetElementType();
    }
    Type as = Nullable<>::GetUnderlyingType(destType);
    destType = (as != nullptr ? as : destType);
    if (destType->get_IsEnum()) {
      EnumBuilder enumBuilder = rt::as<EnumBuilder>(destType);
      Type type2;
      if ((Object)enumBuilder != nullptr) {
        type2 = enumBuilder->GetEnumUnderlyingType();
        if (type != enumBuilder->m_typeBuilder->m_bakedRuntimeType && type != type2) {
          rt::throw_exception<ArgumentException>(SR::get_Argument_ConstantDoesntMatch());
        }
      } else {
        TypeBuilder typeBuilder = rt::as<TypeBuilder>(destType);
        if ((Object)typeBuilder != nullptr) {
          type2 = typeBuilder->m_enumUnderlyingType;
          if (type2 == nullptr || (type != typeBuilder->get_UnderlyingSystemType() && type != type2)) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_ConstantDoesntMatch());
          }
        } else {
          type2 = Enum::in::GetUnderlyingType(destType);
          if (type != destType && type != type2) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_ConstantDoesntMatch());
          }
        }
      }
      type = type2;
    } else if (!destType->IsAssignableFrom(type)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_ConstantDoesntMatch());
    }

    CorElementType corElementType = RuntimeTypeHandle::GetCorElementType((RuntimeType)type);
    if (corElementType - 2 <= CorElementType::ELEMENT_TYPE_U8) {
      {
        Byte* pValue = &RuntimeHelpers::GetRawData(value);
        SetConstantValue(QCallModule(module), tk, (Int32)corElementType, pValue);
      }
      return;
    }
    if (type == typeof<String>()) {
      {
        Char* ptr = (String)value;
        Char* pValue2 = ptr;
        SetConstantValue(QCallModule(module), tk, 14, pValue2);
      }
      return;
    }
    if (!(type == typeof<DateTime>())) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ConstantNotSupported(), type));
    }
    Int64 ticks = ((DateTime)value).get_Ticks();
    SetConstantValue(QCallModule(module), tk, 10, &ticks);
  } else {
    SetConstantValue(QCallModule(module), tk, 18, nullptr);
  }
}

void TypeBuilder___::ctor(ModuleBuilder module) {
  m_tdType = TypeToken(33554432);
  m_isHiddenGlobalType = true;
  m_module = module;
  m_listMethods = rt::newobj<List<MethodBuilder>>();
  m_lastTokenizedMethod = -1;
}

void TypeBuilder___::ctor(String szName, Int32 genParamPos, MethodBuilder declMeth) {
  m_strName = szName;
  m_genParamPos = genParamPos;
  m_bIsGenParam = true;
  m_typeInterfaces = rt::newobj<List<Type>>();
  m_declMeth = declMeth;
  m_DeclaringType = m_declMeth->GetTypeBuilder();
  m_module = declMeth->GetModuleBuilder();
}

void TypeBuilder___::ctor(String szName, Int32 genParamPos, TypeBuilder declType) {
  m_strName = szName;
  m_genParamPos = genParamPos;
  m_bIsGenParam = true;
  m_typeInterfaces = rt::newobj<List<Type>>();
  m_DeclaringType = declType;
  m_module = declType->GetModuleBuilder();
}

void TypeBuilder___::ctor(String fullname, TypeAttributes attr, Type parent, Array<Type> interfaces, ModuleBuilder module, PackingSize iPackingSize, Int32 iTypeSize, TypeBuilder enclosingType) {
  if (fullname == nullptr) {
    rt::throw_exception<ArgumentNullException>("fullname");
  }
  if (fullname->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "fullname");
  }
  if (fullname[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalName(), "fullname");
  }
  if (fullname->get_Length() > 1023) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TypeNameTooLong(), "fullname");
  }
  m_module = module;
  m_DeclaringType = enclosingType;
  AssemblyBuilder containingAssemblyBuilder = m_module->get_ContainingAssemblyBuilder();
  containingAssemblyBuilder->_assemblyData->CheckTypeNameConflict(fullname, enclosingType);
  if (enclosingType != nullptr && ((attr & TypeAttributes::VisibilityMask) == TypeAttributes::Public || (attr & TypeAttributes::VisibilityMask) == 0)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadNestedTypeFlags(), "attr");
  }
  Array<Int32> array = nullptr;
  if (interfaces != nullptr) {
    for (Int32 i = 0; i < interfaces->get_Length(); i++) {
      if (interfaces[i] == nullptr) {
        rt::throw_exception<ArgumentNullException>("interfaces");
      }
    }
    array = rt::newarr<Array<Int32>>(interfaces->get_Length() + 1);
    for (Int32 i = 0; i < interfaces->get_Length(); i++) {
      array[i] = m_module->GetTypeTokenInternal(interfaces[i]).get_Token();
    }
  }
  Int32 num = fullname->LastIndexOf(46);
  if (num == -1 || num == 0) {
    m_strNameSpace = String::in::Empty;
    m_strName = fullname;
  } else {
    m_strNameSpace = fullname->Substring(0, num);
    m_strName = fullname->Substring(num + 1);
  }
  VerifyTypeAttributes(attr);
  m_iAttr = attr;
  SetParent(parent);
  m_listMethods = rt::newobj<List<MethodBuilder>>();
  m_lastTokenizedMethod = -1;
  SetInterfaces(interfaces);
  Int32 tkParent = 0;
  if (m_typeParent != nullptr) {
    tkParent = m_module->GetTypeTokenInternal(m_typeParent).get_Token();
  }
  Int32 tkEnclosingType = 0;
  if (enclosingType != nullptr) {
    tkEnclosingType = enclosingType->m_tdType.get_Token();
  }
  m_tdType = TypeToken(DefineType(QCallModule(module), fullname, tkParent, m_iAttr, tkEnclosingType, array));
  m_iPackingSize = iPackingSize;
  m_iTypeSize = iTypeSize;
  if (m_iPackingSize != 0 || m_iTypeSize != 0) {
    SetClassLayout(QCallModule(module), m_tdType.get_Token(), m_iPackingSize, m_iTypeSize);
  }
  m_module->AddType(get_FullName(), (TypeBuilder)this);
}

FieldBuilder TypeBuilder___::DefineDataHelper(String name, Array<Byte> data, Int32 size, FieldAttributes attributes) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if (size <= 0 || size >= 4128768) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadSizeForData());
  }
  ThrowIfCreated();
  String text = "$ArrayType$" + size;
  Type type = m_module->FindTypeBuilderWithName(text, false);
  TypeBuilder typeBuilder = rt::as<TypeBuilder>(type);
  if (typeBuilder == nullptr) {
    TypeAttributes attr = TypeAttributes::Public | TypeAttributes::ExplicitLayout | TypeAttributes::Sealed;
    typeBuilder = m_module->DefineType(text, attr, typeof<ValueType>(), PackingSize::Size1, size);
    typeBuilder->CreateType();
  }
  FieldBuilder fieldBuilder = DefineField(name, typeBuilder, attributes | FieldAttributes::Static);
  fieldBuilder->SetData(data, size);
  return fieldBuilder;
}

void TypeBuilder___::VerifyTypeAttributes(TypeAttributes attr) {
  if (get_DeclaringType() == nullptr) {
    if ((attr & TypeAttributes::VisibilityMask) != 0 && (attr & TypeAttributes::VisibilityMask) != TypeAttributes::Public) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeAttrNestedVisibilityOnNonNestedType());
    }
  } else if ((attr & TypeAttributes::VisibilityMask) == 0 || (attr & TypeAttributes::VisibilityMask) == TypeAttributes::Public) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeAttrNonNestedVisibilityNestedType());
  }

  if ((attr & TypeAttributes::LayoutMask) != 0 && (attr & TypeAttributes::LayoutMask) != TypeAttributes::SequentialLayout && (attr & TypeAttributes::LayoutMask) != TypeAttributes::ExplicitLayout) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeAttrInvalidLayout());
  }
  if ((attr & TypeAttributes::ReservedMask) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeAttrReservedBitsSet());
  }
}

Boolean TypeBuilder___::IsCreated() {
  return m_hasBeenCreated;
}

void TypeBuilder___::ThrowIfCreated() {
  if (IsCreated()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TypeHasBeenCreated());
  }
}

ModuleBuilder TypeBuilder___::GetModuleBuilder() {
  return m_module;
}

void TypeBuilder___::SetGenParamAttributes(GenericParameterAttributes genericParameterAttributes) {
  m_genParamAttributes = genericParameterAttributes;
}

void TypeBuilder___::SetGenParamCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  CustAttr genParamCustomAttributeNoLock = rt::newobj<CustAttr>(con, binaryAttribute);
  {
    rt::lock(get_SyncRoot());
    SetGenParamCustomAttributeNoLock(genParamCustomAttributeNoLock);
  }
}

void TypeBuilder___::SetGenParamCustomAttribute(CustomAttributeBuilder customBuilder) {
  CustAttr genParamCustomAttributeNoLock = rt::newobj<CustAttr>(customBuilder);
  {
    rt::lock(get_SyncRoot());
    SetGenParamCustomAttributeNoLock(genParamCustomAttributeNoLock);
  }
}

void TypeBuilder___::SetGenParamCustomAttributeNoLock(CustAttr ca) {
  if (m_ca == nullptr) {
    m_ca = rt::newobj<List<CustAttr>>();
  }
  m_ca->Add(ca);
}

String TypeBuilder___::ToString() {
  return TypeNameBuilder::in::ToString((TypeBuilder)this, TypeNameBuilder::in::Format::ToString);
}

Object TypeBuilder___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->InvokeMember(name, invokeAttr, binder, target, args, modifiers, culture, namedParameters);
}

ConstructorInfo TypeBuilder___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetConstructor(bindingAttr, binder, callConvention, types, modifiers);
}

Array<ConstructorInfo> TypeBuilder___::GetConstructors(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetConstructors(bindingAttr);
}

MethodInfo TypeBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  if (types == nullptr) {
    return m_bakedRuntimeType->GetMethod(name, bindingAttr);
  }
  return m_bakedRuntimeType->GetMethod(name, bindingAttr, binder, callConvention, types, modifiers);
}

Array<MethodInfo> TypeBuilder___::GetMethods(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetMethods(bindingAttr);
}

FieldInfo TypeBuilder___::GetField(String name, BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetField(name, bindingAttr);
}

Array<FieldInfo> TypeBuilder___::GetFields(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetFields(bindingAttr);
}

Type TypeBuilder___::GetInterface(String name, Boolean ignoreCase) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetInterface(name, ignoreCase);
}

Array<Type> TypeBuilder___::GetInterfaces() {
  if (m_bakedRuntimeType != nullptr) {
    return m_bakedRuntimeType->GetInterfaces();
  }
  if (m_typeInterfaces == nullptr) {
    return Array<>::in::Empty<Type>();
  }
  return m_typeInterfaces->ToArray();
}

EventInfo TypeBuilder___::GetEvent(String name, BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetEvent(name, bindingAttr);
}

Array<EventInfo> TypeBuilder___::GetEvents() {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetEvents();
}

PropertyInfo TypeBuilder___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<PropertyInfo> TypeBuilder___::GetProperties(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetProperties(bindingAttr);
}

Array<Type> TypeBuilder___::GetNestedTypes(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetNestedTypes(bindingAttr);
}

Type TypeBuilder___::GetNestedType(String name, BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetNestedType(name, bindingAttr);
}

Array<MemberInfo> TypeBuilder___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetMember(name, type, bindingAttr);
}

InterfaceMapping TypeBuilder___::GetInterfaceMap(Type interfaceType) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetInterfaceMap(interfaceType);
}

Array<EventInfo> TypeBuilder___::GetEvents(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetEvents(bindingAttr);
}

Array<MemberInfo> TypeBuilder___::GetMembers(BindingFlags bindingAttr) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return m_bakedRuntimeType->GetMembers(bindingAttr);
}

Boolean TypeBuilder___::IsAssignableFrom(Type c) {
  if (IsTypeEqual(c, (TypeBuilder)this)) {
    return true;
  }
  TypeBuilder typeBuilder = rt::as<TypeBuilder>(c);
  Type type = (!(typeBuilder != nullptr)) ? c : typeBuilder->m_bakedRuntimeType;
  if (type != nullptr && rt::is<RuntimeType>(type)) {
    if (m_bakedRuntimeType == nullptr) {
      return false;
    }
    return m_bakedRuntimeType->IsAssignableFrom(type);
  }
  if (typeBuilder == nullptr) {
    return false;
  }
  if (typeBuilder->IsSubclassOf((TypeBuilder)this)) {
    return true;
  }
  if (!Type::in::get_IsInterface()) {
    return false;
  }
  Array<Type> interfaces = typeBuilder->GetInterfaces();
  for (Int32 i = 0; i < interfaces->get_Length(); i++) {
    if (IsTypeEqual(interfaces[i], (TypeBuilder)this)) {
      return true;
    }
    if (interfaces[i]->IsSubclassOf((TypeBuilder)this)) {
      return true;
    }
  }
  return false;
}

TypeAttributes TypeBuilder___::GetAttributeFlagsImpl() {
  return m_iAttr;
}

Boolean TypeBuilder___::IsArrayImpl() {
  return false;
}

Boolean TypeBuilder___::IsByRefImpl() {
  return false;
}

Boolean TypeBuilder___::IsPointerImpl() {
  return false;
}

Boolean TypeBuilder___::IsPrimitiveImpl() {
  return false;
}

Boolean TypeBuilder___::IsCOMObjectImpl() {
  if ((GetAttributeFlagsImpl() & TypeAttributes::Import) == 0) {
    return false;
  }
  return true;
}

Type TypeBuilder___::GetElementType() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Boolean TypeBuilder___::HasElementTypeImpl() {
  return false;
}

Boolean TypeBuilder___::IsSubclassOf(Type c) {
  Type type = (TypeBuilder)this;
  if (IsTypeEqual(type, c)) {
    return false;
  }
  type = type->get_BaseType();
  while (type != nullptr) {
    if (IsTypeEqual(type, c)) {
      return true;
    }
    type = type->get_BaseType();
  }
  return false;
}

Type TypeBuilder___::MakePointerType() {
  return SymbolType::in::FormCompoundType("*", (TypeBuilder)this, 0);
}

Type TypeBuilder___::MakeByRefType() {
  return SymbolType::in::FormCompoundType("&", (TypeBuilder)this, 0);
}

Type TypeBuilder___::MakeArrayType() {
  return SymbolType::in::FormCompoundType("[]", (TypeBuilder)this, 0);
}

Type TypeBuilder___::MakeArrayType(Int32 rank) {
  String rankString = TypeInfo::in::GetRankString(rank);
  return SymbolType::in::FormCompoundType(rankString, (TypeBuilder)this, 0);
}

Array<Object> TypeBuilder___::GetCustomAttributes(Boolean inherit) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  return CustomAttribute::GetCustomAttributes(m_bakedRuntimeType, rt::as<RuntimeType>(typeof<Object>()), inherit);
}

Array<Object> TypeBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes(m_bakedRuntimeType, runtimeType, inherit);
}

Boolean TypeBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  if (!IsCreated()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_TypeNotYetCreated());
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined(m_bakedRuntimeType, runtimeType, inherit);
}

void TypeBuilder___::SetInterfaces(Array<Type> interfaces) {
  ThrowIfCreated();
  m_typeInterfaces = rt::newobj<List<Type>>();
  if (interfaces != nullptr) {
    m_typeInterfaces->AddRange(interfaces);
  }
}

Array<GenericTypeParameterBuilder> TypeBuilder___::DefineGenericParameters(Array<String> names) {
  if (names == nullptr) {
    rt::throw_exception<ArgumentNullException>("names");
  }
  if (names->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_EmptyArray(), "names");
  }
  for (Int32 i = 0; i < names->get_Length(); i++) {
    if (names[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("names");
    }
  }
  if (m_inst != nullptr) {
    rt::throw_exception<InvalidOperationException>();
  }
  m_inst = rt::newarr<Array<GenericTypeParameterBuilder>>(names->get_Length());
  for (Int32 j = 0; j < names->get_Length(); j++) {
    m_inst[j] = rt::newobj<GenericTypeParameterBuilder>(rt::newobj<TypeBuilder>(names[j], j, (TypeBuilder)this));
  }
  return m_inst;
}

Type TypeBuilder___::MakeGenericType(Array<Type> typeArguments) {
  CheckContext(typeArguments);
  return TypeBuilderInstantiation::in::MakeGenericType((TypeBuilder)this, typeArguments);
}

Array<Type> TypeBuilder___::GetGenericArguments() {
  Array<Type> inst = m_inst;
  Array<Type> as = inst;
  return as != nullptr ? as : Array<>::in::Empty<Type>();
}

Type TypeBuilder___::GetGenericTypeDefinition() {
  if (get_IsGenericTypeDefinition()) {
    return (TypeBuilder)this;
  }
  if (m_genTypeDef == nullptr) {
    rt::throw_exception<InvalidOperationException>();
  }
  return m_genTypeDef;
}

void TypeBuilder___::DefineMethodOverride(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration) {
  {
    rt::lock(get_SyncRoot());
    DefineMethodOverrideNoLock(methodInfoBody, methodInfoDeclaration);
  }
}

void TypeBuilder___::DefineMethodOverrideNoLock(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration) {
  if (methodInfoBody == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodInfoBody");
  }
  if (methodInfoDeclaration == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodInfoDeclaration");
  }
  ThrowIfCreated();
  if ((Object)methodInfoBody->get_DeclaringType() != (TypeBuilder)this) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentException_BadMethodImplBody());
  }
  MethodToken methodTokenInternal = m_module->GetMethodTokenInternal(methodInfoBody);
  MethodToken methodTokenInternal2 = m_module->GetMethodTokenInternal(methodInfoDeclaration);
  ModuleBuilder module = m_module;
  DefineMethodImpl(QCallModule(module), m_tdType.get_Token(), methodTokenInternal.get_Token(), methodTokenInternal2.get_Token());
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return DefineMethod(name, attributes, CallingConventions::Standard, returnType, parameterTypes);
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes) {
  return DefineMethod(name, attributes, CallingConventions::Standard, nullptr, nullptr);
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention) {
  return DefineMethod(name, attributes, callingConvention, nullptr, nullptr);
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return DefineMethod(name, attributes, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  {
    rt::lock(get_SyncRoot());
    return DefineMethodNoLock(name, attributes, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers);
  }
}

MethodBuilder TypeBuilder___::DefineMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  CheckContext(returnType);
  CheckContext(rt::newarr<Array<Array<Type>>>(3, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes));
  CheckContext(parameterTypeRequiredCustomModifiers);
  CheckContext(parameterTypeOptionalCustomModifiers);
  if (parameterTypes != nullptr) {
    if (parameterTypeOptionalCustomModifiers != nullptr && parameterTypeOptionalCustomModifiers->get_Length() != parameterTypes->get_Length()) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MismatchedArrays(), "parameterTypeOptionalCustomModifiers", "parameterTypes"));
    }
    if (parameterTypeRequiredCustomModifiers != nullptr && parameterTypeRequiredCustomModifiers->get_Length() != parameterTypes->get_Length()) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MismatchedArrays(), "parameterTypeRequiredCustomModifiers", "parameterTypes"));
    }
  }
  ThrowIfCreated();
  MethodBuilder methodBuilder = rt::newobj<MethodBuilder>(name, attributes, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers, m_module, (TypeBuilder)this);
  if (!m_isHiddenGlobalType && (methodBuilder->get_Attributes() & MethodAttributes::SpecialName) != 0 && methodBuilder->get_Name()->Equals(ConstructorInfo::in::ConstructorName)) {
    m_constructorCount++;
  }
  m_listMethods->Add(methodBuilder);
  return methodBuilder;
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return DefinePInvokeMethodHelper(name, dllName, name, attributes, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr, nativeCallConv, nativeCharSet);
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return DefinePInvokeMethodHelper(name, dllName, entryName, attributes, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr, nativeCallConv, nativeCharSet);
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return DefinePInvokeMethodHelper(name, dllName, entryName, attributes, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers, nativeCallConv, nativeCharSet);
}

MethodBuilder TypeBuilder___::DefinePInvokeMethodHelper(String name, String dllName, String importName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  CheckContext(returnType);
  CheckContext(rt::newarr<Array<Array<Type>>>(3, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes));
  CheckContext(parameterTypeRequiredCustomModifiers);
  CheckContext(parameterTypeOptionalCustomModifiers);
  {
    rt::lock(get_SyncRoot());
    if (name == nullptr) {
      rt::throw_exception<ArgumentNullException>("name");
    }
    if (name->get_Length() == 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
    }
    if (dllName == nullptr) {
      rt::throw_exception<ArgumentNullException>("dllName");
    }
    if (dllName->get_Length() == 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "dllName");
    }
    if (importName == nullptr) {
      rt::throw_exception<ArgumentNullException>("importName");
    }
    if (importName->get_Length() == 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "importName");
    }
    if ((attributes & MethodAttributes::Abstract) != 0) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadPInvokeMethod());
    }
    if ((m_iAttr & TypeAttributes::ClassSemanticsMask) == TypeAttributes::ClassSemanticsMask) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadPInvokeOnInterface());
    }
    ThrowIfCreated();
    attributes |= MethodAttributes::PinvokeImpl;
    MethodBuilder methodBuilder = rt::newobj<MethodBuilder>(name, attributes, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers, m_module, (TypeBuilder)this);
    Int32 length;
    methodBuilder->GetMethodSignature()->InternalGetSignature(length);
    if (m_listMethods->Contains(methodBuilder)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_MethodRedefined());
    }
    m_listMethods->Add(methodBuilder);
    MethodToken token = methodBuilder->GetToken();
    Int32 num = 0;
    switch (nativeCallConv) {
      case CallingConvention::Winapi:
        num = 256;
        break;
      case CallingConvention::Cdecl:
        num = 512;
        break;
      case CallingConvention::StdCall:
        num = 768;
        break;
      case CallingConvention::ThisCall:
        num = 1024;
        break;
      case CallingConvention::FastCall:
        num = 1280;
        break;
    }
    switch (nativeCharSet) {
      case CharSet::None:
        num |= 0;
        break;
      case CharSet::Ansi:
        num |= 2;
        break;
      case CharSet::Unicode:
        num |= 4;
        break;
      case CharSet::Auto:
        num |= 6;
        break;
    }
    ModuleBuilder module = m_module;
    SetPInvokeData(QCallModule(module), dllName, importName, token.get_Token(), num);
    methodBuilder->SetToken(token);
    return methodBuilder;
  }
}

ConstructorBuilder TypeBuilder___::DefineTypeInitializer() {
  {
    rt::lock(get_SyncRoot());
    return DefineTypeInitializerNoLock();
  }
}

ConstructorBuilder TypeBuilder___::DefineTypeInitializerNoLock() {
  ThrowIfCreated();
  return rt::newobj<ConstructorBuilder>(ConstructorInfo::in::TypeConstructorName, MethodAttributes::Private | MethodAttributes::Static | MethodAttributes::SpecialName, CallingConventions::Standard, nullptr, m_module, (TypeBuilder)this);
}

ConstructorBuilder TypeBuilder___::DefineDefaultConstructor(MethodAttributes attributes) {
  if ((m_iAttr & TypeAttributes::ClassSemanticsMask) == TypeAttributes::ClassSemanticsMask) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConstructorNotAllowedOnInterface());
  }
  {
    rt::lock(get_SyncRoot());
    return DefineDefaultConstructorNoLock(attributes);
  }
}

ConstructorBuilder TypeBuilder___::DefineDefaultConstructorNoLock(MethodAttributes attributes) {
  ConstructorInfo constructorInfo = nullptr;
  if (rt::is<TypeBuilderInstantiation>(m_typeParent)) {
    Type type = m_typeParent->GetGenericTypeDefinition();
    if (rt::is<TypeBuilder>(type)) {
      type = ((TypeBuilder)type)->m_bakedRuntimeType;
    }
    if (type == nullptr) {
      rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
    }
    Type type2 = type->MakeGenericType(m_typeParent->GetGenericArguments());
    constructorInfo = ((!rt::is<TypeBuilderInstantiation>(type2)) ? type2->GetConstructor(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic, nullptr, Type::in::EmptyTypes, nullptr) : GetConstructor(type2, type->GetConstructor(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic, nullptr, Type::in::EmptyTypes, nullptr)));
  }
  if (constructorInfo == nullptr) {
    constructorInfo = m_typeParent->GetConstructor(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic, nullptr, Type::in::EmptyTypes, nullptr);
  }
  if (constructorInfo == nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NoParentDefaultConstructor());
  }
  ConstructorBuilder constructorBuilder = DefineConstructor(attributes, CallingConventions::Standard, nullptr);
  m_constructorCount++;
  ILGenerator iLGenerator = constructorBuilder->GetILGenerator();
  iLGenerator->Emit(OpCodes::in::Ldarg_0);
  iLGenerator->Emit(OpCodes::in::Call, constructorInfo);
  iLGenerator->Emit(OpCodes::in::Ret);
  constructorBuilder->m_isDefaultConstructor = true;
  return constructorBuilder;
}

ConstructorBuilder TypeBuilder___::DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes) {
  return DefineConstructor(attributes, callingConvention, parameterTypes, nullptr, nullptr);
}

ConstructorBuilder TypeBuilder___::DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  if ((m_iAttr & TypeAttributes::ClassSemanticsMask) == TypeAttributes::ClassSemanticsMask && (attributes & MethodAttributes::Static) != MethodAttributes::Static) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConstructorNotAllowedOnInterface());
  }
  {
    rt::lock(get_SyncRoot());
    return DefineConstructorNoLock(attributes, callingConvention, parameterTypes, requiredCustomModifiers, optionalCustomModifiers);
  }
}

ConstructorBuilder TypeBuilder___::DefineConstructorNoLock(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  CheckContext(parameterTypes);
  CheckContext(requiredCustomModifiers);
  CheckContext(optionalCustomModifiers);
  ThrowIfCreated();
  String name = ((attributes & MethodAttributes::Static) != 0) ? ConstructorInfo::in::TypeConstructorName : ConstructorInfo::in::ConstructorName;
  attributes |= MethodAttributes::SpecialName;
  ConstructorBuilder result = rt::newobj<ConstructorBuilder>(name, attributes, callingConvention, parameterTypes, requiredCustomModifiers, optionalCustomModifiers, m_module, (TypeBuilder)this);
  m_constructorCount++;
  return result;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, TypeAttributes::NestedPrivate, nullptr, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces) {
  {
    rt::lock(get_SyncRoot());
    CheckContext(parent);
    CheckContext(interfaces);
    return DefineNestedTypeNoLock(name, attr, parent, interfaces, PackingSize::Unspecified, 0);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, attr, parent, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, attr, nullptr, nullptr, PackingSize::Unspecified, 0);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, Int32 typeSize) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, attr, parent, nullptr, PackingSize::Unspecified, typeSize);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, attr, parent, nullptr, packSize, 0);
  }
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize, Int32 typeSize) {
  {
    rt::lock(get_SyncRoot());
    return DefineNestedTypeNoLock(name, attr, parent, nullptr, packSize, typeSize);
  }
}

TypeBuilder TypeBuilder___::DefineNestedTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packSize, Int32 typeSize) {
  return rt::newobj<TypeBuilder>(name, attr, parent, interfaces, m_module, packSize, typeSize, (TypeBuilder)this);
}

FieldBuilder TypeBuilder___::DefineField(String fieldName, Type type, FieldAttributes attributes) {
  return DefineField(fieldName, type, nullptr, nullptr, attributes);
}

FieldBuilder TypeBuilder___::DefineField(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
  {
    rt::lock(get_SyncRoot());
    return DefineFieldNoLock(fieldName, type, requiredCustomModifiers, optionalCustomModifiers, attributes);
  }
}

FieldBuilder TypeBuilder___::DefineFieldNoLock(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
  ThrowIfCreated();
  CheckContext(type);
  CheckContext(requiredCustomModifiers);
  if (m_enumUnderlyingType == nullptr && get_IsEnum() && (attributes & FieldAttributes::Static) == 0) {
    m_enumUnderlyingType = type;
  }
  return rt::newobj<FieldBuilder>((TypeBuilder)this, fieldName, type, requiredCustomModifiers, optionalCustomModifiers, attributes);
}

FieldBuilder TypeBuilder___::DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes) {
  {
    rt::lock(get_SyncRoot());
    return DefineInitializedDataNoLock(name, data, attributes);
  }
}

FieldBuilder TypeBuilder___::DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes) {
  if (data == nullptr) {
    rt::throw_exception<ArgumentNullException>("data");
  }
  return DefineDataHelper(name, data, data->get_Length(), attributes);
}

FieldBuilder TypeBuilder___::DefineUninitializedData(String name, Int32 size, FieldAttributes attributes) {
  {
    rt::lock(get_SyncRoot());
    return DefineUninitializedDataNoLock(name, size, attributes);
  }
}

FieldBuilder TypeBuilder___::DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes) {
  return DefineDataHelper(name, nullptr, size, attributes);
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return DefineProperty(name, attributes, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return DefineProperty(name, attributes, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return DefineProperty(name, attributes, (CallingConventions)0, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers);
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  {
    rt::lock(get_SyncRoot());
    return DefinePropertyNoLock(name, attributes, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers);
  }
}

PropertyBuilder TypeBuilder___::DefinePropertyNoLock(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  CheckContext(returnType);
  CheckContext(rt::newarr<Array<Array<Type>>>(3, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes));
  CheckContext(parameterTypeRequiredCustomModifiers);
  CheckContext(parameterTypeOptionalCustomModifiers);
  ThrowIfCreated();
  SignatureHelper propertySigHelper = SignatureHelper::in::GetPropertySigHelper(m_module, callingConvention, returnType, returnTypeRequiredCustomModifiers, returnTypeOptionalCustomModifiers, parameterTypes, parameterTypeRequiredCustomModifiers, parameterTypeOptionalCustomModifiers);
  Int32 length;
  Array<Byte> signature = propertySigHelper->InternalGetSignature(length);
  ModuleBuilder module = m_module;
  PropertyToken prToken = PropertyToken(DefineProperty(QCallModule(module), m_tdType.get_Token(), name, attributes, signature, length));
  return rt::newobj<PropertyBuilder>(m_module, name, propertySigHelper, attributes, returnType, prToken, (TypeBuilder)this);
}

EventBuilder TypeBuilder___::DefineEvent(String name, EventAttributes attributes, Type eventtype) {
  {
    rt::lock(get_SyncRoot());
    return DefineEventNoLock(name, attributes, eventtype);
  }
}

EventBuilder TypeBuilder___::DefineEventNoLock(String name, EventAttributes attributes, Type eventtype) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if (name[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalName(), "name");
  }
  CheckContext(eventtype);
  ThrowIfCreated();
  Int32 token = m_module->GetTypeTokenInternal(eventtype).get_Token();
  ModuleBuilder module = m_module;
  EventToken evToken = EventToken(DefineEvent(QCallModule(module), m_tdType.get_Token(), name, attributes, token));
  return rt::newobj<EventBuilder>(m_module, name, attributes, (TypeBuilder)this, evToken);
}

TypeInfo TypeBuilder___::CreateTypeInfo() {
  {
    rt::lock(get_SyncRoot());
    return CreateTypeNoLock();
  }
}

Type TypeBuilder___::CreateType() {
  {
    rt::lock(get_SyncRoot());
    return CreateTypeNoLock();
  }
}

void TypeBuilder___::CheckContext(Array<Array<Type>> typess) {
  m_module->CheckContext(typess);
}

void TypeBuilder___::CheckContext(Array<Type> types) {
  m_module->CheckContext(types);
}

TypeInfo TypeBuilder___::CreateTypeNoLock() {
  if (IsCreated()) {
    return m_bakedRuntimeType;
  }
  if (m_typeInterfaces == nullptr) {
    m_typeInterfaces = rt::newobj<List<Type>>();
  }
  Array<Int32> array = rt::newarr<Array<Int32>>(m_typeInterfaces->get_Count());
  for (Int32 i = 0; i < m_typeInterfaces->get_Count(); i++) {
    array[i] = m_module->GetTypeTokenInternal(m_typeInterfaces[i]).get_Token();
  }
  Int32 num = 0;
  if (m_typeParent != nullptr) {
    num = m_module->GetTypeTokenInternal(m_typeParent).get_Token();
  }
  ModuleBuilder module = m_module;
  if (get_IsGenericParameter()) {
    Array<Int32> array2;
    if (m_typeParent != nullptr) {
      array2 = rt::newarr<Array<Int32>>(m_typeInterfaces->get_Count() + 2);
    } else {
      array2 = rt::newarr<Array<Int32>>(m_typeInterfaces->get_Count() + 1);
    }
    for (Int32 j = 0; j < m_typeInterfaces->get_Count(); j++) {
      array2[j] = m_module->GetTypeTokenInternal(m_typeInterfaces[j]).get_Token();
    }
    Int32 tkParent = (m_declMeth == nullptr) ? m_DeclaringType->m_tdType.get_Token() : m_declMeth->GetToken().get_Token();
    m_tdType = TypeToken(DefineGenericParam(QCallModule(module), m_strName, tkParent, m_genParamAttributes, m_genParamPos, array2));
    if (m_ca != nullptr) {
      for (CustAttr& item : rt::each(m_ca)) {
        item->Bake(m_module, get_MetadataTokenInternal());
      }
    }
    m_hasBeenCreated = true;
    return (TypeBuilder)this;
  }
  if ((m_tdType.get_Token() & 16777215) != 0 && (num & 16777215) != 0) {
    SetParentType(QCallModule(module), m_tdType.get_Token(), num);
  }
  if (m_inst != nullptr) {
    Array<GenericTypeParameterBuilder> inst = m_inst;
    for (GenericTypeParameterBuilder& genericTypeParameterBuilder : rt::each(inst)) {
      genericTypeParameterBuilder->m_type->CreateType();
    }
  }
  if (!m_isHiddenGlobalType && m_constructorCount == 0 && (m_iAttr & TypeAttributes::ClassSemanticsMask) == 0 && !Type::in::get_IsValueType() && (m_iAttr & (TypeAttributes::Abstract | TypeAttributes::Sealed)) != (TypeAttributes::Abstract | TypeAttributes::Sealed)) {
    DefineDefaultConstructor(MethodAttributes::Public);
  }
  Int32 count = m_listMethods->get_Count();
  for (Int32 l = 0; l < count; l++) {
    MethodBuilder methodBuilder = m_listMethods[l];
    if (methodBuilder->get_IsGenericMethodDefinition()) {
      methodBuilder->GetToken();
    }
    MethodAttributes attributes = methodBuilder->get_Attributes();
    if ((methodBuilder->GetMethodImplementationFlags() & (MethodImplAttributes)135) != 0 || (attributes & MethodAttributes::PinvokeImpl) != 0) {
      continue;
    }
    Int32 signatureLength;
    Array<Byte> localSignature = methodBuilder->GetLocalSignature(signatureLength);
    if ((attributes & MethodAttributes::Abstract) != 0 && (m_iAttr & TypeAttributes::Abstract) == 0) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_BadTypeAttributesNotAbstract());
    }
    Array<Byte> body = methodBuilder->GetBody();
    if ((attributes & MethodAttributes::Abstract) != 0) {
      if (body != nullptr) {
        rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_BadMethodBody(), methodBuilder->get_Name()));
      }
    } else if (body == nullptr || body->get_Length() == 0) {
      if (methodBuilder->m_ilGenerator != nullptr) {
        methodBuilder->CreateMethodBodyHelper(methodBuilder->GetILGenerator());
      }
      body = methodBuilder->GetBody();
      if ((body == nullptr || body->get_Length() == 0) && !methodBuilder->m_canBeRuntimeImpl) {
        rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_BadEmptyMethodBody(), methodBuilder->get_Name()));
      }
    }

    Int32 maxStack = methodBuilder->GetMaxStack();
    Array<ExceptionHandler> exceptionHandlers = methodBuilder->GetExceptionHandlers();
    Array<Int32> tokenFixups = methodBuilder->GetTokenFixups();
    SetMethodIL(QCallModule(module), methodBuilder->GetToken().get_Token(), methodBuilder->get_InitLocals(), body, (body != nullptr) ? body->get_Length() : 0, localSignature, signatureLength, maxStack, exceptionHandlers, (exceptionHandlers != nullptr) ? exceptionHandlers->get_Length() : 0, tokenFixups, (tokenFixups != nullptr) ? tokenFixups->get_Length() : 0);
    if (m_module->get_ContainingAssemblyBuilder()->_assemblyData->_access == AssemblyBuilderAccess::Run) {
      methodBuilder->ReleaseBakedStructures();
    }
  }
  m_hasBeenCreated = true;
  RuntimeType o = nullptr;
  TermCreateClass(QCallModule(module), m_tdType.get_Token(), ObjectHandleOnStack::Create(o));
  if (!m_isHiddenGlobalType) {
    m_bakedRuntimeType = o;
    if (m_DeclaringType != nullptr && m_DeclaringType->m_bakedRuntimeType != nullptr) {
      m_DeclaringType->m_bakedRuntimeType->InvalidateCachedNestedType();
    }
    return o;
  }
  return nullptr;
}

void TypeBuilder___::SetParent(Type parent) {
  ThrowIfCreated();
  if (parent != nullptr) {
    CheckContext(parent);
    if (parent->get_IsInterface()) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_CannotSetParentToInterface());
    }
    m_typeParent = parent;
  } else if ((m_iAttr & TypeAttributes::ClassSemanticsMask) != TypeAttributes::ClassSemanticsMask) {
    m_typeParent = typeof<Object>();
  } else {
    if ((m_iAttr & TypeAttributes::Abstract) == 0) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_BadInterfaceNotAbstract());
    }
    m_typeParent = nullptr;
  }

}

void TypeBuilder___::AddInterfaceImplementation(Type interfaceType) {
  if (interfaceType == nullptr) {
    rt::throw_exception<ArgumentNullException>("interfaceType");
  }
  CheckContext(interfaceType);
  ThrowIfCreated();
  TypeToken typeTokenInternal = m_module->GetTypeTokenInternal(interfaceType);
  ModuleBuilder module = m_module;
  AddInterfaceImpl(QCallModule(module), m_tdType.get_Token(), typeTokenInternal.get_Token());
  m_typeInterfaces->Add(interfaceType);
}

void TypeBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  DefineCustomAttribute(m_module, m_tdType.get_Token(), m_module->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void TypeBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  customBuilder->CreateCustomAttribute(m_module, m_tdType.get_Token());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderNamespace
