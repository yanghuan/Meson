#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/WindowsRuntime/EventRegistrationToken.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(Guid)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Threading {
FORWARD(EventWaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IRestrictedErrorInfo)
FORWARD(ManagedActivationFactory)
FORWARD(IActivationFactory)
namespace WindowsRuntimeMarshalNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Threading;
class WindowsRuntimeMarshal {
  public: struct EventRegistrationTokenList {
    public: Boolean Push(EventRegistrationToken token);
    public: Boolean Pop(EventRegistrationToken& token);
    public: void CopyTo(List<EventRegistrationToken> tokens);
    private: EventRegistrationToken firstToken;
    private: List<EventRegistrationToken> restTokens;
  };
  public: class ManagedEventRegistrationImpl {
    private: static Dictionary<Object, EventRegistrationTokenList> GetEventRegistrationTokenTable(Object instance, Action<EventRegistrationToken> removeMethod);
    public: static void RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod);
    public: static ConditionalWeakTable<Object, Dictionary<MethodInfo, Dictionary<Object, EventRegistrationTokenList>>> s_eventRegistrations;
  };
  public: class NativeOrStaticEventRegistrationImpl {
    public: struct EventCacheKey {
      public: String ToString();
      public: Boolean Equals(EventCacheKey other);
      public: Object target;
      public: MethodInfo method;
    };
    public: CLASS(TokenListCount) {
      public: void Inc();
      public: void Dec();
      private: void CleanupCache();
      private: Int32 _count;
      private: EventCacheKey _key;
    };
    public: CLASS(EventRegistrationTokenListWithCount) {
      protected: void Finalize();
      public: void Push(EventRegistrationToken token);
      public: Boolean Pop(EventRegistrationToken& token);
      public: void CopyTo(List<EventRegistrationToken> tokens);
      private: TokenListCount _tokenListCount;
      private: EventRegistrationTokenList _tokenList;
    };
    public: struct EventCacheEntry {
      public: ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> registrationTable;
      public: TokenListCount tokenListCount;
    };
    public: CLASS(ReaderWriterLockTimedOutException) {
    };
    public: CLASS(MyReaderWriterLock) {
      public: void AcquireReaderLock(Int32 millisecondsTimeout);
      public: void AcquireWriterLock(Int32 millisecondsTimeout);
      public: void ReleaseReaderLock();
      public: void ReleaseWriterLock();
      private: void LazyCreateEvent(EventWaitHandle& waitEvent, Boolean makeAutoResetEvent);
      private: void WaitOnEvent(EventWaitHandle waitEvent, UInt32& numWaiters, Int32 millisecondsTimeout);
      private: void ExitAndWakeUpAppropriateWaiters();
      private: void EnterMyLock();
      private: void EnterMyLockSpin();
      private: void ExitMyLock();
      private: Int32 myLock;
      private: Int32 owners;
      private: UInt32 numWriteWaiters;
      private: UInt32 numReadWaiters;
      private: EventWaitHandle writeEvent;
      private: EventWaitHandle readEvent;
    };
    private: static Object GetInstanceKey(Action<EventRegistrationToken> removeMethod);
    private: static Object FindEquivalentKeyUnsafe(ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> registrationTable, Object handler, EventRegistrationTokenListWithCount& tokens);
    private: static ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> GetEventRegistrationTokenTableNoCreate(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount);
    private: static ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> GetOrCreateEventRegistrationTokenTable(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount);
    private: static ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> GetEventRegistrationTokenTableInternal(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount, Boolean createIfNotFound);
    public: static void RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod);
    public: static Dictionary<EventCacheKey, EventCacheEntry> s_eventRegistrations;
    private: static MyReaderWriterLock s_eventCacheRWLock;
  };
  public: static void RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod);
  public: static Int32 GetRegistrationTokenCacheSize();
  public: static void CallRemoveMethods(Action<EventRegistrationToken> removeMethod, List<EventRegistrationToken> tokensToRemove);
  public: static String HStringToString(IntPtr hstring);
  public: static Exception GetExceptionForHR(Int32 hresult, Exception innerException, String messageResource);
  public: static Exception GetExceptionForHR(Int32 hresult, Exception innerException);
  private: static Boolean RoOriginateLanguageException(Int32 error, String message, IntPtr languageException);
  private: static void RoReportUnhandledError(IRestrictedErrorInfo error);
  public: static Boolean ReportUnhandledError(Exception e);
  public: static IntPtr GetActivationFactoryForType(Type type);
  public: static ManagedActivationFactory GetManagedActivationFactory(Type type);
  public: static IActivationFactory GetActivationFactory(Type type);
  public: static IntPtr StringToHString(String s);
  public: static String PtrToStringHString(IntPtr ptr);
  public: static void FreeHString(IntPtr ptr);
  public: static Object GetUniqueObjectForIUnknownWithoutUnboxing(IntPtr unknown);
  public: static void InitializeWrapper(Object o, IntPtr& pUnk);
  public: static Int32 GetHRForException(Exception e);
  public: static void InitializeManagedWinRTFactoryObject(Object o, RuntimeType runtimeClassType);
  public: static Object GetNativeActivationFactory(Type type);
  private: static void Log(String s);
  private: static Boolean s_haveBlueErrorApis;
  private: static Guid s_iidIErrorInfo;
};
} // namespace WindowsRuntimeMarshalNamespace
using WindowsRuntimeMarshal = WindowsRuntimeMarshalNamespace::WindowsRuntimeMarshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
