#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARDS(Int16)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class FlowControl;
enum class OpCodeType;
enum class OpCodeValues;
enum class OperandType;
enum class StackBehaviour;
namespace OpCodeNamespace {
struct OpCode : public valueType<OpCode> {
  using interface = rt::TypeList<IEquatable<OpCode>>;
  public: OperandType get_OperandType();
  public: FlowControl get_FlowControl();
  public: OpCodeType get_OpCodeType();
  public: StackBehaviour get_StackBehaviourPop();
  public: StackBehaviour get_StackBehaviourPush();
  public: Int32 get_Size();
  public: Int16 get_Value();
  public: String get_Name();
  public: explicit OpCode(OpCodeValues value, Int32 flags);
  public: Boolean EndsUncondJmpBlk();
  public: Int32 StackChange();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(OpCode obj);
  public: static Boolean op_Equality(OpCode a, OpCode b);
  public: static Boolean op_Inequality(OpCode a, OpCode b);
  public: Int32 GetHashCode();
  public: String ToString();
  public: explicit OpCode() {}
  private: OpCodeValues m_value;
  private: Int32 m_flags;
  private: static Array<String> g_nameCache;
};
} // namespace OpCodeNamespace
using OpCode = OpCodeNamespace::OpCode;
} // namespace System::Private::CoreLib::System::Reflection::Emit
