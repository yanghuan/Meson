#pragma once

#include <System.Private.CoreLib/System/Reflection/MemberInfo.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class MemberTypes;
enum class PropertyAttributes;
FORWARD(Binder)
FORWARD(MethodInfo)
FORWARD(ParameterInfo)
namespace PropertyInfoNamespace {
using namespace Globalization;
CLASS(PropertyInfo) : public MemberInfo::in {
  public: MemberTypes get_MemberType();
  public: Type get_PropertyType();
  public: PropertyAttributes get_Attributes();
  public: Boolean get_IsSpecialName();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: MethodInfo get_GetMethod();
  public: MethodInfo get_SetMethod();
  protected: void ctor();
  public: Array<ParameterInfo> GetIndexParameters();
  public: Array<MethodInfo> GetAccessors();
  public: Array<MethodInfo> GetAccessors(Boolean nonPublic);
  public: MethodInfo GetGetMethod();
  public: MethodInfo GetGetMethod(Boolean nonPublic);
  public: MethodInfo GetSetMethod();
  public: MethodInfo GetSetMethod(Boolean nonPublic);
  public: Array<Type> GetOptionalCustomModifiers();
  public: Array<Type> GetRequiredCustomModifiers();
  public: Object GetValue(Object obj);
  public: Object GetValue(Object obj, Array<Object> index);
  public: Object GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  public: Object GetConstantValue();
  public: Object GetRawConstantValue();
  public: void SetValue(Object obj, Object value);
  public: void SetValue(Object obj, Object value, Array<Object> index);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(PropertyInfo left, PropertyInfo right);
  public: static Boolean op_Inequality(PropertyInfo left, PropertyInfo right);
};
} // namespace PropertyInfoNamespace
using PropertyInfo = PropertyInfoNamespace::PropertyInfo;
} // namespace System::Private::CoreLib::System::Reflection
