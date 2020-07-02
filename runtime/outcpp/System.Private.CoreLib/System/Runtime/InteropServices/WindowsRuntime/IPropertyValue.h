#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int16)
FORWARDS(UInt16)
FORWARDS(Int32)
FORWARDS(UInt32)
FORWARDS(Int64)
FORWARDS(UInt64)
FORWARDS(Single)
FORWARDS(Double)
FORWARDS(Char)
FORWARD(String)
FORWARDS(Guid)
FORWARDS(DateTimeOffset)
FORWARDS(TimeSpan)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
enum class PropertyType;
FORWARDS(Point)
FORWARDS(Size)
FORWARDS(Rect)
namespace IPropertyValueNamespace {
CLASS(IPropertyValue) {
  public: PropertyType get_Type();
  public: Boolean get_IsNumericScalar();
  public: Byte GetUInt8();
  public: Int16 GetInt16();
  public: UInt16 GetUInt16();
  public: Int32 GetInt32();
  public: UInt32 GetUInt32();
  public: Int64 GetInt64();
  public: UInt64 GetUInt64();
  public: Single GetSingle();
  public: Double GetDouble();
  public: Char GetChar16();
  public: Boolean GetBoolean();
  public: String GetString();
  public: Guid GetGuid();
  public: DateTimeOffset GetDateTime();
  public: TimeSpan GetTimeSpan();
  public: Point GetPoint();
  public: Size GetSize();
  public: Rect GetRect();
  public: Array<Byte> GetUInt8Array();
  public: Array<Int16> GetInt16Array();
  public: Array<UInt16> GetUInt16Array();
  public: Array<Int32> GetInt32Array();
  public: Array<UInt32> GetUInt32Array();
  public: Array<Int64> GetInt64Array();
  public: Array<UInt64> GetUInt64Array();
  public: Array<Single> GetSingleArray();
  public: Array<Double> GetDoubleArray();
  public: Array<Char> GetChar16Array();
  public: Array<Boolean> GetBooleanArray();
  public: Array<String> GetStringArray();
  public: Array<Object> GetInspectableArray();
  public: Array<Guid> GetGuidArray();
  public: Array<DateTimeOffset> GetDateTimeArray();
  public: Array<TimeSpan> GetTimeSpanArray();
  public: Array<Point> GetPointArray();
  public: Array<Size> GetSizeArray();
  public: Array<Rect> GetRectArray();
};
} // namespace IPropertyValueNamespace
using IPropertyValue = IPropertyValueNamespace::IPropertyValue;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
