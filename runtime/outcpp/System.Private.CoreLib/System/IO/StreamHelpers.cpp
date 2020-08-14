#include "StreamHelpers-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/SystemException-dep.h>

namespace System::Private::CoreLib::System::IO::StreamHelpersNamespace {
void StreamHelpers::ValidateCopyToArgs(Stream source, Stream destination, Int32 bufferSize) {
  if (destination == nullptr) {
    rt::throw_exception<ArgumentNullException>("destination");
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", bufferSize, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  Boolean canRead = source->get_CanRead();
  if (!canRead && !source->get_CanWrite()) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
  Boolean canWrite = destination->get_CanWrite();
  if (!canWrite && !destination->get_CanRead()) {
    rt::throw_exception<ObjectDisposedException>("destination", SR::get_ObjectDisposed_StreamClosed());
  }
  if (!canRead) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
  }
  if (!canWrite) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
  }
}

void StreamHelpers::ValidateCopyToArgs(Stream source, Delegate callback, Int32 bufferSize) {
  if ((Object)callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", bufferSize, SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (!source->get_CanRead()) {
    rt::throw_exception(source->get_CanWrite() ? ((SystemException)rt::newobj<NotSupportedException>(SR::get_NotSupported_UnreadableStream())) : ((SystemException)rt::newobj<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed())));
  }
}

} // namespace System::Private::CoreLib::System::IO::StreamHelpersNamespace
