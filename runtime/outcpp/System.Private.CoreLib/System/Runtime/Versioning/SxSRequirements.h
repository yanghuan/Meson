#pragma once

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class SxSRequirements {
  None = 0,
  AppDomainID = 1,
  ProcessID = 2,
  CLRInstanceID = 4,
  AssemblyName = 8,
  TypeName = 16,
};
} // namespace System::Private::CoreLib::System::Runtime::Versioning
