#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
FORWARDS(TypeNameNative)
} // namespace System::Private::CoreLib::System::StubHelpers
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(ICustomProperty)
namespace ICustomPropertyProviderImplNamespace {
using namespace ::System::Private::CoreLib::System::StubHelpers;
class ICustomPropertyProviderImpl {
  public: static ICustomProperty CreateProperty(Object target, String propertyName);
  public: static ICustomProperty CreateIndexedProperty(Object target, String propertyName, TypeNameNative* pIndexedParamType);
  public: static ICustomProperty CreateIndexedProperty(Object target, String propertyName, Type indexedParamType);
  public: static void GetType(Object target, TypeNameNative* pIndexedParamType);
};
} // namespace ICustomPropertyProviderImplNamespace
using ICustomPropertyProviderImpl = ICustomPropertyProviderImplNamespace::ICustomPropertyProviderImpl;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
