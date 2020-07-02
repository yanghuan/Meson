#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(Overlapped)
namespace OverlappedDataNamespace {
CLASS(OverlappedData) {
  public: Int32& get_OffsetLow();
  public: Int32& get_OffsetHigh();
  public: IntPtr& get_EventHandle();
  public: NativeOverlapped* Pack(IOCompletionCallback iocb, Object userData);
  public: NativeOverlapped* UnsafePack(IOCompletionCallback iocb, Object userData);
  private: NativeOverlapped* AllocateNativeOverlapped();
  public: static void FreeNativeOverlapped(NativeOverlapped* nativeOverlappedPtr);
  public: static OverlappedData GetOverlappedFromNative(NativeOverlapped* nativeOverlappedPtr);
  public: static void CheckVMForIOPacket(NativeOverlapped*& pNativeOverlapped, UInt32& errorCode, UInt32& numBytes);
  public: IAsyncResult _asyncResult;
  public: Object _callback;
  public: Overlapped _overlapped;
  private: Object _userObject;
  private: NativeOverlapped* _pNativeOverlapped;
  private: IntPtr _eventHandle;
  private: Int32 _offsetLow;
  private: Int32 _offsetHigh;
};
} // namespace OverlappedDataNamespace
using OverlappedData = OverlappedDataNamespace::OverlappedData;
} // namespace System::Private::CoreLib::System::Threading
