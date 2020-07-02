#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Console {
namespace InteropNamespace {
using namespace ::System::Private::CoreLib::System;
class Interop {
  public: enum class BOOL {
    FALSE = 0,
    TRUE = 1,
  };
  public: struct KeyEventRecord {
    public: BOOL keyDown;
    public: Int16 repeatCount;
    public: Int16 virtualKeyCode;
    public: Int16 virtualScanCode;
    public: Char uChar;
    public: Int32 controlKeyState;
  };
  public: struct InputRecord {
    public: Int16 eventType;
    public: KeyEventRecord keyEvent;
  };
  public: CLASS(Kernel32) {
    public: enum class Color : int16_t {
      Black = 0,
      ForegroundBlue = 1,
      ForegroundGreen = 2,
      ForegroundRed = 4,
      ForegroundYellow = 6,
      ForegroundIntensity = 8,
      BackgroundBlue = 16,
      BackgroundGreen = 32,
      BackgroundRed = 64,
      BackgroundYellow = 96,
      BackgroundIntensity = 128,
      ForegroundMask = 15,
      BackgroundMask = 240,
      ColorMask = 255,
    };
    public: struct COORD {
      public: Int16 X;
      public: Int16 Y;
    };
    public: struct SMALL_RECT {
      public: Int16 Left;
      public: Int16 Top;
      public: Int16 Right;
      public: Int16 Bottom;
    };
    private: struct CPINFOEXW {
      public: UInt32 MaxCharSize;
      public: rt::FixedBuffer<Byte, 2> DefaultChar;
      public: rt::FixedBuffer<Byte, 12> LeadByte;
      public: Char UnicodeDefaultChar;
      public: UInt32 CodePage;
      public: rt::FixedBuffer<Char, 260> CodePageName;
    };
    public: struct CONSOLE_CURSOR_INFO {
      public: Int32 dwSize;
      public: Boolean bVisible;
    };
    public: struct CONSOLE_SCREEN_BUFFER_INFO {
      public: COORD dwSize;
      public: COORD dwCursorPosition;
      public: Int16 wAttributes;
      public: SMALL_RECT srWindow;
      public: COORD dwMaximumWindowSize;
    };
    public: struct CHAR_INFO {
      private: UInt16 charData;
      private: Int16 attributes;
    };
    public: CLASS(ConsoleCtrlHandlerRoutine) {
      public: Boolean Invoke(Int32 controlType);
      public: IAsyncResult BeginInvoke(Int32 controlType, AsyncCallback callback, Object object);
      public: Boolean EndInvoke(IAsyncResult result);
    };
    private: static BOOL GetCPInfoExW(UInt32 CodePage, UInt32 dwFlags, CPINFOEXW* lpCPInfoEx);
    public: static Int32 GetLeadByteRanges(Int32 codePage, Array<Byte> leadByteRanges);
    public: static Boolean Beep(Int32 frequency, Int32 duration);
    private: static Int32 FormatMessage(Int32 dwFlags, IntPtr lpSource, UInt32 dwMessageId, Int32 dwLanguageId, void* lpBuffer, Int32 nSize, IntPtr arguments);
    public: static String GetMessage(Int32 errorCode);
    public: static String GetMessage(Int32 errorCode, IntPtr moduleHandle);
    private: static String GetAndTrimString(Span<Char> buffer);
    public: static Boolean GetConsoleCursorInfo(IntPtr hConsoleOutput, CONSOLE_CURSOR_INFO& cci);
    public: static Boolean SetConsoleCursorInfo(IntPtr hConsoleOutput, CONSOLE_CURSOR_INFO& cci);
    public: static Boolean FillConsoleOutputAttribute(IntPtr hConsoleOutput, Int16 wColorAttribute, Int32 numCells, COORD startCoord, Int32& pNumBytesWritten);
    public: static Boolean FillConsoleOutputCharacter(IntPtr hConsoleOutput, Char character, Int32 nLength, COORD dwWriteCoord, Int32& pNumCharsWritten);
    public: static Boolean GetConsoleScreenBufferInfo(IntPtr hConsoleOutput, CONSOLE_SCREEN_BUFFER_INFO& lpConsoleScreenBufferInfo);
    public: static UInt32 GetConsoleCP();
    public: static UInt32 GetConsoleTitleW(Char* title, UInt32 nSize);
    public: static Boolean GetConsoleMode(IntPtr handle, Int32& mode);
    public: static Boolean IsGetConsoleModeCallSuccessful(IntPtr handle);
    public: static Boolean SetConsoleMode(IntPtr handle, Int32 mode);
    public: static UInt32 GetConsoleOutputCP();
    public: static COORD GetLargestConsoleWindowSize(IntPtr hConsoleOutput);
    public: static UInt32 GetFileType(IntPtr hFile);
    public: static IntPtr GetStdHandle(Int32 nStdHandle);
    public: static Int32 MultiByteToWideChar(UInt32 CodePage, UInt32 dwFlags, Byte* lpMultiByteStr, Int32 cbMultiByte, Char* lpWideCharStr, Int32 cchWideChar);
    public: static Boolean PeekConsoleInput(IntPtr hConsoleInput, InputRecord& buffer, Int32 numInputRecords_UseOne, Int32& numEventsRead);
    public: static Int32 ReadFile(IntPtr handle, Byte* bytes, Int32 numBytesToRead, Int32& numBytesRead, IntPtr mustBeZero);
    public: static Boolean ReadConsole(IntPtr hConsoleInput, Byte* lpBuffer, Int32 nNumberOfCharsToRead, Int32& lpNumberOfCharsRead, IntPtr pInputControl);
    public: static Boolean ReadConsoleInput(IntPtr hConsoleInput, InputRecord& buffer, Int32 numInputRecords_UseOne, Int32& numEventsRead);
    public: static Boolean ReadConsoleOutput(IntPtr hConsoleOutput, CHAR_INFO* pBuffer, COORD bufferSize, COORD bufferCoord, SMALL_RECT& readRegion);
    public: static Boolean SetConsoleCP(Int32 codePage);
    public: static Boolean SetConsoleCtrlHandler(ConsoleCtrlHandlerRoutine handler, Boolean addOrRemove);
    public: static Boolean SetConsoleCursorPosition(IntPtr hConsoleOutput, COORD cursorPosition);
    public: static Boolean SetConsoleOutputCP(Int32 codePage);
    public: static Boolean SetConsoleScreenBufferSize(IntPtr hConsoleOutput, COORD size);
    public: static Int32 SetConsoleTextAttribute(IntPtr hConsoleOutput, Int16 wAttributes);
    public: static Boolean SetConsoleTitle(String title);
    public: static Boolean SetConsoleWindowInfo(IntPtr hConsoleOutput, Boolean absolute, SMALL_RECT* consoleWindow);
    public: static Int32 WideCharToMultiByte(UInt32 CodePage, UInt32 dwFlags, Char* lpWideCharStr, Int32 cchWideChar, Byte* lpMultiByteStr, Int32 cbMultiByte, IntPtr lpDefaultChar, IntPtr lpUsedDefaultChar);
    public: static Int32 WriteFile(IntPtr handle, Byte* bytes, Int32 numBytesToWrite, Int32& numBytesWritten, IntPtr mustBeZero);
    public: static Boolean WriteConsole(IntPtr hConsoleOutput, Byte* lpBuffer, Int32 nNumberOfCharsToWrite, Int32& lpNumberOfCharsWritten, IntPtr lpReservedMustBeNull);
    public: static Boolean WriteConsoleOutput(IntPtr hConsoleOutput, CHAR_INFO* buffer, COORD bufferSize, COORD bufferCoord, SMALL_RECT& writeRegion);
  };
  public: CLASS(User32) {
    public: static Int16 GetKeyState(Int32 virtualKeyCode);
  };
};
} // namespace InteropNamespace
using Interop = InteropNamespace::Interop;
} // namespace System::Console
