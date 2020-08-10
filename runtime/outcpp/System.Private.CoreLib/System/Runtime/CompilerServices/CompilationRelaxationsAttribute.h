#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class CompilationRelaxations;
namespace CompilationRelaxationsAttributeNamespace {
CLASS(CompilationRelaxationsAttribute) : public Attribute::in {
  public: Int32 get_CompilationRelaxations() { return CompilationRelaxations; }
  public: void ctor(Int32 relaxations);
  public: void ctor(CompilationRelaxations relaxations);
  private: Int32 CompilationRelaxations;
};
} // namespace CompilationRelaxationsAttributeNamespace
using CompilationRelaxationsAttribute = CompilationRelaxationsAttributeNamespace::CompilationRelaxationsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
