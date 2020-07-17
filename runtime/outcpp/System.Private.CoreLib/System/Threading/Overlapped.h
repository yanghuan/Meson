#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(OverlappedData)
namespace OverlappedNamespace {
CLASS(Overlapped) {
  public: IAsyncResult get_AsyncResult();
  public: void set_AsyncResult(IAsyncResult value);
  public: Int32 get_OffsetLow();
  public: void set_OffsetLow(Int32 value);
  public: Int32 get_OffsetHigh();
  public: void set_OffsetHigh(Int32 value);
  public: Int32 get_EventHandle();
  public: void set_EventHandle(Int32 value);
  public: IntPtr get_EventHandleIntPtr();
  public: void set_EventHandleIntPtr(IntPtr value);
  public: void Ctor();
  public: void Ctor(Int32 offsetLo, Int32 offsetHi, IntPtr hEvent, IAsyncResult ar);
  public: void Ctor(Int32 offsetLo, Int32 offsetHi, Int32 hEvent, IAsyncResult ar);
  public: NativeOverlapped* Pack(IOCompletionCallback iocb);
  public: NativeOverlapped* Pack(IOCompletionCallback iocb, Object userData);
  public: NativeOverlapped* UnsafePack(IOCompletionCallback iocb);
  public: NativeOverlapped* UnsafePack(IOCompletionCallback iocb, Object userData);
  public: static Overlapped Unpack(NativeOverlapped* nativeOverlappedPtr);
  public: static void Free(NativeOverlapped* nativeOverlappedPtr);
  private: OverlappedData _overlappedData;
};
} // namespace OverlappedNamespace
using Overlapped = OverlappedNamespace::Overlapped;
} // namespace System::Private::CoreLib::System::Threading
