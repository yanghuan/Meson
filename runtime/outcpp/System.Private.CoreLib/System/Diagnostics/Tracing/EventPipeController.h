#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(EventPipeProviderConfiguration)
FORWARD(EventPipeConfiguration)
namespace EventPipeControllerNamespace {
class EventPipeController {
  private: static Array<EventPipeProviderConfiguration> get_DefaultProviderConfiguration();
  private: static Int32 get_Config_EnableEventPipe();
  private: static Int32 get_Config_NetTraceFormat();
  private: static String get_Config_EventPipeConfig();
  private: static UInt32 get_Config_EventPipeCircularMB();
  private: static String get_Config_EventPipeOutputPath();
  public: static void Initialize();
  private: static EventPipeConfiguration BuildConfigFromEnvironment();
  private: static String BuildTraceFileName();
  private: static String GetAppName();
  private: static void SetProviderConfiguration(String strConfig, EventPipeConfiguration config);
  private: static String DefaultAppName;
  private: static String NetPerfFileExtension;
  private: static String NetTraceFileExtension;
  private: static UInt32 DefaultCircularBufferMB;
  private: static Char ProviderConfigDelimiter;
  private: static Char ConfigComponentDelimiter;
};
} // namespace EventPipeControllerNamespace
using EventPipeController = EventPipeControllerNamespace::EventPipeController;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
