#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace IDisposableNamespace {
CLASS(IDisposable) : public Object::in {
  public: void Dispose();
};
} // namespace IDisposableNamespace
using IDisposable = IDisposableNamespace::IDisposable;
} // namespace System::Private::CoreLib::System
