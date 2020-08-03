#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyTrademarkAttributeNamespace {
CLASS(AssemblyTrademarkAttribute) : public Attribute::in {
  public: String get_Trademark() { return Trademark; }
  public: void Ctor(String trademark);
  private: String Trademark;
};
} // namespace AssemblyTrademarkAttributeNamespace
using AssemblyTrademarkAttribute = AssemblyTrademarkAttributeNamespace::AssemblyTrademarkAttribute;
} // namespace System::Private::CoreLib::System::Reflection
