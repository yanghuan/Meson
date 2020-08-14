#include "ConsolePal-dep.h"

#include <System.Console/Interop-dep.h>
#include <System.Console/System/Console-dep.h>
#include <System.Console/System/ConsoleKey.h>
#include <System.Console/System/ConsolePal-dep.h>
#include <System.Console/System/ConsoleSpecialKey.h>
#include <System.Console/System/IO/Error-dep.h>
#include <System.Console/System/IO/SyncTextReader-dep.h>
#include <System.Console/System/IO/Win32Marshal-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Console/System/Text/ConsoleEncoding-dep.h>
#include <System.Console/System/Text/EncodingHelper-dep.h>
#include <System.Console/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/StreamReader-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/Version-dep.h>

namespace System::Console::System::ConsolePalNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
using namespace System::IO;
using namespace System::Text;

void ConsolePal::WindowsConsoleStream___::ctor(IntPtr handle, FileAccess access, Boolean useFileAPIs) {
  _handle = handle;
  _isPipe = (Interop::Kernel32::GetFileType(handle) == 3);
  _useFileAPIs = useFileAPIs;
}

void ConsolePal::WindowsConsoleStream___::Dispose(Boolean disposing) {
  _handle = IntPtr::Zero;
  ConsoleStream::Dispose(disposing);
}

Int32 ConsolePal::WindowsConsoleStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  ValidateRead(buffer, offset, count);
  Int32 bytesRead;
  Int32 num = ReadFileNative(_handle, buffer, offset, count, _isPipe, bytesRead, _useFileAPIs);
  if (num != 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(num));
  }
  return bytesRead;
}

void ConsolePal::WindowsConsoleStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  ValidateWrite(buffer, offset, count);
  Int32 num = WriteFileNative(_handle, buffer, offset, count, _useFileAPIs);
  if (num != 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(num));
  }
}

void ConsolePal::WindowsConsoleStream___::Flush() {
  if (_handle == IntPtr::Zero) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
  ConsoleStream::Flush();
}

Int32 ConsolePal::WindowsConsoleStream___::ReadFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean isPipe, Int32& bytesRead, Boolean useFileAPIs) {
  if (bytes->get_Length() - offset < count) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_IORaceCondition());
  }
  if (bytes->get_Length() == 0) {
    bytesRead = 0;
    return 0;
  }
  Boolean flag;
  {
    Byte* ptr = &bytes[0];
    if (useFileAPIs) {
      flag = (Interop::Kernel32::ReadFile(hFile, ptr + offset, count, bytesRead, IntPtr::Zero) != 0);
    } else {
      Int32 lpNumberOfCharsRead;
      flag = Interop::Kernel32::ReadConsole(hFile, ptr + offset, count / 2, lpNumberOfCharsRead, IntPtr::Zero);
      bytesRead = lpNumberOfCharsRead * 2;
    }
  }
  if (flag) {
    return 0;
  }
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (lastWin32Error == 232 || lastWin32Error == 109) {
    return 0;
  }
  return lastWin32Error;
}

Int32 ConsolePal::WindowsConsoleStream___::WriteFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean useFileAPIs) {
  if (bytes->get_Length() == 0) {
    return 0;
  }
  Boolean flag;
  {
    Byte* ptr = &bytes[0];
    Int32 _;
    Int32 _;
    flag = ((!useFileAPIs) ? Interop::Kernel32::WriteConsole(hFile, ptr + offset, count / 2, _, IntPtr::Zero) : (Interop::Kernel32::WriteFile(hFile, ptr + offset, count, _, IntPtr::Zero) != 0));
  }
  if (flag) {
    return 0;
  }
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  if (lastWin32Error == 232 || lastWin32Error == 109) {
    return 0;
  }
  return lastWin32Error;
}

void ConsolePal::ControlCHandlerRegistrar___::ctor() {
  _handler = BreakEvent;
}

void ConsolePal::ControlCHandlerRegistrar___::Register() {
  if (!Interop::Kernel32::SetConsoleCtrlHandler(_handler, true)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  _handlerRegistered = true;
}

void ConsolePal::ControlCHandlerRegistrar___::Unregister() {
  if (!Interop::Kernel32::SetConsoleCtrlHandler(_handler, false)) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  _handlerRegistered = false;
}

Boolean ConsolePal::ControlCHandlerRegistrar___::BreakEvent(Int32 controlType) {
  if (controlType != 0 && controlType != 1) {
    return false;
  }
  return Console::HandleBreakEvent((controlType != 0) ? ConsoleSpecialKey::ControlBreak : ConsoleSpecialKey::ControlC);
}

IntPtr ConsolePal::get_InvalidHandleValue() {
  return IntPtr(-1);
}

IntPtr ConsolePal::get_InputHandle() {
  return Interop::Kernel32::GetStdHandle(-10);
}

IntPtr ConsolePal::get_OutputHandle() {
  return Interop::Kernel32::GetStdHandle(-11);
}

IntPtr ConsolePal::get_ErrorHandle() {
  return Interop::Kernel32::GetStdHandle(-12);
}

Encoding ConsolePal::get_InputEncoding() {
  return EncodingHelper::GetSupportedConsoleEncoding((Int32)Interop::Kernel32::GetConsoleCP());
}

Encoding ConsolePal::get_OutputEncoding() {
  return EncodingHelper::GetSupportedConsoleEncoding((Int32)Interop::Kernel32::GetConsoleOutputCP());
}

Boolean ConsolePal::get_NumberLock() {
  try{
    Int16 keyState = Interop::User32::in::GetKeyState(144);
    return (keyState & 1) == 1;
  } catch (Exception) {
  }
}

Boolean ConsolePal::get_CapsLock() {
  try{
    Int16 keyState = Interop::User32::in::GetKeyState(20);
    return (keyState & 1) == 1;
  } catch (Exception) {
  }
}

Boolean ConsolePal::get_KeyAvailable() {
  if (_cachedInputRecord.eventType == 1) {
    return true;
  }
  Interop::InputRecord buffer = Interop::InputRecord();
  Int32 numEventsRead = 0;
  while (true) {
    if (!Interop::Kernel32::PeekConsoleInput(get_InputHandle(), buffer, 1, numEventsRead)) {
      Int32 lastWin32Error = Marshal::GetLastWin32Error();
      if (lastWin32Error == 6) {
        rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConsoleKeyAvailableOnFile());
      }
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, "stdin"));
    }
    if (numEventsRead == 0) {
      return false;
    }
    if (IsKeyDownEvent(buffer) && !IsModKey(buffer)) {
      break;
    }
    if (!Interop::Kernel32::ReadConsoleInput(get_InputHandle(), buffer, 1, numEventsRead)) {
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
    }
  }
  return true;
}

Boolean ConsolePal::get_TreatControlCAsInput() {
  IntPtr inputHandle = get_InputHandle();
  if (inputHandle == get_InvalidHandleValue()) {
    rt::throw_exception<IOException>(SR::get_IO_NoConsole());
  }
  Int32 mode = 0;
  if (!Interop::Kernel32::GetConsoleMode(inputHandle, mode)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  return (mode & 1) == 0;
}

void ConsolePal::set_TreatControlCAsInput(Boolean value) {
  IntPtr inputHandle = get_InputHandle();
  if (inputHandle == get_InvalidHandleValue()) {
    rt::throw_exception<IOException>(SR::get_IO_NoConsole());
  }
  Int32 mode = 0;
  if (!Interop::Kernel32::GetConsoleMode(inputHandle, mode)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  mode = ((!value) ? (mode | 1) : (mode & -2));
  if (!Interop::Kernel32::SetConsoleMode(inputHandle, mode)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

ConsoleColor ConsolePal::get_BackgroundColor() {
  Boolean succeeded;
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo(false, succeeded);
  if (!succeeded) {
    return ConsoleColor::Black;
  }
  return ColorAttributeToConsoleColor((Interop::Kernel32::Color)(bufferInfo.wAttributes & 240));
}

void ConsolePal::set_BackgroundColor(ConsoleColor value) {
  Interop::Kernel32::Color color = ConsoleColorToColorAttribute(value, true);
  Boolean succeeded;
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo(false, succeeded);
  if (succeeded) {
    Int16 wAttributes = bufferInfo.wAttributes;
    wAttributes = (Int16)(wAttributes & -241);
    wAttributes = (Int16)((UInt16)wAttributes | (UInt16)color);
    Interop::Kernel32::SetConsoleTextAttribute(get_OutputHandle(), wAttributes);
  }
}

ConsoleColor ConsolePal::get_ForegroundColor() {
  Boolean succeeded;
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo(false, succeeded);
  if (!succeeded) {
    return ConsoleColor::Gray;
  }
  return ColorAttributeToConsoleColor((Interop::Kernel32::Color)(bufferInfo.wAttributes & 15));
}

void ConsolePal::set_ForegroundColor(ConsoleColor value) {
  Interop::Kernel32::Color color = ConsoleColorToColorAttribute(value, false);
  Boolean succeeded;
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo(false, succeeded);
  if (succeeded) {
    Int16 wAttributes = bufferInfo.wAttributes;
    wAttributes = (Int16)(wAttributes & -16);
    wAttributes = (Int16)((UInt16)wAttributes | (UInt16)color);
    Interop::Kernel32::SetConsoleTextAttribute(get_OutputHandle(), wAttributes);
  }
}

Int32 ConsolePal::get_CursorSize() {
  Interop::Kernel32::CONSOLE_CURSOR_INFO cci;
  if (!Interop::Kernel32::GetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  return cci.dwSize;
}

void ConsolePal::set_CursorSize(Int32 value) {
  if (value < 1 || value > 100) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::get_ArgumentOutOfRange_CursorSize());
  }
  Interop::Kernel32::CONSOLE_CURSOR_INFO cci;
  if (!Interop::Kernel32::GetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  cci.dwSize = value;
  if (!Interop::Kernel32::SetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

Boolean ConsolePal::get_CursorVisible() {
  Interop::Kernel32::CONSOLE_CURSOR_INFO cci;
  if (!Interop::Kernel32::GetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  return cci.bVisible;
}

void ConsolePal::set_CursorVisible(Boolean value) {
  Interop::Kernel32::CONSOLE_CURSOR_INFO cci;
  if (!Interop::Kernel32::GetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  cci.bVisible = value;
  if (!Interop::Kernel32::SetConsoleCursorInfo(get_OutputHandle(), cci)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

Int32 ConsolePal::get_CursorLeft() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.dwCursorPosition.X;
}

Int32 ConsolePal::get_CursorTop() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.dwCursorPosition.Y;
}

String ConsolePal::get_Title() {
  Char default[256] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  UInt32 num;
  while (true) {
    num = 0u;
    {
      Char* title = valueStringBuilder;
      num = Interop::Kernel32::GetConsoleTitleW(title, (UInt32)valueStringBuilder.get_Capacity());
    }
    if (num == 0) {
      Int32 lastWin32Error = Marshal::GetLastWin32Error();
      switch (lastWin32Error.get()) {
        case 122:
          valueStringBuilder.EnsureCapacity(valueStringBuilder.get_Capacity() * 2);
          continue;
        default:
          rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error, String::in::Empty));
        case 0:
          break;
      }
      break;
    }
    if (num < valueStringBuilder.get_Capacity() - 1 && (!IsWindows7() || num < valueStringBuilder.get_Capacity() / 2 - 1)) {
      break;
    }
    valueStringBuilder.EnsureCapacity(valueStringBuilder.get_Capacity() * 2);
  }
  valueStringBuilder.set_Length = (Int32)num;
  return valueStringBuilder.ToString();
}

void ConsolePal::set_Title(String value) {
  if (!Interop::Kernel32::SetConsoleTitle(value)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

Int32 ConsolePal::get_BufferWidth() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.dwSize.X;
}

void ConsolePal::set_BufferWidth(Int32 value) {
  SetBufferSize(value, get_BufferHeight());
}

Int32 ConsolePal::get_BufferHeight() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.dwSize.Y;
}

void ConsolePal::set_BufferHeight(Int32 value) {
  SetBufferSize(get_BufferWidth(), value);
}

Int32 ConsolePal::get_LargestWindowWidth() {
  Interop::Kernel32::COORD largestConsoleWindowSize = Interop::Kernel32::GetLargestConsoleWindowSize(get_OutputHandle());
  return largestConsoleWindowSize.X;
}

Int32 ConsolePal::get_LargestWindowHeight() {
  Interop::Kernel32::COORD largestConsoleWindowSize = Interop::Kernel32::GetLargestConsoleWindowSize(get_OutputHandle());
  return largestConsoleWindowSize.Y;
}

Int32 ConsolePal::get_WindowLeft() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.srWindow.Left;
}

void ConsolePal::set_WindowLeft(Int32 value) {
  SetWindowPosition(value, get_WindowTop());
}

Int32 ConsolePal::get_WindowTop() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.srWindow.Top;
}

void ConsolePal::set_WindowTop(Int32 value) {
  SetWindowPosition(get_WindowLeft(), value);
}

Int32 ConsolePal::get_WindowWidth() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
}

void ConsolePal::set_WindowWidth(Int32 value) {
  SetWindowSize(value, get_WindowHeight());
}

Int32 ConsolePal::get_WindowHeight() {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  return bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1;
}

void ConsolePal::set_WindowHeight(Int32 value) {
  SetWindowSize(get_WindowWidth(), value);
}

void ConsolePal::EnsureConsoleInitialized() {
}

Boolean ConsolePal::IsWindows7() {
  Version version = Environment::get_OSVersion()->get_Version();
  if (version->get_Major() == 6) {
    return version->get_Minor() == 1;
  }
  return false;
}

Stream ConsolePal::OpenStandardInput() {
  return GetStandardFile(-10, FileAccess::Read, Console::get_InputEncoding()->get_CodePage() != Encoding::in::get_Unicode()->get_CodePage() || Console::get_IsInputRedirected());
}

Stream ConsolePal::OpenStandardOutput() {
  return GetStandardFile(-11, FileAccess::Write, Console::get_OutputEncoding()->get_CodePage() != Encoding::in::get_Unicode()->get_CodePage() || Console::get_IsOutputRedirected());
}

Stream ConsolePal::OpenStandardError() {
  return GetStandardFile(-12, FileAccess::Write, Console::get_OutputEncoding()->get_CodePage() != Encoding::in::get_Unicode()->get_CodePage() || Console::get_IsErrorRedirected());
}

Stream ConsolePal::GetStandardFile(Int32 handleType, FileAccess access, Boolean useFileAPIs) {
  IntPtr stdHandle = Interop::Kernel32::GetStdHandle(handleType);
  if (stdHandle == IntPtr::Zero || stdHandle == get_InvalidHandleValue() || (access != FileAccess::Read && !ConsoleHandleIsWritable(stdHandle))) {
    return Stream::in::Null;
  }
  return rt::newobj<WindowsConsoleStream>(stdHandle, access, useFileAPIs);
}

Boolean ConsolePal::ConsoleHandleIsWritable(IntPtr outErrHandle) {
  Byte b = 65;
  Int32 numBytesWritten;
  Int32 num = Interop::Kernel32::WriteFile(outErrHandle, &b, 0, numBytesWritten, IntPtr::Zero);
  return num != 0;
}

void ConsolePal::SetConsoleInputEncoding(Encoding enc) {
  if (enc->get_CodePage() != Encoding::in::get_Unicode()->get_CodePage() && !Interop::Kernel32::SetConsoleCP(enc->get_CodePage())) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

void ConsolePal::SetConsoleOutputEncoding(Encoding enc) {
  if (enc->get_CodePage() != Encoding::in::get_Unicode()->get_CodePage() && !Interop::Kernel32::SetConsoleOutputCP(enc->get_CodePage())) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

Boolean ConsolePal::IsInputRedirectedCore() {
  return IsHandleRedirected(get_InputHandle());
}

Boolean ConsolePal::IsOutputRedirectedCore() {
  return IsHandleRedirected(get_OutputHandle());
}

Boolean ConsolePal::IsErrorRedirectedCore() {
  return IsHandleRedirected(get_ErrorHandle());
}

Boolean ConsolePal::IsHandleRedirected(IntPtr handle) {
  UInt32 fileType = Interop::Kernel32::GetFileType(handle);
  if ((fileType & 2) != 2) {
    return true;
  }
  return !Interop::Kernel32::IsGetConsoleModeCallSuccessful(handle);
}

TextReader ConsolePal::GetOrCreateReader() {
  Stream stream = OpenStandardInput();
  return SyncTextReader::in::GetSynchronizedTextReader((stream == Stream::in::Null) ? StreamReader::in::Null : rt::newobj<StreamReader>(stream, rt::newobj<ConsoleEncoding>(Console::get_InputEncoding()), false, 4096, true));
}

Boolean ConsolePal::IsKeyDownEvent(Interop::InputRecord ir) {
  if (ir.eventType == 1) {
    return ir.keyEvent.keyDown != Interop::BOOL::FALSE;
  }
  return false;
}

Boolean ConsolePal::IsModKey(Interop::InputRecord ir) {
  Int16 virtualKeyCode = ir.keyEvent.virtualKeyCode;
  if ((virtualKeyCode < 16 || virtualKeyCode > 18) && virtualKeyCode != 20 && virtualKeyCode != 144) {
    return virtualKeyCode == 145;
  }
  return true;
}

Boolean ConsolePal::IsAltKeyDown(Interop::InputRecord ir) {
  return (ir.keyEvent.controlKeyState & 3) != 0;
}

ConsoleKeyInfo ConsolePal::ReadKey(Boolean intercept) {
  Int32 numEventsRead = -1;
  Interop::InputRecord buffer;
  {
    rt::lock(s_readKeySyncObject);
    if (_cachedInputRecord.eventType == 1) {
      buffer = _cachedInputRecord;
      if (_cachedInputRecord.keyEvent.repeatCount == 0) {
        _cachedInputRecord.eventType = -1;
      } else {
        _cachedInputRecord.keyEvent.repeatCount--;
      }
    } else {
      while (true) {
        if (!Interop::Kernel32::ReadConsoleInput(get_InputHandle(), buffer, 1, numEventsRead) || numEventsRead == 0) {
          rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConsoleReadKeyOnFile());
        }
        Int16 virtualKeyCode = buffer.keyEvent.virtualKeyCode;
        if ((!IsKeyDownEvent(buffer) && virtualKeyCode != 18) || (buffer.keyEvent.uChar == 0 && IsModKey(buffer))) {
          continue;
        }
        ConsoleKey consoleKey = (ConsoleKey)virtualKeyCode;
        if (!IsAltKeyDown(buffer)) {
          break;
        }
        if (consoleKey < ConsoleKey::NumPad0 || consoleKey > ConsoleKey::NumPad9) {
          switch (consoleKey) {
            case ConsoleKey::Clear:
            case ConsoleKey::PageUp:
            case ConsoleKey::PageDown:
            case ConsoleKey::End:
            case ConsoleKey::Home:
            case ConsoleKey::LeftArrow:
            case ConsoleKey::UpArrow:
            case ConsoleKey::RightArrow:
            case ConsoleKey::DownArrow:
            case ConsoleKey::Insert:
              continue;
          }
          break;
        }
      }
      if (buffer.keyEvent.repeatCount > 1) {
        buffer.keyEvent.repeatCount--;
        _cachedInputRecord = buffer;
      }
    }
  }
  ControlKeyState controlKeyState = (ControlKeyState)buffer.keyEvent.controlKeyState;
  Boolean shift = (controlKeyState & ControlKeyState::ShiftPressed) != 0;
  Boolean alt = (controlKeyState & (ControlKeyState::RightAltPressed | ControlKeyState::LeftAltPressed)) != 0;
  Boolean control = (controlKeyState & (ControlKeyState::RightCtrlPressed | ControlKeyState::LeftCtrlPressed)) != 0;
  ConsoleKeyInfo result = ConsoleKeyInfo(buffer.keyEvent.uChar, (ConsoleKey)buffer.keyEvent.virtualKeyCode, shift, alt, control);
  if (!intercept) {
    Console::Write(buffer.keyEvent.uChar);
  }
  return result;
}

void ConsolePal::ResetColor() {
  if (!_haveReadDefaultColors) {
    Boolean succeeded;
    GetBufferInfo(false, succeeded);
    if (!succeeded) {
      return;
    }
  }
  Interop::Kernel32::SetConsoleTextAttribute(get_OutputHandle(), _defaultColors);
}

void ConsolePal::Beep() {
  Interop::Kernel32::Beep(800, 200);
}

void ConsolePal::Beep(Int32 frequency, Int32 duration) {
  if (frequency < 37 || frequency > 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("frequency", frequency, SR::Format(SR::get_ArgumentOutOfRange_BeepFrequency(), 37, 32767));
  }
  if (duration <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("duration", duration, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  Interop::Kernel32::Beep(frequency, duration);
}

void ConsolePal::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
  if (sourceForeColor < ConsoleColor::Black || sourceForeColor > ConsoleColor::White) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidConsoleColor(), "sourceForeColor");
  }
  if (sourceBackColor < ConsoleColor::Black || sourceBackColor > ConsoleColor::White) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidConsoleColor(), "sourceBackColor");
  }
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  Interop::Kernel32::COORD dwSize = bufferInfo.dwSize;
  if (sourceLeft < 0 || sourceLeft > dwSize.X) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceLeft", sourceLeft, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (sourceTop < 0 || sourceTop > dwSize.Y) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceTop", sourceTop, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (sourceWidth < 0 || sourceWidth > dwSize.X - sourceLeft) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceWidth", sourceWidth, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (sourceHeight < 0 || sourceTop > dwSize.Y - sourceHeight) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceHeight", sourceHeight, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (targetLeft < 0 || targetLeft > dwSize.X) {
    rt::throw_exception<ArgumentOutOfRangeException>("targetLeft", targetLeft, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (targetTop < 0 || targetTop > dwSize.Y) {
    rt::throw_exception<ArgumentOutOfRangeException>("targetTop", targetTop, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (sourceWidth == 0 || sourceHeight == 0) {
    return;
  }
  Array<Interop::Kernel32::CHAR_INFO> array = rt::newarr<Array<Interop::Kernel32::CHAR_INFO>>(sourceWidth * sourceHeight);
  dwSize.X = (Int16)sourceWidth;
  dwSize.Y = (Int16)sourceHeight;
  Interop::Kernel32::COORD bufferCoord = Interop::Kernel32::COORD();
  Interop::Kernel32::SMALL_RECT readRegion = Interop::Kernel32::SMALL_RECT();
  readRegion.Left = (Int16)sourceLeft;
  readRegion.Right = (Int16)(sourceLeft + sourceWidth - 1);
  readRegion.Top = (Int16)sourceTop;
  readRegion.Bottom = (Int16)(sourceTop + sourceHeight - 1);
  Boolean flag;
  {
    Interop::Kernel32::CHAR_INFO* pBuffer = array;
    flag = Interop::Kernel32::ReadConsoleOutput(get_OutputHandle(), pBuffer, dwSize, bufferCoord, readRegion);
  }
  if (!flag) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  Interop::Kernel32::COORD cOORD = Interop::Kernel32::COORD();
  cOORD.X = (Int16)sourceLeft;
  Interop::Kernel32::Color color = ConsoleColorToColorAttribute(sourceBackColor, true);
  color |= ConsoleColorToColorAttribute(sourceForeColor, false);
  Int16 wColorAttribute = (Int16)color;
  for (Int32 i = sourceTop; i < sourceTop + sourceHeight; i++) {
    cOORD.Y = (Int16)i;
    Int32 pNumCharsWritten;
    if (!Interop::Kernel32::FillConsoleOutputCharacter(get_OutputHandle(), sourceChar, sourceWidth, cOORD, pNumCharsWritten)) {
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
    }
    if (!Interop::Kernel32::FillConsoleOutputAttribute(get_OutputHandle(), wColorAttribute, sourceWidth, cOORD, pNumCharsWritten)) {
      rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
    }
  }
  Interop::Kernel32::SMALL_RECT writeRegion = Interop::Kernel32::SMALL_RECT();
  writeRegion.Left = (Int16)targetLeft;
  writeRegion.Right = (Int16)(targetLeft + sourceWidth);
  writeRegion.Top = (Int16)targetTop;
  writeRegion.Bottom = (Int16)(targetTop + sourceHeight);
  {
    Interop::Kernel32::CHAR_INFO* buffer = array;
    Interop::Kernel32::WriteConsoleOutput(get_OutputHandle(), buffer, dwSize, bufferCoord, writeRegion);
  }
}

void ConsolePal::Clear() {
  Interop::Kernel32::COORD cOORD = Interop::Kernel32::COORD();
  IntPtr outputHandle = get_OutputHandle();
  if (outputHandle == get_InvalidHandleValue()) {
    rt::throw_exception<IOException>(SR::get_IO_NoConsole());
  }
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  Int32 num = bufferInfo.dwSize.X * bufferInfo.dwSize.Y;
  Int32 pNumCharsWritten = 0;
  if (!Interop::Kernel32::FillConsoleOutputCharacter(outputHandle, 32, num, cOORD, pNumCharsWritten)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  pNumCharsWritten = 0;
  if (!Interop::Kernel32::FillConsoleOutputAttribute(outputHandle, bufferInfo.wAttributes, num, cOORD, pNumCharsWritten)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  if (!Interop::Kernel32::SetConsoleCursorPosition(outputHandle, cOORD)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

void ConsolePal::SetCursorPosition(Int32 left, Int32 top) {
  IntPtr outputHandle = get_OutputHandle();
  Interop::Kernel32::COORD cursorPosition = Interop::Kernel32::COORD();
  cursorPosition.X = (Int16)left;
  cursorPosition.Y = (Int16)top;
  if (!Interop::Kernel32::SetConsoleCursorPosition(outputHandle, cursorPosition)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
    if (left >= bufferInfo.dwSize.X) {
      rt::throw_exception<ArgumentOutOfRangeException>("left", left, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
    }
    if (top >= bufferInfo.dwSize.Y) {
      rt::throw_exception<ArgumentOutOfRangeException>("top", top, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error));
  }
}

void ConsolePal::SetBufferSize(Int32 width, Int32 height) {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  Interop::Kernel32::SMALL_RECT srWindow = bufferInfo.srWindow;
  if (width < srWindow.Right + 1 || width >= 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("width", width, SR::get_ArgumentOutOfRange_ConsoleBufferLessThanWindowSize());
  }
  if (height < srWindow.Bottom + 1 || height >= 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("height", height, SR::get_ArgumentOutOfRange_ConsoleBufferLessThanWindowSize());
  }
  Interop::Kernel32::COORD size = Interop::Kernel32::COORD();
  size.X = (Int16)width;
  size.Y = (Int16)height;
  if (!Interop::Kernel32::SetConsoleScreenBufferSize(get_OutputHandle(), size)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

void ConsolePal::SetWindowPosition(Int32 left, Int32 top) {
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  Interop::Kernel32::SMALL_RECT srWindow = bufferInfo.srWindow;
  Int32 num = left + srWindow.Right - srWindow.Left;
  if (left < 0 || num > bufferInfo.dwSize.X - 1 || num < left) {
    rt::throw_exception<ArgumentOutOfRangeException>("left", left, SR::get_ArgumentOutOfRange_ConsoleWindowPos());
  }
  Int32 num2 = top + srWindow.Bottom - srWindow.Top;
  if (top < 0 || num2 > bufferInfo.dwSize.Y - 1 || num2 < top) {
    rt::throw_exception<ArgumentOutOfRangeException>("top", top, SR::get_ArgumentOutOfRange_ConsoleWindowPos());
  }
  srWindow.Bottom = (Int16)num2;
  srWindow.Right = (Int16)num;
  srWindow.Left = (Int16)left;
  srWindow.Top = (Int16)top;
  if (!Interop::Kernel32::SetConsoleWindowInfo(get_OutputHandle(), true, &srWindow)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
}

void ConsolePal::SetWindowSize(Int32 width, Int32 height) {
  if (width <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("width", width, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (height <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("height", height, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO bufferInfo = GetBufferInfo();
  Boolean flag = false;
  Interop::Kernel32::COORD size = Interop::Kernel32::COORD();
  size.X = bufferInfo.dwSize.X;
  size.Y = bufferInfo.dwSize.Y;
  if (bufferInfo.dwSize.X < bufferInfo.srWindow.Left + width) {
    if (bufferInfo.srWindow.Left >= 32767 - width) {
      rt::throw_exception<ArgumentOutOfRangeException>("width", SR::Format(SR::get_ArgumentOutOfRange_ConsoleWindowBufferSize(), 32767 - width));
    }
    size.X = (Int16)(bufferInfo.srWindow.Left + width);
    flag = true;
  }
  if (bufferInfo.dwSize.Y < bufferInfo.srWindow.Top + height) {
    if (bufferInfo.srWindow.Top >= 32767 - height) {
      rt::throw_exception<ArgumentOutOfRangeException>("height", SR::Format(SR::get_ArgumentOutOfRange_ConsoleWindowBufferSize(), 32767 - height));
    }
    size.Y = (Int16)(bufferInfo.srWindow.Top + height);
    flag = true;
  }
  if (flag && !Interop::Kernel32::SetConsoleScreenBufferSize(get_OutputHandle(), size)) {
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(Marshal::GetLastWin32Error()));
  }
  Interop::Kernel32::SMALL_RECT srWindow = bufferInfo.srWindow;
  srWindow.Bottom = (Int16)(srWindow.Top + height - 1);
  srWindow.Right = (Int16)(srWindow.Left + width - 1);
  if (!Interop::Kernel32::SetConsoleWindowInfo(get_OutputHandle(), true, &srWindow)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (flag) {
      Interop::Kernel32::SetConsoleScreenBufferSize(get_OutputHandle(), bufferInfo.dwSize);
    }
    Interop::Kernel32::COORD largestConsoleWindowSize = Interop::Kernel32::GetLargestConsoleWindowSize(get_OutputHandle());
    if (width > largestConsoleWindowSize.X) {
      rt::throw_exception<ArgumentOutOfRangeException>("width", width, SR::Format(SR::get_ArgumentOutOfRange_ConsoleWindowSize_Size(), largestConsoleWindowSize.X));
    }
    if (height > largestConsoleWindowSize.Y) {
      rt::throw_exception<ArgumentOutOfRangeException>("height", height, SR::Format(SR::get_ArgumentOutOfRange_ConsoleWindowSize_Size(), largestConsoleWindowSize.Y));
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error));
  }
}

Interop::Kernel32::Color ConsolePal::ConsoleColorToColorAttribute(ConsoleColor color, Boolean isBackground) {
  if ((color & (ConsoleColor)(-16)) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidConsoleColor());
  }
  Interop::Kernel32::Color color2 = (Interop::Kernel32::Color)color;
  if (isBackground) {
    color2 = (Interop::Kernel32::Color)((Int32)color2 << 4);
  }
  return color2;
}

ConsoleColor ConsolePal::ColorAttributeToConsoleColor(Interop::Kernel32::Color c) {
  if ((c & Interop::Kernel32::Color::BackgroundMask) != 0) {
    c = (Interop::Kernel32::Color)((Int32)c >> 4);
  }
  return (ConsoleColor)c;
}

Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO ConsolePal::GetBufferInfo() {
  Boolean succeeded;
  return GetBufferInfo(true, succeeded);
}

Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO ConsolePal::GetBufferInfo(Boolean throwOnNoConsole, Boolean& succeeded) {
  succeeded = false;
  IntPtr outputHandle = get_OutputHandle();
  if (outputHandle == get_InvalidHandleValue()) {
    if (throwOnNoConsole) {
      rt::throw_exception<IOException>(SR::get_IO_NoConsole());
    }
    return Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO();
  }
  Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo;
  if (!Interop::Kernel32::GetConsoleScreenBufferInfo(outputHandle, lpConsoleScreenBufferInfo) && !Interop::Kernel32::GetConsoleScreenBufferInfo(get_ErrorHandle(), lpConsoleScreenBufferInfo) && !Interop::Kernel32::GetConsoleScreenBufferInfo(get_InputHandle(), lpConsoleScreenBufferInfo)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (lastWin32Error == 6 && !throwOnNoConsole) {
      return Interop::Kernel32::CONSOLE_SCREEN_BUFFER_INFO();
    }
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error(lastWin32Error));
  }
  if (!_haveReadDefaultColors) {
    _defaultColors = (Byte)(lpConsoleScreenBufferInfo.wAttributes & 255);
    _haveReadDefaultColors = true;
  }
  succeeded = true;
  return lpConsoleScreenBufferInfo;
}

void ConsolePal::cctor() {
  s_readKeySyncObject = rt::newobj<Object>();
}

} // namespace System::Console::System::ConsolePalNamespace
