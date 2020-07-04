#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CompilationRelaxationsAttributeNamespace {
CLASS(CompilationRelaxationsAttribute) {
  public: Int32 get_CompilationRelaxations() { return CompilationRelaxations; }
  private: Int32 CompilationRelaxations;
};
} // namespace CompilationRelaxationsAttributeNamespace
using CompilationRelaxationsAttribute = CompilationRelaxationsAttributeNamespace::CompilationRelaxationsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
