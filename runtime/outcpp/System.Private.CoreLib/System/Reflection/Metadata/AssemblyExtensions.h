#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(QCallAssembly)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Metadata {
namespace AssemblyExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
class AssemblyExtensions {
  private: static Boolean InternalTryGetRawMetadata(QCallAssembly assembly, Byte*& blob, Int32& length);
  public: static Boolean TryGetRawMetadata(Assembly assembly, Byte*& blob, Int32& length);
};
} // namespace AssemblyExtensionsNamespace
using AssemblyExtensions = AssemblyExtensionsNamespace::AssemblyExtensions;
} // namespace System::Private::CoreLib::System::Reflection::Metadata
