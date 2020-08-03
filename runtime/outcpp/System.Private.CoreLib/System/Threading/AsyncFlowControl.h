#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(Thread)
namespace AsyncFlowControlNamespace {
struct AsyncFlowControl : public valueType<AsyncFlowControl> {
  public: void Initialize(Thread currentThread);
  public: void Undo();
  public: void Dispose();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(AsyncFlowControl obj);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(AsyncFlowControl a, AsyncFlowControl b);
  public: static Boolean op_Inequality(AsyncFlowControl a, AsyncFlowControl b);
  private: Thread _thread;
};
} // namespace AsyncFlowControlNamespace
using AsyncFlowControl = AsyncFlowControlNamespace::AsyncFlowControl;
} // namespace System::Private::CoreLib::System::Threading
