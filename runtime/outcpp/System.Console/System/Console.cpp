#include "Console-dep.h"

namespace System::Console::System::ConsoleNamespace {
TextReader Console::get_In() {
  return nullptr;
};
Encoding Console::get_InputEncoding() {
  return nullptr;
};
void Console::set_InputEncoding(Encoding value) {
  return void();
};
Encoding Console::get_OutputEncoding() {
  return nullptr;
};
void Console::set_OutputEncoding(Encoding value) {
  return void();
};
Boolean Console::get_KeyAvailable() {
  return Boolean();
};
TextWriter Console::get_Out() {
  return nullptr;
};
TextWriter Console::get_Error() {
  return nullptr;
};
Boolean Console::get_IsInputRedirected() {
  return Boolean();
};
Boolean Console::get_IsOutputRedirected() {
  return Boolean();
};
Boolean Console::get_IsErrorRedirected() {
  return Boolean();
};
Int32 Console::get_CursorSize() {
  return Int32();
};
void Console::set_CursorSize(Int32 value) {
  return void();
};
Boolean Console::get_NumberLock() {
  return Boolean();
};
Boolean Console::get_CapsLock() {
  return Boolean();
};
ConsoleColor Console::get_BackgroundColor() {
  return ConsoleColor();
};
void Console::set_BackgroundColor(ConsoleColor value) {
  return void();
};
ConsoleColor Console::get_ForegroundColor() {
  return ConsoleColor();
};
void Console::set_ForegroundColor(ConsoleColor value) {
  return void();
};
Int32 Console::get_BufferWidth() {
  return Int32();
};
void Console::set_BufferWidth(Int32 value) {
  return void();
};
Int32 Console::get_BufferHeight() {
  return Int32();
};
void Console::set_BufferHeight(Int32 value) {
  return void();
};
Int32 Console::get_WindowLeft() {
  return Int32();
};
void Console::set_WindowLeft(Int32 value) {
  return void();
};
Int32 Console::get_WindowTop() {
  return Int32();
};
void Console::set_WindowTop(Int32 value) {
  return void();
};
Int32 Console::get_WindowWidth() {
  return Int32();
};
void Console::set_WindowWidth(Int32 value) {
  return void();
};
Int32 Console::get_WindowHeight() {
  return Int32();
};
void Console::set_WindowHeight(Int32 value) {
  return void();
};
Int32 Console::get_LargestWindowWidth() {
  return Int32();
};
Int32 Console::get_LargestWindowHeight() {
  return Int32();
};
Boolean Console::get_CursorVisible() {
  return Boolean();
};
void Console::set_CursorVisible(Boolean value) {
  return void();
};
Int32 Console::get_CursorLeft() {
  return Int32();
};
void Console::set_CursorLeft(Int32 value) {
  return void();
};
Int32 Console::get_CursorTop() {
  return Int32();
};
void Console::set_CursorTop(Int32 value) {
  return void();
};
String Console::get_Title() {
  return nullptr;
};
void Console::set_Title(String value) {
  return void();
};
Boolean Console::get_TreatControlCAsInput() {
  return Boolean();
};
void Console::set_TreatControlCAsInput(Boolean value) {
  return void();
};
ConsoleKeyInfo Console::ReadKey() {
  return ConsoleKeyInfo();
};
ConsoleKeyInfo Console::ReadKey(Boolean intercept) {
  return ConsoleKeyInfo();
};
TextWriter Console::CreateOutputWriter(Stream outputStream) {
  return nullptr;
};
void Console::ResetColor() {
  return void();
};
void Console::SetBufferSize(Int32 width, Int32 height) {
  return void();
};
void Console::SetWindowPosition(Int32 left, Int32 top) {
  return void();
};
void Console::SetWindowSize(Int32 width, Int32 height) {
  return void();
};
void Console::Beep() {
  return void();
};
void Console::Beep(Int32 frequency, Int32 duration) {
  return void();
};
void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop) {
  return void();
};
void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
  return void();
};
void Console::Clear() {
  return void();
};
void Console::SetCursorPosition(Int32 left, Int32 top) {
  return void();
};
Stream Console::OpenStandardInput() {
  return nullptr;
};
Stream Console::OpenStandardInput(Int32 bufferSize) {
  return nullptr;
};
Stream Console::OpenStandardOutput() {
  return nullptr;
};
Stream Console::OpenStandardOutput(Int32 bufferSize) {
  return nullptr;
};
Stream Console::OpenStandardError() {
  return nullptr;
};
Stream Console::OpenStandardError(Int32 bufferSize) {
  return nullptr;
};
void Console::SetIn(TextReader newIn) {
  return void();
};
void Console::SetOut(TextWriter newOut) {
  return void();
};
void Console::SetError(TextWriter newError) {
  return void();
};
void Console::CheckNonNull(Object obj, String paramName) {
  return void();
};
Int32 Console::Read() {
  return Int32();
};
String Console::ReadLine() {
  return nullptr;
};
void Console::WriteLine() {
  return void();
};
void Console::WriteLine(Boolean value) {
  return void();
};
void Console::WriteLine(Char value) {
  return void();
};
void Console::WriteLine(Array<Char> buffer) {
  return void();
};
void Console::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  return void();
};
void Console::WriteLine(Decimal value) {
  return void();
};
void Console::WriteLine(Double value) {
  return void();
};
void Console::WriteLine(Single value) {
  return void();
};
void Console::WriteLine(Int32 value) {
  return void();
};
void Console::WriteLine(UInt32 value) {
  return void();
};
void Console::WriteLine(Int64 value) {
  return void();
};
void Console::WriteLine(UInt64 value) {
  return void();
};
void Console::WriteLine(Object value) {
  return void();
};
void Console::WriteLine(String value) {
  return void();
};
void Console::WriteLine(String format, Object arg0) {
  return void();
};
void Console::WriteLine(String format, Object arg0, Object arg1) {
  return void();
};
void Console::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  return void();
};
void Console::WriteLine(String format, Array<Object> arg) {
  return void();
};
void Console::Write(String format, Object arg0) {
  return void();
};
void Console::Write(String format, Object arg0, Object arg1) {
  return void();
};
void Console::Write(String format, Object arg0, Object arg1, Object arg2) {
  return void();
};
void Console::Write(String format, Array<Object> arg) {
  return void();
};
void Console::Write(Boolean value) {
  return void();
};
void Console::Write(Char value) {
  return void();
};
void Console::Write(Array<Char> buffer) {
  return void();
};
void Console::Write(Array<Char> buffer, Int32 index, Int32 count) {
  return void();
};
void Console::Write(Double value) {
  return void();
};
void Console::Write(Decimal value) {
  return void();
};
void Console::Write(Single value) {
  return void();
};
void Console::Write(Int32 value) {
  return void();
};
void Console::Write(UInt32 value) {
  return void();
};
void Console::Write(Int64 value) {
  return void();
};
void Console::Write(UInt64 value) {
  return void();
};
void Console::Write(Object value) {
  return void();
};
void Console::Write(String value) {
  return void();
};
Boolean Console::HandleBreakEvent(ConsoleSpecialKey controlKey) {
  return Boolean();
};
} // namespace System::Console::System::ConsoleNamespace
