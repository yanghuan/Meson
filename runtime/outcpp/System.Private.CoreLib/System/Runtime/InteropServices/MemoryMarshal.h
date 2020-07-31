#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Memory, T)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace MemoryMarshalNamespace {
using namespace Collections::Generic;
class MemoryMarshal : public Object::in {
  public: template <class T>
  static T& GetArrayDataReference(Array<T> array);
  public: template <class T>
  static Span<Byte> AsBytes(Span<T> span);
  public: template <class T>
  static ReadOnlySpan<Byte> AsBytes(ReadOnlySpan<T> span);
  public: template <class T>
  static Memory<T> AsMemory(ReadOnlyMemory<T> memory);
  public: template <class T>
  static T& GetReference(Span<T> span);
  public: template <class T>
  static T& GetReference(ReadOnlySpan<T> span);
  public: template <class T>
  static T& GetNonNullPinnableReference(Span<T> span);
  public: template <class T>
  static T& GetNonNullPinnableReference(ReadOnlySpan<T> span);
  public: template <class TFrom, class TTo>
  static Span<TTo> Cast(Span<TFrom> span);
  public: template <class TFrom, class TTo>
  static ReadOnlySpan<TTo> Cast(ReadOnlySpan<TFrom> span);
  public: template <class T>
  static Span<T> CreateSpan(T& reference, Int32 length);
  public: template <class T>
  static ReadOnlySpan<T> CreateReadOnlySpan(T& reference, Int32 length);
  public: template <class T>
  static Boolean TryGetArray(ReadOnlyMemory<T> memory, ArraySegment<T>& segment);
  public: template <class T, class TManager>
  static Boolean TryGetMemoryManager(ReadOnlyMemory<T> memory, TManager& manager);
  public: template <class T, class TManager>
  static Boolean TryGetMemoryManager(ReadOnlyMemory<T> memory, TManager& manager, Int32& start, Int32& length);
  public: template <class T>
  static IEnumerable<T> ToEnumerable(ReadOnlyMemory<T> memory);
  public: static Boolean TryGetString(ReadOnlyMemory<Char> memory, String& text, Int32& start, Int32& length);
  public: template <class T>
  static T Read(ReadOnlySpan<Byte> source);
  public: template <class T>
  static Boolean TryRead(ReadOnlySpan<Byte> source, T& value);
  public: template <class T>
  static void Write(Span<Byte> destination, T& value);
  public: template <class T>
  static Boolean TryWrite(Span<Byte> destination, T& value);
  public: template <class T>
  static T& AsRef(Span<Byte> span);
  public: template <class T>
  static T& AsRef(ReadOnlySpan<Byte> span);
  public: template <class T>
  static Memory<T> CreateFromPinnedArray(Array<T> array, Int32 start, Int32 length);
};
} // namespace MemoryMarshalNamespace
using MemoryMarshal = MemoryMarshalNamespace::MemoryMarshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
