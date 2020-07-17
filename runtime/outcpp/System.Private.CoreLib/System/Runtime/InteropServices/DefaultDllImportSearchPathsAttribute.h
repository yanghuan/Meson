#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class DllImportSearchPath;
namespace DefaultDllImportSearchPathsAttributeNamespace {
CLASS(DefaultDllImportSearchPathsAttribute) {
  public: DllImportSearchPath get_Paths() { return Paths; }
  public: void Ctor(DllImportSearchPath paths);
  private: DllImportSearchPath Paths;
};
} // namespace DefaultDllImportSearchPathsAttributeNamespace
using DefaultDllImportSearchPathsAttribute = DefaultDllImportSearchPathsAttributeNamespace::DefaultDllImportSearchPathsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
