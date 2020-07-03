#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyCopyrightAttributeNamespace {
CLASS(AssemblyCopyrightAttribute) {
  private: String Copyright;
};
} // namespace AssemblyCopyrightAttributeNamespace
using AssemblyCopyrightAttribute = AssemblyCopyrightAttributeNamespace::AssemblyCopyrightAttribute;
} // namespace System::Private::CoreLib::System::Reflection
