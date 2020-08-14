#include "Error-dep.h"

#include <System.Private.CoreLib/System/IO/EndOfStreamException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::IO::ErrorNamespace {
Exception Error::GetStreamIsClosed() {
  return rt::newobj<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
}

Exception Error::GetEndOfFile() {
  return rt::newobj<EndOfStreamException>(SR::get_IO_EOF_ReadBeyondEOF());
}

Exception Error::GetFileNotOpen() {
  return rt::newobj<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_FileClosed());
}

Exception Error::GetReadNotSupported() {
  return rt::newobj<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
}

Exception Error::GetSeekNotSupported() {
  return rt::newobj<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

Exception Error::GetWriteNotSupported() {
  return rt::newobj<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
}

} // namespace System::Private::CoreLib::System::IO::ErrorNamespace
