#pragma once

#include <System.Console/Interop.h>
#include <System.Console/System/IO/ConsoleStream.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::IO {
enum class FileAccess : int32_t;
FORWARD(Stream)
FORWARD(TextReader)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
FORWARDS_(ValueTuple)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System {
enum class ConsoleColor : int32_t;
FORWARDS(ConsoleKeyInfo)
namespace ConsolePalNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Text;
using namespace System::IO;
class ConsolePal {
  public: enum class ControlKeyState : int32_t {
    RightAltPressed = 1,
    LeftAltPressed = 2,
    RightCtrlPressed = 4,
    LeftCtrlPressed = 8,
    ShiftPressed = 16,
    NumLockOn = 32,
    ScrollLockOn = 64,
    CapsLockOn = 128,
    EnhancedKey = 256,
  };
  private: CLASS(WindowsConsoleStream) : public ConsoleStream::in {
    public: void ctor(IntPtr handle, FileAccess access, Boolean useFileAPIs);
    protected: void Dispose(Boolean disposing);
    public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
    public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
    public: void Flush();
    private: static Int32 ReadFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean isPipe, Int32& bytesRead, Boolean useFileAPIs);
    private: static Int32 WriteFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean useFileAPIs);
    private: Boolean _isPipe;
    private: IntPtr _handle;
    private: Boolean _useFileAPIs;
  };
  public: CLASS(ControlCHandlerRegistrar) : public object {
    public: void ctor();
    public: void Register();
    public: void Unregister();
    private: static Boolean BreakEvent(Int32 controlType);
    private: Boolean _handlerRegistered;
    private: Interop::Kernel32::ConsoleCtrlHandlerRoutine _handler;
  };
  private: static IntPtr get_InvalidHandleValue();
  private: static IntPtr get_InputHandle();
  private: static IntPtr get_OutputHandle();
  private: static IntPtr get_ErrorHandle();
  public: static Encoding get_InputEncoding();
  public: static Encoding get_OutputEncoding();
  public: static Boolean get_NumberLock();
  public: static Boolean get_CapsLock();
  public: static Boolean get_KeyAvailable();
  public: static Boolean get_TreatControlCAsInput();
  public: static void set_TreatControlCAsInput(Boolean value);
  public: static ConsoleColor get_BackgroundColor();
  public: static void set_BackgroundColor(ConsoleColor value);
  public: static ConsoleColor get_ForegroundColor();
  public: static void set_ForegroundColor(ConsoleColor value);
  public: static Int32 get_CursorSize();
  public: static void set_CursorSize(Int32 value);
  public: static Boolean get_CursorVisible();
  public: static void set_CursorVisible(Boolean value);
  public: static String get_Title();
  public: static void set_Title(String value);
  public: static Int32 get_BufferWidth();
  public: static void set_BufferWidth(Int32 value);
  public: static Int32 get_BufferHeight();
  public: static void set_BufferHeight(Int32 value);
  public: static Int32 get_LargestWindowWidth();
  public: static Int32 get_LargestWindowHeight();
  public: static Int32 get_WindowLeft();
  public: static void set_WindowLeft(Int32 value);
  public: static Int32 get_WindowTop();
  public: static void set_WindowTop(Int32 value);
  public: static Int32 get_WindowWidth();
  public: static void set_WindowWidth(Int32 value);
  public: static Int32 get_WindowHeight();
  public: static void set_WindowHeight(Int32 value);
  public: static void EnsureConsoleInitialized();
  private: static Boolean IsWindows7();
  public: static Stream OpenStandardInput();
  public: static Stream OpenStandardOutput();
  public: static Stream OpenStandardError();
  private: static Stream GetStandardFile(Int32 handleType, FileAccess access, Boolean useFileAPIs);
  private: static Boolean ConsoleHandleIsWritable(IntPtr outErrHandle);
  public: static void SetConsoleInputEncoding(Encoding enc);
  public: static void SetConsoleOutputEncoding(Encoding enc);
  public: static Boolean IsInputRedirectedCore();
  public: static Boolean IsOutputRedirectedCore();
  public: static Boolean IsErrorRedirectedCore();
  private: static Boolean IsHandleRedirected(IntPtr handle);
  public: static TextReader GetOrCreateReader();
  private: static Boolean IsKeyDownEvent(Interop::InputRecord ir);
  private: static Boolean IsModKey(Interop::InputRecord ir);
  private: static Boolean IsAltKeyDown(Interop::InputRecord ir);
  public: static ConsoleKeyInfo ReadKey(Boolean intercept);
  public: static void ResetColor();
  public: static ValueTuple<Int32, Int32> GetCursorPosition();
  public: static void Beep();
  public: static void Beep(Int32 frequency, Int32 duration);
  public: static void MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor);
  public: static void Clear();
  public: static void SetCursorPosition(Int32 left, Int32 top);
  public: static void SetBufferSize(Int32 width, Int32 height);
  public: static void SetWindowPosition(Int32 left, Int32 top);
  public: static void SetWindowSize(Int32 width, Int32 height);
  private: static Interop::Kernel32::Color ConsoleColorToColorAttribute(ConsoleColor color, Boolean isBackground);
  private: static ConsoleColor ColorAttributeToConsoleColor(Interop::Kernel32::Color c);
  private: static Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO GetBufferInfo();
  private: static Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO GetBufferInfo(Boolean throwOnNoConsole, Boolean& succeeded);
  public: static void cctor();
  private: static Object s_readKeySyncObject;
  private: static Interop::InputRecord _cachedInputRecord;
  private: static Boolean _haveReadDefaultColors;
  private: static Byte _defaultColors;
};
} // namespace ConsolePalNamespace
using ConsolePal = ConsolePalNamespace::ConsolePal;
} // namespace System::Console::System
