#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Span, T)
FORWARDS(Memory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(ReadOnlyMemory, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeBuffer)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class FileAccess;
enum class SeekOrigin;
namespace UnmanagedMemoryStreamNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(UnmanagedMemoryStream) {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int64 get_Length();
  public: Int64 get_Capacity();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: Byte* get_PositionPointer();
  public: void set_PositionPointer(Byte* value);
  protected: void Initialize(SafeBuffer buffer, Int64 offset, Int64 length, FileAccess access);
  protected: void Initialize(Byte* pointer, Int64 length, Int64 capacity, FileAccess access);
  protected: void Dispose(Boolean disposing);
  private: void EnsureNotClosed();
  private: void EnsureReadable();
  private: void EnsureWriteable();
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Int32 ReadCore(Span<Byte> buffer);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  public: Int32 ReadByte();
  public: Int64 Seek(Int64 offset, SeekOrigin loc);
  public: void SetLength(Int64 value);
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: void WriteCore(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  public: void WriteByte(Byte value);
  private: SafeBuffer _buffer;
  private: Byte* _mem;
  private: Int64 _length;
  private: Int64 _capacity;
  private: Int64 _position;
  private: Int64 _offset;
  private: FileAccess _access;
  private: Boolean _isOpen;
  private: Task<Int32> _lastReadTask;
};
} // namespace UnmanagedMemoryStreamNamespace
using UnmanagedMemoryStream = UnmanagedMemoryStreamNamespace::UnmanagedMemoryStream;
} // namespace System::Private::CoreLib::System::IO
