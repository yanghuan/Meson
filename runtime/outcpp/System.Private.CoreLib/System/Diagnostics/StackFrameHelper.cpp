#include "StackFrameHelper-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/StackFrameHelper-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodInfoStub-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::StackFrameHelperNamespace {
using namespace System::Reflection;

void StackFrameHelper___::ctor(Thread target) {
  targetThread = target;
  rgMethodHandle = nullptr;
  rgiMethodToken = nullptr;
  rgiOffset = nullptr;
  rgiILOffset = nullptr;
  rgAssemblyPath = nullptr;
  rgAssembly = nullptr;
  rgLoadedPeAddress = nullptr;
  rgiLoadedPeSize = nullptr;
  rgInMemoryPdbAddress = nullptr;
  rgiInMemoryPdbSize = nullptr;
  dynamicMethods = nullptr;
  rgFilename = nullptr;
  rgiLineNumber = nullptr;
  rgiColumnNumber = nullptr;
  rgiLastFrameFromForeignExceptionStackTrace = nullptr;
  iFrameCount = 0;
}

void StackFrameHelper___::InitializeSourceInfo(Int32 iSkip, Boolean fNeedFileInfo, Exception exception) {
  StackTrace::in::GetStackFramesInternal((StackFrameHelper)this, iSkip, fNeedFileInfo, exception);
  if (!fNeedFileInfo || t_reentrancy > 0) {
    return;
  }
  t_reentrancy++;
  try{
    if (s_getSourceLineInfo != nullptr) {
    }
    Type type = Type::in::GetType("System.Diagnostics.StackTraceSymbols, System.Diagnostics.StackTrace, Version=4.0.1.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", false);
    if (!(type == nullptr)) {
      Array<Type> types = rt::newarr<Array<Type>>(11);
    }
  } catch (...) {
  } finally: {
    t_reentrancy--;
  }
}

MethodBase StackFrameHelper___::GetMethodBase(Int32 i) {
  IntPtr intPtr = rgMethodHandle[i];
  if (intPtr == IntPtr::Zero) {
    return nullptr;
  }
  IRuntimeMethodInfo typicalMethodDefinition = RuntimeMethodHandle::GetTypicalMethodDefinition(rt::newobj<RuntimeMethodInfoStub>(intPtr, (StackFrameHelper)this));
  return RuntimeType::in::GetMethodBase(typicalMethodDefinition);
}

Int32 StackFrameHelper___::GetOffset(Int32 i) {
  return rgiOffset[i];
}

Int32 StackFrameHelper___::GetILOffset(Int32 i) {
  return rgiILOffset[i];
}

String StackFrameHelper___::GetFilename(Int32 i) {
  Array<String> array = rgFilename;
  if (array == nullptr) {
    return nullptr;
  }
  return array[i];
}

Int32 StackFrameHelper___::GetLineNumber(Int32 i) {
  if (rgiLineNumber != nullptr) {
    return rgiLineNumber[i];
  }
  return 0;
}

Int32 StackFrameHelper___::GetColumnNumber(Int32 i) {
  if (rgiColumnNumber != nullptr) {
    return rgiColumnNumber[i];
  }
  return 0;
}

Boolean StackFrameHelper___::IsLastFrameFromForeignExceptionStackTrace(Int32 i) {
  if (rgiLastFrameFromForeignExceptionStackTrace != nullptr) {
    return rgiLastFrameFromForeignExceptionStackTrace[i];
  }
  return false;
}

Int32 StackFrameHelper___::GetNumberOfFrames() {
  return iFrameCount;
}

} // namespace System::Private::CoreLib::System::Diagnostics::StackFrameHelperNamespace
