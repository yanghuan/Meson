#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
FORWARD(DebugProvider)
namespace DebugNamespace {
class Debug {
  public: static Boolean get_AutoFlush();
  public: static void set_AutoFlush(Boolean value);
  public: static Int32 get_IndentLevel();
  public: static void set_IndentLevel(Int32 value);
  public: static Int32 get_IndentSize();
  public: static void set_IndentSize(Int32 value);
  public: static DebugProvider SetProvider(DebugProvider provider);
  public: static void Close();
  public: static void Flush();
  public: static void Indent();
  public: static void Unindent();
  public: static void Print(String message);
  public: static void Print(String format, Array<Object> args);
  public: static void Assert(Boolean condition);
  public: static void Assert(Boolean condition, String message);
  public: static void Assert(Boolean condition, String message, String detailMessage);
  public: static void ContractFailure(String message, String detailMessage, String failureKindMessage);
  public: static void Fail(String message);
  public: static void Fail(String message, String detailMessage);
  public: static void Assert(Boolean condition, String message, String detailMessageFormat, Array<Object> args);
  public: static void WriteLine(String message);
  public: static void Write(String message);
  public: static void WriteLine(Object value);
  public: static void WriteLine(Object value, String category);
  public: static void WriteLine(String format, Array<Object> args);
  public: static void WriteLine(String message, String category);
  public: static void Write(Object value);
  public: static void Write(String message, String category);
  public: static void Write(Object value, String category);
  public: static void WriteIf(Boolean condition, String message);
  public: static void WriteIf(Boolean condition, Object value);
  public: static void WriteIf(Boolean condition, String message, String category);
  public: static void WriteIf(Boolean condition, Object value, String category);
  public: static void WriteLineIf(Boolean condition, Object value);
  public: static void WriteLineIf(Boolean condition, Object value, String category);
  public: static void WriteLineIf(Boolean condition, String message);
  public: static void WriteLineIf(Boolean condition, String message, String category);
  private: static DebugProvider s_provider;
  private: static Int32 t_indentLevel;
  private: static Int32 s_indentSize;
};
} // namespace DebugNamespace
using Debug = DebugNamespace::Debug;
} // namespace System::Private::CoreLib::System::Diagnostics
