#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeTypeHandle)
FORWARD(Type)
FORWARDS(TypedReference)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
enum class FieldAttributes;
enum class BindingFlags;
FORWARD(Binder)
namespace FieldInfoNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(FieldInfo) {
  public: MemberTypes get_MemberType();
  public: FieldAttributes get_Attributes();
  public: Type get_FieldType();
  public: Boolean get_IsInitOnly();
  public: Boolean get_IsLiteral();
  public: Boolean get_IsNotSerialized();
  public: Boolean get_IsPinvokeImpl();
  public: Boolean get_IsSpecialName();
  public: Boolean get_IsStatic();
  public: Boolean get_IsAssembly();
  public: Boolean get_IsFamily();
  public: Boolean get_IsFamilyAndAssembly();
  public: Boolean get_IsFamilyOrAssembly();
  public: Boolean get_IsPrivate();
  public: Boolean get_IsPublic();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: RuntimeFieldHandle get_FieldHandle();
  public: static FieldInfo GetFieldFromHandle(RuntimeFieldHandle handle);
  public: static FieldInfo GetFieldFromHandle(RuntimeFieldHandle handle, RuntimeTypeHandle declaringType);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Object GetValue(Object obj);
  public: void SetValue(Object obj, Object value);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture);
  public: void SetValueDirect(TypedReference obj, Object value);
  public: Object GetValueDirect(TypedReference obj);
  public: Object GetRawConstantValue();
  public: Array<Type> GetOptionalCustomModifiers();
  public: Array<Type> GetRequiredCustomModifiers();
};
} // namespace FieldInfoNamespace
using FieldInfo = FieldInfoNamespace::FieldInfo;
} // namespace System::Private::CoreLib::System::Reflection
