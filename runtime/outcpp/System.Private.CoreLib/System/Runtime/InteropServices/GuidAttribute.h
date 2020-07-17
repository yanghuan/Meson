#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace GuidAttributeNamespace {
CLASS(GuidAttribute) {
  public: String get_Value() { return Value; }
  public: void Ctor(String guid);
  private: String Value;
};
} // namespace GuidAttributeNamespace
using GuidAttribute = GuidAttributeNamespace::GuidAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
