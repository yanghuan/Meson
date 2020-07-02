#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int16)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class OperandType;
enum class FlowControl;
enum class OpCodeType;
enum class StackBehaviour;
enum class OpCodeValues;
namespace OpCodeNamespace {
struct OpCode {
  public: OperandType get_OperandType();
  public: FlowControl get_FlowControl();
  public: OpCodeType get_OpCodeType();
  public: StackBehaviour get_StackBehaviourPop();
  public: StackBehaviour get_StackBehaviourPush();
  public: Int32 get_Size();
  public: Int16 get_Value();
  public: String get_Name();
  public: Boolean EndsUncondJmpBlk();
  public: Int32 StackChange();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(OpCode obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: OpCodeValues m_value;
  private: Int32 m_flags;
  private: static Array<String> g_nameCache;
};
} // namespace OpCodeNamespace
using OpCode = OpCodeNamespace::OpCode;
} // namespace System::Private::CoreLib::System::Reflection::Emit
