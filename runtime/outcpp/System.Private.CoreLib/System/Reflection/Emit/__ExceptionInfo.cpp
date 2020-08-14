#include "__ExceptionInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ILGenerator-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::__ExceptionInfoNamespace {
void __ExceptionInfo___::ctor(Int32 startAddr, Label endLabel) {
  m_startAddr = startAddr;
  m_endAddr = -1;
  m_filterAddr = rt::newarr<Array<Int32>>(4);
  m_catchAddr = rt::newarr<Array<Int32>>(4);
  m_catchEndAddr = rt::newarr<Array<Int32>>(4);
  m_catchClass = rt::newarr<Array<Type>>(4);
  m_currentCatch = 0;
  m_endLabel = endLabel;
  m_type = rt::newarr<Array<Int32>>(4);
  m_endFinally = -1;
  m_currentState = 0;
}

void __ExceptionInfo___::MarkHelper(Int32 catchorfilterAddr, Int32 catchEndAddr, Type catchClass, Int32 type) {
  Int32 currentCatch = m_currentCatch;
  if (currentCatch >= m_catchAddr->get_Length()) {
    m_filterAddr = ILGenerator::in::EnlargeArray(m_filterAddr);
    m_catchAddr = ILGenerator::in::EnlargeArray(m_catchAddr);
    m_catchEndAddr = ILGenerator::in::EnlargeArray(m_catchEndAddr);
    m_catchClass = ILGenerator::in::EnlargeArray(m_catchClass);
    m_type = ILGenerator::in::EnlargeArray(m_type);
  }
  if (type == 1) {
    m_type[currentCatch] = type;
    m_filterAddr[currentCatch] = catchorfilterAddr;
    m_catchAddr[currentCatch] = -1;
    if (currentCatch > 0) {
      m_catchEndAddr[currentCatch - 1] = catchorfilterAddr;
    }
  } else {
    m_catchClass[currentCatch] = catchClass;
    if (m_type[currentCatch] != 1) {
      m_type[currentCatch] = type;
    }
    m_catchAddr[currentCatch] = catchorfilterAddr;
    if (currentCatch > 0 && m_type[currentCatch] != 1) {
      m_catchEndAddr[currentCatch - 1] = catchEndAddr;
    }
    m_catchEndAddr[currentCatch] = -1;
    m_currentCatch++;
  }
  if (m_endAddr == -1) {
    m_endAddr = catchorfilterAddr;
  }
}

void __ExceptionInfo___::MarkFilterAddr(Int32 filterAddr) {
  m_currentState = 1;
  MarkHelper(filterAddr, filterAddr, nullptr, 1);
}

void __ExceptionInfo___::MarkFaultAddr(Int32 faultAddr) {
  m_currentState = 4;
  MarkHelper(faultAddr, faultAddr, nullptr, 4);
}

void __ExceptionInfo___::MarkCatchAddr(Int32 catchAddr, Type catchException) {
  m_currentState = 2;
  MarkHelper(catchAddr, catchAddr, catchException, 0);
}

void __ExceptionInfo___::MarkFinallyAddr(Int32 finallyAddr, Int32 endCatchAddr) {
  if (m_endFinally != -1) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TooManyFinallyClause());
  }
  m_currentState = 3;
  m_endFinally = finallyAddr;
  MarkHelper(finallyAddr, endCatchAddr, nullptr, 2);
}

void __ExceptionInfo___::Done(Int32 endAddr) {
  m_catchEndAddr[m_currentCatch - 1] = endAddr;
  m_currentState = 5;
}

Int32 __ExceptionInfo___::GetStartAddress() {
  return m_startAddr;
}

Int32 __ExceptionInfo___::GetEndAddress() {
  return m_endAddr;
}

Int32 __ExceptionInfo___::GetFinallyEndAddress() {
  return m_endFinally;
}

Label __ExceptionInfo___::GetEndLabel() {
  return m_endLabel;
}

Array<Int32> __ExceptionInfo___::GetFilterAddresses() {
  return m_filterAddr;
}

Array<Int32> __ExceptionInfo___::GetCatchAddresses() {
  return m_catchAddr;
}

Array<Int32> __ExceptionInfo___::GetCatchEndAddresses() {
  return m_catchEndAddr;
}

Array<Type> __ExceptionInfo___::GetCatchClass() {
  return m_catchClass;
}

Int32 __ExceptionInfo___::GetNumberOfCatches() {
  return m_currentCatch;
}

Array<Int32> __ExceptionInfo___::GetExceptionTypes() {
  return m_type;
}

void __ExceptionInfo___::SetFinallyEndLabel(Label lbl) {
  m_finallyEndLabel = lbl;
}

Boolean __ExceptionInfo___::IsInner(__ExceptionInfo exc) {
  Int32 num = exc->m_currentCatch - 1;
  Int32 num2 = m_currentCatch - 1;
  if (exc->m_catchEndAddr[num] < m_catchEndAddr[num2]) {
    return true;
  }
  if (exc->m_catchEndAddr[num] != m_catchEndAddr[num2]) {
    return false;
  }
  return exc->GetEndAddress() > GetEndAddress();
}

Int32 __ExceptionInfo___::GetCurrentState() {
  return m_currentState;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::__ExceptionInfoNamespace
