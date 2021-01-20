#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldToken.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class FieldAttributes : int32_t;
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(Module)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(RuntimeFieldHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(TypeBuilder)
namespace FieldBuilderNamespace {
using namespace System::Globalization;
CLASS(FieldBuilder) : public FieldInfo::in {
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Type get_FieldType();
  public: RuntimeFieldHandle get_FieldHandle();
  public: FieldAttributes get_Attributes();
  public: void ctor(TypeBuilder typeBuilder, String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes);
  public: void SetData(Array<Byte> data, Int32 size);
  public: Object GetValue(Object obj);
  public: void SetValue(Object obj, Object val, BindingFlags invokeAttr, Binder binder, CultureInfo culture);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: FieldToken GetToken();
  public: void SetOffset(Int32 iOffset);
  public: void SetConstant(Object defaultValue);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  private: Int32 m_fieldTok;
  private: FieldToken m_tkField;
  private: TypeBuilder m_typeBuilder;
  private: String m_fieldName;
  private: FieldAttributes m_Attributes;
  private: Type m_fieldType;
};
} // namespace FieldBuilderNamespace
using FieldBuilder = FieldBuilderNamespace::FieldBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
