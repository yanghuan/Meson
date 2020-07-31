#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class MemberTypes;
enum class TypeAttributes;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARDS(InterfaceMapping)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
namespace TypeDelegatorNamespace {
using namespace Globalization;
CLASS(TypeDelegator) : public TypeInfo::in {
  public: Guid get_GUID();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: Assembly get_Assembly();
  public: RuntimeTypeHandle get_TypeHandle();
  public: String get_Name();
  public: String get_FullName();
  public: String get_Namespace();
  public: String get_AssemblyQualifiedName();
  public: Type get_BaseType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: Boolean get_IsByRefLike();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsCollectible();
  public: Type get_UnderlyingSystemType();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  protected: void Ctor();
  public: void Ctor(Type delegatingType);
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
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: Type GetNestedType(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  protected: TypeAttributes GetAttributeFlagsImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean IsValueTypeImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Type GetElementType();
  protected: Boolean HasElementTypeImpl();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  protected: Type typeImpl;
};
} // namespace TypeDelegatorNamespace
using TypeDelegator = TypeDelegatorNamespace::TypeDelegator;
} // namespace System::Private::CoreLib::System::Reflection
