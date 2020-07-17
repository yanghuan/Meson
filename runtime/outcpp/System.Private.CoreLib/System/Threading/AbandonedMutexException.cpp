#include "AbandonedMutexException-dep.h"

namespace System::Private::CoreLib::System::Threading::AbandonedMutexExceptionNamespace {
Mutex AbandonedMutexException___::get_Mutex() {
  return nullptr;
};

Int32 AbandonedMutexException___::get_MutexIndex() {
  return Int32();
};

void AbandonedMutexException___::Ctor() {
};

void AbandonedMutexException___::Ctor(String message) {
};

void AbandonedMutexException___::Ctor(String message, Exception inner) {
};

void AbandonedMutexException___::Ctor(Int32 location, WaitHandle handle) {
};

void AbandonedMutexException___::Ctor(String message, Int32 location, WaitHandle handle) {
};

void AbandonedMutexException___::Ctor(String message, Exception inner, Int32 location, WaitHandle handle) {
};

void AbandonedMutexException___::Ctor(SerializationInfo info, StreamingContext context) {
};

void AbandonedMutexException___::SetupException(Int32 location, WaitHandle handle) {
};

} // namespace System::Private::CoreLib::System::Threading::AbandonedMutexExceptionNamespace
