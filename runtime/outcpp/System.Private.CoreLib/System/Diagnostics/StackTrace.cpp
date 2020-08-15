#include "StackTrace-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/IEnumerator.h>
#include <System.Private.CoreLib/System/Diagnostics/StackFrame-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTraceHiddenAttribute-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodImplAttributes.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CompilerGeneratedAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachine.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace {
using namespace System::Collections;
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Text;

Int32 StackTrace___::get_FrameCount() {
  return _numOfFrames;
}

Int32 StackTrace___::CalculateFramesToSkip(StackFrameHelper StackF, Int32 iNumFrames) {
  Int32 num = 0;
  for (Int32 i = 0; i < iNumFrames; i++) {
    MethodBase methodBase = StackF->GetMethodBase(i);
    if (methodBase != nullptr) {
      Type declaringType = methodBase->get_DeclaringType();
      if (declaringType == nullptr) {
        break;
      }
      String namespace = declaringType->get_Namespace();
      if (namespace == nullptr || !String::in::Equals(namespace, "System.Diagnostics", StringComparison::Ordinal)) {
        break;
      }
    }
    num++;
  }
  return num;
}

void StackTrace___::InitializeForException(Exception exception, Int32 skipFrames, Boolean fNeedFileInfo) {
  CaptureStackTrace(skipFrames, fNeedFileInfo, exception);
}

void StackTrace___::InitializeForCurrentThread(Int32 skipFrames, Boolean fNeedFileInfo) {
  CaptureStackTrace(skipFrames, fNeedFileInfo, nullptr);
}

void StackTrace___::CaptureStackTrace(Int32 skipFrames, Boolean fNeedFileInfo, Exception e) {
  _methodsToSkip = skipFrames;
  StackFrameHelper stackFrameHelper = rt::newobj<StackFrameHelper>(nullptr);
  stackFrameHelper->InitializeSourceInfo(0, fNeedFileInfo, e);
  _numOfFrames = stackFrameHelper->GetNumberOfFrames();
  if (_methodsToSkip > _numOfFrames) {
    _methodsToSkip = _numOfFrames;
  }
  if (_numOfFrames != 0) {
    _stackFrames = rt::newarr<Array<StackFrame>>(_numOfFrames);
    for (Int32 i = 0; i < _numOfFrames; i++) {
      _stackFrames[i] = rt::newobj<StackFrame>(stackFrameHelper, i, fNeedFileInfo);
    }
    if (e == nullptr) {
      _methodsToSkip += CalculateFramesToSkip(stackFrameHelper, _numOfFrames);
    }
    _numOfFrames -= _methodsToSkip;
    if (_numOfFrames < 0) {
      _numOfFrames = 0;
    }
  }
}

void StackTrace___::ctor() {
  InitializeForCurrentThread(0, false);
}

void StackTrace___::ctor(Boolean fNeedFileInfo) {
  InitializeForCurrentThread(0, fNeedFileInfo);
}

void StackTrace___::ctor(Int32 skipFrames) {
  if (skipFrames < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("skipFrames", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  InitializeForCurrentThread(skipFrames, false);
}

void StackTrace___::ctor(Int32 skipFrames, Boolean fNeedFileInfo) {
  if (skipFrames < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("skipFrames", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  InitializeForCurrentThread(skipFrames, fNeedFileInfo);
}

void StackTrace___::ctor(Exception e) {
  if (e == nullptr) {
    rt::throw_exception<ArgumentNullException>("e");
  }
  InitializeForException(e, 0, false);
}

void StackTrace___::ctor(Exception e, Boolean fNeedFileInfo) {
  if (e == nullptr) {
    rt::throw_exception<ArgumentNullException>("e");
  }
  InitializeForException(e, 0, fNeedFileInfo);
}

void StackTrace___::ctor(Exception e, Int32 skipFrames) {
  if (e == nullptr) {
    rt::throw_exception<ArgumentNullException>("e");
  }
  if (skipFrames < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("skipFrames", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  InitializeForException(e, skipFrames, false);
}

void StackTrace___::ctor(Exception e, Int32 skipFrames, Boolean fNeedFileInfo) {
  if (e == nullptr) {
    rt::throw_exception<ArgumentNullException>("e");
  }
  if (skipFrames < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("skipFrames", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  InitializeForException(e, skipFrames, fNeedFileInfo);
}

void StackTrace___::ctor(StackFrame frame) {
  _stackFrames = rt::newarr<Array<StackFrame>>(1);
  _numOfFrames = 1;
}

StackFrame StackTrace___::GetFrame(Int32 index) {
  if (_stackFrames != nullptr && index < _numOfFrames && index >= 0) {
    return _stackFrames[index + _methodsToSkip];
  }
  return nullptr;
}

Array<StackFrame> StackTrace___::GetFrames() {
  if (_stackFrames == nullptr || _numOfFrames <= 0) {
    return Array<>::in::Empty<StackFrame>();
  }
  Array<StackFrame> array = rt::newarr<Array<StackFrame>>(_numOfFrames);
  Array<>::in::Copy(_stackFrames, _methodsToSkip, array, 0, _numOfFrames);
  return array;
}

String StackTrace___::ToString() {
  return ToString(TraceFormat::TrailingNewLine);
}

String StackTrace___::ToString(TraceFormat traceFormat) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(256);
  ToString(traceFormat, stringBuilder);
  return stringBuilder->ToString();
}

void StackTrace___::ToString(TraceFormat traceFormat, StringBuilder sb) {
  String word_At = SR::get_Word_At();
  String stackTrace_InFileLineNumber = SR::get_StackTrace_InFileLineNumber();
  Boolean flag = true;
  for (Int32 i = 0; i < _numOfFrames; i++) {
    StackFrame frame = GetFrame(i);
    auto& default = frame;
    MethodBase method = default == nullptr ? nullptr : default->GetMethod();
    if (!(method != nullptr) || (!ShowInStackTrace(method) && i != _numOfFrames - 1)) {
      continue;
    }
    if (flag) {
      flag = false;
    } else {
      sb->AppendLine();
    }
    sb->AppendFormat(CultureInfo::in::get_InvariantCulture(), "   {0} ", word_At);
    Boolean flag2 = false;
    Type declaringType = method->get_DeclaringType();
    String name = method->get_Name();
    Boolean flag3 = false;
    if (declaringType != nullptr && declaringType->IsDefined(rt::typeof<CompilerGeneratedAttribute>(), false)) {
      flag2 = rt::typeof<IAsyncStateMachine>()->IsAssignableFrom(declaringType);
      if (flag2 || rt::typeof<IEnumerator>()->IsAssignableFrom(declaringType)) {
        flag3 = TryResolveStateMachineMethod(method, declaringType);
      }
    }
    if (declaringType != nullptr) {
      String fullName = declaringType->get_FullName();
    }
    sb->Append(method->get_Name());
    MethodInfo methodInfo = rt::as<MethodInfo>(method);
    if ((Object)methodInfo != nullptr && methodInfo->get_IsGenericMethod()) {
      Array<Type> genericArguments = methodInfo->GetGenericArguments();
      sb->Append(91);
      Int32 k = 0;
      Boolean flag4 = true;
      for (; k < genericArguments->get_Length(); k++) {
        if (!flag4) {
          sb->Append(44);
        } else {
          flag4 = false;
        }
        sb->Append(genericArguments[k]->get_Name());
      }
      sb->Append(93);
    }
    Array<ParameterInfo> array = nullptr;
    try{
      array = method->GetParameters();
    } catch (...) {
    }
    if (array != nullptr) {
      sb->Append(40);
      Boolean flag5 = true;
      for (Int32 l = 0; l < array->get_Length(); l++) {
        if (!flag5) {
          sb->Append(", ");
        } else {
          flag5 = false;
        }
        String value = "<UnknownType>";
        if (array[l]->get_ParameterType() != nullptr) {
          value = array[l]->get_ParameterType()->get_Name();
        }
        sb->Append(value);
        sb->Append(32);
        sb->Append(array[l]->get_Name());
      }
      sb->Append(41);
    }
    if (flag3) {
      sb->Append(43);
      sb->Append(name);
      sb->Append(40)->Append(41);
    }
    if (frame->GetILOffset() != -1) {
      String fileName = frame->GetFileName();
      if (fileName != nullptr) {
        sb->Append(32);
        sb->AppendFormat(CultureInfo::in::get_InvariantCulture(), stackTrace_InFileLineNumber, fileName, frame->GetFileLineNumber());
      }
    }
    if (frame->get_IsLastFrameFromForeignExceptionStackTrace() && !flag2) {
      sb->AppendLine();
      sb->Append(SR::get_Exception_EndStackTraceFromPreviousThrow());
    }
  }
  if (traceFormat == TraceFormat::TrailingNewLine) {
    sb->AppendLine();
  }
}

Boolean StackTrace___::ShowInStackTrace(MethodBase mb) {
  if ((mb->get_MethodImplementationFlags() & MethodImplAttributes::AggressiveInlining) != 0) {
    return false;
  }
  if (mb->IsDefined(rt::typeof<StackTraceHiddenAttribute>(), false)) {
    return false;
  }
  Type declaringType = mb->get_DeclaringType();
  if (declaringType != nullptr && declaringType->IsDefined(rt::typeof<StackTraceHiddenAttribute>(), false)) {
    return false;
  }
  return true;
}

Boolean StackTrace___::TryResolveStateMachineMethod(MethodBase& method, Type& declaringType) {
  declaringType = method->get_DeclaringType();
  Type declaringType2 = declaringType->get_DeclaringType();
  if (declaringType2 == nullptr) {
    return false;
  }
  Array<MethodInfo> methods = declaringType2->GetMethods(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
  if (methods == nullptr) {
    return false;
  }
  Array<MethodInfo> array = methods;
}

} // namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace
