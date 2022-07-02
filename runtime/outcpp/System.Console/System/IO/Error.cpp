#include "Error-dep.h"

#include <System.Console/System/SR-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>

namespace System::Console::System::IO::ErrorNamespace {
using namespace ::System::Private::CoreLib::System;

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

} // namespace System::Console::System::IO::ErrorNamespace
