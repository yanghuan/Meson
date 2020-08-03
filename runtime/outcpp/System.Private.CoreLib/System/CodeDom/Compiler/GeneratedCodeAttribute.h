#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::CodeDom::Compiler {
namespace GeneratedCodeAttributeNamespace {
CLASS(GeneratedCodeAttribute) : public Attribute::in {
  public: String get_Tool();
  public: String get_Version();
  public: void Ctor(String tool, String version);
  private: String _tool;
  private: String _version;
};
} // namespace GeneratedCodeAttributeNamespace
using GeneratedCodeAttribute = GeneratedCodeAttributeNamespace::GeneratedCodeAttribute;
} // namespace System::Private::CoreLib::System::CodeDom::Compiler
