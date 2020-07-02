#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Guid)
FORWARDS(RuntimeTypeHandle)
FORWARD(Type)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
FORWARD(Assembly)
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
FORWARDS(TypeToken)
FORWARD(FieldBuilder)
FORWARD(CustomAttributeBuilder)
FORWARD(TypeBuilder)
namespace EnumBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(EnumBuilder) {
  public: TypeToken get_TypeToken();
  public: FieldBuilder get_UnderlyingField();
  public: String get_Name();
  public: Guid get_GUID();
  public: Module get_Module();
  public: Assembly get_Assembly();
  public: RuntimeTypeHandle get_TypeHandle();
  public: String get_FullName();
  public: String get_AssemblyQualifiedName();
  public: String get_Namespace();
  public: Type get_BaseType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsConstructedGenericType();
  public: Type get_UnderlyingSystemType();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: FieldBuilder DefineLiteral(String literalName, Object literalValue);
  public: TypeInfo CreateTypeInfo();
  public: Type CreateType();
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
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  protected: TypeAttributes GetAttributeFlagsImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsValueTypeImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Type GetElementType();
  protected: Boolean HasElementTypeImpl();
  public: Type GetEnumUnderlyingType();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: TypeBuilder m_typeBuilder;
  private: FieldBuilder m_underlyingField;
};
} // namespace EnumBuilderNamespace
using EnumBuilder = EnumBuilderNamespace::EnumBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
