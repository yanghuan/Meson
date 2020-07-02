#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
namespace AutoResetEventNamespace {
CLASS(AutoResetEvent) {
};
} // namespace AutoResetEventNamespace
using AutoResetEvent = AutoResetEventNamespace::AutoResetEvent;
} // namespace System::Private::CoreLib::System::Threading
