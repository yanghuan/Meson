#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/SByte.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(FieldMetadata)
enum class TraceLoggingDataType;
namespace TraceLoggingMetadataCollectorNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(TraceLoggingMetadataCollector) {
  private: CLASS(Impl) {
    public: void AddScalar(Int32 size);
    public: void AddNonscalar();
    public: void BeginBuffered();
    public: void EndBuffered();
    public: Int32 Encode(Array<Byte> metadata);
    public: List<FieldMetadata> fields;
    public: Int16 scratchSize;
    public: SByte dataCount;
    public: SByte pinCount;
    private: Int32 bufferNesting;
    private: Boolean scalar;
  };
  public: Int32 get_ScratchSize();
  public: Int32 get_DataCount();
  public: Int32 get_PinCount();
  private: Boolean get_BeginningBufferedArray();
  public: TraceLoggingMetadataCollector AddGroup(String name);
  public: void AddScalar(String name, TraceLoggingDataType type);
  public: void AddNullTerminatedString(String name, TraceLoggingDataType type);
  public: void AddArray(String name, TraceLoggingDataType type);
  public: void BeginBufferedArray();
  public: void EndBufferedArray();
  public: Array<Byte> GetMetadata();
  private: void AddField(FieldMetadata fieldMetadata);
  private: Impl impl;
  private: FieldMetadata currentGroup;
  private: Int32 bufferedArrayFieldCount;
};
} // namespace TraceLoggingMetadataCollectorNamespace
using TraceLoggingMetadataCollector = TraceLoggingMetadataCollectorNamespace::TraceLoggingMetadataCollector;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
