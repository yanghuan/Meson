#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyTrademarkAttributeNamespace {
CLASS(AssemblyTrademarkAttribute) {
  private: String Trademark;
};
} // namespace AssemblyTrademarkAttributeNamespace
using AssemblyTrademarkAttribute = AssemblyTrademarkAttributeNamespace::AssemblyTrademarkAttribute;
} // namespace System::Private::CoreLib::System::Reflection
