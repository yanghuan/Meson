#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IFormatProvider)
FORWARDS(ParamsArray)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace ValueStringBuilderNamespace {
struct ValueStringBuilder {
  public: Int32 get_Length();
  public: void set_Length(Int32 value);
  public: Int32 get_Capacity();
  public: Char& get_Item(Int32 index);
  public: Span<Char> get_RawChars();
  public: void AppendFormatHelper(IFormatProvider provider, String format, ParamsArray args);
  private: static void ThrowFormatError();
  public: void Ctor(Span<Char> initialBuffer);
  public: void Ctor(Int32 initialCapacity);
  public: void EnsureCapacity(Int32 capacity);
  public: String ToString();
  public: ReadOnlySpan<Char> AsSpan(Boolean terminate);
  public: ReadOnlySpan<Char> AsSpan();
  public: ReadOnlySpan<Char> AsSpan(Int32 start);
  public: ReadOnlySpan<Char> AsSpan(Int32 start, Int32 length);
  public: Boolean TryCopyTo(Span<Char> destination, Int32& charsWritten);
  public: void Insert(Int32 index, String s);
  public: void Append(Char c);
  public: void Append(String s);
  private: void AppendSlow(String s);
  public: void Append(Char c, Int32 count);
  public: void Append(Char* value, Int32 length);
  public: void Append(ReadOnlySpan<Char> value);
  public: Span<Char> AppendSpan(Int32 length);
  private: void GrowAndAppend(Char c);
  private: void Grow(Int32 additionalCapacityBeyondPos);
  public: void Dispose();
  public: void Ctor();
  private: Array<Char> _arrayToReturnToPool;
  private: Span<Char> _chars;
  private: Int32 _pos;
};
} // namespace ValueStringBuilderNamespace
using ValueStringBuilder = ValueStringBuilderNamespace::ValueStringBuilder;
} // namespace System::Private::CoreLib::System::Text
