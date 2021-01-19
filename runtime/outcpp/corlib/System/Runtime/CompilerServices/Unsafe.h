#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace corlib::System::Runtime::CompilerServices {
namespace UnsafeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(Unsafe) : public object {
};
} // namespace UnsafeNamespace
using Unsafe = UnsafeNamespace::Unsafe;
} // namespace corlib::System::Runtime::CompilerServices
