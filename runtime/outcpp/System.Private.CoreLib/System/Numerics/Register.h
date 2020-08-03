#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/SByte.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Numerics {
namespace RegisterNamespace {
struct Register : public valueType<Register> {
  public: Byte byte_0;
  public: Byte byte_1;
  public: Byte byte_2;
  public: Byte byte_3;
  public: Byte byte_4;
  public: Byte byte_5;
  public: Byte byte_6;
  public: Byte byte_7;
  public: Byte byte_8;
  public: Byte byte_9;
  public: Byte byte_10;
  public: Byte byte_11;
  public: Byte byte_12;
  public: Byte byte_13;
  public: Byte byte_14;
  public: Byte byte_15;
  public: SByte sbyte_0;
  public: SByte sbyte_1;
  public: SByte sbyte_2;
  public: SByte sbyte_3;
  public: SByte sbyte_4;
  public: SByte sbyte_5;
  public: SByte sbyte_6;
  public: SByte sbyte_7;
  public: SByte sbyte_8;
  public: SByte sbyte_9;
  public: SByte sbyte_10;
  public: SByte sbyte_11;
  public: SByte sbyte_12;
  public: SByte sbyte_13;
  public: SByte sbyte_14;
  public: SByte sbyte_15;
  public: UInt16 uint16_0;
  public: UInt16 uint16_1;
  public: UInt16 uint16_2;
  public: UInt16 uint16_3;
  public: UInt16 uint16_4;
  public: UInt16 uint16_5;
  public: UInt16 uint16_6;
  public: UInt16 uint16_7;
  public: Int16 int16_0;
  public: Int16 int16_1;
  public: Int16 int16_2;
  public: Int16 int16_3;
  public: Int16 int16_4;
  public: Int16 int16_5;
  public: Int16 int16_6;
  public: Int16 int16_7;
  public: UInt32 uint32_0;
  public: UInt32 uint32_1;
  public: UInt32 uint32_2;
  public: UInt32 uint32_3;
  public: Int32 int32_0;
  public: Int32 int32_1;
  public: Int32 int32_2;
  public: Int32 int32_3;
  public: UInt64 uint64_0;
  public: UInt64 uint64_1;
  public: Int64 int64_0;
  public: Int64 int64_1;
  public: Single single_0;
  public: Single single_1;
  public: Single single_2;
  public: Single single_3;
  public: Double double_0;
  public: Double double_1;
};
} // namespace RegisterNamespace
using Register = RegisterNamespace::Register;
} // namespace System::Private::CoreLib::System::Numerics
