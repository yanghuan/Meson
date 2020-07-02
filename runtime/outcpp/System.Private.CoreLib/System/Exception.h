#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionary)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARDS(Boolean)
FORWARD(IRuntimeMethodInfo)
FORWARDS(UInt32)
FORWARD(Type)
namespace ExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(Exception) {
  public: enum class ExceptionMessageKind {
    ThreadAbort = 1,
    ThreadInterrupted = 2,
    OutOfMemory = 3,
  };
  public: CLASS(__RestrictedErrorObject) {
    public: Object get_RealErrorObject();
    private: Object _realErrorObject;
  };
  public: struct DispatchState {
    public: Object StackTrace;
    public: Object DynamicMethods;
    public: String RemoteStackTrace;
    public: UIntPtr IpForWatsonBuckets;
    public: Object WatsonBuckets;
  };
  public: MethodBase get_TargetSite();
  public: String get_StackTrace();
  private: String get_SerializationRemoteStackTraceString();
  private: Object get_SerializationWatsonBuckets();
  private: String get_SerializationStackTraceString();
  public: String get_Message();
  public: IDictionary get_Data();
  public: Exception get_InnerException();
  public: String get_HelpLink();
  public: void set_HelpLink(String value);
  public: String get_Source();
  public: void set_Source(String value);
  public: Int32 get_HResult();
  public: void set_HResult(Int32 value);
  private: IDictionary CreateDataContainer();
  private: static Boolean IsImmutableAgileException(Exception e);
  public: void AddExceptionDataForRestrictedErrorInfo(String restrictedError, String restrictedErrorReference, String restrictedCapabilitySid, Object restrictedErrorObject, Boolean hasrestrictedLanguageErrorObject);
  public: Boolean TryGetRestrictedLanguageErrorObject(Object& restrictedErrorObject);
  private: static IRuntimeMethodInfo GetMethodFromStackTrace(Object stackTrace);
  private: MethodBase GetExceptionMethodFromStackTrace();
  private: static String GetStackTrace(Exception e);
  private: String CreateSourceName();
  private: void OnDeserialized(StreamingContext context);
  public: void InternalPreserveStackTrace();
  private: static void PrepareForForeignExceptionRaise();
  private: static void GetStackTracesDeepCopy(Exception exception, Object& currentStackTrace, Object& dynamicMethodArray);
  public: static void SaveStackTracesFromDeepCopy(Exception exception, Object currentStackTrace, Object dynamicMethodArray);
  private: static Object CopyStackTrace(Object currentStackTrace);
  private: static Object CopyDynamicMethods(Object currentDynamicMethods);
  public: static UInt32 GetExceptionCount();
  public: Object DeepCopyStackTrace(Object currentStackTrace);
  public: Object DeepCopyDynamicMethods(Object currentDynamicMethods);
  public: void RestoreDispatchState(DispatchState& dispatchState);
  public: static String GetMessageFromNativeResources(ExceptionMessageKind kind);
  private: static void GetMessageFromNativeResources(ExceptionMessageKind kind, StringHandleOnStack retMesg);
  public: DispatchState CaptureDispatchState();
  private: String GetClassName();
  public: Exception GetBaseException();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: Type GetType();
  private: void RestoreRemoteStackTrace(SerializationInfo info, StreamingContext context);
  private: static Object s_DispatchStateLock;
  private: MethodBase _exceptionMethod;
  public: String _message;
  private: IDictionary _data;
  private: Exception _innerException;
  private: String _helpURL;
  private: Object _stackTrace;
  private: Object _watsonBuckets;
  private: String _stackTraceString;
  private: String _remoteStackTraceString;
  private: Object _dynamicMethods;
  private: String _source;
  private: UIntPtr _ipForWatsonBuckets;
  private: IntPtr _xptrs;
  private: Int32 _xcode;
  private: Int32 _HResult;
  private: static Int32 _COMPlusExceptionCode;
  public: static String InnerExceptionPrefix;
};
} // namespace ExceptionNamespace
using Exception = ExceptionNamespace::Exception;
} // namespace System::Private::CoreLib::System
