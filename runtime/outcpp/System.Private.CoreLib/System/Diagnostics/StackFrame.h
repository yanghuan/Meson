#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace StackFrameNamespace {
using namespace Reflection;
using namespace Text;
CLASS(StackFrame) {
  public: Boolean get_IsLastFrameFromForeignExceptionStackTrace();
  private: void BuildStackFrame(Int32 skipFrames, Boolean needFileInfo);
  private: Boolean AppendStackFrameWithoutMethodBase(StringBuilder sb);
  private: void InitMembers();
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
  public: static Int32 OFFSET_UNKNOWN;
};
} // namespace StackFrameNamespace
using StackFrame = StackFrameNamespace::StackFrame;
} // namespace System::Private::CoreLib::System::Diagnostics
