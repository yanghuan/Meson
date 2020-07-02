#pragma once

namespace System::Private::CoreLib::System::IO {
enum class FileMode {
  CreateNew = 1,
  Create = 2,
  Open = 3,
  OpenOrCreate = 4,
  Truncate = 5,
  Append = 6,
};
} // namespace System::Private::CoreLib::System::IO
