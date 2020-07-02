#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
FORWARD(Binder)
FORWARDS(ParameterModifier)
FORWARD(MethodInfo)
FORWARD(FieldInfo)
FORWARD(PropertyInfo)
FORWARD(MemberInfo)
namespace IReflectNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(IReflect) {
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
};
} // namespace IReflectNamespace
using IReflect = IReflectNamespace::IReflect;
} // namespace System::Private::CoreLib::System::Reflection
