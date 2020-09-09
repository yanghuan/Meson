#pragma once

#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus : int32_t;
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Text::Unicode {
namespace Utf8Namespace {
using namespace System::Buffers;
class Utf8 {
  public: static OperationStatus FromUtf16(ReadOnlySpan<Char> source, Span<Byte> destination, Int32& charsRead, Int32& bytesWritten, Boolean replaceInvalidSequences = true, Boolean isFinalBlock = true);
  public: static OperationStatus ToUtf16(ReadOnlySpan<Byte> source, Span<Char> destination, Int32& bytesRead, Int32& charsWritten, Boolean replaceInvalidSequences = true, Boolean isFinalBlock = true);
};
} // namespace Utf8Namespace
using Utf8 = Utf8Namespace::Utf8;
} // namespace System::Private::CoreLib::System::Text::Unicode
