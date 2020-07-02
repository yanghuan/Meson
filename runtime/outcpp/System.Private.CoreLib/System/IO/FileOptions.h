#pragma once

namespace System::Private::CoreLib::System::IO {
enum class FileOptions {
  None = 0,
  WriteThrough = -2147483647 - 1,
  Asynchronous = 1073741824,
  RandomAccess = 268435456,
  DeleteOnClose = 67108864,
  SequentialScan = 134217728,
  Encrypted = 16384,
};
} // namespace System::Private::CoreLib::System::IO
