#include "StackTrace-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace {
Int32 StackTrace___::get_FrameCount() {
  return Int32();
};

Int32 StackTrace___::CalculateFramesToSkip(StackFrameHelper StackF, Int32 iNumFrames) {
  return Int32();
};

void StackTrace___::InitializeForException(Exception exception, Int32 skipFrames, Boolean fNeedFileInfo) {
};

void StackTrace___::InitializeForCurrentThread(Int32 skipFrames, Boolean fNeedFileInfo) {
};

void StackTrace___::CaptureStackTrace(Int32 skipFrames, Boolean fNeedFileInfo, Exception e) {
};

void StackTrace___::Ctor() {
};

void StackTrace___::Ctor(Boolean fNeedFileInfo) {
};

void StackTrace___::Ctor(Int32 skipFrames) {
};

void StackTrace___::Ctor(Int32 skipFrames, Boolean fNeedFileInfo) {
};

void StackTrace___::Ctor(Exception e) {
};

void StackTrace___::Ctor(Exception e, Boolean fNeedFileInfo) {
};

void StackTrace___::Ctor(Exception e, Int32 skipFrames) {
};

void StackTrace___::Ctor(Exception e, Int32 skipFrames, Boolean fNeedFileInfo) {
};

void StackTrace___::Ctor(StackFrame frame) {
};

StackFrame StackTrace___::GetFrame(Int32 index) {
  return nullptr;
};

Array<StackFrame> StackTrace___::GetFrames() {
  return Array<StackFrame>();
};

String StackTrace___::ToString() {
  return nullptr;
};

String StackTrace___::ToString(TraceFormat traceFormat) {
  return nullptr;
};

void StackTrace___::ToString(TraceFormat traceFormat, StringBuilder sb) {
};

Boolean StackTrace___::ShowInStackTrace(MethodBase mb) {
  return Boolean();
};

Boolean StackTrace___::TryResolveStateMachineMethod(MethodBase& method, Type& declaringType) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace
