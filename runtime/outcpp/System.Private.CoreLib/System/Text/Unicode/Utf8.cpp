#include "Utf8-dep.h"

namespace System::Private::CoreLib::System::Text::Unicode::Utf8Namespace {
OperationStatus Utf8::FromUtf16(ReadOnlySpan<Char> source, Span<Byte> destination, Int32& charsRead, Int32& bytesWritten, Boolean replaceInvalidSequences, Boolean isFinalBlock) {
  return OperationStatus();
};
OperationStatus Utf8::ToUtf16(ReadOnlySpan<Byte> source, Span<Char> destination, Int32& bytesRead, Int32& charsWritten, Boolean replaceInvalidSequences, Boolean isFinalBlock) {
  return OperationStatus();
};
} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8Namespace
