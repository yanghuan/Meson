#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Guid)
FORWARDS(RuntimeTypeHandle)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
FORWARD(Assembly)
enum class GenericParameterAttributes;
FORWARD(MethodBase)
FORWARD(TypeInfo)
enum class BindingFlags;
FORWARD(Binder)
FORWARDS(ParameterModifier)
enum class CallingConventions;
FORWARD(ConstructorInfo)
FORWARD(MethodInfo)
FORWARD(FieldInfo)
FORWARD(EventInfo)
FORWARD(PropertyInfo)
enum class MemberTypes;
FORWARD(MemberInfo)
FORWARDS(InterfaceMapping)
enum class TypeAttributes;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(TypeBuilder)
namespace GenericTypeParameterBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(GenericTypeParameterBuilder) {
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: String get_Name();
  public: Module get_Module();
  public: Int32 get_MetadataTokenInternal();
  public: Guid get_GUID();
  public: Assembly get_Assembly();
  public: RuntimeTypeHandle get_TypeHandle();
  public: String get_FullName();
  public: String get_Namespace();
  public: String get_AssemblyQualifiedName();
  public: Type get_BaseType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Type get_UnderlyingSystemType();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsGenericType();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsConstructedGenericType();
  public: Int32 get_GenericParameterPosition();
  public: Boolean get_ContainsGenericParameters();
  public: GenericParameterAttributes get_GenericParameterAttributes();
  public: MethodBase get_DeclaringMethod();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: String ToString();
  public: Boolean Equals(Object o);
  public: Int32 GetHashCode();
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  protected: ConstructorInfo GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<ConstructorInfo> GetConstructors(BindingFlags bindingAttr);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: Type GetInterface(String name, Boolean ignoreCase);
  public: Array<Type> GetInterfaces();
  public: EventInfo GetEvent(String name, BindingFlags bindingAttr);
  public: Array<EventInfo> GetEvents();
  protected: PropertyInfo GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: Type GetNestedType(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  protected: TypeAttributes GetAttributeFlagsImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Type GetElementType();
  protected: Boolean HasElementTypeImpl();
  public: Array<Type> GetGenericArguments();
  public: Type GetGenericTypeDefinition();
  public: Type MakeGenericType(Array<Type> typeArguments);
  protected: Boolean IsValueTypeImpl();
  public: Boolean IsAssignableFrom(Type c);
  public: Boolean IsSubclassOf(Type c);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: void SetBaseTypeConstraint(Type baseTypeConstraint);
  public: void SetInterfaceConstraints(Array<Type> interfaceConstraints);
  public: void SetGenericParameterAttributes(GenericParameterAttributes genericParameterAttributes);
  public: TypeBuilder m_type;
};
} // namespace GenericTypeParameterBuilderNamespace
using GenericTypeParameterBuilder = GenericTypeParameterBuilderNamespace::GenericTypeParameterBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
