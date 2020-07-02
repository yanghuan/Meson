#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARDS(Guid)
FORWARDS(RuntimeTypeHandle)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
FORWARD(Assembly)
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
namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace TypeBuilderInstantiationNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(TypeBuilderInstantiation) {
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: String get_Name();
  public: Module get_Module();
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
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericParameter();
  public: Int32 get_GenericParameterPosition();
  public: Boolean get_ContainsGenericParameters();
  public: MethodBase get_DeclaringMethod();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: static Type MakeGenericType(Type type, Array<Type> typeArguments);
  public: String ToString();
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  private: Type Substitute(Array<Type> substitutes);
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
  protected: Boolean IsValueTypeImpl();
  public: Type GetGenericTypeDefinition();
  public: Type MakeGenericType(Array<Type> inst);
  public: Boolean IsAssignableFrom(Type c);
  public: Boolean IsSubclassOf(Type c);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  private: Type m_type;
  private: Array<Type> m_inst;
  private: String m_strFullQualName;
  public: Hashtable m_hashtable;
};
} // namespace TypeBuilderInstantiationNamespace
using TypeBuilderInstantiation = TypeBuilderInstantiationNamespace::TypeBuilderInstantiation;
} // namespace System::Private::CoreLib::System::Reflection::Emit
