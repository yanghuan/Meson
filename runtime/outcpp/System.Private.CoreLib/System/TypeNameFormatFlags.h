#pragma once

namespace System::Private::CoreLib::System {
enum class TypeNameFormatFlags {
  FormatBasic = 0,
  FormatNamespace = 1,
  FormatFullInst = 2,
  FormatAssembly = 4,
  FormatSignature = 8,
  FormatNoVersion = 16,
  FormatAngleBrackets = 64,
  FormatStubInfo = 128,
  FormatGenericParam = 256,
};
} // namespace System::Private::CoreLib::System
