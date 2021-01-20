#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARD(Binder)
FORWARD(FieldInfo)
FORWARD(IReflect)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando {
namespace IExpandoNamespace {
using namespace System::Globalization;
using namespace System::Reflection;
CLASS(IExpando) : public object {
  public: using interface = rt::TypeList<IReflect>;
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
  public: FieldInfo AddField(String name);
  public: void RemoveMember(MemberInfo m);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IExpandoNamespace
using IExpando = IExpandoNamespace::IExpando;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::Expando
