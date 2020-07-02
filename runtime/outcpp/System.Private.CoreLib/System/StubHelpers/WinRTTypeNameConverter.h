#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace WinRTTypeNameConverterNamespace {
class WinRTTypeNameConverter {
  public: static String ConvertToWinRTTypeName(Type managedType, Boolean& isPrimitive);
  public: static Type GetTypeFromWinRTTypeName(String typeName, Boolean& isPrimitive);
};
} // namespace WinRTTypeNameConverterNamespace
using WinRTTypeNameConverter = WinRTTypeNameConverterNamespace::WinRTTypeNameConverter;
} // namespace System::Private::CoreLib::System::StubHelpers
