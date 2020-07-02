#pragma once

namespace System::Private::CoreLib::System::IO {
enum class FileShare {
  None = 0,
  Read = 1,
  Write = 2,
  ReadWrite = 3,
  Delete = 4,
  Inheritable = 16,
};
} // namespace System::Private::CoreLib::System::IO
