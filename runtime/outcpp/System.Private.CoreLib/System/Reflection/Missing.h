#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
namespace MissingNamespace {
CLASS(Missing) {
  public: static Missing Value;
};
} // namespace MissingNamespace
using Missing = MissingNamespace::Missing;
} // namespace System::Private::CoreLib::System::Reflection
