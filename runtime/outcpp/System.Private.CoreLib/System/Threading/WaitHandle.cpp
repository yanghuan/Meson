#include "WaitHandle-dep.h"

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeWaitHandle-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/AbandonedMutexException-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::WaitHandleNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System::Runtime::InteropServices;

IntPtr WaitHandle___::get_Handle() {
  if (_waitHandle != nullptr) {
    return _waitHandle->DangerousGetHandle();
  }
  return InvalidHandle;
}

void WaitHandle___::set_Handle(IntPtr value) {
  if (value == InvalidHandle) {
    if (_waitHandle != nullptr) {
      _waitHandle->SetHandleAsInvalid();
      _waitHandle = nullptr;
    }
  } else {
    _waitHandle = rt::newobj<SafeWaitHandle>(value, true);
  }
}

SafeWaitHandle WaitHandle___::get_SafeWaitHandle() {
  auto& default = _waitHandle;
  return default != nullptr ? default : (_waitHandle = rt::newobj<SafeWaitHandle>(InvalidHandle, false));
}

void WaitHandle___::set_SafeWaitHandle(SafeWaitHandle value) {
  _waitHandle = value;
}

Int32 WaitHandle___::WaitMultipleIgnoringSyncContext(Span<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  {
    IntPtr* waitHandles2 = &MemoryMarshal::GetReference(waitHandles);
    return WaitMultipleIgnoringSyncContext(waitHandles2, waitHandles.get_Length(), waitAll, millisecondsTimeout);
  }
}

Int32 WaitHandle___::SignalAndWaitCore(IntPtr waitHandleToSignal, IntPtr waitHandleToWaitOn, Int32 millisecondsTimeout) {
  Int32 num = SignalAndWaitNative(waitHandleToSignal, waitHandleToWaitOn, millisecondsTimeout);
  if (num == 298) {
    rt::throw_exception<InvalidOperationException>(SR::get_Threading_WaitHandleTooManyPosts());
  }
  return num;
}

void WaitHandle___::ctor() {
}

Int32 WaitHandle___::ToTimeoutMilliseconds(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return (Int32)num;
}

void WaitHandle___::Close() {
  Dispose();
}

void WaitHandle___::Dispose(Boolean explicitDisposing) {
  auto& default = _waitHandle;
  default == nullptr ? nullptr : default->Close();
}

void WaitHandle___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((WaitHandle)this);
}

Boolean WaitHandle___::WaitOne(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return WaitOneNoCheck(millisecondsTimeout);
}

Boolean WaitHandle___::WaitOneNoCheck(Int32 millisecondsTimeout) {
  auto& default = _waitHandle;
  SafeWaitHandle safeWaitHandle = default != nullptr ? default : rt::throw_exception(rt::newobj<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_Generic()));
  Boolean success = false;
  try{
    safeWaitHandle->DangerousAddRef(success);
    SynchronizationContext current = SynchronizationContext::in::get_Current();
    Int32 num = (current == nullptr || !current->IsWaitNotificationRequired()) ? WaitOneCore(safeWaitHandle->DangerousGetHandle(), millisecondsTimeout) : current->Wait(rt::newarr<Array<IntPtr>>(1), false, millisecondsTimeout);
    if (num == 128) {
      rt::throw_exception<AbandonedMutexException>();
    }
    return num != 258;
  } catch (...) {
  } finally: {
    if (success) {
      safeWaitHandle->DangerousRelease();
    }
  }
}

Array<SafeWaitHandle> WaitHandle___::RentSafeWaitHandleArray(Int32 capacity) {
  Array<SafeWaitHandle> array = t_safeWaitHandlesForRent;
  t_safeWaitHandlesForRent = nullptr;
  Int32 num = (array != nullptr) ? array->get_Length() : 0;
  if (num < capacity) {
    array = rt::newarr<Array<SafeWaitHandle>>(Math::Max(capacity, Math::Min(64, 2 * num)));
  }
  return array;
}

void WaitHandle___::ReturnSafeWaitHandleArray(Array<SafeWaitHandle> safeWaitHandles) {
  t_safeWaitHandlesForRent = safeWaitHandles;
}

void WaitHandle___::ObtainSafeWaitHandles(ReadOnlySpan<WaitHandle> waitHandles, Span<SafeWaitHandle> safeWaitHandles, Span<IntPtr> unsafeWaitHandles) {
  Boolean success = true;
  SafeWaitHandle safeWaitHandle = nullptr;
  try{
    for (Int32 i = 0; i < waitHandles.get_Length(); i++) {
      WaitHandle waitHandle = waitHandles[i];
      if (waitHandle == nullptr) {
        rt::throw_exception<ArgumentNullException>("waitHandles[" + i + "]", SR::get_ArgumentNull_ArrayElement());
      }
      auto& default = waitHandle->_waitHandle;
      SafeWaitHandle safeWaitHandle2 = default != nullptr ? default : rt::throw_exception(rt::newobj<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_Generic()));
      safeWaitHandle = safeWaitHandle2;
      success = false;
      safeWaitHandle2->DangerousAddRef(success);
      safeWaitHandles[i] = safeWaitHandle2;
      unsafeWaitHandles[i] = safeWaitHandle2->DangerousGetHandle();
    }
  } catch (...) {
  }
}

Int32 WaitHandle___::WaitMultiple(Array<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  if (waitHandles == nullptr) {
    rt::throw_exception<ArgumentNullException>("waitHandles", SR::get_ArgumentNull_Waithandles());
  }
  return WaitMultiple(ReadOnlySpan<WaitHandle>(waitHandles), waitAll, millisecondsTimeout);
}

Int32 WaitHandle___::WaitMultiple(ReadOnlySpan<WaitHandle> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  if (waitHandles.get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyWaithandleArray(), "waitHandles");
  }
  if (waitHandles.get_Length() > 64) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_MaxWaitHandles());
  }
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  auto& default = current;
  auto& extern = default == nullptr ? nullptr : default->IsWaitNotificationRequired();
  Boolean flag = extern != nullptr ? extern : false;
  Array<SafeWaitHandle> array = RentSafeWaitHandleArray(waitHandles.get_Length());
  try{
    Int32 num;
    if (flag) {
      Array<IntPtr> array2 = rt::newarr<Array<IntPtr>>(waitHandles.get_Length());
      ObtainSafeWaitHandles(waitHandles, array, array2);
      num = current->Wait(array2, waitAll, millisecondsTimeout);
    } else {
      IntPtr ref[waitHandles.get_Length()] = {};
      Span<IntPtr> span = ref;
      ObtainSafeWaitHandles(waitHandles, array, span);
      num = WaitMultipleIgnoringSyncContext(span, waitAll, millisecondsTimeout);
    }
    if (num >= 128 && num < 128 + waitHandles.get_Length()) {
      if (waitAll) {
        rt::throw_exception<AbandonedMutexException>();
      }
      num -= 128;
      rt::throw_exception<AbandonedMutexException>(num, waitHandles[num]);
    }
    return num;
  } catch (...) {
  } finally: {
    for (Int32 i = 0; i < waitHandles.get_Length(); i++) {
      if (array[i] != nullptr) {
        array[i]->DangerousRelease();
        array[i] = nullptr;
      }
    }
    ReturnSafeWaitHandleArray(array);
  }
}

Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout) {
  if (toSignal == nullptr) {
    rt::throw_exception<ArgumentNullException>("toSignal");
  }
  if (toWaitOn == nullptr) {
    rt::throw_exception<ArgumentNullException>("toWaitOn");
  }
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  SafeWaitHandle waitHandle = toSignal->_waitHandle;
  SafeWaitHandle waitHandle2 = toWaitOn->_waitHandle;
  if (waitHandle == nullptr || waitHandle2 == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_Generic());
  }
  Boolean success = false;
  Boolean success2 = false;
  try{
    waitHandle->DangerousAddRef(success);
    waitHandle2->DangerousAddRef(success2);
    Int32 num = SignalAndWaitCore(waitHandle->DangerousGetHandle(), waitHandle2->DangerousGetHandle(), millisecondsTimeout);
    if (num == 128) {
      rt::throw_exception<AbandonedMutexException>();
    }
    return num != 258;
  } catch (...) {
  } finally: {
    if (success2) {
      waitHandle2->DangerousRelease();
    }
    if (success) {
      waitHandle->DangerousRelease();
    }
  }
}

Boolean WaitHandle___::WaitOne(TimeSpan timeout) {
  return WaitOneNoCheck(ToTimeoutMilliseconds(timeout));
}

Boolean WaitHandle___::WaitOne() {
  return WaitOneNoCheck(-1);
}

Boolean WaitHandle___::WaitOne(Int32 millisecondsTimeout, Boolean exitContext) {
  return WaitOne(millisecondsTimeout);
}

Boolean WaitHandle___::WaitOne(TimeSpan timeout, Boolean exitContext) {
  return WaitOneNoCheck(ToTimeoutMilliseconds(timeout));
}

Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout) {
  return WaitMultiple(waitHandles, true, millisecondsTimeout) != 258;
}

Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout) {
  return WaitMultiple(waitHandles, true, ToTimeoutMilliseconds(timeout)) != 258;
}

Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles) {
  return WaitMultiple(waitHandles, true, -1) != 258;
}

Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext) {
  return WaitMultiple(waitHandles, true, millisecondsTimeout) != 258;
}

Boolean WaitHandle___::WaitAll(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext) {
  return WaitMultiple(waitHandles, true, ToTimeoutMilliseconds(timeout)) != 258;
}

Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout) {
  return WaitMultiple(waitHandles, false, millisecondsTimeout);
}

Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout) {
  return WaitMultiple(waitHandles, false, ToTimeoutMilliseconds(timeout));
}

Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles) {
  return WaitMultiple(waitHandles, false, -1);
}

Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, Int32 millisecondsTimeout, Boolean exitContext) {
  return WaitMultiple(waitHandles, false, millisecondsTimeout);
}

Int32 WaitHandle___::WaitAny(Array<WaitHandle> waitHandles, TimeSpan timeout, Boolean exitContext) {
  return WaitMultiple(waitHandles, false, ToTimeoutMilliseconds(timeout));
}

Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn) {
  return SignalAndWait(toSignal, toWaitOn, -1);
}

Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, TimeSpan timeout, Boolean exitContext) {
  return SignalAndWait(toSignal, toWaitOn, ToTimeoutMilliseconds(timeout));
}

Boolean WaitHandle___::SignalAndWait(WaitHandle toSignal, WaitHandle toWaitOn, Int32 millisecondsTimeout, Boolean exitContext) {
  return SignalAndWait(toSignal, toWaitOn, millisecondsTimeout);
}

void WaitHandle___::cctor() {
  InvalidHandle = IntPtr(-1);
}

} // namespace System::Private::CoreLib::System::Threading::WaitHandleNamespace
