#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::StubHelpers {
enum class TypeKind;
namespace TypeNameNativeNamespace {
struct TypeNameNative {
  public: IntPtr typeName;
  public: TypeKind typeKind;
};
} // namespace TypeNameNativeNamespace
using TypeNameNative = TypeNameNativeNamespace::TypeNameNative;
} // namespace System::Private::CoreLib::System::StubHelpers
