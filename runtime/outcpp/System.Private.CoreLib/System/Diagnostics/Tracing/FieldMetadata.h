#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt16.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldTags : int32_t;
enum class TraceLoggingDataType : int32_t;
namespace FieldMetadataNamespace {
CLASS(FieldMetadata) : public object {
  public: void ctor(String name, TraceLoggingDataType type, EventFieldTags tags, Boolean variableCount);
  private: void ctor(String name, TraceLoggingDataType dataType, EventFieldTags tags, Byte countFlags, UInt16 fixedCount = 0, Array<Byte> custom = nullptr);
  public: void IncrementStructFieldCount();
  public: void Encode(Int32& pos, Array<Byte> metadata);
  private: String name;
  private: Int32 nameSize;
  private: EventFieldTags tags;
  private: Array<Byte> custom;
  private: UInt16 fixedCount;
  private: Byte inType;
  private: Byte outType;
};
} // namespace FieldMetadataNamespace
using FieldMetadata = FieldMetadataNamespace::FieldMetadata;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
