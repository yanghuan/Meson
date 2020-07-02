#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics {
FORWARD(StackFrameHelper)
FORWARD(StackFrame)
namespace StackTraceNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(StackTrace) {
  public: enum class TraceFormat {
    Normal = 0,
    TrailingNewLine = 1,
  };
  public: Int32 get_FrameCount();
  public: static void GetStackFramesInternal(StackFrameHelper sfh, Int32 iSkip, Boolean fNeedFileInfo, Exception e);
  public: static Int32 CalculateFramesToSkip(StackFrameHelper StackF, Int32 iNumFrames);
  private: void InitializeForException(Exception exception, Int32 skipFrames, Boolean fNeedFileInfo);
  private: void InitializeForCurrentThread(Int32 skipFrames, Boolean fNeedFileInfo);
  private: void CaptureStackTrace(Int32 skipFrames, Boolean fNeedFileInfo, Exception e);
  public: StackFrame GetFrame(Int32 index);
  public: Array<StackFrame> GetFrames();
  public: String ToString();
  public: String ToString(TraceFormat traceFormat);
  private: static Boolean ShowInStackTrace(MethodBase mb);
  private: static Boolean TryResolveStateMachineMethod(MethodBase& method, Type& declaringType);
  public: static Int32 METHODS_TO_SKIP;
  private: Int32 _numOfFrames;
  private: Int32 _methodsToSkip;
  private: Array<StackFrame> _stackFrames;
};
} // namespace StackTraceNamespace
using StackTrace = StackTraceNamespace::StackTrace;
} // namespace System::Private::CoreLib::System::Diagnostics
