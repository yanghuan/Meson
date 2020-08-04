#include "Console-dep.h"

namespace System::Console::System::ConsoleNamespace {
TextReader Console::get_In() {
  return nullptr;
}

Encoding Console::get_InputEncoding() {
  return nullptr;
}

void Console::set_InputEncoding(Encoding value) {
}

Encoding Console::get_OutputEncoding() {
  return nullptr;
}

void Console::set_OutputEncoding(Encoding value) {
}

Boolean Console::get_KeyAvailable() {
  return Boolean();
}

TextWriter Console::get_Out() {
  return nullptr;
}

TextWriter Console::get_Error() {
  return nullptr;
}

Boolean Console::get_IsInputRedirected() {
  return Boolean();
}

Boolean Console::get_IsOutputRedirected() {
  return Boolean();
}

Boolean Console::get_IsErrorRedirected() {
  return Boolean();
}

Int32 Console::get_CursorSize() {
  return Int32();
}

void Console::set_CursorSize(Int32 value) {
}

Boolean Console::get_NumberLock() {
  return Boolean();
}

Boolean Console::get_CapsLock() {
  return Boolean();
}

ConsoleColor Console::get_BackgroundColor() {
  return ConsoleColor::White;
}

void Console::set_BackgroundColor(ConsoleColor value) {
}

ConsoleColor Console::get_ForegroundColor() {
  return ConsoleColor::White;
}

void Console::set_ForegroundColor(ConsoleColor value) {
}

Int32 Console::get_BufferWidth() {
  return Int32();
}

void Console::set_BufferWidth(Int32 value) {
}

Int32 Console::get_BufferHeight() {
  return Int32();
}

void Console::set_BufferHeight(Int32 value) {
}

Int32 Console::get_WindowLeft() {
  return Int32();
}

void Console::set_WindowLeft(Int32 value) {
}

Int32 Console::get_WindowTop() {
  return Int32();
}

void Console::set_WindowTop(Int32 value) {
}

Int32 Console::get_WindowWidth() {
  return Int32();
}

void Console::set_WindowWidth(Int32 value) {
}

Int32 Console::get_WindowHeight() {
  return Int32();
}

void Console::set_WindowHeight(Int32 value) {
}

Int32 Console::get_LargestWindowWidth() {
  return Int32();
}

Int32 Console::get_LargestWindowHeight() {
  return Int32();
}

Boolean Console::get_CursorVisible() {
  return Boolean();
}

void Console::set_CursorVisible(Boolean value) {
}

Int32 Console::get_CursorLeft() {
  return Int32();
}

void Console::set_CursorLeft(Int32 value) {
}

Int32 Console::get_CursorTop() {
  return Int32();
}

void Console::set_CursorTop(Int32 value) {
}

String Console::get_Title() {
  return nullptr;
}

void Console::set_Title(String value) {
}

Boolean Console::get_TreatControlCAsInput() {
  return Boolean();
}

void Console::set_TreatControlCAsInput(Boolean value) {
}

ConsoleKeyInfo Console::ReadKey() {
  return ConsoleKeyInfo();
}

ConsoleKeyInfo Console::ReadKey(Boolean intercept) {
  return ConsoleKeyInfo();
}

TextWriter Console::CreateOutputWriter(Stream outputStream) {
  return nullptr;
}

void Console::ResetColor() {
}

void Console::SetBufferSize(Int32 width, Int32 height) {
}

void Console::SetWindowPosition(Int32 left, Int32 top) {
}

void Console::SetWindowSize(Int32 width, Int32 height) {
}

void Console::Beep() {
}

void Console::Beep(Int32 frequency, Int32 duration) {
}

void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop) {
}

void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
}

void Console::Clear() {
}

void Console::SetCursorPosition(Int32 left, Int32 top) {
}

Stream Console::OpenStandardInput() {
  return nullptr;
}

Stream Console::OpenStandardInput(Int32 bufferSize) {
  return nullptr;
}

Stream Console::OpenStandardOutput() {
  return nullptr;
}

Stream Console::OpenStandardOutput(Int32 bufferSize) {
  return nullptr;
}

Stream Console::OpenStandardError() {
  return nullptr;
}

Stream Console::OpenStandardError(Int32 bufferSize) {
  return nullptr;
}

void Console::SetIn(TextReader newIn) {
}

void Console::SetOut(TextWriter newOut) {
}

void Console::SetError(TextWriter newError) {
}

void Console::CheckNonNull(Object obj, String paramName) {
}

Int32 Console::Read() {
  return Int32();
}

String Console::ReadLine() {
  return nullptr;
}

void Console::WriteLine() {
  get_Out()->WriteLine();
}

void Console::WriteLine(Boolean value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Char value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Array<Char> buffer) {
  get_Out()->WriteLine(buffer);
}

void Console::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  get_Out()->WriteLine(buffer, index, count);
}

void Console::WriteLine(Decimal value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Double value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Single value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Int32 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(UInt32 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Int64 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(UInt64 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Object value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(String value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(String format, Object arg0) {
  get_Out()->WriteLine(format, arg0);
}

void Console::WriteLine(String format, Object arg0, Object arg1) {
  get_Out()->WriteLine(format, arg0, arg1);
}

void Console::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  get_Out()->WriteLine(format, arg0, arg1, arg2);
}

void Console::WriteLine(String format, Array<Object> arg) {
  if (arg == nullptr) {
    get_Out()->WriteLine(format, nullptr, nullptr);
  } else {
    get_Out()->WriteLine(format, arg);
  }
}

void Console::Write(String format, Object arg0) {
}

void Console::Write(String format, Object arg0, Object arg1) {
}

void Console::Write(String format, Object arg0, Object arg1, Object arg2) {
}

void Console::Write(String format, Array<Object> arg) {
}

void Console::Write(Boolean value) {
}

void Console::Write(Char value) {
}

void Console::Write(Array<Char> buffer) {
}

void Console::Write(Array<Char> buffer, Int32 index, Int32 count) {
}

void Console::Write(Double value) {
}

void Console::Write(Decimal value) {
}

void Console::Write(Single value) {
}

void Console::Write(Int32 value) {
}

void Console::Write(UInt32 value) {
}

void Console::Write(Int64 value) {
}

void Console::Write(UInt64 value) {
}

void Console::Write(Object value) {
}

void Console::Write(String value) {
}

Boolean Console::HandleBreakEvent(ConsoleSpecialKey controlKey) {
  return Boolean();
}

void Console::SCtor() {
}

} // namespace System::Console::System::ConsoleNamespace
