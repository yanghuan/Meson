#include "UnmanagedMemoryStreamWrapper-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamWrapperNamespace {
Boolean UnmanagedMemoryStreamWrapper___::get_CanRead() {
  return _unmanagedStream->get_CanRead();
}

Boolean UnmanagedMemoryStreamWrapper___::get_CanSeek() {
  return _unmanagedStream->get_CanSeek();
}

Boolean UnmanagedMemoryStreamWrapper___::get_CanWrite() {
  return _unmanagedStream->get_CanWrite();
}

Int32 UnmanagedMemoryStreamWrapper___::get_Capacity() {
  return (Int32)_unmanagedStream->get_Capacity();
}

void UnmanagedMemoryStreamWrapper___::set_Capacity(Int32 value) {
  rt::throw_exception<IOException>(SR::get_IO_FixedCapacity());
}

Int64 UnmanagedMemoryStreamWrapper___::get_Length() {
  return _unmanagedStream->get_Length();
}

Int64 UnmanagedMemoryStreamWrapper___::get_Position() {
  return _unmanagedStream->get_Position();
}

void UnmanagedMemoryStreamWrapper___::set_Position(Int64 value) {
  _unmanagedStream->set_Position = value;
}

void UnmanagedMemoryStreamWrapper___::ctor(UnmanagedMemoryStream stream) {
  _unmanagedStream = stream;
}

void UnmanagedMemoryStreamWrapper___::Dispose(Boolean disposing) {
  try{
    if (disposing) {
      _unmanagedStream->Dispose();
    }
  } finally: {
    MemoryStream::Dispose(disposing);
  }
}

void UnmanagedMemoryStreamWrapper___::Flush() {
  _unmanagedStream->Flush();
}

Array<Byte> UnmanagedMemoryStreamWrapper___::GetBuffer() {
  rt::throw_exception<UnauthorizedAccessException>(SR::get_UnauthorizedAccess_MemStreamBuffer());
}

Boolean UnmanagedMemoryStreamWrapper___::TryGetBuffer(ArraySegment<Byte>& buffer) {
  buffer = ArraySegment<T>();
  return false;
}

Int32 UnmanagedMemoryStreamWrapper___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return _unmanagedStream->Read(buffer, offset, count);
}

Int32 UnmanagedMemoryStreamWrapper___::Read(Span<Byte> buffer) {
  return _unmanagedStream->Read(buffer);
}

Int32 UnmanagedMemoryStreamWrapper___::ReadByte() {
  return _unmanagedStream->ReadByte();
}

Int64 UnmanagedMemoryStreamWrapper___::Seek(Int64 offset, SeekOrigin loc) {
  return _unmanagedStream->Seek(offset, loc);
}

Array<Byte> UnmanagedMemoryStreamWrapper___::ToArray() {
  Array<Byte> array = rt::newarr<Array<Byte>>(_unmanagedStream->get_Length());
  _unmanagedStream->Read(array, 0, (Int32)_unmanagedStream->get_Length());
  return array;
}

void UnmanagedMemoryStreamWrapper___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  _unmanagedStream->Write(buffer, offset, count);
}

void UnmanagedMemoryStreamWrapper___::Write(ReadOnlySpan<Byte> buffer) {
  _unmanagedStream->Write(buffer);
}

void UnmanagedMemoryStreamWrapper___::WriteByte(Byte value) {
  _unmanagedStream->WriteByte(value);
}

void UnmanagedMemoryStreamWrapper___::WriteTo(Stream stream) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream", SR::get_ArgumentNull_Stream());
  }
  Array<Byte> array = ToArray();
  stream->Write(array, 0, array->get_Length());
}

void UnmanagedMemoryStreamWrapper___::SetLength(Int64 value) {
  MemoryStream::SetLength(value);
}

Task<> UnmanagedMemoryStreamWrapper___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  if (destination == nullptr) {
    rt::throw_exception<ArgumentNullException>("destination");
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (!get_CanRead() && !get_CanWrite()) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
  if (!destination->get_CanRead() && !destination->get_CanWrite()) {
    rt::throw_exception<ObjectDisposedException>("destination", SR::get_ObjectDisposed_StreamClosed());
  }
  if (!get_CanRead()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
  }
  if (!destination->get_CanWrite()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
  }
  return _unmanagedStream->CopyToAsync(destination, bufferSize, cancellationToken);
}

Task<> UnmanagedMemoryStreamWrapper___::FlushAsync(CancellationToken cancellationToken) {
  return _unmanagedStream->FlushAsync(cancellationToken);
}

Task<Int32> UnmanagedMemoryStreamWrapper___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return _unmanagedStream->ReadAsync(buffer, offset, count, cancellationToken);
}

ValueTask<Int32> UnmanagedMemoryStreamWrapper___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return _unmanagedStream->ReadAsync(buffer, cancellationToken);
}

Task<> UnmanagedMemoryStreamWrapper___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return _unmanagedStream->WriteAsync(buffer, offset, count, cancellationToken);
}

ValueTask<> UnmanagedMemoryStreamWrapper___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return _unmanagedStream->WriteAsync(buffer, cancellationToken);
}

} // namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamWrapperNamespace
