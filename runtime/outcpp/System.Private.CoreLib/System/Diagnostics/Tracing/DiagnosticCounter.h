#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARDS(Int32)
FORWARDS(Single)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterGroup)
FORWARD(EventSource)
namespace DiagnosticCounterNamespace {
using namespace Collections::Generic;
CLASS(DiagnosticCounter) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: String get_DisplayName();
  public: void set_DisplayName(String value);
  public: String get_DisplayUnits();
  public: void set_DisplayUnits(String value);
  public: String get_Name() { return Name; }
  public: EventSource get_EventSource() { return EventSource; }
  public: void ctor(String name, EventSource eventSource);
  public: void Publish();
  public: void Dispose();
  public: void AddMetadata(String key, String value);
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  public: void ReportOutOfBandMessage(String message);
  public: String GetMetadataString();
  private: String _displayName;
  private: String _displayUnits;
  private: String Name;
  private: EventSource EventSource;
  private: CounterGroup _group;
  private: Dictionary<String, String> _metadata;
};
} // namespace DiagnosticCounterNamespace
using DiagnosticCounter = DiagnosticCounterNamespace::DiagnosticCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
