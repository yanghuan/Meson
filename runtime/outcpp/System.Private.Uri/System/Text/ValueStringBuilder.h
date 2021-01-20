#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System::Text {
namespace ValueStringBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
struct ValueStringBuilder : public valueType<ValueStringBuilder> {
  public: Int32 get_Length();
  public: explicit ValueStringBuilder(Span<Char> initialBuffer);
  public: explicit ValueStringBuilder(Int32 initialCapacity);
  public: void EnsureCapacity(Int32 capacity);
  public: String ToString();
  public: ReadOnlySpan<Char> AsSpan();
  public: ReadOnlySpan<Char> AsSpan(Int32 start);
  public: Boolean TryCopyTo(Span<Char> destination, Int32& charsWritten);
  public: void Append(Char c);
  public: void Append(ReadOnlySpan<Char> value);
  public: Span<Char> AppendSpan(Int32 length);
  private: void GrowAndAppend(Char c);
  private: void Grow(Int32 additionalCapacityBeyondPos);
  public: void Dispose();
  public: explicit ValueStringBuilder() {}
  private: Array<Char> _arrayToReturnToPool;
  private: Span<Char> _chars;
  private: Int32 _pos;
};
} // namespace ValueStringBuilderNamespace
using ValueStringBuilder = ValueStringBuilderNamespace::ValueStringBuilder;
} // namespace System::Private::Uri::System::Text
