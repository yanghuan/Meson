#include "Debug-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace {
using namespace System::Threading;

Boolean Debug::get_AutoFlush() {
  return true;
}

void Debug::set_AutoFlush(Boolean value) {
}

Int32 Debug::get_IndentLevel() {
  return t_indentLevel;
}

void Debug::set_IndentLevel(Int32 value) {
  t_indentLevel = ((value >= 0) ? value : 0);
  s_provider->OnIndentLevelChanged(t_indentLevel);
}

Int32 Debug::get_IndentSize() {
  return s_indentSize;
}

void Debug::set_IndentSize(Int32 value) {
  s_indentSize = ((value >= 0) ? value : 0);
  s_provider->OnIndentSizeChanged(s_indentSize);
}

DebugProvider Debug::SetProvider(DebugProvider provider) {
  if (provider == nullptr) {
    rt::throw_exception<ArgumentNullException>("provider");
  }
  return Interlocked::Exchange(s_provider, provider);
}

void Debug::Close() {
}

void Debug::Flush() {
}

void Debug::Indent() {
  get_IndentLevel()++;
}

void Debug::Unindent() {
  get_IndentLevel()--;
}

void Debug::Print(String message) {
  WriteLine(message);
}

void Debug::Print(String format, Array<Object> args) {
  WriteLine(String::in::Format(nullptr, format, rt::newarr<Array<Object>>(1, args)));
}

void Debug::Assert(Boolean condition) {
  Assert(condition, String::in::Empty, String::in::Empty);
}

void Debug::Assert(Boolean condition, String message) {
  Assert(condition, message, String::in::Empty);
}

void Debug::Assert(Boolean condition, String message, String detailMessage) {
  if (!condition) {
    Fail(message, detailMessage);
  }
}

void Debug::ContractFailure(String message, String detailMessage, String failureKindMessage) {
  String stackTrace;
  try{
    stackTrace = rt::newobj<StackTrace>(2, true)->ToString(StackTrace::in::TraceFormat::Normal);
  } catch (...) {
  }
  s_provider->WriteAssert(stackTrace, message, detailMessage);
  DebugProvider::in::FailCore(stackTrace, message, detailMessage, failureKindMessage);
}

void Debug::Fail(String message) {
  Fail(message, String::in::Empty);
}

void Debug::Fail(String message, String detailMessage) {
  s_provider->Fail(message, detailMessage);
}

void Debug::Assert(Boolean condition, String message, String detailMessageFormat, Array<Object> args) {
  Assert(condition, message, String::in::Format(detailMessageFormat, rt::newarr<Array<Object>>(1, args)));
}

void Debug::WriteLine(String message) {
  s_provider->WriteLine(message);
}

void Debug::Write(String message) {
  s_provider->Write(message);
}

void Debug::WriteLine(Object value) {
}

void Debug::WriteLine(Object value, String category) {
}

void Debug::WriteLine(String format, Array<Object> args) {
  WriteLine(String::in::Format(nullptr, format, rt::newarr<Array<Object>>(1, args)));
}

void Debug::WriteLine(String message, String category) {
  if (category == nullptr) {
    WriteLine(message);
  } else {
    WriteLine(category + ": " + message);
  }
}

void Debug::Write(Object value) {
}

void Debug::Write(String message, String category) {
  if (category == nullptr) {
    Write(message);
  } else {
    Write(category + ": " + message);
  }
}

void Debug::Write(Object value, String category) {
}

void Debug::WriteIf(Boolean condition, String message) {
  if (condition) {
    Write(message);
  }
}

void Debug::WriteIf(Boolean condition, Object value) {
  if (condition) {
    Write(value);
  }
}

void Debug::WriteIf(Boolean condition, String message, String category) {
  if (condition) {
    Write(message, category);
  }
}

void Debug::WriteIf(Boolean condition, Object value, String category) {
  if (condition) {
    Write(value, category);
  }
}

void Debug::WriteLineIf(Boolean condition, Object value) {
  if (condition) {
    WriteLine(value);
  }
}

void Debug::WriteLineIf(Boolean condition, Object value, String category) {
  if (condition) {
    WriteLine(value, category);
  }
}

void Debug::WriteLineIf(Boolean condition, String message) {
  if (condition) {
    WriteLine(message);
  }
}

void Debug::WriteLineIf(Boolean condition, String message, String category) {
  if (condition) {
    WriteLine(message, category);
  }
}

void Debug::cctor() {
  s_provider = rt::newobj<DebugProvider>();
  s_indentSize = 4;
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace
