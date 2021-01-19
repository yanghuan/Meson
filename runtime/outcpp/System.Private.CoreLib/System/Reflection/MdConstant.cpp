#include "MdConstant-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

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
  if (runtimeType == typeof<DateTime>()) {
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
}

} // namespace System::Private::CoreLib::System::Reflection::MdConstantNamespace
