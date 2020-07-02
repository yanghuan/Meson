#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class INVOKEKIND {
  INVOKE_FUNC = 1,
  INVOKE_PROPERTYGET = 2,
  INVOKE_PROPERTYPUT = 4,
  INVOKE_PROPERTYPUTREF = 8,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
