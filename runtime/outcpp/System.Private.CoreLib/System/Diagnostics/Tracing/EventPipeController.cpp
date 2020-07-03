#include "EventPipeController-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeControllerNamespace {
Array<EventPipeProviderConfiguration> EventPipeController::get_DefaultProviderConfiguration() {
  return Array<EventPipeProviderConfiguration>();
};
Int32 EventPipeController::get_Config_EnableEventPipe() {
  return Int32();
};
Int32 EventPipeController::get_Config_NetTraceFormat() {
  return Int32();
};
String EventPipeController::get_Config_EventPipeConfig() {
  return nullptr;
};
UInt32 EventPipeController::get_Config_EventPipeCircularMB() {
  return UInt32();
};
String EventPipeController::get_Config_EventPipeOutputPath() {
  return nullptr;
};
void EventPipeController::Initialize() {
};
EventPipeConfiguration EventPipeController::BuildConfigFromEnvironment() {
  return nullptr;
};
String EventPipeController::BuildTraceFileName() {
  return nullptr;
};
String EventPipeController::GetAppName() {
  return nullptr;
};
void EventPipeController::SetProviderConfiguration(String strConfig, EventPipeConfiguration config) {
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeControllerNamespace
