#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace LocalVariableInfoNamespace {
CLASS(LocalVariableInfo) {
  public: Type get_LocalType();
  public: Int32 get_LocalIndex();
  public: Boolean get_IsPinned();
  public: String ToString();
};
} // namespace LocalVariableInfoNamespace
using LocalVariableInfo = LocalVariableInfoNamespace::LocalVariableInfo;
} // namespace System::Private::CoreLib::System::Reflection
