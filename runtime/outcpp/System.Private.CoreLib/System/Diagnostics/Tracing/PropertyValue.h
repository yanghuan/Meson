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
FORWARD_(Func)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace PropertyValueNamespace {
using namespace System::Reflection;
struct PropertyValue : public valueType<PropertyValue> {
  private: CLASS(TypeHelper) : public object {
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
    protected: Delegate GetGetMethod(PropertyInfo property, Type propertyType);
    public: void ctor();
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
    private: CLASS(__c__DisplayClass0_0) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__0(PropertyValue container);
      public: PropertyInfo property;
    };
    private: CLASS(__c__DisplayClass0_1) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__1(PropertyValue container);
      public: Func<TContainer, Object> getter;
    };
    private: CLASS(__c__DisplayClass0_2) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__2(PropertyValue container);
      public: Func<TContainer, Boolean> f;
    };
    private: CLASS(__c__DisplayClass0_3) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__3(PropertyValue container);
      public: Func<TContainer, Byte> f;
    };
    private: CLASS(__c__DisplayClass0_4) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__4(PropertyValue container);
      public: Func<TContainer, SByte> f;
    };
    private: CLASS(__c__DisplayClass0_5) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__5(PropertyValue container);
      public: Func<TContainer, Char> f;
    };
    private: CLASS(__c__DisplayClass0_6) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__6(PropertyValue container);
      public: Func<TContainer, Int16> f;
    };
    private: CLASS(__c__DisplayClass0_7) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__7(PropertyValue container);
      public: Func<TContainer, UInt16> f;
    };
    private: CLASS(__c__DisplayClass0_8) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__8(PropertyValue container);
      public: Func<TContainer, Int32> f;
    };
    private: CLASS(__c__DisplayClass0_9) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__9(PropertyValue container);
      public: Func<TContainer, UInt32> f;
    };
    private: CLASS(__c__DisplayClass0_10) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__10(PropertyValue container);
      public: Func<TContainer, Int64> f;
    };
    private: CLASS(__c__DisplayClass0_11) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__11(PropertyValue container);
      public: Func<TContainer, UInt64> f;
    };
    private: CLASS(__c__DisplayClass0_12) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__12(PropertyValue container);
      public: Func<TContainer, IntPtr> f;
    };
    private: CLASS(__c__DisplayClass0_13) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__13(PropertyValue container);
      public: Func<TContainer, UIntPtr> f;
    };
    private: CLASS(__c__DisplayClass0_14) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__14(PropertyValue container);
      public: Func<TContainer, Single> f;
    };
    private: CLASS(__c__DisplayClass0_15) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__15(PropertyValue container);
      public: Func<TContainer, Double> f;
    };
    private: CLASS(__c__DisplayClass0_16) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__16(PropertyValue container);
      public: Func<TContainer, Guid> f;
    };
    private: CLASS(__c__DisplayClass0_17) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__17(PropertyValue container);
      public: Func<TContainer, DateTime> f;
    };
    private: CLASS(__c__DisplayClass0_18) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__18(PropertyValue container);
      public: Func<TContainer, DateTimeOffset> f;
    };
    private: CLASS(__c__DisplayClass0_19) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__19(PropertyValue container);
      public: Func<TContainer, TimeSpan> f;
    };
    private: CLASS(__c__DisplayClass0_20) : public object {
      public: void ctor();
      public: PropertyValue _GetPropertyGetter_b__20(PropertyValue container);
      public: Func<TContainer, Decimal> f;
    };
    public: Func<PropertyValue, PropertyValue> GetPropertyGetter(PropertyInfo property);
    public: void ctor();
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: PropertyValue _GetFactory_b__25_0(Object value);
    public: PropertyValue _GetFactory_b__25_1(Object value);
    public: PropertyValue _GetFactory_b__25_2(Object value);
    public: PropertyValue _GetFactory_b__25_3(Object value);
    public: PropertyValue _GetFactory_b__25_4(Object value);
    public: PropertyValue _GetFactory_b__25_5(Object value);
    public: PropertyValue _GetFactory_b__25_6(Object value);
    public: PropertyValue _GetFactory_b__25_7(Object value);
    public: PropertyValue _GetFactory_b__25_8(Object value);
    public: PropertyValue _GetFactory_b__25_9(Object value);
    public: PropertyValue _GetFactory_b__25_10(Object value);
    public: PropertyValue _GetFactory_b__25_11(Object value);
    public: PropertyValue _GetFactory_b__25_12(Object value);
    public: PropertyValue _GetFactory_b__25_13(Object value);
    public: PropertyValue _GetFactory_b__25_14(Object value);
    public: PropertyValue _GetFactory_b__25_15(Object value);
    public: PropertyValue _GetFactory_b__25_16(Object value);
    public: PropertyValue _GetFactory_b__25_17(Object value);
    public: PropertyValue _GetFactory_b__25_18(Object value);
    public: PropertyValue _GetFactory_b__25_19(Object value);
    public: static __c __9;
    public: static Func<Object, PropertyValue> __9__25_0;
    public: static Func<Object, PropertyValue> __9__25_1;
    public: static Func<Object, PropertyValue> __9__25_2;
    public: static Func<Object, PropertyValue> __9__25_3;
    public: static Func<Object, PropertyValue> __9__25_4;
    public: static Func<Object, PropertyValue> __9__25_5;
    public: static Func<Object, PropertyValue> __9__25_6;
    public: static Func<Object, PropertyValue> __9__25_7;
    public: static Func<Object, PropertyValue> __9__25_8;
    public: static Func<Object, PropertyValue> __9__25_9;
    public: static Func<Object, PropertyValue> __9__25_10;
    public: static Func<Object, PropertyValue> __9__25_11;
    public: static Func<Object, PropertyValue> __9__25_12;
    public: static Func<Object, PropertyValue> __9__25_13;
    public: static Func<Object, PropertyValue> __9__25_14;
    public: static Func<Object, PropertyValue> __9__25_15;
    public: static Func<Object, PropertyValue> __9__25_16;
    public: static Func<Object, PropertyValue> __9__25_17;
    public: static Func<Object, PropertyValue> __9__25_18;
    public: static Func<Object, PropertyValue> __9__25_19;
  };
  private: CLASS(__c__DisplayClass33_0) : public object {
    public: void ctor();
    public: PropertyValue _GetBoxedValueTypePropertyGetter_b__0(PropertyValue container);
    public: Func<Object, PropertyValue> factory;
    public: PropertyInfo property;
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
