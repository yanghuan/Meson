#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/LocalVariableInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace LocalBuilderNamespace {
CLASS(LocalBuilder) : public LocalVariableInfo::in {
  public: Boolean get_IsPinned();
  public: Type get_LocalType();
  public: Int32 get_LocalIndex();
  public: void Ctor(Int32 localIndex, Type localType, MethodInfo methodBuilder);
  public: void Ctor(Int32 localIndex, Type localType, MethodInfo methodBuilder, Boolean isPinned);
  public: Int32 GetLocalIndex();
  public: MethodInfo GetMethodBuilder();
  public: void SetLocalSymInfo(String name);
  public: void SetLocalSymInfo(String name, Int32 startOffset, Int32 endOffset);
  private: Int32 m_localIndex;
  private: Type m_localType;
  private: MethodInfo m_methodBuilder;
  private: Boolean m_isPinned;
};
} // namespace LocalBuilderNamespace
using LocalBuilder = LocalBuilderNamespace::LocalBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
