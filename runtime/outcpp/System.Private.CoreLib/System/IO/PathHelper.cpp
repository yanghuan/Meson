#include "PathHelper-dep.h"

namespace System::Private::CoreLib::System::IO::PathHelperNamespace {
String PathHelper::Normalize(String path) {
  return nullptr;
};

String PathHelper::Normalize(ValueStringBuilder& path) {
  return nullptr;
};

void PathHelper::GetFullPathName(ReadOnlySpan<Char> path, ValueStringBuilder& builder) {
};

Int32 PathHelper::PrependDevicePathChars(ValueStringBuilder& content, Boolean isDosUnc, ValueStringBuilder& buffer) {
  return Int32();
};

String PathHelper::TryExpandShortFileName(ValueStringBuilder& outputBuilder, String originalPath) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::IO::PathHelperNamespace
