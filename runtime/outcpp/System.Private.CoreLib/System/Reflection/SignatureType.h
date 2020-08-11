#pragma once

#include <System.Private.CoreLib/System/Type.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(StructLayoutAttribute)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class GenericParameterAttributes : int32_t;
enum class MemberTypes : int32_t;
enum class TypeAttributes : int32_t;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(CustomAttributeData)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARDS(InterfaceMapping)
FORWARD(MemberFilter)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
FORWARD(TypeFilter)
namespace SignatureTypeNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace Runtime::InteropServices;
using Collections::Generic::IList;
CLASS(SignatureType) : public Type::in {
  public: Boolean get_IsSignatureType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  public: Boolean get_IsByRefLike();
  public: Boolean get_IsGenericType();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: Boolean get_ContainsGenericParameters();
  public: MemberTypes get_MemberType();
  public: Array<Type> get_GenericTypeArguments();
  public: Int32 get_GenericParameterPosition();
  public: SignatureType get_ElementType();
  public: Type get_UnderlyingSystemType();
  public: String get_Name();
  public: String get_Namespace();
  public: String get_FullName();
  public: String get_AssemblyQualifiedName();
  public: Assembly get_Assembly();
  public: Module get_Module();
  public: Type get_ReflectedType();
  public: Type get_BaseType();
  public: Int32 get_MetadataToken();
  public: Type get_DeclaringType();
  public: MethodBase get_DeclaringMethod();
  public: GenericParameterAttributes get_GenericParameterAttributes();
  public: Guid get_GUID();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: Boolean get_IsEnum();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Boolean get_IsSerializable();
  public: StructLayoutAttribute get_StructLayoutAttribute();
  public: RuntimeTypeHandle get_TypeHandle();
  protected: Boolean HasElementTypeImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Type MakeByRefType();
  public: Type MakePointerType();
  public: Type MakeGenericType(Array<Type> typeArguments);
  public: Type GetElementType();
  public: Int32 GetArrayRank();
  public: Type GetGenericTypeDefinition();
  public: Array<Type> GetGenericArguments();
  public: String ToString();
  public: Array<Type> GetInterfaces();
  public: Boolean IsAssignableFrom(Type c);
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: Array<Type> GetGenericParameterConstraints();
  public: Boolean IsEnumDefined(Object value);
  public: String GetEnumName(Object value);
  public: Array<String> GetEnumNames();
  public: Type GetEnumUnderlyingType();
  public: Array<> GetEnumValues();
  protected: TypeCode GetTypeCodeImpl();
  protected: TypeAttributes GetAttributeFlagsImpl();
  public: Array<ConstructorInfo> GetConstructors(BindingFlags bindingAttr);
  public: EventInfo GetEvent(String name, BindingFlags bindingAttr);
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: Type GetNestedType(String name, BindingFlags bindingAttr);
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: MethodInfo GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: PropertyInfo GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<MemberInfo> FindMembers(MemberTypes memberType, BindingFlags bindingAttr, MemberFilter filter, Object filterCriteria);
  public: Array<MemberInfo> GetMember(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetDefaultMembers();
  public: Array<EventInfo> GetEvents();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Type GetInterface(String name, Boolean ignoreCase);
  protected: ConstructorInfo GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: Boolean IsCOMObjectImpl();
  protected: Boolean IsPrimitiveImpl();
  public: Array<Type> FindInterfaces(TypeFilter filter, Object filterCriteria);
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  protected: Boolean IsContextfulImpl();
  public: Boolean IsEquivalentTo(Type other);
  public: Boolean IsInstanceOfType(Object o);
  protected: Boolean IsMarshalByRefImpl();
  public: Boolean IsSubclassOf(Type c);
  protected: Boolean IsValueTypeImpl();
  protected: void ctor();
};
} // namespace SignatureTypeNamespace
using SignatureType = SignatureTypeNamespace::SignatureType;
} // namespace System::Private::CoreLib::System::Reflection
