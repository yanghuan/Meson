#include "StackTrace-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
#include <System.Private.CoreLib/System/Collections/IEnumerator.h>
#include <System.Private.CoreLib/System/Diagnostics/StackFrame-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTraceHiddenAttribute-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodImplAttributes.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncIteratorStateMachineAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CompilerGeneratedAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachine.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IteratorStateMachineAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StateMachineAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
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
      String namespace一 = declaringType->get_Namespace();
      if (namespace一 == nullptr || !String::in::Equals(namespace一, "System.Diagnostics", StringComparison::Ordinal)) {
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
  String resourceString = SR::GetResourceString("Word_At", "at");
  String resourceString2 = SR::GetResourceString("StackTrace_InFileLineNumber", "in {0}:line {1}");
  Boolean flag = true;
  for (Int32 i = 0; i < _numOfFrames; i++) {
    StackFrame frame = GetFrame(i);
    MethodBase method = (frame != nullptr) ? frame->GetMethod() : nullptr;
    if (!(method != nullptr) || (!ShowInStackTrace(method) && i != _numOfFrames - 1)) {
      continue;
    }
    if (flag) {
      flag = false;
    } else {
      sb->AppendLine();
    }
    sb->AppendFormat(CultureInfo::in::get_InvariantCulture(), "   {0} ", resourceString);
    Boolean flag2 = false;
    Type declaringType = method->get_DeclaringType();
    String name = method->get_Name();
    Boolean flag3 = false;
    if (declaringType != nullptr && declaringType->IsDefined(typeof<CompilerGeneratedAttribute>(), false)) {
      flag2 = declaringType->IsAssignableTo(typeof<IAsyncStateMachine>());
      if (flag2 || declaringType->IsAssignableTo(typeof<IEnumerator>())) {
        flag3 = TryResolveStateMachineMethod(method, declaringType);
      }
    }
    if (declaringType != nullptr) {
      String fullName = declaringType->get_FullName();
      for (Char&& c : *fullName) {
        sb->Append((c == '+') ? '.' : c);
      }
      sb->Append((Char)'.');
    }
    sb->Append(method->get_Name());
    MethodInfo methodInfo = rt::as<MethodInfo>(method);
    if ((Object)methodInfo != nullptr && methodInfo->get_IsGenericMethod()) {
      Array<Type> genericArguments = methodInfo->GetGenericArguments();
      sb->Append((Char)'[');
      Int32 k = 0;
      Boolean flag4 = true;
      for (; k < genericArguments->get_Length(); k++) {
        if (!flag4) {
          sb->Append((Char)',');
        } else {
          flag4 = false;
        }
        sb->Append(genericArguments[k]->get_Name());
      }
      sb->Append((Char)']');
    }
    Array<ParameterInfo> array = nullptr;
    try {
      array = method->GetParameters();
    } catch (...) {
    }
    if (array != nullptr) {
      sb->Append((Char)'(');
      Boolean flag5 = true;
      for (Int32 l = 0; l < array->get_Length(); l++) {
        if (!flag5) {
          sb->Append((String)", ");
        } else {
          flag5 = false;
        }
        String value = "<UnknownType>";
        if (array[l]->get_ParameterType() != nullptr) {
          value = array[l]->get_ParameterType()->get_Name();
        }
        sb->Append(value);
        sb->Append((Char)' ');
        sb->Append(array[l]->get_Name());
      }
      sb->Append((Char)')');
    }
    if (flag3) {
      sb->Append((Char)'+');
      sb->Append(name);
      sb->Append((Char)'(')->Append((Char)')');
    }
    if (frame->GetILOffset() != -1) {
      String fileName = frame->GetFileName();
      if (fileName != nullptr) {
        sb->Append((Char)' ');
        sb->AppendFormat(CultureInfo::in::get_InvariantCulture(), resourceString2, fileName, frame->GetFileLineNumber());
      }
    }
    if (frame->get_IsLastFrameFromForeignExceptionStackTrace() && !flag2) {
      sb->AppendLine();
      sb->Append(SR::GetResourceString("Exception_EndStackTraceFromPreviousThrow", "--- End of stack trace from previous location ---"));
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
  if (mb->IsDefined(typeof<StackTraceHiddenAttribute>(), false)) {
    return false;
  }
  Type declaringType = mb->get_DeclaringType();
  if (declaringType != nullptr && declaringType->IsDefined(typeof<StackTraceHiddenAttribute>(), false)) {
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
  for (MethodInfo&& methodInfo : *array) {
    IEnumerable<StateMachineAttribute> customAttributes = CustomAttributeExtensions::GetCustomAttributes<StateMachineAttribute>(methodInfo, false);
    if (customAttributes == nullptr) {
      continue;
    }
    Boolean flag = false;
    Boolean flag2 = false;
    for (StateMachineAttribute&& item : *customAttributes) {
      if (item->get_StateMachineType() == declaringType) {
        flag = true;
        flag2 = (flag2 || rt::is<IteratorStateMachineAttribute>(item) || rt::is<AsyncIteratorStateMachineAttribute>(item));
      }
    }
    if (flag) {
      method = methodInfo;
      declaringType = methodInfo->get_DeclaringType();
      return flag2;
    }
  }
  return false;
}

} // namespace System::Private::CoreLib::System::Diagnostics::StackTraceNamespace
