#include "Error-dep.h"

namespace System::Console::System::IO::ErrorNamespace {
Exception Error::GetFileNotOpen() {
  return nullptr;
};

Exception Error::GetReadNotSupported() {
  return nullptr;
};

Exception Error::GetSeekNotSupported() {
  return nullptr;
};

Exception Error::GetWriteNotSupported() {
  return nullptr;
};

} // namespace System::Console::System::IO::ErrorNamespace
