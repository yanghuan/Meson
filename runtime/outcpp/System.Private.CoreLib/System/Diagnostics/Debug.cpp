#include "Debug-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace {
Boolean Debug::get_AutoFlush() {
  return Boolean();
}

void Debug::set_AutoFlush(Boolean value) {
}

Int32 Debug::get_IndentLevel() {
  return Int32();
}

void Debug::set_IndentLevel(Int32 value) {
}

Int32 Debug::get_IndentSize() {
  return Int32();
}

void Debug::set_IndentSize(Int32 value) {
}

DebugProvider Debug::SetProvider(DebugProvider provider) {
  return nullptr;
}

void Debug::Close() {
}

void Debug::Flush() {
}

void Debug::Indent() {
}

void Debug::Unindent() {
}

void Debug::Print(String message) {
}

void Debug::Print(String format, Array<Object> args) {
}

void Debug::Assert(Boolean condition) {
}

void Debug::Assert(Boolean condition, String message) {
}

void Debug::Assert(Boolean condition, String message, String detailMessage) {
}

void Debug::ContractFailure(String message, String detailMessage, String failureKindMessage) {
}

void Debug::Fail(String message) {
}

void Debug::Fail(String message, String detailMessage) {
}

void Debug::Assert(Boolean condition, String message, String detailMessageFormat, Array<Object> args) {
}

void Debug::WriteLine(String message) {
}

void Debug::Write(String message) {
}

void Debug::WriteLine(Object value) {
}

void Debug::WriteLine(Object value, String category) {
}

void Debug::WriteLine(String format, Array<Object> args) {
}

void Debug::WriteLine(String message, String category) {
}

void Debug::Write(Object value) {
}

void Debug::Write(String message, String category) {
}

void Debug::Write(Object value, String category) {
}

void Debug::WriteIf(Boolean condition, String message) {
}

void Debug::WriteIf(Boolean condition, Object value) {
}

void Debug::WriteIf(Boolean condition, String message, String category) {
}

void Debug::WriteIf(Boolean condition, Object value, String category) {
}

void Debug::WriteLineIf(Boolean condition, Object value) {
}

void Debug::WriteLineIf(Boolean condition, Object value, String category) {
}

void Debug::WriteLineIf(Boolean condition, String message) {
}

void Debug::WriteLineIf(Boolean condition, String message, String category) {
}

void Debug::SCtor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebugNamespace
