#include "Debug-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace {
Boolean Debug::get_AutoFlush() {
  return Boolean();
};
void Debug::set_AutoFlush(Boolean value) {
  return void();
};
Int32 Debug::get_IndentLevel() {
  return Int32();
};
void Debug::set_IndentLevel(Int32 value) {
  return void();
};
Int32 Debug::get_IndentSize() {
  return Int32();
};
void Debug::set_IndentSize(Int32 value) {
  return void();
};
DebugProvider Debug::SetProvider(DebugProvider provider) {
  return nullptr;
};
void Debug::Close() {
  return void();
};
void Debug::Flush() {
  return void();
};
void Debug::Indent() {
  return void();
};
void Debug::Unindent() {
  return void();
};
void Debug::Print(String message) {
  return void();
};
void Debug::Print(String format, Array<Object> args) {
  return void();
};
void Debug::Assert(Boolean condition) {
  return void();
};
void Debug::Assert(Boolean condition, String message) {
  return void();
};
void Debug::Assert(Boolean condition, String message, String detailMessage) {
  return void();
};
void Debug::ContractFailure(String message, String detailMessage, String failureKindMessage) {
  return void();
};
void Debug::Fail(String message) {
  return void();
};
void Debug::Fail(String message, String detailMessage) {
  return void();
};
void Debug::Assert(Boolean condition, String message, String detailMessageFormat, Array<Object> args) {
  return void();
};
void Debug::WriteLine(String message) {
  return void();
};
void Debug::Write(String message) {
  return void();
};
void Debug::WriteLine(Object value) {
  return void();
};
void Debug::WriteLine(Object value, String category) {
  return void();
};
void Debug::WriteLine(String format, Array<Object> args) {
  return void();
};
void Debug::WriteLine(String message, String category) {
  return void();
};
void Debug::Write(Object value) {
  return void();
};
void Debug::Write(String message, String category) {
  return void();
};
void Debug::Write(Object value, String category) {
  return void();
};
void Debug::WriteIf(Boolean condition, String message) {
  return void();
};
void Debug::WriteIf(Boolean condition, Object value) {
  return void();
};
void Debug::WriteIf(Boolean condition, String message, String category) {
  return void();
};
void Debug::WriteIf(Boolean condition, Object value, String category) {
  return void();
};
void Debug::WriteLineIf(Boolean condition, Object value) {
  return void();
};
void Debug::WriteLineIf(Boolean condition, Object value, String category) {
  return void();
};
void Debug::WriteLineIf(Boolean condition, String message) {
  return void();
};
void Debug::WriteLineIf(Boolean condition, String message, String category) {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace
