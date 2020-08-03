#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyCopyrightAttributeNamespace {
CLASS(AssemblyCopyrightAttribute) : public Attribute::in {
  public: String get_Copyright() { return Copyright; }
  public: void Ctor(String copyright);
  private: String Copyright;
};
} // namespace AssemblyCopyrightAttributeNamespace
using AssemblyCopyrightAttribute = AssemblyCopyrightAttributeNamespace::AssemblyCopyrightAttribute;
} // namespace System::Private::CoreLib::System::Reflection
