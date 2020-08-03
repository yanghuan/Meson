#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Decimal.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/SByte.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class VarEnum;
namespace VariantNamespace {
struct Variant : public valueType<Variant> {
  private: struct Record : public valueType<Record> {
    public: IntPtr _record;
    public: IntPtr _recordInfo;
  };
  private: struct UnionTypes : public valueType<UnionTypes> {
    public: SByte _i1;
    public: Int16 _i2;
    public: Int32 _i4;
    public: Int64 _i8;
    public: Byte _ui1;
    public: UInt16 _ui2;
    public: UInt32 _ui4;
    public: UInt64 _ui8;
    public: Int32 _int;
    public: UInt32 _uint;
    public: Int16 _bool;
    public: Int32 _error;
    public: Single _r4;
    public: Double _r8;
    public: Int64 _cy;
    public: Double _date;
    public: IntPtr _bstr;
    public: IntPtr _unknown;
    public: IntPtr _dispatch;
    public: IntPtr _pvarVal;
    public: IntPtr _byref;
    public: Record _record;
  };
  private: struct TypeUnion : public valueType<TypeUnion> {
    public: UInt16 _vt;
    public: UInt16 _wReserved1;
    public: UInt16 _wReserved2;
    public: UInt16 _wReserved3;
    public: UnionTypes _unionTypes;
  };
  public: VarEnum get_VariantType();
  public: void set_VariantType(VarEnum value);
  public: Boolean get_IsEmpty();
  public: Boolean get_IsByRef();
  public: SByte get_AsI1();
  public: Int16 get_AsI2();
  public: Int32 get_AsI4();
  public: Int64 get_AsI8();
  public: Byte get_AsUi1();
  public: UInt16 get_AsUi2();
  public: UInt32 get_AsUi4();
  public: UInt64 get_AsUi8();
  public: Int32 get_AsInt();
  public: UInt32 get_AsUint();
  public: Boolean get_AsBool();
  public: Int32 get_AsError();
  public: Single get_AsR4();
  public: Double get_AsR8();
  public: Decimal get_AsDecimal();
  public: Decimal get_AsCy();
  public: DateTime get_AsDate();
  public: String get_AsBstr();
  public: Object get_AsUnknown();
  public: Object get_AsDispatch();
  public: IntPtr get_AsByRefVariant();
  public: void CopyFromIndirect(Object value);
  public: Object ToObject();
  public: void Clear();
  private: TypeUnion _typeUnion;
  private: Decimal _decimal;
};
} // namespace VariantNamespace
using Variant = VariantNamespace::Variant;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
