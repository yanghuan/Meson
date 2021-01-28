#include "ConsoleKeyInfo-dep.h"

#include <System.Console/System/ConsoleKeyInfo-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>

namespace System::Console::System::ConsoleKeyInfoNamespace {
using namespace ::System::Private::CoreLib::System;

Char ConsoleKeyInfo::get_KeyChar() {
  return _keyChar;
}

ConsoleKey ConsoleKeyInfo::get_Key() {
  return _key;
}

ConsoleModifiers ConsoleKeyInfo::get_Modifiers() {
  return _mods;
}

ConsoleKeyInfo::ConsoleKeyInfo(Char keyChar, ConsoleKey key, Boolean shift, Boolean alt, Boolean control) {
  if (key < (ConsoleKey)0 || key > (ConsoleKey)255) {
    rt::throw_exception<ArgumentOutOfRangeException>("key", SR::get_ArgumentOutOfRange_ConsoleKey());
  }
  _keyChar = keyChar;
  _key = key;
  _mods = (ConsoleModifiers)0;
  if (shift) {
    _mods |= ConsoleModifiers::Shift;
  }
  if (alt) {
    _mods |= ConsoleModifiers::Alt;
  }
  if (control) {
    _mods |= ConsoleModifiers::Control;
  }
}

Boolean ConsoleKeyInfo::Equals(Object value) {
  if (rt::is<ConsoleKeyInfo>(value)) {
    return Equals((ConsoleKeyInfo)value);
  }
  return false;
}

Boolean ConsoleKeyInfo::Equals(ConsoleKeyInfo obj) {
  if (obj._keyChar == _keyChar && obj._key == _key) {
    return obj._mods == _mods;
  }
  return false;
}

Boolean ConsoleKeyInfo::op_Equality(ConsoleKeyInfo a, ConsoleKeyInfo b) {
  return a.Equals(b);
}

Boolean ConsoleKeyInfo::op_Inequality(ConsoleKeyInfo a, ConsoleKeyInfo b) {
  return !(a == b);
}

Int32 ConsoleKeyInfo::GetHashCode() {
  return _keyChar | ((Int32)_key << 16) | ((Int32)_mods << 24);
}

} // namespace System::Console::System::ConsoleKeyInfoNamespace
