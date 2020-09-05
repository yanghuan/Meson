#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace EmptyNamespace {
CLASS(Empty) : public object {
  public: void ctor();
  public: String ToString();
  public: static void cctor();
  public: static Empty Value;
};
} // namespace EmptyNamespace
using Empty = EmptyNamespace::Empty;
} // namespace System::Private::CoreLib::System
