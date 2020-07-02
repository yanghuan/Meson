#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int64)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(ArraySegment, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS(Memory, T)
FORWARDS(ReadOnlyMemory, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
enum class SeekOrigin;
namespace MemoryStreamNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(MemoryStream) {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
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
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  public: Int32 ReadByte();
  public: void CopyTo(Stream destination, Int32 bufferSize);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  public: Int64 Seek(Int64 offset, SeekOrigin loc);
  public: void SetLength(Int64 value);
  public: Array<Byte> ToArray();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
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
