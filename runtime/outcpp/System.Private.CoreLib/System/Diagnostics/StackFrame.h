#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics {
FORWARD(StackFrameHelper)
namespace StackFrameNamespace {
using namespace System::Reflection;
using namespace System::Text;
CLASS(StackFrame) : public object {
  public: Boolean get_IsLastFrameFromForeignExceptionStackTrace();
  public: void ctor(StackFrameHelper stackFrameHelper, Int32 skipFrames, Boolean needFileInfo);
  private: void BuildStackFrame(Int32 skipFrames, Boolean needFileInfo);
  private: Boolean AppendStackFrameWithoutMethodBase(StringBuilder sb);
  private: void InitMembers();
  public: void ctor();
  public: void ctor(Boolean needFileInfo);
  public: void ctor(Int32 skipFrames);
  public: void ctor(Int32 skipFrames, Boolean needFileInfo);
  public: void ctor(String fileName, Int32 lineNumber);
  public: void ctor(String fileName, Int32 lineNumber, Int32 colNumber);
  public: MethodBase GetMethod();
  public: Int32 GetNativeOffset();
  public: Int32 GetILOffset();
  public: String GetFileName();
  public: Int32 GetFileLineNumber();
  public: Int32 GetFileColumnNumber();
  public: String ToString();
  private: MethodBase _method;
  private: Int32 _nativeOffset;
  private: Int32 _ilOffset;
  private: String _fileName;
  private: Int32 _lineNumber;
  private: Int32 _columnNumber;
  private: Boolean _isLastFrameFromForeignExceptionStackTrace;
  public: static constexpr Int32 OFFSET_UNKNOWN = -1;
};
} // namespace StackFrameNamespace
using StackFrame = StackFrameNamespace::StackFrame;
} // namespace System::Private::CoreLib::System::Diagnostics
