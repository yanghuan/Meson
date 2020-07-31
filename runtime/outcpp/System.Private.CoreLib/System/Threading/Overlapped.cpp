#include "Overlapped-dep.h"

#include <System.Private.CoreLib/System/Threading/Overlapped-dep.h>

namespace System::Private::CoreLib::System::Threading::OverlappedNamespace {
IAsyncResult Overlapped___::get_AsyncResult() {
  return nullptr;
}

void Overlapped___::set_AsyncResult(IAsyncResult value) {
}

Int32 Overlapped___::get_OffsetLow() {
  return Int32();
}

void Overlapped___::set_OffsetLow(Int32 value) {
}

Int32 Overlapped___::get_OffsetHigh() {
  return Int32();
}

void Overlapped___::set_OffsetHigh(Int32 value) {
}

Int32 Overlapped___::get_EventHandle() {
  return Int32();
}

void Overlapped___::set_EventHandle(Int32 value) {
}

IntPtr Overlapped___::get_EventHandleIntPtr() {
  return IntPtr();
}

void Overlapped___::set_EventHandleIntPtr(IntPtr value) {
}

void Overlapped___::Ctor() {
}

void Overlapped___::Ctor(Int32 offsetLo, Int32 offsetHi, IntPtr hEvent, IAsyncResult ar) {
}

void Overlapped___::Ctor(Int32 offsetLo, Int32 offsetHi, Int32 hEvent, IAsyncResult ar) {
}

NativeOverlapped* Overlapped___::Pack(IOCompletionCallback iocb) {
  return nullptr;
}

NativeOverlapped* Overlapped___::Pack(IOCompletionCallback iocb, Object userData) {
  return nullptr;
}

NativeOverlapped* Overlapped___::UnsafePack(IOCompletionCallback iocb) {
  return nullptr;
}

NativeOverlapped* Overlapped___::UnsafePack(IOCompletionCallback iocb, Object userData) {
  return nullptr;
}

Overlapped Overlapped___::Unpack(NativeOverlapped* nativeOverlappedPtr) {
  return nullptr;
}

void Overlapped___::Free(NativeOverlapped* nativeOverlappedPtr) {
}

} // namespace System::Private::CoreLib::System::Threading::OverlappedNamespace
