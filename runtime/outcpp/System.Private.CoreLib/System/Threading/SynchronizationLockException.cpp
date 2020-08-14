#include "SynchronizationLockException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::SynchronizationLockExceptionNamespace {
void SynchronizationLockException___::ctor() {
  Exception::set_HResult = -2146233064;
}

void SynchronizationLockException___::ctor(String message) {
  Exception::set_HResult = -2146233064;
}

void SynchronizationLockException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233064;
}

void SynchronizationLockException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::SynchronizationLockExceptionNamespace
