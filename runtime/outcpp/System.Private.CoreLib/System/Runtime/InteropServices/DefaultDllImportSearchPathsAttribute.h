#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class DllImportSearchPath : int32_t;
namespace DefaultDllImportSearchPathsAttributeNamespace {
CLASS(DefaultDllImportSearchPathsAttribute) : public Attribute::in {
  public: DllImportSearchPath get_Paths() { return Paths; }
  public: void ctor(DllImportSearchPath paths);
  private: DllImportSearchPath Paths;
};
} // namespace DefaultDllImportSearchPathsAttributeNamespace
using DefaultDllImportSearchPathsAttribute = DefaultDllImportSearchPathsAttributeNamespace::DefaultDllImportSearchPathsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
