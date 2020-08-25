#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ITaskAwaiterNamespace {
CLASS(ITaskAwaiter) : public object {
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITaskAwaiterNamespace
using ITaskAwaiter = ITaskAwaiterNamespace::ITaskAwaiter;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
