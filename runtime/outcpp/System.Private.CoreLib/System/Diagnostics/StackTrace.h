#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics {
FORWARD(StackFrame)
FORWARD(StackFrameHelper)
namespace StackTraceNamespace {
using namespace Reflection;
using namespace Text;
CLASS(StackTrace) : public Object::in {
  public: enum class TraceFormat : int32_t {
    Normal = 0,
    TrailingNewLine = 1,
  };
  public: Int32 get_FrameCount();
  public: static void GetStackFramesInternal(StackFrameHelper sfh, Int32 iSkip, Boolean fNeedFileInfo, Exception e);
  public: static Int32 CalculateFramesToSkip(StackFrameHelper StackF, Int32 iNumFrames);
  private: void InitializeForException(Exception exception, Int32 skipFrames, Boolean fNeedFileInfo);
  private: void InitializeForCurrentThread(Int32 skipFrames, Boolean fNeedFileInfo);
  private: void CaptureStackTrace(Int32 skipFrames, Boolean fNeedFileInfo, Exception e);
  public: void ctor();
  public: void ctor(Boolean fNeedFileInfo);
  public: void ctor(Int32 skipFrames);
  public: void ctor(Int32 skipFrames, Boolean fNeedFileInfo);
  public: void ctor(Exception e);
  public: void ctor(Exception e, Boolean fNeedFileInfo);
  public: void ctor(Exception e, Int32 skipFrames);
  public: void ctor(Exception e, Int32 skipFrames, Boolean fNeedFileInfo);
  public: void ctor(StackFrame frame);
  public: StackFrame GetFrame(Int32 index);
  public: Array<StackFrame> GetFrames();
  public: String ToString();
  public: String ToString(TraceFormat traceFormat);
  public: void ToString(TraceFormat traceFormat, StringBuilder sb);
  private: static Boolean ShowInStackTrace(MethodBase mb);
  private: static Boolean TryResolveStateMachineMethod(MethodBase& method, Type& declaringType);
  public: static constexpr Int32 METHODS_TO_SKIP = 0;
  private: Int32 _numOfFrames;
  private: Int32 _methodsToSkip;
  private: Array<StackFrame> _stackFrames;
};
} // namespace StackTraceNamespace
using StackTrace = StackTraceNamespace::StackTrace;
} // namespace System::Private::CoreLib::System::Diagnostics
