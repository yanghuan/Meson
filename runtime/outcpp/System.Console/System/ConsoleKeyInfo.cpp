#include "ConsoleKeyInfo-dep.h"

namespace System::Console::System::ConsoleKeyInfoNamespace {
Char ConsoleKeyInfo::get_KeyChar() {
  return Char();
};

ConsoleKey ConsoleKeyInfo::get_Key() {
  return ConsoleKey::OemClear;
};

ConsoleModifiers ConsoleKeyInfo::get_Modifiers() {
  return ConsoleModifiers::Control;
};

Boolean ConsoleKeyInfo::Equals(Object value) {
  return Boolean();
};

Boolean ConsoleKeyInfo::Equals(ConsoleKeyInfo obj) {
  return Boolean();
};

Boolean ConsoleKeyInfo::op_Equality(ConsoleKeyInfo a, ConsoleKeyInfo b) {
  return Boolean();
};

Boolean ConsoleKeyInfo::op_Inequality(ConsoleKeyInfo a, ConsoleKeyInfo b) {
  return Boolean();
};

Int32 ConsoleKeyInfo::GetHashCode() {
  return Int32();
};

} // namespace System::Console::System::ConsoleKeyInfoNamespace
