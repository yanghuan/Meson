#pragma once

namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
enum class SymAddressKind {
  ILOffset = 1,
  NativeRVA = 2,
  NativeRegister = 3,
  NativeRegisterRelative = 4,
  NativeOffset = 5,
  NativeRegisterRegister = 6,
  NativeRegisterStack = 7,
  NativeStackRegister = 8,
  BitField = 9,
  NativeSectionOffset = 10,
};
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
