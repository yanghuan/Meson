#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UIntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionary)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(IRuntimeMethodInfo)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
namespace ExceptionNamespace {
using namespace System::Collections;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;
CLASS(Exception) : public object {
  public: using interface = rt::TypeList<ISerializable>;
  public: enum class ExceptionMessageKind : int32_t {
    ThreadAbort = 1,
    ThreadInterrupted = 2,
    OutOfMemory = 3,
  };
  public: struct DispatchState : public valueType<DispatchState> {
    public: explicit DispatchState(Array<Byte> stackTrace, Array<Object> dynamicMethods, String remoteStackTrace, UIntPtr ipForWatsonBuckets, Array<Byte> watsonBuckets);
    public: explicit DispatchState() {}
    public: Array<Byte> StackTrace;
    public: Array<Object> DynamicMethods;
    public: String RemoteStackTrace;
    public: UIntPtr IpForWatsonBuckets;
    public: Array<Byte> WatsonBuckets;
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
  private: static IRuntimeMethodInfo GetMethodFromStackTrace(Object stackTrace);
  private: MethodBase GetExceptionMethodFromStackTrace();
  private: static String GetStackTrace(Exception e);
  private: String CreateSourceName();
  private: void OnDeserialized(StreamingContext context);
  public: void InternalPreserveStackTrace();
  private: static void PrepareForForeignExceptionRaise();
  private: static void GetStackTracesDeepCopy(Exception exception, Array<Byte>& currentStackTrace, Array<Object>& dynamicMethodArray);
  public: static void SaveStackTracesFromDeepCopy(Exception exception, Array<Byte> currentStackTrace, Array<Object> dynamicMethodArray);
  public: static UInt32 GetExceptionCount();
  public: void RestoreDispatchState(DispatchState& dispatchState);
  public: static String GetMessageFromNativeResources(ExceptionMessageKind kind);
  private: static void GetMessageFromNativeResources(ExceptionMessageKind kind, StringHandleOnStack retMesg);
  public: DispatchState CaptureDispatchState();
  public: void SetCurrentStackTrace();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: String GetClassName();
  public: Exception GetBaseException();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: Type GetType();
  private: void RestoreRemoteStackTrace(SerializationInfo info, StreamingContext context);
  public: static void _ToString_g__Write65_0(String source, Span<Char>& dest);
  private: MethodBase _exceptionMethod;
  public: String _message;
  private: IDictionary _data;
  private: Exception _innerException;
  private: String _helpURL;
  private: Array<Byte> _stackTrace;
  private: Array<Byte> _watsonBuckets;
  private: String _stackTraceString;
  private: String _remoteStackTraceString;
  private: Array<Object> _dynamicMethods;
  private: String _source;
  private: UIntPtr _ipForWatsonBuckets;
  private: IntPtr _xptrs;
  private: Int32 _xcode;
  private: Int32 _HResult;
  private: static constexpr Int32 _COMPlusExceptionCode = -532462766;
};
} // namespace ExceptionNamespace
using Exception = ExceptionNamespace::Exception;
} // namespace System::Private::CoreLib::System
