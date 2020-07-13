#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Threading {
namespace WaitHandleNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
CLASS(WaitHandle) {
  public: enum class OpenExistingResult {
    Success = 0,
    NameNotFound = 1,
    PathNotFound = 2,
    NameInvalid = 3,
  };
  public: IntPtr get_Handle();
  public: void set_Handle(IntPtr value);
  public: SafeWaitHandle get_SafeWaitHandle();
  public: void set_SafeWaitHandle(SafeWaitHandle value);
  private: static Int32 WaitOneCore(IntPtr waitHandle, Int32 millisecondsTimeout);
  public: static Int32 WaitMultipleIgnoringSyncContext(Span<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  private: static Int32 WaitMultipleIgnoringSyncContext(IntPtr* waitHandles, Int32 numHandles, Boolean waitAll, Int32 millisecondsTimeout);
  private: static Int32 SignalAndWaitCore(IntPtr waitHandleToSignal, IntPtr waitHandleToWaitOn, Int32 millisecondsTimeout);
  private: static Int32 SignalAndWaitNative(IntPtr waitHandleToSignal, IntPtr waitHandleToWaitOn, Int32 millisecondsTimeout);
  public: static Int32 ToTimeoutMilliseconds(TimeSpan timeout);
  public: void Close();
  protected: void Dispose(Boolean explicitDisposing);
  public: void Dispose();
  public: Boolean WaitOne(Int32 millisecondsTimeout);
  private: Boolean WaitOneNoCheck(Int32 millisecondsTimeout);
  private: static Array<SafeWaitHandle> RentSafeWaitHandleArray(Int32 capacity);
  private: static void ReturnSafeWaitHandleArray(Array<SafeWaitHandle> safeWaitHandles);
  private: static void ObtainSafeWaitHandles(ReadOnlySpan<WaitHandle> waitHandles, Span<SafeWaitHandle> safeWaitHandles, Span<IntPtr> unsafeWaitHandles);
  private: static Int32 WaitMultiple(Array<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  private: static Int32 WaitMultiple(ReadOnlySpan<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  private: static Boolean SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout);
  public: Boolean WaitOne(TimeSpan timeout);
  public: Boolean WaitOne();
  public: Boolean WaitOne(Int32 millisecondsTimeout, Boolean exitContext);
  public: Boolean WaitOne(TimeSpan timeout, Boolean exitContext);
  public: static Boolean WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout);
  public: static Boolean WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout);
  public: static Boolean WaitAll(Array<WaitHandle> waitHandles);
  public: static Boolean WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext);
  public: static Boolean WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext);
  public: static Int32 WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout);
  public: static Int32 WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout);
  public: static Int32 WaitAny(Array<WaitHandle> waitHandles);
  public: static Int32 WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext);
  public: static Int32 WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext);
  public: static Boolean SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn);
  public: static Boolean SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, TimeSpan timeout, Boolean exitContext);
  public: static Boolean SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout, Boolean exitContext);
  public: static constexpr Int32 MaxWaitHandles = 64;
  protected: static IntPtr InvalidHandle;
  private: SafeWaitHandle _waitHandle;
  private: static Array<SafeWaitHandle> t_safeWaitHandlesForRent;
  public: static constexpr Int32 WaitSuccess = 0;
  public: static constexpr Int32 WaitAbandoned = 128;
  public: static constexpr Int32 WaitTimeout = 258;
};
} // namespace WaitHandleNamespace
using WaitHandle = WaitHandleNamespace::WaitHandle;
} // namespace System::Private::CoreLib::System::Threading
