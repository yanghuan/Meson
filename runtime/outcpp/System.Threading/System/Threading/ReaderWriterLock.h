#pragma once

#include <System.Private.CoreLib/System/ApplicationException.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>
#include <System.Private.CoreLib/System/UInt16.h>

namespace System::Private::CoreLib::System {
FORWARD(ArgumentOutOfRangeException)
FORWARDS(Boolean)
FORWARD(String)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
FORWARD(AutoResetEvent)
FORWARD(ManualResetEventSlim)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Threading::System::Threading {
enum class LockCookieFlags : int32_t;
FORWARDS(LockCookie)
namespace ReaderWriterLockNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::ConstrainedExecution;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(ReaderWriterLock) : public CriticalFinalizerObject::in {
  private: CLASS(ReaderWriterLockApplicationException) : public ApplicationException::in {
    public: void ctor(Int32 errorHResult, String message);
    public: void ctor(SerializationInfo info, StreamingContext context);
  };
  private: CLASS(ThreadLocalLockEntry) : public Object::in {
    public: Boolean get_IsFree();
    private: void ctor(Int64 lockID);
    public: static ThreadLocalLockEntry GetCurrent(Int64 lockID);
    public: static ThreadLocalLockEntry GetOrCreateCurrent(Int64 lockID);
    private: static ThreadLocalLockEntry GetOrCreateCurrentSlow(Int64 lockID, ThreadLocalLockEntry headEntry);
    private: static ThreadLocalLockEntry t_lockEntryHead;
    private: Int64 _lockID;
    private: ThreadLocalLockEntry _next;
    public: UInt16 _readerLevel;
  };
  public: Boolean get_IsReaderLockHeld();
  public: Boolean get_IsWriterLockHeld();
  public: Int32 get_WriterSeqNum();
  public: void ctor();
  public: Boolean AnyWritersSince(Int32 seqNum);
  public: void AcquireReaderLock(Int32 millisecondsTimeout);
  public: void AcquireReaderLock(TimeSpan timeout);
  public: void AcquireWriterLock(Int32 millisecondsTimeout);
  public: void AcquireWriterLock(TimeSpan timeout);
  public: void ReleaseReaderLock();
  public: void ReleaseWriterLock();
  public: LockCookie UpgradeToWriterLock(Int32 millisecondsTimeout);
  public: LockCookie UpgradeToWriterLock(TimeSpan timeout);
  public: void DowngradeFromWriterLock(LockCookie& lockCookie);
  public: LockCookie ReleaseLock();
  public: void RestoreLock(LockCookie& lockCookie);
  private: void RecoverLock(LockCookie& lockCookie, LockCookieFlags flags);
  private: static Int32 GetCurrentThreadID();
  private: static Boolean YieldProcessor();
  private: ManualResetEventSlim GetOrCreateReaderEvent();
  private: AutoResetEvent GetOrCreateWriterEvent();
  private: ManualResetEventSlim TryGetOrCreateReaderEvent();
  private: AutoResetEvent TryGetOrCreateWriterEvent();
  private: void ReleaseEvents();
  private: static ArgumentOutOfRangeException GetInvalidTimeoutException(String parameterName);
  private: static Int32 ToTimeoutMilliseconds(TimeSpan timeout);
  private: static ApplicationException GetTimeoutException();
  private: static ApplicationException GetNotOwnerException();
  private: static ApplicationException GetInvalidLockCookieException();
  private: static void cctor();
  private: static Int32 DefaultSpinCount;
  private: static Int64 s_mostRecentLockID;
  private: ManualResetEventSlim _readerEvent;
  private: AutoResetEvent _writerEvent;
  private: Int64 _lockID;
  private: Int32 _state;
  private: Int32 _writerID;
  private: Int32 _writerSeqNum;
  private: UInt16 _writerLevel;
};
} // namespace ReaderWriterLockNamespace
using ReaderWriterLock = ReaderWriterLockNamespace::ReaderWriterLock;
} // namespace System::Threading::System::Threading
