#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(IDisposable)
FORWARDS(Memory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace MemoryMarshalNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
class MemoryMarshal {
  private: CLASS(_ToEnumerable_d__15, T) : public object {
    public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_, IEnumerator<T>, IDisposable, IEnumerator_>;
    private: T get_CurrentOfIEnumeratorT();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<T> GetEnumeratorOfIEnumerableT();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: T __2__current;
    private: Int32 __l__initialThreadId;
    private: ReadOnlyMemory<T> memory;
    public: ReadOnlyMemory<T> __3__memory;
    private: Int32 _i_5__2;
  };
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
