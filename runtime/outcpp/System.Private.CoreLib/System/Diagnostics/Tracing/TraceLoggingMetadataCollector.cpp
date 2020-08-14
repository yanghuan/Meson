#include "TraceLoggingMetadataCollector-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FieldMetadata-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingMetadataCollector-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingMetadataCollectorNamespace {
using namespace System::Collections::Generic;

void TraceLoggingMetadataCollector___::Impl___::AddScalar(Int32 size) {
}

void TraceLoggingMetadataCollector___::Impl___::AddNonscalar() {
}

void TraceLoggingMetadataCollector___::Impl___::BeginBuffered() {
  if (bufferNesting == 0) {
    AddNonscalar();
  }
  bufferNesting++;
}

void TraceLoggingMetadataCollector___::Impl___::EndBuffered() {
  bufferNesting--;
}

Int32 TraceLoggingMetadataCollector___::Impl___::Encode(Array<Byte> metadata) {
  Int32 pos = 0;
}

void TraceLoggingMetadataCollector___::Impl___::ctor() {
  fields = rt::newobj<List<FieldMetadata>>();
}

Int32 TraceLoggingMetadataCollector___::get_ScratchSize() {
  return impl->scratchSize;
}

Int32 TraceLoggingMetadataCollector___::get_DataCount() {
  return impl->dataCount;
}

Int32 TraceLoggingMetadataCollector___::get_PinCount() {
  return impl->pinCount;
}

Boolean TraceLoggingMetadataCollector___::get_BeginningBufferedArray() {
  return bufferedArrayFieldCount == 0;
}

void TraceLoggingMetadataCollector___::ctor() {
  bufferedArrayFieldCount = Int32::MinValue;
}

void TraceLoggingMetadataCollector___::ctor(TraceLoggingMetadataCollector other, FieldMetadata group) {
  bufferedArrayFieldCount = Int32::MinValue;
}

TraceLoggingMetadataCollector TraceLoggingMetadataCollector___::AddGroup(String name) {
  TraceLoggingMetadataCollector result = (TraceLoggingMetadataCollector)this;
  if (name != nullptr || get_BeginningBufferedArray()) {
    FieldMetadata fieldMetadata = rt::newobj<FieldMetadata>(name, TraceLoggingDataType::Struct, Tags, get_BeginningBufferedArray());
    AddField(fieldMetadata);
    result = rt::newobj<TraceLoggingMetadataCollector>((TraceLoggingMetadataCollector)this, fieldMetadata);
  }
  return result;
}

void TraceLoggingMetadataCollector___::AddScalar(String name, TraceLoggingDataType type) {
  Int32 size;
  switch (type & (TraceLoggingDataType)31) {
    case TraceLoggingDataType::Int8:
    case TraceLoggingDataType::UInt8:
    case TraceLoggingDataType::Char8:
      size = 1;
      break;
    case TraceLoggingDataType::Int16:
    case TraceLoggingDataType::UInt16:
    case TraceLoggingDataType::Char16:
      size = 2;
      break;
    case TraceLoggingDataType::Int32:
    case TraceLoggingDataType::UInt32:
    case TraceLoggingDataType::Float:
    case TraceLoggingDataType::Boolean32:
    case TraceLoggingDataType::HexInt32:
      size = 4;
      break;
    case TraceLoggingDataType::Int64:
    case TraceLoggingDataType::UInt64:
    case TraceLoggingDataType::Double:
    case TraceLoggingDataType::FileTime:
    case TraceLoggingDataType::HexInt64:
      size = 8;
      break;
    case TraceLoggingDataType::Guid:
    case TraceLoggingDataType::SystemTime:
      size = 16;
      break;
    default:
      rt::throw_exception<ArgumentOutOfRangeException>("type");
  }
  impl->AddScalar(size);
  AddField(rt::newobj<FieldMetadata>(name, type, Tags, get_BeginningBufferedArray()));
}

void TraceLoggingMetadataCollector___::AddNullTerminatedString(String name, TraceLoggingDataType type) {
  TraceLoggingDataType traceLoggingDataType = type & (TraceLoggingDataType)31;
  if (traceLoggingDataType != TraceLoggingDataType::Utf16String) {
    rt::throw_exception<ArgumentOutOfRangeException>("type");
  }
  impl->AddNonscalar();
  AddField(rt::newobj<FieldMetadata>(name, type, Tags, get_BeginningBufferedArray()));
}

void TraceLoggingMetadataCollector___::AddArray(String name, TraceLoggingDataType type) {
  switch (type & (TraceLoggingDataType)31) {
    default:
      rt::throw_exception<ArgumentOutOfRangeException>("type");
    case TraceLoggingDataType::Int8:
    case TraceLoggingDataType::UInt8:
    case TraceLoggingDataType::Int16:
    case TraceLoggingDataType::UInt16:
    case TraceLoggingDataType::Int32:
    case TraceLoggingDataType::UInt32:
    case TraceLoggingDataType::Int64:
    case TraceLoggingDataType::UInt64:
    case TraceLoggingDataType::Float:
    case TraceLoggingDataType::Double:
    case TraceLoggingDataType::Boolean32:
    case TraceLoggingDataType::Guid:
    case TraceLoggingDataType::FileTime:
    case TraceLoggingDataType::HexInt32:
    case TraceLoggingDataType::HexInt64:
    case TraceLoggingDataType::Char8:
    case TraceLoggingDataType::Char16:
      if (get_BeginningBufferedArray()) {
        rt::throw_exception<NotSupportedException>(SR::get_EventSource_NotSupportedNestedArraysEnums());
      }
      impl->AddScalar(2);
      impl->AddNonscalar();
      AddField(rt::newobj<FieldMetadata>(name, type, Tags, true));
      break;
  }
}

void TraceLoggingMetadataCollector___::BeginBufferedArray() {
  if (bufferedArrayFieldCount >= 0) {
    rt::throw_exception<NotSupportedException>(SR::get_EventSource_NotSupportedNestedArraysEnums());
  }
  bufferedArrayFieldCount = 0;
  impl->BeginBuffered();
}

void TraceLoggingMetadataCollector___::EndBufferedArray() {
  if (bufferedArrayFieldCount != 1) {
    rt::throw_exception<InvalidOperationException>(SR::get_EventSource_IncorrentlyAuthoredTypeInfo());
  }
  bufferedArrayFieldCount = Int32::MinValue;
  impl->EndBuffered();
}

Array<Byte> TraceLoggingMetadataCollector___::GetMetadata() {
  Int32 num = impl->Encode(nullptr);
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  impl->Encode(array);
  return array;
}

void TraceLoggingMetadataCollector___::AddField(FieldMetadata fieldMetadata) {
  Tags = EventFieldTags::None;
  bufferedArrayFieldCount++;
  impl->fields->Add(fieldMetadata);
  if (currentGroup != nullptr) {
    currentGroup->IncrementStructFieldCount();
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingMetadataCollectorNamespace
