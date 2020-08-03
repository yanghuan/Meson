#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ProgIdAttributeNamespace {
CLASS(ProgIdAttribute) : public Attribute::in {
  public: String get_Value() { return Value; }
  public: void Ctor(String progId);
  private: String Value;
};
} // namespace ProgIdAttributeNamespace
using ProgIdAttribute = ProgIdAttributeNamespace::ProgIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
