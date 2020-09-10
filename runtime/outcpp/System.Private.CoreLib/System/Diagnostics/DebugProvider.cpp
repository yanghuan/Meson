#include "DebugProvider-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debug-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debugger-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/DebugProvider-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Diagnostics::DebugProviderNamespace {
void DebugProvider___::DebugAssertException___::ctor(String message, String detailMessage, String stackTrace) {
}

String DebugProvider___::DebugAssertException___::Terminate(String s) {
  if (s == nullptr) {
    return s;
  }
  s = s->Trim();
  if (s->get_Length() > 0) {
    s += "\r\n";
  }
  return s;
}

void DebugProvider___::Fail(String message, String detailMessage) {
  String stackTrace;
  try {
    stackTrace = rt::newobj<StackTrace>(0, true)->ToString(StackTrace::in::TraceFormat::Normal);
  } catch (...) {
    stackTrace = "";
  }
  WriteAssert(stackTrace, message, detailMessage);
  FailCore(stackTrace, message, detailMessage, "Assertion failed.");
}

void DebugProvider___::WriteAssert(String stackTrace, String message, String detailMessage) {
  WriteLine(SR::get_DebugAssertBanner() + "\r\n" + SR::get_DebugAssertShortMessage() + "\r\n" + message + "\r\n" + SR::get_DebugAssertLongMessage() + "\r\n" + detailMessage + "\r\n" + stackTrace);
}

void DebugProvider___::Write(String message) {
  {
    rt::lock(s_lock);
    if (message == nullptr) {
      WriteCore(String::in::Empty);
      return;
    }
    if (_needIndent) {
      message = GetIndentString() + message;
      _needIndent = false;
    }
    WriteCore(message);
    if (message->EndsWith("\r\n", StringComparison::Ordinal)) {
      _needIndent = true;
    }
  }
}

void DebugProvider___::WriteLine(String message) {
  Write(message + "\r\n");
}

void DebugProvider___::OnIndentLevelChanged(Int32 indentLevel) {
}

void DebugProvider___::OnIndentSizeChanged(Int32 indentSize) {
}

String DebugProvider___::GetIndentString() {
  Int32 num = Debug::get_IndentSize() * Debug::get_IndentLevel();
  String indentString = _indentString;
  if (indentString != nullptr && indentString->get_Length() == num) {
    return _indentString;
  }
  return _indentString = rt::newstr<String>(' ', num);
}

void DebugProvider___::FailCore(String stackTrace, String message, String detailMessage, String errorSource) {
  if (s_FailCore != nullptr) {
    s_FailCore(stackTrace, message, detailMessage, errorSource);
    return;
  }
  if (Debugger::get_IsAttached()) {
    Debugger::Break();
    return;
  }
  DebugAssertException ex = rt::newobj<DebugAssertException>(message, detailMessage, stackTrace);
  Environment::FailFast(ex->get_Message(), ex, errorSource);
}

void DebugProvider___::WriteCore(String message) {
  if (s_WriteCore != nullptr) {
    s_WriteCore(message);
    return;
  }
  {
    rt::lock(s_ForLock);
    if (message->get_Length() <= 4091) {
      WriteToDebugger(message);
      return;
    }
    Int32 i;
    for (i = 0; i < message->get_Length() - 4091; i += 4091) {
      WriteToDebugger(message->Substring(i, 4091));
    }
    WriteToDebugger(message->Substring(i));
  }
}

void DebugProvider___::WriteToDebugger(String message) {
  if (Debugger::IsLogging()) {
    Debugger::Log(0, nullptr, message);
  } else {
    String as = message;
    Interop::Kernel32::OutputDebugString(as != nullptr ? as : String::in::Empty);
  }
}

void DebugProvider___::ctor() {
  _needIndent = true;
  Object::in::ctor();
}

void DebugProvider___::cctor() {
  s_lock = rt::newobj<Object>();
  s_ForLock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebugProviderNamespace
