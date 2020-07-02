#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
enum class MemberTypes;
FORWARD(Module)
enum class FieldAttributes;
enum class BindingFlags;
FORWARD(Binder)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
FORWARDS(Int32)
FORWARDS(RuntimeFieldHandle)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(TypedReference)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(TypeBuilderInstantiation)
namespace FieldOnTypeBuilderInstantiationNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(FieldOnTypeBuilderInstantiation) {
  public: FieldInfo get_FieldInfo();
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: RuntimeFieldHandle get_FieldHandle();
  public: Type get_FieldType();
  public: FieldAttributes get_Attributes();
  public: static FieldInfo GetField(FieldInfo Field, TypeBuilderInstantiation type);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Array<Type> GetRequiredCustomModifiers();
  public: Array<Type> GetOptionalCustomModifiers();
  public: void SetValueDirect(TypedReference obj, Object value);
  public: Object GetValueDirect(TypedReference obj);
  public: Object GetValue(Object obj);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture);
  private: FieldInfo m_field;
  private: TypeBuilderInstantiation m_type;
};
} // namespace FieldOnTypeBuilderInstantiationNamespace
using FieldOnTypeBuilderInstantiation = FieldOnTypeBuilderInstantiationNamespace::FieldOnTypeBuilderInstantiation;
} // namespace System::Private::CoreLib::System::Reflection::Emit
