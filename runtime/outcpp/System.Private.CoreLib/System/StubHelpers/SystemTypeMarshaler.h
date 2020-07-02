#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
FORWARDS(TypeNameNative)
namespace SystemTypeMarshalerNamespace {
class SystemTypeMarshaler {
  public: static void ConvertToNative(Type managedType, TypeNameNative* pNativeType);
  public: static void ConvertToManaged(TypeNameNative* pNativeType, Type& managedType);
  public: static void ClearNative(TypeNameNative* pNativeType);
};
} // namespace SystemTypeMarshalerNamespace
using SystemTypeMarshaler = SystemTypeMarshalerNamespace::SystemTypeMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
