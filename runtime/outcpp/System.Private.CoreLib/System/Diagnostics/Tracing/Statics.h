#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
enum class TraceLoggingDataType : int32_t;
FORWARD(TraceLoggingTypeInfo)
namespace StaticsNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
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
  public: static Boolean HasCustomAttribute(PropertyInfo propInfo, Type attributeType);
  public: template <class AttributeType>
  static AttributeType GetCustomAttribute(PropertyInfo propInfo);
  public: template <class AttributeType>
  static AttributeType GetCustomAttribute(Type type);
  public: static Type FindEnumerableElementType(Type type);
  public: static Boolean IsGenericMatch(Type type, Object openType);
  public: static TraceLoggingTypeInfo CreateDefaultTypeInfo(Type dataType, List<Type> recursionCheck);
  public: static void cctor();
  public: static TraceLoggingDataType IntPtrType;
  public: static TraceLoggingDataType UIntPtrType;
  public: static TraceLoggingDataType HexIntPtrType;
};
} // namespace StaticsNamespace
using Statics = StaticsNamespace::Statics;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
