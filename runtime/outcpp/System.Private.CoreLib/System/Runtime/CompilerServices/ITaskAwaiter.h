#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ITaskAwaiterNamespace {
CLASS(ITaskAwaiter) : public Object::in {
};
} // namespace ITaskAwaiterNamespace
using ITaskAwaiter = ITaskAwaiterNamespace::ITaskAwaiter;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
