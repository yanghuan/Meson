#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace LocalBuilderNamespace {
CLASS(LocalBuilder) {
  public: Boolean get_IsPinned();
  public: Type get_LocalType();
  public: Int32 get_LocalIndex();
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