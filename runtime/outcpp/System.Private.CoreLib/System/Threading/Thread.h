#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AppDomain)
FORWARDS(Byte)
FORWARD(Delegate)
FORWARDS(Double)
FORWARD(Exception)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARD(LocalDataStoreSlot)
FORWARD(Object)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARDS(TimeSpan)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Security::Principal {
FORWARD(IPrincipal)
} // namespace System::Private::CoreLib::System::Security::Principal
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(DeserializationTracker)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
enum class ApartmentState : int32_t;
enum class StackCrawlMark : int32_t;
enum class ThreadPriority : int32_t;
enum class ThreadState : int32_t;
FORWARD(AsyncLocal, T)
FORWARD(CompressedStack)
FORWARD(ExecutionContext)
FORWARD(ParameterizedThreadStart)
FORWARD(SynchronizationContext)
FORWARDS(ThreadHandle)
FORWARD(ThreadLocal, T)
FORWARD(ThreadStart)
namespace ThreadNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Runtime::ConstrainedExecution;
using namespace System::Runtime::Serialization;
using namespace System::Security::Principal;
CLASS(Thread) : public CriticalFinalizerObject::in {
  private: class LocalDataStore {
    public: static LocalDataStoreSlot AllocateSlot();
    private: static Dictionary<String, LocalDataStoreSlot> EnsureNameToSlotMap();
    public: static LocalDataStoreSlot AllocateNamedSlot(String name);
    public: static LocalDataStoreSlot GetNamedSlot(String name);
    public: static void FreeNamedSlot(String name);
    private: static ThreadLocal<Object> GetThreadLocal(LocalDataStoreSlot slot);
    public: static Object GetData(LocalDataStoreSlot slot);
    public: static void SetData(LocalDataStoreSlot slot, Object value);
    private: static Dictionary<String, LocalDataStoreSlot> s_nameToSlotMap;
  };
  public: Int32 get_ManagedThreadId();
  public: Boolean get_IsAlive();
  public: Boolean get_IsBackground();
  public: void set_IsBackground(Boolean value);
  public: Boolean get_IsThreadPoolThread();
  public: ThreadPriority get_Priority();
  public: void set_Priority(ThreadPriority value);
  public: static UInt64 get_CurrentOSThreadId();
  public: ThreadState get_ThreadState();
  public: static Int32 get_OptimalMaxSpinWaitsPerSpinIteration();
  public: CultureInfo get_CurrentCulture();
  public: void set_CurrentCulture(CultureInfo value);
  public: CultureInfo get_CurrentUICulture();
  public: void set_CurrentUICulture(CultureInfo value);
  public: static IPrincipal get_CurrentPrincipal();
  public: static void set_CurrentPrincipal(IPrincipal value);
  public: static Thread get_CurrentThread();
  public: ExecutionContext get_ExecutionContext();
  public: String get_Name();
  public: void set_Name(String value);
  public: ApartmentState get_ApartmentState();
  public: void set_ApartmentState(ApartmentState value);
  private: void ctor();
  private: void Create(ThreadStart start);
  private: void Create(ThreadStart start, Int32 maxStackSize);
  private: void Create(ParameterizedThreadStart start);
  private: void Create(ParameterizedThreadStart start, Int32 maxStackSize);
  public: ThreadHandle GetNativeHandle();
  public: void Start(Object parameter);
  public: void Start();
  private: void SetCultureOnUnstartedThreadNoCheck(CultureInfo value, Boolean uiCulture);
  private: void StartInternal();
  private: static IntPtr InternalGetCurrentThread();
  private: static void SleepInternal(Int32 millisecondsTimeout);
  public: static void Sleep(Int32 millisecondsTimeout);
  private: static void SpinWaitInternal(Int32 iterations);
  public: static void SpinWait(Int32 iterations);
  private: static Interop::BOOL YieldInternal();
  public: static Boolean Yield();
  private: static Thread InitializeCurrentThread();
  private: static Thread GetCurrentThreadNative();
  private: void SetStartHelper(Delegate start, Int32 maxStackSize);
  private: void SetStart(Delegate start, Int32 maxStackSize);
  protected: void Finalize();
  private: void InternalFinalize();
  private: void StartupSetApartmentStateInternal();
  private: static void InformThreadNameChange(ThreadHandle t, String name, Int32 len);
  public: static DeserializationTracker GetThreadDeserializationTracker(StackCrawlMark& stackMark);
  private: Boolean IsBackgroundNative();
  private: void SetBackgroundNative(Boolean isBackground);
  private: Int32 GetPriorityNative();
  private: void SetPriorityNative(Int32 priority);
  private: static UInt64 GetCurrentOSThreadId();
  private: Int32 GetThreadStateNative();
  public: ApartmentState GetApartmentState();
  private: Boolean TrySetApartmentStateUnchecked(ApartmentState state);
  public: Int32 GetApartmentStateNative();
  public: Int32 SetApartmentStateNative(Int32 state);
  public: void DisableComObjectEagerCleanup();
  public: void Interrupt();
  public: Boolean Join(Int32 millisecondsTimeout);
  private: static Int32 GetOptimalMaxSpinWaitsPerSpinIterationInternal();
  private: static Int32 CalculateOptimalMaxSpinWaitsPerSpinIteration();
  public: static Int32 GetCurrentProcessorNumber();
  public: static Int32 GetCurrentProcessorId();
  public: void ResetThreadPoolThread();
  public: void ctor(ThreadStart start);
  public: void ctor(ThreadStart start, Int32 maxStackSize);
  public: void ctor(ParameterizedThreadStart start);
  public: void ctor(ParameterizedThreadStart start, Int32 maxStackSize);
  private: void RequireCurrentThread();
  private: void SetCultureOnUnstartedThread(CultureInfo value, Boolean uiCulture);
  private: void ThreadNameChanged(String value);
  public: void Abort();
  public: void Abort(Object stateInfo);
  public: static void ResetAbort();
  public: void Suspend();
  public: void Resume();
  public: static void BeginCriticalRegion();
  public: static void EndCriticalRegion();
  public: static void BeginThreadAffinity();
  public: static void EndThreadAffinity();
  public: static LocalDataStoreSlot AllocateDataSlot();
  public: static LocalDataStoreSlot AllocateNamedDataSlot(String name);
  public: static LocalDataStoreSlot GetNamedDataSlot(String name);
  public: static void FreeNamedDataSlot(String name);
  public: static Object GetData(LocalDataStoreSlot slot);
  public: static void SetData(LocalDataStoreSlot slot, Object data);
  public: void SetApartmentState(ApartmentState state);
  public: Boolean TrySetApartmentState(ApartmentState state);
  public: CompressedStack GetCompressedStack();
  public: void SetCompressedStack(CompressedStack stack);
  public: static AppDomain GetDomain();
  public: static Int32 GetDomainID();
  public: Int32 GetHashCode();
  public: void Join();
  public: Boolean Join(TimeSpan timeout);
  public: static void MemoryBarrier();
  public: static void Sleep(TimeSpan timeout);
  public: static Byte VolatileRead(Byte& address);
  public: static Double VolatileRead(Double& address);
  public: static Int16 VolatileRead(Int16& address);
  public: static Int32 VolatileRead(Int32& address);
  public: static Int64 VolatileRead(Int64& address);
  public: static IntPtr VolatileRead(IntPtr& address);
  public: static Object VolatileRead(Object& address);
  public: static SByte VolatileRead(SByte& address);
  public: static Single VolatileRead(Single& address);
  public: static UInt16 VolatileRead(UInt16& address);
  public: static UInt32 VolatileRead(UInt32& address);
  public: static UInt64 VolatileRead(UInt64& address);
  public: static UIntPtr VolatileRead(UIntPtr& address);
  public: static void VolatileWrite(Byte& address, Byte value);
  public: static void VolatileWrite(Double& address, Double value);
  public: static void VolatileWrite(Int16& address, Int16 value);
  public: static void VolatileWrite(Int32& address, Int32 value);
  public: static void VolatileWrite(Int64& address, Int64 value);
  public: static void VolatileWrite(IntPtr& address, IntPtr value);
  public: static void VolatileWrite(Object& address, Object value);
  public: static void VolatileWrite(SByte& address, SByte value);
  public: static void VolatileWrite(Single& address, Single value);
  public: static void VolatileWrite(UInt16& address, UInt16 value);
  public: static void VolatileWrite(UInt32& address, UInt32 value);
  public: static void VolatileWrite(UInt64& address, UInt64 value);
  public: static void VolatileWrite(UIntPtr& address, UIntPtr value);
  private: static Exception GetApartmentStateChangeFailedException();
  private: static void cctor();
  public: ExecutionContext _executionContext;
  public: SynchronizationContext _synchronizationContext;
  private: String _name;
  private: Delegate _delegate;
  private: Object _threadStartArg;
  private: IntPtr _DONT_USE_InternalThread;
  private: Int32 _priority;
  private: Int32 _managedThreadId;
  public: static constexpr Boolean IsThreadStartSupported = true;
  private: static Int32 s_optimalMaxSpinWaitsPerSpinIteration;
  private: static Boolean s_isProcessorNumberReallyFast;
  private: static AsyncLocal<IPrincipal> s_asyncLocalPrincipal;
  private: static Thread t_currentThread;
};
} // namespace ThreadNamespace
using Thread = ThreadNamespace::Thread;
} // namespace System::Private::CoreLib::System::Threading
