#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
FORWARD(Object)
FORWARD_(Array, T1, T2)
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
enum class TypeKind;
namespace SymbolTypeNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(SymbolType) {
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Guid get_GUID();
  public: Module get_Module();
  public: Assembly get_Assembly();
  public: RuntimeTypeHandle get_TypeHandle();
  public: String get_Name();
  public: String get_FullName();
  public: String get_AssemblyQualifiedName();
  public: String get_Namespace();
  public: Type get_BaseType();
  public: Boolean get_IsConstructedGenericType();
  public: Type get_UnderlyingSystemType();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: static Type FormCompoundType(String format, Type baseType, Int32 curIndex);
  public: void SetElementType(Type baseType);
  private: void SetBounds(Int32 lower, Int32 upper);
  public: void SetFormat(String format, Int32 curIndex, Int32 length);
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Int32 GetArrayRank();
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  public: String ToString();
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
  protected: Boolean IsPointerImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsValueTypeImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Type GetElementType();
  protected: Boolean HasElementTypeImpl();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: TypeKind m_typeKind;
  public: Type m_baseType;
  public: Int32 m_cRank;
  public: Array<Int32> m_iaLowerBound;
  public: Array<Int32> m_iaUpperBound;
  private: String m_format;
  private: Boolean m_isSzArray;
};
} // namespace SymbolTypeNamespace
using SymbolType = SymbolTypeNamespace::SymbolType;
} // namespace System::Private::CoreLib::System::Reflection::Emit
