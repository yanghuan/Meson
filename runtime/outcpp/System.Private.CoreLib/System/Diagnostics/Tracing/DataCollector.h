#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARDS(GCHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace DataCollectorNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
struct DataCollector {
  public: void Enable(Byte* scratch, Int32 scratchSize, EventSource::in::EventData* datas, Int32 dataCount, GCHandle* pins, Int32 pinCount);
  public: void Disable();
  public: EventSource::in::EventData* Finish();
  public: void AddScalar(void* value, Int32 size);
  public: void AddNullTerminatedString(String value);
  public: void AddArray(Array<> value, Int32 length, Int32 itemSize);
  public: Int32 BeginBufferedArray();
  public: void EndBufferedArray(Int32 bookmark, Int32 count);
  public: void BeginBuffered();
  public: void EndBuffered();
  private: void EnsureBuffer();
  private: void EnsureBuffer(Int32 additionalSize);
  private: void GrowBuffer(Int32 required);
  private: void PinArray(Object value, Int32 size);
  private: void ScalarsBegin();
  private: void ScalarsEnd();
  public: static DataCollector ThreadInstance;
  private: Byte* scratchEnd;
  private: EventSource::in::EventData* datasEnd;
  private: GCHandle* pinsEnd;
  private: EventSource::in::EventData* datasStart;
  private: Byte* scratch;
  private: EventSource::in::EventData* datas;
  private: GCHandle* pins;
  private: Array<Byte> buffer;
  private: Int32 bufferPos;
  private: Int32 bufferNesting;
  private: Boolean writingScalars;
};
} // namespace DataCollectorNamespace
using DataCollector = DataCollectorNamespace::DataCollector;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
