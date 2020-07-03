#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ResolveEventArgsNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(ResolveEventArgs) {
  private: String Name;
  private: Assembly RequestingAssembly;
};
} // namespace ResolveEventArgsNamespace
using ResolveEventArgs = ResolveEventArgsNamespace::ResolveEventArgs;
} // namespace System::Private::CoreLib::System
