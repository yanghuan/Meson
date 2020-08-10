#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/DateTimeOffset.h>
#include <System.Private.CoreLib/System/Decimal.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/SByte.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/TimeSpan.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/UIntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace PropertyValueNamespace {
using namespace Reflection;
struct PropertyValue : public valueType<PropertyValue> {
  private: CLASS(TypeHelper) : public Object::in {
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
    protected: Delegate GetGetMethod(PropertyInfo property, Type propertyType);
    protected: void ctor();
  };
  public: struct Scalar : public valueType<Scalar> {
    public: Boolean AsBoolean;
    public: Byte AsByte;
    public: SByte AsSByte;
    public: Char AsChar;
    public: Int16 AsInt16;
    public: UInt16 AsUInt16;
    public: Int32 AsInt32;
    public: UInt32 AsUInt32;
    public: Int64 AsInt64;
    public: UInt64 AsUInt64;
    public: IntPtr AsIntPtr;
    public: UIntPtr AsUIntPtr;
    public: Single AsSingle;
    public: Double AsDouble;
    public: Guid AsGuid;
    public: DateTime AsDateTime;
    public: DateTimeOffset AsDateTimeOffset;
    public: TimeSpan AsTimeSpan;
    public: Decimal AsDecimal;
  };
  private: CLASS(ReferenceTypeHelper, TContainer) : public TypeHelper::in {
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
    public: void ctor();
  };
  public: Object get_ReferenceValue();
  public: Scalar get_ScalarValue();
  public: Int32 get_ScalarLength();
  private: explicit PropertyValue(Object value);
  private: explicit PropertyValue(Scalar scalar, Int32 scalarLength);
  private: explicit PropertyValue(Boolean value);
  private: explicit PropertyValue(Byte value);
  private: explicit PropertyValue(SByte value);
  private: explicit PropertyValue(Char value);
  private: explicit PropertyValue(Int16 value);
  private: explicit PropertyValue(UInt16 value);
  private: explicit PropertyValue(Int32 value);
  private: explicit PropertyValue(UInt32 value);
  private: explicit PropertyValue(Int64 value);
  private: explicit PropertyValue(UInt64 value);
  private: explicit PropertyValue(IntPtr value);
  private: explicit PropertyValue(UIntPtr value);
  private: explicit PropertyValue(Single value);
  private: explicit PropertyValue(Double value);
  private: explicit PropertyValue(Guid value);
  private: explicit PropertyValue(DateTime value);
  private: explicit PropertyValue(DateTimeOffset value);
  private: explicit PropertyValue(TimeSpan value);
  private: explicit PropertyValue(Decimal value);
  public: static Func<Object, PropertyValue> GetFactory(Type type);
  public: static Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
  private: static Func<PropertyValue, PropertyValue> GetBoxedValueTypePropertyGetter(PropertyInfo property);
  private: static Func<PropertyValue, PropertyValue> GetReferenceTypePropertyGetter(PropertyInfo property);
  public: explicit PropertyValue() {}
  private: Object _reference;
  private: Scalar _scalar;
  private: Int32 _scalarLength;
};
} // namespace PropertyValueNamespace
using PropertyValue = PropertyValueNamespace::PropertyValue;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
