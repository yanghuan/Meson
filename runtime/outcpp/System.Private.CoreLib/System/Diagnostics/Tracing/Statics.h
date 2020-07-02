#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Boolean)
FORWARD(Type)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class TraceLoggingDataType;
enum class EventFieldFormat;
FORWARD(TraceLoggingTypeInfo)
namespace StaticsNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Reflection;
class Statics {
  public: static Array<Byte> MetadataForString(String name, Int32 prefixSize, Int32 suffixSize, Int32 additionalSize);
  public: static void EncodeTags(Int32 tags, Int32& pos, Array<Byte> metadata);
  public: static Byte Combine(Int32 settingValue, Byte defaultValue);
  public: static Int32 Combine(Int32 settingValue1, Int32 settingValue2);
  public: static void CheckName(String name);
  public: static Boolean ShouldOverrideFieldName(String fieldName);
  public: static TraceLoggingDataType MakeDataType(TraceLoggingDataType baseType, EventFieldFormat format);
  public: static TraceLoggingDataType Format8(EventFieldFormat format, TraceLoggingDataType native);
  public: static TraceLoggingDataType Format16(EventFieldFormat format, TraceLoggingDataType native);
  public: static TraceLoggingDataType Format32(EventFieldFormat format, TraceLoggingDataType native);
  public: static TraceLoggingDataType Format64(EventFieldFormat format, TraceLoggingDataType native);
  public: static TraceLoggingDataType FormatPtr(EventFieldFormat format, TraceLoggingDataType native);
  public: static Boolean IsValueType(Type type);
  public: static Boolean IsEnum(Type type);
  public: static IEnumerable<PropertyInfo> GetProperties(Type type);
  public: static MethodInfo GetGetMethod(PropertyInfo propInfo);
  public: static Boolean HasCustomAttribute(PropertyInfo propInfo, Type attributeType);
  public: static Array<Type> GetGenericArguments(Type type);
  public: static Type FindEnumerableElementType(Type type);
  public: static Boolean IsGenericMatch(Type type, Object openType);
  public: static TraceLoggingTypeInfo CreateDefaultTypeInfo(Type dataType, List<Type> recursionCheck);
  public: static TraceLoggingDataType IntPtrType;
  public: static TraceLoggingDataType UIntPtrType;
  public: static TraceLoggingDataType HexIntPtrType;
};
} // namespace StaticsNamespace
using Statics = StaticsNamespace::Statics;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
