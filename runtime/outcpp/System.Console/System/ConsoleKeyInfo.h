#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Console::System {
enum class ConsoleKey;
enum class ConsoleModifiers;
namespace ConsoleKeyInfoNamespace {
using namespace ::System::Private::CoreLib::System;
struct ConsoleKeyInfo {
  public: Char get_KeyChar();
  public: ConsoleKey get_Key();
  public: ConsoleModifiers get_Modifiers();
  public: Boolean Equals(Object value);
  public: Boolean Equals(ConsoleKeyInfo obj);
  public: Int32 GetHashCode();
  private: Char _keyChar;
  private: ConsoleKey _key;
  private: ConsoleModifiers _mods;
};
} // namespace ConsoleKeyInfoNamespace
using ConsoleKeyInfo = ConsoleKeyInfoNamespace::ConsoleKeyInfo;
} // namespace System::Console::System
