#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Single)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(CounterGroup)
namespace DiagnosticCounterNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(DiagnosticCounter) {
  public: String get_DisplayName();
  public: void set_DisplayName(String value);
  public: String get_DisplayUnits();
  public: void set_DisplayUnits(String value);
  public: void Dispose();
  public: void AddMetadata(String key, String value);
  public: void WritePayload(Single intervalSec, Int32 pollingIntervalMillisec);
  public: void ReportOutOfBandMessage(String message);
  public: String GetMetadataString();
  private: String _displayName;
  private: String _displayUnits;
  private: CounterGroup _group;
  private: Dictionary<String, String> _metadata;
};
} // namespace DiagnosticCounterNamespace
using DiagnosticCounter = DiagnosticCounterNamespace::DiagnosticCounter;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
