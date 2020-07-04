#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::CodeDom::Compiler {
namespace GeneratedCodeAttributeNamespace {
CLASS(GeneratedCodeAttribute) {
  public: String get_Tool();
  public: String get_Version();
  private: String _tool;
  private: String _version;
};
} // namespace GeneratedCodeAttributeNamespace
using GeneratedCodeAttribute = GeneratedCodeAttributeNamespace::GeneratedCodeAttribute;
} // namespace System::Private::CoreLib::System::CodeDom::Compiler
