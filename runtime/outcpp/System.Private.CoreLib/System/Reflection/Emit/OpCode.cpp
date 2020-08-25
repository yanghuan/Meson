#include "OpCode-dep.h"

#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCode-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCodeValues.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace {
using namespace System::Threading;

OperandType OpCode::get_OperandType() {
  return (OperandType)(m_flags & 31);
}

FlowControl OpCode::get_FlowControl() {
  return (FlowControl)((m_flags >> 5) & 15);
}

OpCodeType OpCode::get_OpCodeType() {
  return (OpCodeType)((m_flags >> 9) & 7);
}

StackBehaviour OpCode::get_StackBehaviourPop() {
  return (StackBehaviour)((m_flags >> 12) & 31);
}

StackBehaviour OpCode::get_StackBehaviourPush() {
  return (StackBehaviour)((m_flags >> 17) & 31);
}

Int32 OpCode::get_Size() {
  return (m_flags >> 22) & 3;
}

Int16 OpCode::get_Value() {
  return (Int16)m_value;
}

String OpCode::get_Name() {
  if (get_Size() == 0) {
    return nullptr;
  }
  Array<String> array = g_nameCache;
  if (array == nullptr) {
    array = (g_nameCache = rt::newarr<Array<String>>(287));
  }
  OpCodeValues opCodeValues = (OpCodeValues)(UInt16)get_Value();
  Int32 num = (Int32)opCodeValues;
  if (num > 255) {
    if (num < 65024 || num > 65054) {
      return nullptr;
    }
    num = 256 + (num - 65024);
  }
  String text = Volatile::Read(array[num]);
  if (text != nullptr) {
    return text;
  }
  text = Enum::in::GetName(typeof<OpCodeValues>(), opCodeValues)->ToLowerInvariant()->Replace(95, 46);
  Volatile::Write(array[num], text);
  return text;
}

OpCode::OpCode(OpCodeValues value, Int32 flags) {
  m_value = value;
  m_flags = flags;
}

Boolean OpCode::EndsUncondJmpBlk() {
  return (m_flags & 16777216) != 0;
}

Int32 OpCode::StackChange() {
  return m_flags >> 28;
}

Boolean OpCode::Equals(Object obj) {
  if (rt::is<OpCode>(obj)) {
    OpCode obj2 = (OpCode)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean OpCode::Equals(OpCode obj) {
  return obj.get_Value() == get_Value();
}

Boolean OpCode::op_Equality(OpCode a, OpCode b) {
  return a.Equals(b);
}

Boolean OpCode::op_Inequality(OpCode a, OpCode b) {
  return !(a == b);
}

Int32 OpCode::GetHashCode() {
  return get_Value();
}

String OpCode::ToString() {
  return get_Name();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace
