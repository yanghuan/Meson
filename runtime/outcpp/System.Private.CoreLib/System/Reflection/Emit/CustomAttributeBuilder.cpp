#include "CustomAttributeBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::CustomAttributeBuilderNamespace {
using namespace System::Text;

void CustomAttributeBuilder___::ctor(ConstructorInfo con, Array<Object> constructorArgs) {
}

void CustomAttributeBuilder___::ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<PropertyInfo> namedProperties, Array<Object> propertyValues) {
}

void CustomAttributeBuilder___::ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<FieldInfo> namedFields, Array<Object> fieldValues) {
}

void CustomAttributeBuilder___::ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<PropertyInfo> namedProperties, Array<Object> propertyValues, Array<FieldInfo> namedFields, Array<Object> fieldValues) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (constructorArgs == nullptr) {
    rt::throw_exception<ArgumentNullException>("constructorArgs");
  }
  if (namedProperties == nullptr) {
    rt::throw_exception<ArgumentNullException>("namedProperties");
  }
  if (propertyValues == nullptr) {
    rt::throw_exception<ArgumentNullException>("propertyValues");
  }
  if (namedFields == nullptr) {
    rt::throw_exception<ArgumentNullException>("namedFields");
  }
  if (fieldValues == nullptr) {
    rt::throw_exception<ArgumentNullException>("fieldValues");
  }
  if (namedProperties->get_Length() != propertyValues->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayLengthsDiffer(), "namedProperties, propertyValues");
  }
  if (namedFields->get_Length() != fieldValues->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayLengthsDiffer(), "namedFields, fieldValues");
  }
}

Boolean CustomAttributeBuilder___::ValidateType(Type t) {
  if (t->get_IsPrimitive()) {
  }
}

void CustomAttributeBuilder___::VerifyTypeAndPassedObjectType(Type type, Type passedType, String paramName) {
}

void CustomAttributeBuilder___::EmitType(BinaryWriter writer, Type type) {
}

void CustomAttributeBuilder___::EmitString(BinaryWriter writer, String str) {
  Array<Byte> bytes = Encoding::in::get_UTF8()->GetBytes(str);
  UInt32 num = (UInt32)bytes->get_Length();
  if (num <= 127) {
    writer->Write((Byte)num);
  } else if (num <= 16383) {
  } else {
  }

  writer->Write(bytes);
}

void CustomAttributeBuilder___::EmitValue(BinaryWriter writer, Type type, Object value) {
  if (type->get_IsEnum()) {
    switch (Type::in::GetTypeCode(Enum::in::GetUnderlyingType(type))) {
      case TypeCode::SByte:
        writer->Write((SByte)value);
        break;
      case TypeCode::Byte:
        writer->Write((Byte)value);
        break;
      case TypeCode::Int16:
        writer->Write((Int16)value);
        break;
      case TypeCode::UInt16:
        writer->Write((UInt16)value);
        break;
      case TypeCode::Int32:
        writer->Write((Int32)value);
        break;
      case TypeCode::UInt32:
        writer->Write((UInt32)value);
        break;
      case TypeCode::Int64:
        writer->Write((Int64)value);
        break;
      case TypeCode::UInt64:
        writer->Write((UInt64)value);
        break;
    }
    return;
  }
}

void CustomAttributeBuilder___::CreateCustomAttribute(ModuleBuilder mod, Int32 tkOwner) {
  CreateCustomAttribute(mod, tkOwner, mod->GetConstructorToken(m_con).get_Token(), false);
}

void CustomAttributeBuilder___::CreateCustomAttribute(ModuleBuilder mod, Int32 tkOwner, Int32 tkAttrib, Boolean toDisk) {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::CustomAttributeBuilderNamespace
