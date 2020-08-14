#include "AbandonedMutexException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Threading::AbandonedMutexExceptionNamespace {
Mutex AbandonedMutexException___::get_Mutex() {
  return _mutex;
}

Int32 AbandonedMutexException___::get_MutexIndex() {
  return _mutexIndex;
}

void AbandonedMutexException___::ctor() {
  _mutexIndex = -1;
  SystemException::ctor(SR::get_Threading_AbandonedMutexException());
  Exception::set_HResult = -2146233043;
}

void AbandonedMutexException___::ctor(String message) {
  _mutexIndex = -1;
  SystemException::ctor(message);
  Exception::set_HResult = -2146233043;
}

void AbandonedMutexException___::ctor(String message, Exception inner) {
  _mutexIndex = -1;
  SystemException::ctor(message, inner);
  Exception::set_HResult = -2146233043;
}

void AbandonedMutexException___::ctor(Int32 location, WaitHandle handle) {
  _mutexIndex = -1;
  SystemException::ctor(SR::get_Threading_AbandonedMutexException());
  Exception::set_HResult = -2146233043;
  SetupException(location, handle);
}

void AbandonedMutexException___::ctor(String message, Int32 location, WaitHandle handle) {
  _mutexIndex = -1;
  SystemException::ctor(message);
  Exception::set_HResult = -2146233043;
  SetupException(location, handle);
}

void AbandonedMutexException___::ctor(String message, Exception inner, Int32 location, WaitHandle handle) {
  _mutexIndex = -1;
  SystemException::ctor(message, inner);
  Exception::set_HResult = -2146233043;
  SetupException(location, handle);
}

void AbandonedMutexException___::ctor(SerializationInfo info, StreamingContext context) {
  _mutexIndex = -1;
  SystemException::ctor(info, context);
}

void AbandonedMutexException___::SetupException(Int32 location, WaitHandle handle) {
  _mutexIndex = location;
  _mutex = (rt::as<Mutex>(handle));
}

} // namespace System::Private::CoreLib::System::Threading::AbandonedMutexExceptionNamespace
