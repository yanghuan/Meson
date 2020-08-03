#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/LocalVariableInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(RuntimeType)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace RuntimeLocalVariableInfoNamespace {
CLASS(RuntimeLocalVariableInfo) : public LocalVariableInfo::in {
  public: Type get_LocalType();
  public: Int32 get_LocalIndex();
  public: Boolean get_IsPinned();
  private: void Ctor();
  private: RuntimeType _type;
  private: Int32 _localIndex;
  private: Boolean _isPinned;
};
} // namespace RuntimeLocalVariableInfoNamespace
using RuntimeLocalVariableInfo = RuntimeLocalVariableInfoNamespace::RuntimeLocalVariableInfo;
} // namespace System::Private::CoreLib::System::Reflection
