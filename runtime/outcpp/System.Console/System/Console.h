#pragma once

#include <System.Console/System/ConsolePal.h>

namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
FORWARD(TextReader)
FORWARD(TextWriter)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(StrongBox, T)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Console::System {
enum class ConsoleColor : int32_t;
enum class ConsoleSpecialKey : int32_t;
FORWARD(ConsoleCancelEventHandler)
FORWARDS(ConsoleKeyInfo)
namespace ConsoleNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Text;
class Console {
  public: static TextReader get_In();
  public: static Encoding get_InputEncoding();
  public: static void set_InputEncoding(Encoding value);
  public: static Encoding get_OutputEncoding();
  public: static void set_OutputEncoding(Encoding value);
  public: static Boolean get_KeyAvailable();
  public: static TextWriter get_Out();
  public: static TextWriter get_Error();
  public: static Boolean get_IsInputRedirected();
  public: static Boolean get_IsOutputRedirected();
  public: static Boolean get_IsErrorRedirected();
  public: static Int32 get_CursorSize();
  public: static void set_CursorSize(Int32 value);
  public: static Boolean get_NumberLock();
  public: static Boolean get_CapsLock();
  public: static ConsoleColor get_BackgroundColor();
  public: static void set_BackgroundColor(ConsoleColor value);
  public: static ConsoleColor get_ForegroundColor();
  public: static void set_ForegroundColor(ConsoleColor value);
  public: static Int32 get_BufferWidth();
  public: static void set_BufferWidth(Int32 value);
  public: static Int32 get_BufferHeight();
  public: static void set_BufferHeight(Int32 value);
  public: static Int32 get_WindowLeft();
  public: static void set_WindowLeft(Int32 value);
  public: static Int32 get_WindowTop();
  public: static void set_WindowTop(Int32 value);
  public: static Int32 get_WindowWidth();
  public: static void set_WindowWidth(Int32 value);
  public: static Int32 get_WindowHeight();
  public: static void set_WindowHeight(Int32 value);
  public: static Int32 get_LargestWindowWidth();
  public: static Int32 get_LargestWindowHeight();
  public: static Boolean get_CursorVisible();
  public: static void set_CursorVisible(Boolean value);
  public: static Int32 get_CursorLeft();
  public: static void set_CursorLeft(Int32 value);
  public: static Int32 get_CursorTop();
  public: static void set_CursorTop(Int32 value);
  public: static String get_Title();
  public: static void set_Title(String value);
  public: static Boolean get_TreatControlCAsInput();
  public: static void set_TreatControlCAsInput(Boolean value);
  public: static ConsoleKeyInfo ReadKey();
  public: static ConsoleKeyInfo ReadKey(Boolean intercept);
  private: static TextWriter CreateOutputWriter(Stream outputStream);
  public: static void ResetColor();
  public: static void SetBufferSize(Int32 width, Int32 height);
  public: static void SetWindowPosition(Int32 left, Int32 top);
  public: static void SetWindowSize(Int32 width, Int32 height);
  public: static ValueTuple<Int32, Int32> GetCursorPosition();
  public: static void Beep();
  public: static void Beep(Int32 frequency, Int32 duration);
  public: static void MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop);
  public: static void MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor);
  public: static void Clear();
  public: static void SetCursorPosition(Int32 left, Int32 top);
  public: static Stream OpenStandardInput();
  public: static Stream OpenStandardInput(Int32 bufferSize);
  public: static Stream OpenStandardOutput();
  public: static Stream OpenStandardOutput(Int32 bufferSize);
  public: static Stream OpenStandardError();
  public: static Stream OpenStandardError(Int32 bufferSize);
  public: static void SetIn(TextReader newIn);
  public: static void SetOut(TextWriter newOut);
  public: static void SetError(TextWriter newError);
  private: static void CheckNonNull(Object obj, String paramName);
  public: static Int32 Read();
  public: static String ReadLine();
  public: static void WriteLine();
  public: static void WriteLine(Boolean value);
  public: static void WriteLine(Char value);
  public: static void WriteLine(Array<Char> buffer);
  public: static void WriteLine(Array<Char> buffer, Int32 index, Int32 count);
  public: static void WriteLine(Decimal value);
  public: static void WriteLine(Double value);
  public: static void WriteLine(Single value);
  public: static void WriteLine(Int32 value);
  public: static void WriteLine(UInt32 value);
  public: static void WriteLine(Int64 value);
  public: static void WriteLine(UInt64 value);
  public: static void WriteLine(Object value);
  public: static void WriteLine(String value);
  public: static void WriteLine(String format, Object arg0);
  public: static void WriteLine(String format, Object arg0, Object arg1);
  public: static void WriteLine(String format, Object arg0, Object arg1, Object arg2);
  public: static void WriteLine(String format, Array<Object> arg);
  public: static void Write(String format, Object arg0);
  public: static void Write(String format, Object arg0, Object arg1);
  public: static void Write(String format, Object arg0, Object arg1, Object arg2);
  public: static void Write(String format, Array<Object> arg);
  public: static void Write(Boolean value);
  public: static void Write(Char value);
  public: static void Write(Array<Char> buffer);
  public: static void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: static void Write(Double value);
  public: static void Write(Decimal value);
  public: static void Write(Single value);
  public: static void Write(Int32 value);
  public: static void Write(UInt32 value);
  public: static void Write(Int64 value);
  public: static void Write(UInt64 value);
  public: static void Write(Object value);
  public: static void Write(String value);
  public: static Boolean HandleBreakEvent(ConsoleSpecialKey controlKey);
  public: static void cctor();
  public: static TextReader _get_In_g__EnsureInitialized13_0();
  public: static TextWriter _get_Out_g__EnsureInitialized25_0();
  public: static TextWriter _get_Error_g__EnsureInitialized27_0();
  public: static StrongBox<Boolean> _get_IsInputRedirected_g__EnsureInitialized33_0();
  public: static StrongBox<Boolean> _get_IsOutputRedirected_g__EnsureInitialized35_0();
  public: static StrongBox<Boolean> _get_IsErrorRedirected_g__EnsureInitialized37_0();
  private: static Object s_syncObject;
  private: static TextReader s_in;
  private: static TextWriter s_out;
  private: static TextWriter s_error;
  private: static Encoding s_inputEncoding;
  private: static Encoding s_outputEncoding;
  private: static Boolean s_isOutTextWriterRedirected;
  private: static Boolean s_isErrorTextWriterRedirected;
  private: static ConsoleCancelEventHandler s_cancelCallbacks;
  private: static ConsolePal::ControlCHandlerRegistrar s_registrar;
  private: static StrongBox<Boolean> _isStdInRedirected;
  private: static StrongBox<Boolean> _isStdOutRedirected;
  private: static StrongBox<Boolean> _isStdErrRedirected;
};
} // namespace ConsoleNamespace
using Console = ConsoleNamespace::Console;
} // namespace System::Console::System
