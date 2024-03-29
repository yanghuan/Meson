#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARD(FieldInfo)
FORWARD(MethodBase)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
namespace BinderNamespace {
using namespace System::Globalization;
CLASS(Binder) : public object {
  public: void ctor();
  public: FieldInfo BindToField(BindingFlags bindingAttr, Array<FieldInfo> match, Object value, CultureInfo culture);
  public: MethodBase BindToMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Object>& args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> names, Object& state);
  public: Object ChangeType(Object value, Type type, CultureInfo culture);
  public: void ReorderArgumentArray(Array<Object>& args, Object state);
  public: MethodBase SelectMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers);
  public: PropertyInfo SelectProperty(BindingFlags bindingAttr, Array<PropertyInfo> match, Type returnType, Array<Type> indexes, Array<ParameterModifier> modifiers);
};
} // namespace BinderNamespace
using Binder = BinderNamespace::Binder;
} // namespace System::Private::CoreLib::System::Reflection
