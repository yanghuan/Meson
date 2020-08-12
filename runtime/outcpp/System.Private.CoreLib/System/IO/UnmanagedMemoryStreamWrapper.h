#pragma once

#include <System.Private.CoreLib/System/IO/MemoryStream.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(Memory, T)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
FORWARD(Stream)
FORWARD(UnmanagedMemoryStream)
namespace UnmanagedMemoryStreamWrapperNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(UnmanagedMemoryStreamWrapper) : public MemoryStream::in {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void ctor(UnmanagedMemoryStream stream);
  protected: void Dispose(Boolean disposing);
  public: void Flush();
  public: Array<Byte> GetBuffer();
  public: Boolean TryGetBuffer(ArraySegment<Byte>& buffer);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Int32 ReadByte();
  public: Int64 Seek(Int64 offset, SeekOrigin loc);
  public: Array<Byte> ToArray();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: void WriteByte(Byte value);
  public: void WriteTo(Stream stream);
  public: void SetLength(Int64 value);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  private: UnmanagedMemoryStream _unmanagedStream;
};
} // namespace UnmanagedMemoryStreamWrapperNamespace
using UnmanagedMemoryStreamWrapper = UnmanagedMemoryStreamWrapperNamespace::UnmanagedMemoryStreamWrapper;
} // namespace System::Private::CoreLib::System::IO
