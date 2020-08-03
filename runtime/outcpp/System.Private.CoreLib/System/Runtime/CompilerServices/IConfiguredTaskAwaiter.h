#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IConfiguredTaskAwaiterNamespace {
CLASS(IConfiguredTaskAwaiter) : public Object::in {
};
} // namespace IConfiguredTaskAwaiterNamespace
using IConfiguredTaskAwaiter = IConfiguredTaskAwaiterNamespace::IConfiguredTaskAwaiter;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
