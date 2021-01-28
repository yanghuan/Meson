#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/Stream.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(ArraySegment, T)
FORWARDS(Byte)
FORWARD_(Func)
FORWARDS(Int64)
FORWARDS(Memory, T)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Buffers {
FORWARD(ReadOnlySpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
namespace MemoryStreamNamespace {
using namespace System::Buffers;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(MemoryStream) : public Stream::in {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void ctor();
  public: void ctor(Int32 capacity);
  public: void ctor(Array<Byte> buffer);
  public: void ctor(Array<Byte> buffer, Boolean writable);
  public: void ctor(Array<Byte> buffer, Int32 index, Int32 count);
  public: void ctor(Array<Byte> buffer, Int32 index, Int32 count, Boolean writable);
  public: void ctor(Array<Byte> buffer, Int32 index, Int32 count, Boolean writable, Boolean publiclyVisible);
  private: void EnsureNotClosed();
  private: void EnsureWriteable();
  protected: void Dispose(Boolean disposing);
  private: Boolean EnsureCapacity(Int32 value);
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: Array<Byte> GetBuffer();
  public: Boolean TryGetBuffer(ArraySegment<Byte>& buffer);
  public: Array<Byte> InternalGetBuffer();
  public: Int32 InternalGetPosition();
  public: ReadOnlySpan<Byte> InternalReadSpan(Int32 count);
  public: Int32 InternalEmulateRead(Int32 count);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Byte> buffer, T0 cancellationToken = rt::default__);
  public: Int32 ReadByte();
  public: void CopyTo(Stream destination, Int32 bufferSize);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  public: void CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize);
  public: Task<> CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken);
  public: Int64 Seek(Int64 offset, SeekOrigin loc);
  public: void SetLength(Int64 value);
  public: Array<Byte> ToArray();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, T0 cancellationToken = rt::default__);
  public: void WriteByte(Byte value);
  public: void WriteTo(Stream stream);
  private: Array<Byte> _buffer;
  private: Int32 _origin;
  private: Int32 _position;
  private: Int32 _length;
  private: Int32 _capacity;
  private: Boolean _expandable;
  private: Boolean _writable;
  private: Boolean _exposable;
  private: Boolean _isOpen;
  private: Task<Int32> _lastReadTask;
};
} // namespace MemoryStreamNamespace
using MemoryStream = MemoryStreamNamespace::MemoryStream;
} // namespace System::Private::CoreLib::System::IO
