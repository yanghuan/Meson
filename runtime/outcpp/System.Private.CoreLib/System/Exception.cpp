#include "Exception-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/EmptyReadOnlyDictionaryInternal-dep.h>
#include <System.Private.CoreLib/System/Collections/ListDictionaryInternal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackFrame-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Module-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/StreamingContextStates.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::ExceptionNamespace {
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;
using namespace System::Text;

Exception___::DispatchState::DispatchState(Array<Byte> stackTrace, Array<Object> dynamicMethods, String remoteStackTrace, UIntPtr ipForWatsonBuckets, Array<Byte> watsonBuckets) {
  StackTrace = stackTrace;
  DynamicMethods = dynamicMethods;
  RemoteStackTrace = remoteStackTrace;
  IpForWatsonBuckets = ipForWatsonBuckets;
  WatsonBuckets = watsonBuckets;
}

MethodBase Exception___::get_TargetSite() {
  if (_exceptionMethod != nullptr) {
    return _exceptionMethod;
  }
  if (_stackTrace == nullptr) {
    return nullptr;
  }
  _exceptionMethod = GetExceptionMethodFromStackTrace();
  return _exceptionMethod;
}

String Exception___::get_StackTrace() {
  String stackTraceString = _stackTraceString;
  String remoteStackTraceString = _remoteStackTraceString;
  if (stackTraceString != nullptr) {
    return remoteStackTraceString + stackTraceString;
  }
  if (_stackTrace == nullptr) {
    return remoteStackTraceString;
  }
  return remoteStackTraceString + GetStackTrace((Exception)this);
}

String Exception___::get_SerializationRemoteStackTraceString() {
  return _remoteStackTraceString;
}

Object Exception___::get_SerializationWatsonBuckets() {
  return _watsonBuckets;
}

String Exception___::get_SerializationStackTraceString() {
  String text = _stackTraceString;
  if (text == nullptr && _stackTrace != nullptr) {
    text = GetStackTrace((Exception)this);
  }
  return text;
}

String Exception___::get_Message() {
  auto& default = _message;
  return default != nullptr ? default : SR::Format(SR::get_Exception_WasThrown(), GetClassName());
}

IDictionary Exception___::get_Data() {
  auto& default = _data;
  return default != nullptr ? default : (_data = CreateDataContainer());
}

Exception Exception___::get_InnerException() {
  return _innerException;
}

String Exception___::get_HelpLink() {
  return _helpURL;
}

void Exception___::set_HelpLink(String value) {
  _helpURL = value;
}

String Exception___::get_Source() {
  auto& default = _source;
  return default != nullptr ? default : (_source = CreateSourceName());
}

void Exception___::set_Source(String value) {
  _source = value;
}

Int32 Exception___::get_HResult() {
  return _HResult;
}

void Exception___::set_HResult(Int32 value) {
  _HResult = value;
}

IDictionary Exception___::CreateDataContainer() {
  if (IsImmutableAgileException((Exception)this)) {
    return rt::newobj<EmptyReadOnlyDictionaryInternal>();
  }
  return rt::newobj<ListDictionaryInternal>();
}

MethodBase Exception___::GetExceptionMethodFromStackTrace() {
  IRuntimeMethodInfo methodFromStackTrace = GetMethodFromStackTrace(_stackTrace);
  if (methodFromStackTrace == nullptr) {
    return nullptr;
  }
  return RuntimeType::in::GetMethodBase(methodFromStackTrace);
}

String Exception___::GetStackTrace(Exception e) {
  return rt::newobj<StackTrace>(e, true)->ToString(StackTrace::in::TraceFormat::Normal);
}

String Exception___::CreateSourceName() {
  StackTrace stackTrace = rt::newobj<StackTrace>((Exception)this, false);
  if (stackTrace->get_FrameCount() > 0) {
    StackFrame frame = stackTrace->GetFrame(0);
    MethodBase method = frame->GetMethod();
    Module module = method->get_Module();
    RuntimeModule runtimeModule = rt::as<RuntimeModule>(module);
    if ((Object)runtimeModule == nullptr) {
      ModuleBuilder moduleBuilder = rt::as<ModuleBuilder>(module);
      if ((Object)moduleBuilder == nullptr) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeReflectionObject());
      }
      runtimeModule = moduleBuilder->get_InternalModule();
    }
    return runtimeModule->GetRuntimeAssembly()->GetSimpleName();
  }
  return nullptr;
}

void Exception___::OnDeserialized(StreamingContext context) {
  _stackTrace = nullptr;
  _ipForWatsonBuckets = UIntPtr::Zero;
}

void Exception___::InternalPreserveStackTrace() {
  _ = get_Source();
  String stackTrace = get_StackTrace();
  if (!String::in::IsNullOrEmpty(stackTrace)) {
    _remoteStackTraceString = stackTrace + "
";
  }
  _stackTrace = nullptr;
  _stackTraceString = nullptr;
}

void Exception___::RestoreDispatchState(DispatchState& dispatchState) {
  if (!IsImmutableAgileException((Exception)this)) {
    auto& default = dispatchState.StackTrace;
    Array<Byte> currentStackTrace = (Array<Byte>)default == nullptr ? nullptr : default->Clone();
    auto& extern = dispatchState.DynamicMethods;
    Array<Object> dynamicMethodArray = (Array<Object>)extern == nullptr ? nullptr : extern->Clone();
    _watsonBuckets = dispatchState.WatsonBuckets;
    _ipForWatsonBuckets = dispatchState.IpForWatsonBuckets;
    _remoteStackTraceString = dispatchState.RemoteStackTrace;
    SaveStackTracesFromDeepCopy((Exception)this, currentStackTrace, dynamicMethodArray);
    _stackTraceString = nullptr;
    PrepareForForeignExceptionRaise();
  }
}

String Exception___::GetMessageFromNativeResources(ExceptionMessageKind kind) {
  String s = nullptr;
  GetMessageFromNativeResources(kind, StringHandleOnStack(s));
  return s;
}

Exception::in::DispatchState Exception___::CaptureDispatchState() {
  Array<Byte> currentStackTrace;
  Array<Object> dynamicMethodArray;
  GetStackTracesDeepCopy((Exception)this, currentStackTrace, dynamicMethodArray);
  return DispatchState(currentStackTrace, dynamicMethodArray, _remoteStackTraceString, _ipForWatsonBuckets, _watsonBuckets);
}

void Exception___::SetCurrentStackTrace() {
  if (!IsImmutableAgileException((Exception)this)) {
    if (_stackTrace != nullptr || _stackTraceString != nullptr || _remoteStackTraceString != nullptr) {
      ThrowHelper::ThrowInvalidOperationException();
    }
    StringBuilder stringBuilder = rt::newobj<StringBuilder>(256);
    rt::newobj<StackTrace>(true)->ToString(StackTrace::in::TraceFormat::TrailingNewLine, stringBuilder);
    stringBuilder->AppendLine(SR::get_Exception_EndStackTraceFromPreviousThrow());
    _remoteStackTraceString = stringBuilder->ToString();
  }
}

void Exception___::ctor() {
  _xcode = -532462766;
  Object::ctor();
  _HResult = -2146233088;
}

void Exception___::ctor(String message) {
  _message = message;
}

void Exception___::ctor(String message, Exception innerException) {
  _message = message;
  _innerException = innerException;
}

void Exception___::ctor(SerializationInfo info, StreamingContext context) {
  _xcode = -532462766;
  Object::ctor();
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _message = info->GetString("Message");
  _data = (IDictionary)info->GetValueNoThrow("Data", rt::typeof<IDictionary>());
  _innerException = (Exception)info->GetValue("InnerException", rt::typeof<Exception>());
  _helpURL = info->GetString("HelpURL");
  _stackTraceString = info->GetString("StackTraceString");
  _HResult = info->GetInt32("HResult");
  _source = info->GetString("Source");
  RestoreRemoteStackTrace(info, context);
}

String Exception___::GetClassName() {
  return GetType()->ToString();
}

Exception Exception___::GetBaseException() {
  Exception innerException = get_InnerException();
  Exception result = (Exception)this;
  while (innerException != nullptr) {
    result = innerException;
    innerException = innerException->get_InnerException();
  }
  return result;
}

void Exception___::GetObjectData(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  if (_source == nullptr) {
    _source = get_Source();
  }
  info->AddValue("ClassName", GetClassName(), rt::typeof<String>());
  info->AddValue("Message", _message, rt::typeof<String>());
  info->AddValue("Data", _data, rt::typeof<IDictionary>());
  info->AddValue("InnerException", _innerException, rt::typeof<Exception>());
  info->AddValue("HelpURL", _helpURL, rt::typeof<String>());
  info->AddValue("StackTraceString", get_SerializationStackTraceString(), rt::typeof<String>());
  info->AddValue("RemoteStackTraceString", get_SerializationRemoteStackTraceString(), rt::typeof<String>());
  info->AddValue("RemoteStackIndex", 0, rt::typeof<Int32>());
  info->AddValue("ExceptionMethod", nullptr, rt::typeof<String>());
  info->AddValue("HResult", _HResult);
  info->AddValue("Source", _source, rt::typeof<String>());
  info->AddValue("WatsonBuckets", get_SerializationWatsonBuckets(), rt::typeof<Array<Byte>>());
}

String Exception___::ToString() {
  auto Write = [](String source, Span<Char>& dest) -> void {
    MemoryExtensions::AsSpan(source).CopyTo(dest);
    dest = dest.Slice(source->get_Length());
  };
  String className = GetClassName();
  String message = get_Message();
  auto& default = _innerException;
  auto& extern = default == nullptr ? nullptr : default->ToString();
  String text = extern != nullptr ? extern : "";
  String exception_EndOfInnerExceptionStack = SR::get_Exception_EndOfInnerExceptionStack();
  String stackTrace = get_StackTrace();
  Int32 num = className->get_Length();
  {
    if (!String::in::IsNullOrEmpty(message)) {
      num += 2 + message->get_Length();
    }
    if (_innerException != nullptr) {
      num += "
"->get_Length() + " ---> "->get_Length() + text->get_Length() + "
"->get_Length() + 3 + exception_EndOfInnerExceptionStack->get_Length();
    }
    if (stackTrace != nullptr) {
      num += "
"->get_Length() + stackTrace->get_Length();
    }
    String text2 = String::in::FastAllocateString(num);
    Span<Char> dest2 = Span<Char>(text2->GetRawStringData(), text2->get_Length());
    Write(className, dest2);
    if (!String::in::IsNullOrEmpty(message)) {
      Write(": ", dest2);
      Write(message, dest2);
    }
    if (_innerException != nullptr) {
      Write("
", dest2);
      Write(" ---> ", dest2);
      Write(text, dest2);
      Write("
", dest2);
      Write("   ", dest2);
      Write(exception_EndOfInnerExceptionStack, dest2);
    }
    if (stackTrace != nullptr) {
      Write("
", dest2);
      Write(stackTrace, dest2);
    }
    return text2;
  }
}

Type Exception___::GetType() {
  return Object::GetType();
}

void Exception___::RestoreRemoteStackTrace(SerializationInfo info, StreamingContext context) {
  _remoteStackTraceString = info->GetString("RemoteStackTraceString");
  _watsonBuckets = (Array<Byte>)info->GetValueNoThrow("WatsonBuckets", rt::typeof<Array<Byte>>());
  if (context.get_State() == StreamingContextStates::CrossAppDomain) {
    _remoteStackTraceString += _stackTraceString;
    _stackTraceString = nullptr;
  }
}

} // namespace System::Private::CoreLib::System::ExceptionNamespace
