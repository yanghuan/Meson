#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/Label.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace __ExceptionInfoNamespace {
CLASS(__ExceptionInfo) {
  private: void MarkHelper(Int32 catchorfilterAddr, Int32 catchEndAddr, Type catchClass, Int32 type);
  public: void MarkFilterAddr(Int32 filterAddr);
  public: void MarkFaultAddr(Int32 faultAddr);
  public: void MarkCatchAddr(Int32 catchAddr, Type catchException);
  public: void MarkFinallyAddr(Int32 finallyAddr, Int32 endCatchAddr);
  public: void Done(Int32 endAddr);
  public: Int32 GetStartAddress();
  public: Int32 GetEndAddress();
  public: Int32 GetFinallyEndAddress();
  public: Label GetEndLabel();
  public: Array<Int32> GetFilterAddresses();
  public: Array<Int32> GetCatchAddresses();
  public: Array<Int32> GetCatchEndAddresses();
  public: Array<Type> GetCatchClass();
  public: Int32 GetNumberOfCatches();
  public: Array<Int32> GetExceptionTypes();
  public: void SetFinallyEndLabel(Label lbl);
  public: Boolean IsInner(__ExceptionInfo exc);
  public: Int32 GetCurrentState();
  public: Int32 m_startAddr;
  public: Array<Int32> m_filterAddr;
  public: Array<Int32> m_catchAddr;
  public: Array<Int32> m_catchEndAddr;
  public: Array<Int32> m_type;
  public: Array<Type> m_catchClass;
  public: Label m_endLabel;
  public: Label m_finallyEndLabel;
  public: Int32 m_endAddr;
  public: Int32 m_endFinally;
  public: Int32 m_currentCatch;
  private: Int32 m_currentState;
};
} // namespace __ExceptionInfoNamespace
using __ExceptionInfo = __ExceptionInfoNamespace::__ExceptionInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
