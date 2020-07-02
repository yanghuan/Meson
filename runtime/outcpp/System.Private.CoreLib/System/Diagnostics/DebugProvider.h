#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD(Object)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebugProviderNamespace {
CLASS(DebugProvider) {
  private: CLASS(DebugAssertException) {
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
