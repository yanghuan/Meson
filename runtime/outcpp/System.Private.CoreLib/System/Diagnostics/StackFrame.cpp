#include "StackFrame-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::StackFrameNamespace {
using namespace System::Reflection;

Boolean StackFrame___::get_IsLastFrameFromForeignExceptionStackTrace() {
  return _isLastFrameFromForeignExceptionStackTrace;
}

void StackFrame___::ctor(StackFrameHelper stackFrameHelper, Int32 skipFrames, Boolean needFileInfo) {
  _method = stackFrameHelper->GetMethodBase(skipFrames);
  _nativeOffset = stackFrameHelper->GetOffset(skipFrames);
  _ilOffset = stackFrameHelper->GetILOffset(skipFrames);
  _isLastFrameFromForeignExceptionStackTrace = stackFrameHelper->IsLastFrameFromForeignExceptionStackTrace(skipFrames);
  if (needFileInfo) {
    _fileName = stackFrameHelper->GetFilename(skipFrames);
    _lineNumber = stackFrameHelper->GetLineNumber(skipFrames);
    _columnNumber = stackFrameHelper->GetColumnNumber(skipFrames);
  }
}

void StackFrame___::BuildStackFrame(Int32 skipFrames, Boolean needFileInfo) {
  StackFrameHelper stackFrameHelper = rt::newobj<StackFrameHelper>(nullptr);
  stackFrameHelper->InitializeSourceInfo(0, needFileInfo, nullptr);
  Int32 numberOfFrames = stackFrameHelper->GetNumberOfFrames();
  skipFrames += StackTrace::in::CalculateFramesToSkip(stackFrameHelper, numberOfFrames);
  if (numberOfFrames - skipFrames > 0) {
    _method = stackFrameHelper->GetMethodBase(skipFrames);
    _nativeOffset = stackFrameHelper->GetOffset(skipFrames);
    _ilOffset = stackFrameHelper->GetILOffset(skipFrames);
    if (needFileInfo) {
      _fileName = stackFrameHelper->GetFilename(skipFrames);
      _lineNumber = stackFrameHelper->GetLineNumber(skipFrames);
      _columnNumber = stackFrameHelper->GetColumnNumber(skipFrames);
    }
  }
}

Boolean StackFrame___::AppendStackFrameWithoutMethodBase(StringBuilder sb) {
  return false;
}

void StackFrame___::InitMembers() {
  _nativeOffset = -1;
  _ilOffset = -1;
}

void StackFrame___::ctor() {
  InitMembers();
  BuildStackFrame(0, false);
}

void StackFrame___::ctor(Boolean needFileInfo) {
  InitMembers();
  BuildStackFrame(0, needFileInfo);
}

void StackFrame___::ctor(Int32 skipFrames) {
  InitMembers();
  BuildStackFrame(skipFrames, false);
}

void StackFrame___::ctor(Int32 skipFrames, Boolean needFileInfo) {
  InitMembers();
  BuildStackFrame(skipFrames, needFileInfo);
}

void StackFrame___::ctor(String fileName, Int32 lineNumber) {
  InitMembers();
  BuildStackFrame(0, false);
  _fileName = fileName;
  _lineNumber = lineNumber;
}

void StackFrame___::ctor(String fileName, Int32 lineNumber, Int32 colNumber) {
  _columnNumber = colNumber;
}

MethodBase StackFrame___::GetMethod() {
  return _method;
}

Int32 StackFrame___::GetNativeOffset() {
  return _nativeOffset;
}

Int32 StackFrame___::GetILOffset() {
  return _ilOffset;
}

String StackFrame___::GetFileName() {
  return _fileName;
}

Int32 StackFrame___::GetFileLineNumber() {
  return _lineNumber;
}

Int32 StackFrame___::GetFileColumnNumber() {
  return _columnNumber;
}

String StackFrame___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(255);
  Boolean flag2;
  if (_method != nullptr) {
    stringBuilder->Append(_method->get_Name());
    MethodInfo methodInfo = rt::as<MethodInfo>(_method);
    if ((Object)methodInfo != nullptr && methodInfo->get_IsGenericMethod()) {
      Array<Type> genericArguments = methodInfo->GetGenericArguments();
      stringBuilder->Append(60);
      Int32 i = 0;
      Boolean flag = true;
      for (; i < genericArguments->get_Length(); i++) {
        if (!flag) {
          stringBuilder->Append(44);
        } else {
          flag = false;
        }
        stringBuilder->Append(genericArguments[i]->get_Name());
      }
      stringBuilder->Append(62);
    }
    flag2 = true;
  } else {
    flag2 = AppendStackFrameWithoutMethodBase(stringBuilder);
  }
  if (flag2) {
    stringBuilder->Append(" at offset ");
    if (_nativeOffset == -1) {
      stringBuilder->Append("<offset unknown>");
    } else {
      stringBuilder->Append(_nativeOffset);
    }
    stringBuilder->Append(" in file:line:column ");
    String as = _fileName;
    stringBuilder->Append(as != nullptr ? as : "<filename unknown>");
    stringBuilder->Append(58);
    stringBuilder->Append(_lineNumber);
    stringBuilder->Append(58);
    stringBuilder->Append(_columnNumber);
  } else {
    stringBuilder->Append("<null>");
  }
  stringBuilder->AppendLine();
  return stringBuilder->ToString();
}

} // namespace System::Private::CoreLib::System::Diagnostics::StackFrameNamespace
