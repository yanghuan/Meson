#include "OpCode-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace {
OperandType OpCode::get_OperandType() {
  return OperandType::ShortInlineVar;
};

FlowControl OpCode::get_FlowControl() {
  return FlowControl::Throw;
};

OpCodeType OpCode::get_OpCodeType() {
  return OpCodeType::Primitive;
};

StackBehaviour OpCode::get_StackBehaviourPop() {
  return StackBehaviour::Popref_popi_pop1;
};

StackBehaviour OpCode::get_StackBehaviourPush() {
  return StackBehaviour::Popref_popi_pop1;
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

void OpCode::Ctor(OpCodeValues value, Int32 flags) {
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

Boolean OpCode::op_Equality(OpCode a, OpCode b) {
  return Boolean();
};

Boolean OpCode::op_Inequality(OpCode a, OpCode b) {
  return Boolean();
};

Int32 OpCode::GetHashCode() {
  return Int32();
};

String OpCode::ToString() {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Reflection::Emit::OpCodeNamespace
