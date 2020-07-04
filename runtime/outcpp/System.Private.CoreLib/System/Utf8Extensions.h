#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARDS(Rune)
FORWARDS(Utf8Span)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char8)
FORWARDS(Byte)
FORWARD(Utf8String)
FORWARDS(Int32)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(Index)
FORWARDS(Range)
namespace Utf8ExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class Utf8Extensions {
  public: static ReadOnlySpan<Byte> AsBytes(ReadOnlySpan<Char8> text);
  public: static ReadOnlySpan<Byte> AsBytes(Utf8String text);
  public: static ReadOnlySpan<Byte> AsBytes(Utf8String text, Int32 start);
  public: static ReadOnlySpan<Byte> AsBytes(Utf8String text, Int32 start, Int32 length);
  public: static Utf8Span AsSpan(Utf8String text);
  public: static Utf8Span AsSpan(Utf8String text, Int32 start);
  public: static Utf8Span AsSpan(Utf8String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char8> AsMemory(Utf8String text);
  public: static ReadOnlyMemory<Char8> AsMemory(Utf8String text, Int32 start);
  public: static ReadOnlyMemory<Char8> AsMemory(Utf8String text, Index startIndex);
  public: static ReadOnlyMemory<Char8> AsMemory(Utf8String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Char8> AsMemory(Utf8String text, Range range);
  public: static ReadOnlyMemory<Byte> AsMemoryBytes(Utf8String text);
  public: static ReadOnlyMemory<Byte> AsMemoryBytes(Utf8String text, Int32 start);
  public: static ReadOnlyMemory<Byte> AsMemoryBytes(Utf8String text, Index startIndex);
  public: static ReadOnlyMemory<Byte> AsMemoryBytes(Utf8String text, Int32 start, Int32 length);
  public: static ReadOnlyMemory<Byte> AsMemoryBytes(Utf8String text, Range range);
  public: static Utf8String ToUtf8String(Rune rune);
};
} // namespace Utf8ExtensionsNamespace
using Utf8Extensions = Utf8ExtensionsNamespace::Utf8Extensions;
} // namespace System::Private::CoreLib::System
