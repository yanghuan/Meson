#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/FieldToken.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
enum class FieldAttributes;
enum class BindingFlags;
FORWARD(Binder)
FORWARD(ConstructorInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
FORWARDS(RuntimeFieldHandle)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(TypeBuilder)
namespace FieldBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(FieldBuilder) {
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Type get_FieldType();
  public: RuntimeFieldHandle get_FieldHandle();
  public: FieldAttributes get_Attributes();
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
