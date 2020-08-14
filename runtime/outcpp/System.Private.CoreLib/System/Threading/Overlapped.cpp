#include "Overlapped-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Threading/Overlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/OverlappedData-dep.h>

namespace System::Private::CoreLib::System::Threading::OverlappedNamespace {
IAsyncResult Overlapped___::get_AsyncResult() {
  return _overlappedData->_asyncResult;
}

void Overlapped___::set_AsyncResult(IAsyncResult value) {
  _overlappedData->_asyncResult = value;
}

Int32 Overlapped___::get_OffsetLow() {
  return _overlappedData->get_OffsetLow();
}

void Overlapped___::set_OffsetLow(Int32 value) {
  _overlappedData->get_OffsetLow() = value;
}

Int32 Overlapped___::get_OffsetHigh() {
  return _overlappedData->get_OffsetHigh();
}

void Overlapped___::set_OffsetHigh(Int32 value) {
  _overlappedData->get_OffsetHigh() = value;
}

Int32 Overlapped___::get_EventHandle() {
  return get_EventHandleIntPtr().ToInt32();
}

void Overlapped___::set_EventHandle(Int32 value) {
  get_EventHandleIntPtr() = IntPtr(value);
}

IntPtr Overlapped___::get_EventHandleIntPtr() {
  return _overlappedData->get_EventHandle();
}

void Overlapped___::set_EventHandleIntPtr(IntPtr value) {
  _overlappedData->get_EventHandle() = value;
}

void Overlapped___::ctor() {
  _overlappedData = rt::newobj<OverlappedData>((Overlapped)this);
}

void Overlapped___::ctor(Int32 offsetLo, Int32 offsetHi, IntPtr hEvent, IAsyncResult ar) {
  _overlappedData->get_OffsetLow() = offsetLo;
  _overlappedData->get_OffsetHigh() = offsetHi;
  _overlappedData->get_EventHandle() = hEvent;
  _overlappedData->_asyncResult = ar;
}

void Overlapped___::ctor(Int32 offsetLo, Int32 offsetHi, Int32 hEvent, IAsyncResult ar) {
}

NativeOverlapped* Overlapped___::Pack(IOCompletionCallback iocb) {
  return Pack(iocb, nullptr);
}

NativeOverlapped* Overlapped___::Pack(IOCompletionCallback iocb, Object userData) {
  return _overlappedData->Pack(iocb, userData);
}

NativeOverlapped* Overlapped___::UnsafePack(IOCompletionCallback iocb) {
  return UnsafePack(iocb, nullptr);
}

NativeOverlapped* Overlapped___::UnsafePack(IOCompletionCallback iocb, Object userData) {
  return _overlappedData->UnsafePack(iocb, userData);
}

Overlapped Overlapped___::Unpack(NativeOverlapped* nativeOverlappedPtr) {
  if (nativeOverlappedPtr == nullptr) {
    rt::throw_exception<ArgumentNullException>("nativeOverlappedPtr");
  }
  return OverlappedData::in::GetOverlappedFromNative(nativeOverlappedPtr)->_overlapped;
}

void Overlapped___::Free(NativeOverlapped* nativeOverlappedPtr) {
  if (nativeOverlappedPtr == nullptr) {
    rt::throw_exception<ArgumentNullException>("nativeOverlappedPtr");
  }
  OverlappedData::in::GetOverlappedFromNative(nativeOverlappedPtr)->_overlapped->_overlappedData = nullptr;
  OverlappedData::in::FreeNativeOverlapped(nativeOverlappedPtr);
}

} // namespace System::Private::CoreLib::System::Threading::OverlappedNamespace
