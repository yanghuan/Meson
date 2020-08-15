#include "MdConstant-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Reflection::MdConstantNamespace {
Object MdConstant::GetValue(MetadataImport scope, Int32 token, RuntimeTypeHandle fieldTypeHandle, Boolean raw) {
  Int64 value;
  Int32 length;
  CorElementType corElementType;
  String defaultValue = scope.GetDefaultValue(token, value, length, corElementType);
  RuntimeType runtimeType = fieldTypeHandle.GetRuntimeType();
  if (runtimeType->get_IsEnum() && !raw) {
    Int64 num = 0;
    switch (corElementType) {
      case CorElementType::ELEMENT_TYPE_VOID:
        return DBNull::in::Value;
      case CorElementType::ELEMENT_TYPE_CHAR:
        num = *(UInt16*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_I1:
        num = *(SByte*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_U1:
        num = *(Byte*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_I2:
        num = *(Int16*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_U2:
        num = *(UInt16*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_I4:
        num = *(Int32*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_U4:
        num = *(UInt32*)(&value);
        break;
      case CorElementType::ELEMENT_TYPE_I8:
        num = value;
        break;
      case CorElementType::ELEMENT_TYPE_U8:
        num = value;
        break;
      case CorElementType::ELEMENT_TYPE_CLASS:
        return nullptr;
      default:
        rt::throw_exception<FormatException>(SR::get_Arg_BadLiteralFormat());
    }
    return RuntimeType::in::CreateEnum(runtimeType, num);
  }
  if (runtimeType == rt::typeof<DateTime>()) {
    Int64 num2 = 0;
    switch (corElementType) {
      case CorElementType::ELEMENT_TYPE_VOID:
        return DBNull::in::Value;
      case CorElementType::ELEMENT_TYPE_I8:
        num2 = value;
        break;
      case CorElementType::ELEMENT_TYPE_U8:
        num2 = value;
        break;
      case CorElementType::ELEMENT_TYPE_CLASS:
        return nullptr;
      default:
        rt::throw_exception<FormatException>(SR::get_Arg_BadLiteralFormat());
    }
    return DateTime(num2);
  }
  auto& default = defaultValue;
  switch (corElementType) {
    case CorElementType::ELEMENT_TYPE_VOID:
      return DBNull::in::Value;
    case CorElementType::ELEMENT_TYPE_CHAR:
      return (Char)(*(UInt16*)(&value));
    case CorElementType::ELEMENT_TYPE_I1:
      return *(SByte*)(&value);
    case CorElementType::ELEMENT_TYPE_U1:
      return *(Byte*)(&value);
    case CorElementType::ELEMENT_TYPE_I2:
      return *(Int16*)(&value);
    case CorElementType::ELEMENT_TYPE_U2:
      return *(UInt16*)(&value);
    case CorElementType::ELEMENT_TYPE_I4:
      return *(Int32*)(&value);
    case CorElementType::ELEMENT_TYPE_U4:
      return *(UInt32*)(&value);
    case CorElementType::ELEMENT_TYPE_I8:
      return value;
    case CorElementType::ELEMENT_TYPE_U8:
      return (UInt64)value;
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return *(Int32*)(&value) != 0;
    case CorElementType::ELEMENT_TYPE_R4:
      return *(Single*)(&value);
    case CorElementType::ELEMENT_TYPE_R8:
      return *(Double*)(&value);
    case CorElementType::ELEMENT_TYPE_STRING:
      return default != nullptr ? default : String::in::Empty;
    case CorElementType::ELEMENT_TYPE_CLASS:
      return nullptr;
    default:
      rt::throw_exception<FormatException>(SR::get_Arg_BadLiteralFormat());
  }
}

} // namespace System::Private::CoreLib::System::Reflection::MdConstantNamespace
