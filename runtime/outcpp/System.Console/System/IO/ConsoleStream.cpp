#include "ConsoleStream-dep.h"

#include <System.Console/System/IO/Error-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/MarshalByRefObject-dep.h>

namespace System::Console::System::IO::ConsoleStreamNamespace {
using namespace ::System::Private::CoreLib::System;

Boolean ConsoleStream___::get_CanRead() {
  return _canRead;
}

Boolean ConsoleStream___::get_CanWrite() {
  return _canWrite;
}

Boolean ConsoleStream___::get_CanSeek() {
  return false;
}

Int64 ConsoleStream___::get_Length() {
  rt::throw_exception(Error::GetSeekNotSupported());
}

Int64 ConsoleStream___::get_Position() {
  rt::throw_exception(Error::GetSeekNotSupported());
}

void ConsoleStream___::set_Position(Int64 value) {
  rt::throw_exception(Error::GetSeekNotSupported());
}

void ConsoleStream___::ctor(FileAccess access) {
  _canRead = ((access & FileAccess::Read) == FileAccess::Read);
  _canWrite = ((access & FileAccess::Write) == FileAccess::Write);
}

void ConsoleStream___::Dispose(Boolean disposing) {
  _canRead = false;
  _canWrite = false;
  MarshalByRefObject->Dispose(disposing);
}

void ConsoleStream___::Flush() {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
}

void ConsoleStream___::SetLength(Int64 value) {
  rt::throw_exception(Error::GetSeekNotSupported());
}

Int64 ConsoleStream___::Seek(Int64 offset, SeekOrigin origin) {
  rt::throw_exception(Error::GetSeekNotSupported());
}

void ConsoleStream___::ValidateRead(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  if (offset < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((offset < 0) ? "offset" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (!_canRead) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
}

void ConsoleStream___::ValidateWrite(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  if (offset < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((offset < 0) ? "offset" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (!_canWrite) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
}

} // namespace System::Console::System::IO::ConsoleStreamNamespace
