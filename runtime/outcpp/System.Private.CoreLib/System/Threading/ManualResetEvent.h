#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
namespace ManualResetEventNamespace {
CLASS(ManualResetEvent) {
};
} // namespace ManualResetEventNamespace
using ManualResetEvent = ManualResetEventNamespace::ManualResetEvent;
} // namespace System::Private::CoreLib::System::Threading
