#pragma once

#include <rt/GCObject.h>
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
#include <System.Private.CoreLib/System/SByte.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/TimeSpan.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace PropertyValueNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
struct PropertyValue {
  public: struct Scalar {
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
  private: CLASS(TypeHelper) {
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
    protected: Delegate GetGetMethod(PropertyInfo property, Type propertyType);
  };
  private: CLASS(ReferenceTypeHelper, TContainer) {
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
  };
  public: Object get_ReferenceValue();
  public: Scalar get_ScalarValue();
  public: Int32 get_ScalarLength();
  public: static Func<Object, PropertyValue> GetFactory(Type type);
  public: static Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
  private: static Func<PropertyValue, PropertyValue> GetBoxedValueTypePropertyGetter(PropertyInfo property);
  private: static Func<PropertyValue, PropertyValue> GetReferenceTypePropertyGetter(PropertyInfo property);
  private: Object _reference;
  private: Scalar _scalar;
  private: Int32 _scalarLength;
};
} // namespace PropertyValueNamespace
using PropertyValue = PropertyValueNamespace::PropertyValue;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
