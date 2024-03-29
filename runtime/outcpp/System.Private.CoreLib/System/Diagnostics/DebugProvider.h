#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Exception.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebugProviderNamespace {
CLASS(DebugProvider) : public object {
  private: CLASS(DebugAssertException) : public Exception::in {
    public: void ctor(String message, String detailMessage, String stackTrace);
    private: static String Terminate(String s);
  };
  public: void Fail(String message, String detailMessage);
  public: void WriteAssert(String stackTrace, String message, String detailMessage);
  public: void Write(String message);
  public: void WriteLine(String message);
  public: void OnIndentLevelChanged(Int32 indentLevel);
  public: void OnIndentSizeChanged(Int32 indentSize);
  private: String GetIndentString();
  public: static void FailCore(String stackTrace, String message, String detailMessage, String errorSource);
  public: static void WriteCore(String message);
  private: static void WriteToDebugger(String message);
  public: void ctor();
  public: static void cctor();
  private: static Object s_lock;
  private: Boolean _needIndent;
  private: String _indentString;
  public: static Action<String, String, String, String> s_FailCore;
  public: static Action<String> s_WriteCore;
  private: static Object s_ForLock;
};
} // namespace DebugProviderNamespace
using DebugProvider = DebugProviderNamespace::DebugProvider;
} // namespace System::Private::CoreLib::System::Diagnostics
