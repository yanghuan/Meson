#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(MethodBase)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Threading {
FORWARD(Thread)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Diagnostics {
namespace StackFrameHelperNamespace {
using namespace System::Reflection;
using namespace System::Threading;
CLASS(StackFrameHelper) : public object {
  private: CLASS(GetSourceLineInfoDelegate) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: void Invoke(Assembly assembly, String assemblyPath, IntPtr loadedPeAddress, Int32 loadedPeSize, IntPtr inMemoryPdbAddress, Int32 inMemoryPdbSize, Int32 methodToken, Int32 ilOffset, String& sourceFile, Int32& sourceLine, Int32& sourceColumn);
    public: IAsyncResult BeginInvoke(Assembly assembly, String assemblyPath, IntPtr loadedPeAddress, Int32 loadedPeSize, IntPtr inMemoryPdbAddress, Int32 inMemoryPdbSize, Int32 methodToken, Int32 ilOffset, String& sourceFile, Int32& sourceLine, Int32& sourceColumn, AsyncCallback callback, Object object);
    public: void EndInvoke(String& sourceFile, Int32& sourceLine, Int32& sourceColumn, IAsyncResult result);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  public: void ctor(Thread target);
  public: void InitializeSourceInfo(Int32 iSkip, Boolean fNeedFileInfo, Exception exception);
  public: MethodBase GetMethodBase(Int32 i);
  public: Int32 GetOffset(Int32 i);
  public: Int32 GetILOffset(Int32 i);
  public: String GetFilename(Int32 i);
  public: Int32 GetLineNumber(Int32 i);
  public: Int32 GetColumnNumber(Int32 i);
  public: Boolean IsLastFrameFromForeignExceptionStackTrace(Int32 i);
  public: Int32 GetNumberOfFrames();
  private: Thread targetThread;
  private: Array<Int32> rgiOffset;
  private: Array<Int32> rgiILOffset;
  private: Object dynamicMethods;
  private: Array<IntPtr> rgMethodHandle;
  private: Array<String> rgAssemblyPath;
  private: Array<Assembly> rgAssembly;
  private: Array<IntPtr> rgLoadedPeAddress;
  private: Array<Int32> rgiLoadedPeSize;
  private: Array<IntPtr> rgInMemoryPdbAddress;
  private: Array<Int32> rgiInMemoryPdbSize;
  private: Array<Int32> rgiMethodToken;
  private: Array<String> rgFilename;
  private: Array<Int32> rgiLineNumber;
  private: Array<Int32> rgiColumnNumber;
  private: Array<Boolean> rgiLastFrameFromForeignExceptionStackTrace;
  private: Int32 iFrameCount;
  private: static GetSourceLineInfoDelegate s_getSourceLineInfo;
  private: static Int32 t_reentrancy;
};
} // namespace StackFrameHelperNamespace
using StackFrameHelper = StackFrameHelperNamespace::StackFrameHelper;
} // namespace System::Private::CoreLib::System::Diagnostics
