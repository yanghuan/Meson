#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARD(Binder)
FORWARD(FieldInfo)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
namespace IReflectNamespace {
using namespace System::Globalization;
CLASS(IReflect) : public Object::in {
  public: Type get_UnderlyingSystemType();
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: PropertyInfo GetProperty(String name, BindingFlags bindingAttr);
  public: PropertyInfo GetProperty(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReflectNamespace
using IReflect = IReflectNamespace::IReflect;
} // namespace System::Private::CoreLib::System::Reflection
