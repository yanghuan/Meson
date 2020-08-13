#include "ResolveEventArgs-dep.h"

namespace System::Private::CoreLib::System::ResolveEventArgsNamespace {
void ResolveEventArgs___::ctor(String name) {
  Name = name;
}

void ResolveEventArgs___::ctor(String name, Assembly requestingAssembly) {
  Name = name;
  RequestingAssembly = requestingAssembly;
}

} // namespace System::Private::CoreLib::System::ResolveEventArgsNamespace
