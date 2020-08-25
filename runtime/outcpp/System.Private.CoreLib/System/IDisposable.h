#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace IDisposableNamespace {
CLASS(IDisposable) : public object {
  public: void Dispose();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDisposableNamespace
using IDisposable = IDisposableNamespace::IDisposable;
} // namespace System::Private::CoreLib::System
