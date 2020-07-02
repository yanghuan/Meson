#include "OpCode-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace {
OperandType OpCode::get_OperandType() {
  return OperandType();
};
FlowControl OpCode::get_FlowControl() {
  return FlowControl();
};
OpCodeType OpCode::get_OpCodeType() {
  return OpCodeType();
};
StackBehaviour OpCode::get_StackBehaviourPop() {
  return StackBehaviour();
};
StackBehaviour OpCode::get_StackBehaviourPush() {
  return StackBehaviour();
};
Int32 OpCode::get_Size() {
  return Int32();
};
Int16 OpCode::get_Value() {
  return Int16();
};
String OpCode::get_Name() {
  return nullptr;
};
Boolean OpCode::EndsUncondJmpBlk() {
  return Boolean();
};
Int32 OpCode::StackChange() {
  return Int32();
};
Boolean OpCode::Equals(Object obj) {
  return Boolean();
};
Boolean OpCode::Equals(OpCode obj) {
  return Boolean();
};
Int32 OpCode::GetHashCode() {
  return Int32();
};
String OpCode::ToString() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace