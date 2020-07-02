#include "ConsolePal-dep.h"

namespace System::Console::System::ConsolePalNamespace {
void ConsolePal::WindowsConsoleStream___::Dispose(Boolean disposing) {
  return void();
};
Int32 ConsolePal::WindowsConsoleStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
};
void ConsolePal::WindowsConsoleStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  return void();
};
void ConsolePal::WindowsConsoleStream___::Flush() {
  return void();
};
Int32 ConsolePal::WindowsConsoleStream___::ReadFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean isPipe, Int32& bytesRead, Boolean useFileAPIs) {
  return Int32();
};
Int32 ConsolePal::WindowsConsoleStream___::WriteFileNative(IntPtr hFile, Array<Byte> bytes, Int32 offset, Int32 count, Boolean useFileAPIs) {
  return Int32();
};
void ConsolePal::ControlCHandlerRegistrar___::Register() {
  return void();
};
void ConsolePal::ControlCHandlerRegistrar___::Unregister() {
  return void();
};
Boolean ConsolePal::ControlCHandlerRegistrar___::BreakEvent(Int32 controlType) {
  return Boolean();
};
IntPtr ConsolePal::get_InvalidHandleValue() {
  return IntPtr();
};
IntPtr ConsolePal::get_InputHandle() {
  return IntPtr();
};
IntPtr ConsolePal::get_OutputHandle() {
  return IntPtr();
};
IntPtr ConsolePal::get_ErrorHandle() {
  return IntPtr();
};
Encoding ConsolePal::get_InputEncoding() {
  return nullptr;
};
Encoding ConsolePal::get_OutputEncoding() {
  return nullptr;
};
Boolean ConsolePal::get_NumberLock() {
  return Boolean();
};
Boolean ConsolePal::get_CapsLock() {
  return Boolean();
};
Boolean ConsolePal::get_KeyAvailable() {
  return Boolean();
};
Boolean ConsolePal::get_TreatControlCAsInput() {
  return Boolean();
};
void ConsolePal::set_TreatControlCAsInput(Boolean value) {
  return void();
};
ConsoleColor ConsolePal::get_BackgroundColor() {
  return ConsoleColor();
};
void ConsolePal::set_BackgroundColor(ConsoleColor value) {
  return void();
};
ConsoleColor ConsolePal::get_ForegroundColor() {
  return ConsoleColor();
};
void ConsolePal::set_ForegroundColor(ConsoleColor value) {
  return void();
};
Int32 ConsolePal::get_CursorSize() {
  return Int32();
};
void ConsolePal::set_CursorSize(Int32 value) {
  return void();
};
Boolean ConsolePal::get_CursorVisible() {
  return Boolean();
};
void ConsolePal::set_CursorVisible(Boolean value) {
  return void();
};
Int32 ConsolePal::get_CursorLeft() {
  return Int32();
};
Int32 ConsolePal::get_CursorTop() {
  return Int32();
};
String ConsolePal::get_Title() {
  return nullptr;
};
void ConsolePal::set_Title(String value) {
  return void();
};
Int32 ConsolePal::get_BufferWidth() {
  return Int32();
};
void ConsolePal::set_BufferWidth(Int32 value) {
  return void();
};
Int32 ConsolePal::get_BufferHeight() {
  return Int32();
};
void ConsolePal::set_BufferHeight(Int32 value) {
  return void();
};
Int32 ConsolePal::get_LargestWindowWidth() {
  return Int32();
};
Int32 ConsolePal::get_LargestWindowHeight() {
  return Int32();
};
Int32 ConsolePal::get_WindowLeft() {
  return Int32();
};
void ConsolePal::set_WindowLeft(Int32 value) {
  return void();
};
Int32 ConsolePal::get_WindowTop() {
  return Int32();
};
void ConsolePal::set_WindowTop(Int32 value) {
  return void();
};
Int32 ConsolePal::get_WindowWidth() {
  return Int32();
};
void ConsolePal::set_WindowWidth(Int32 value) {
  return void();
};
Int32 ConsolePal::get_WindowHeight() {
  return Int32();
};
void ConsolePal::set_WindowHeight(Int32 value) {
  return void();
};
Boolean ConsolePal::IsWindows7() {
  return Boolean();
};
Stream ConsolePal::OpenStandardInput() {
  return nullptr;
};
Stream ConsolePal::OpenStandardOutput() {
  return nullptr;
};
Stream ConsolePal::OpenStandardError() {
  return nullptr;
};
Stream ConsolePal::GetStandardFile(Int32 handleType, FileAccess access) {
  return nullptr;
};
Boolean ConsolePal::ConsoleHandleIsWritable(IntPtr outErrHandle) {
  return Boolean();
};
void ConsolePal::SetConsoleInputEncoding(Encoding enc) {
  return void();
};
void ConsolePal::SetConsoleOutputEncoding(Encoding enc) {
  return void();
};
Boolean ConsolePal::GetUseFileAPIs(Int32 handleType) {
  return Boolean();
};
Boolean ConsolePal::IsInputRedirectedCore() {
  return Boolean();
};
Boolean ConsolePal::IsOutputRedirectedCore() {
  return Boolean();
};
Boolean ConsolePal::IsErrorRedirectedCore() {
  return Boolean();
};
Boolean ConsolePal::IsHandleRedirected(IntPtr handle) {
  return Boolean();
};
TextReader ConsolePal::GetOrCreateReader() {
  return nullptr;
};
Boolean ConsolePal::IsKeyDownEvent(Interop::InputRecord ir) {
  return Boolean();
};
Boolean ConsolePal::IsModKey(Interop::InputRecord ir) {
  return Boolean();
};
Boolean ConsolePal::IsAltKeyDown(Interop::InputRecord ir) {
  return Boolean();
};
ConsoleKeyInfo ConsolePal::ReadKey(Boolean intercept) {
  return ConsoleKeyInfo();
};
void ConsolePal::ResetColor() {
  return void();
};
void ConsolePal::Beep() {
  return void();
};
void ConsolePal::Beep(Int32 frequency, Int32 duration) {
  return void();
};
void ConsolePal::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
  return void();
};
void ConsolePal::Clear() {
  return void();
};
void ConsolePal::SetCursorPosition(Int32 left, Int32 top) {
  return void();
};
void ConsolePal::SetBufferSize(Int32 width, Int32 height) {
  return void();
};
void ConsolePal::SetWindowPosition(Int32 left, Int32 top) {
  return void();
};
void ConsolePal::SetWindowSize(Int32 width, Int32 height) {
  return void();
};
Interop::Kernel32::in::Color ConsolePal::ConsoleColorToColorAttribute(ConsoleColor color, Boolean isBackground) {
  return Interop::Kernel32::in::Color();
};
ConsoleColor ConsolePal::ColorAttributeToConsoleColor(Interop::Kernel32::in::Color c) {
  return ConsoleColor();
};
Interop::Kernel32::in::CONSOLE_SCREEN_BUFFER_INFO ConsolePal::GetBufferInfo() {
  return Interop::Kernel32::in::CONSOLE_SCREEN_BUFFER_INFO();
};
Interop::Kernel32::in::CONSOLE_SCREEN_BUFFER_INFO ConsolePal::GetBufferInfo(Boolean throwOnNoConsole, Boolean& succeeded) {
  return Interop::Kernel32::in::CONSOLE_SCREEN_BUFFER_INFO();
};
} // namespace System::Console::System::ConsolePalNamespace
