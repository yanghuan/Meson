#include "CustomAttributeBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/BinaryWriter-dep.h>
#include <System.Private.CoreLib/System/IO/MemoryStream-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::CustomAttributeBuilderNamespace {
using namespace System::Buffers::Binary;
using namespace System::IO;
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
  if ((con->get_Attributes() & MethodAttributes::Static) == MethodAttributes::Static || (con->get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::Private) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadConstructor());
  }
  if ((con->get_CallingConvention() & CallingConventions::Standard) != CallingConventions::Standard) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadConstructorCallConv());
  }
  m_con = con;
  m_constructorArgs = rt::newarr<Array<Object>>(constructorArgs->get_Length());
  Array<>::in::Copy(constructorArgs, m_constructorArgs, constructorArgs->get_Length());
  Array<Type> parameterTypes = con->GetParameterTypes();
  if (parameterTypes->get_Length() != constructorArgs->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadParameterCountsForConstructor());
  }
  for (Int32 i = 0; i < parameterTypes->get_Length(); i++) {
    if (!ValidateType(parameterTypes[i])) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeInCustomAttribute());
    }
  }
  for (Int32 i = 0; i < parameterTypes->get_Length(); i++) {
    Object obj = constructorArgs[i];
    if (obj == nullptr) {
      if (parameterTypes[i]->get_IsValueType()) {
        rt::throw_exception<ArgumentNullException>(String::in::Format("{0}[{1}]", "constructorArgs", i));
      }
    } else {
      VerifyTypeAndPassedObjectType(parameterTypes[i], obj->GetType(), String::in::Format("{0}[{1}]", "constructorArgs", i));
    }
  }
  MemoryStream output = rt::newobj<MemoryStream>();
  BinaryWriter binaryWriter = rt::newobj<BinaryWriter>(output);
  binaryWriter->Write((?)1);
  for (Int32 i = 0; i < constructorArgs->get_Length(); i++) {
    EmitValue(binaryWriter, parameterTypes[i], constructorArgs[i]);
  }
  binaryWriter->Write((UInt16)(namedProperties->get_Length() + namedFields->get_Length()));
  for (Int32 i = 0; i < namedProperties->get_Length(); i++) {
    PropertyInfo propertyInfo = namedProperties[i];
    if (propertyInfo == nullptr) {
      rt::throw_exception<ArgumentNullException>("namedProperties[" + i + "]");
    }
    Type propertyType = propertyInfo->get_PropertyType();
    Object obj2 = propertyValues[i];
    if (obj2 == nullptr && propertyType->get_IsValueType()) {
      rt::throw_exception<ArgumentNullException>("propertyValues[" + i + "]");
    }
    if (!ValidateType(propertyType)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeInCustomAttribute());
    }
    if (!propertyInfo->get_CanWrite()) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_NotAWritableProperty());
    }
    if (propertyInfo->get_DeclaringType() != con->get_DeclaringType() && !rt::is<TypeBuilderInstantiation>(con->get_DeclaringType()) && !con->get_DeclaringType()->IsSubclassOf(propertyInfo->get_DeclaringType()) && !TypeBuilder::in::IsTypeEqual(propertyInfo->get_DeclaringType(), con->get_DeclaringType()) && (!rt::is<TypeBuilder>(propertyInfo->get_DeclaringType()) || !con->get_DeclaringType()->IsSubclassOf(((TypeBuilder)propertyInfo->get_DeclaringType())->get_BakedRuntimeType()))) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadPropertyForConstructorBuilder());
    }
    if (obj2 != nullptr) {
      VerifyTypeAndPassedObjectType(propertyType, obj2->GetType(), String::in::Format("{0}[{1}]", "propertyValues", i));
    }
    binaryWriter->Write((?)84);
    EmitType(binaryWriter, propertyType);
    EmitString(binaryWriter, namedProperties[i]->get_Name());
    EmitValue(binaryWriter, propertyType, obj2);
  }
  for (Int32 i = 0; i < namedFields->get_Length(); i++) {
    FieldInfo fieldInfo = namedFields[i];
    if (fieldInfo == nullptr) {
      rt::throw_exception<ArgumentNullException>("namedFields[" + i + "]");
    }
    Type fieldType = fieldInfo->get_FieldType();
    Object obj3 = fieldValues[i];
    if (obj3 == nullptr && fieldType->get_IsValueType()) {
      rt::throw_exception<ArgumentNullException>("fieldValues[" + i + "]");
    }
    if (!ValidateType(fieldType)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadTypeInCustomAttribute());
    }
    if (fieldInfo->get_DeclaringType() != con->get_DeclaringType() && !rt::is<TypeBuilderInstantiation>(con->get_DeclaringType()) && !con->get_DeclaringType()->IsSubclassOf(fieldInfo->get_DeclaringType()) && !TypeBuilder::in::IsTypeEqual(fieldInfo->get_DeclaringType(), con->get_DeclaringType()) && (!rt::is<TypeBuilder>(fieldInfo->get_DeclaringType()) || !con->get_DeclaringType()->IsSubclassOf(((TypeBuilder)namedFields[i]->get_DeclaringType())->get_BakedRuntimeType()))) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadFieldForConstructorBuilder());
    }
    if (obj3 != nullptr) {
      VerifyTypeAndPassedObjectType(fieldType, obj3->GetType(), String::in::Format("{0}[{1}]", "fieldValues", i));
    }
    binaryWriter->Write((?)83);
    EmitType(binaryWriter, fieldType);
    EmitString(binaryWriter, fieldInfo->get_Name());
    EmitValue(binaryWriter, fieldType, obj3);
  }
  m_blob = ((MemoryStream)binaryWriter->get_BaseStream())->ToArray();
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
    writer->Write(BinaryPrimitives::ReverseEndianness((Int16)(num | 32768)));
  } else {
    writer->Write(BinaryPrimitives::ReverseEndianness(num | 3221225472u));
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
