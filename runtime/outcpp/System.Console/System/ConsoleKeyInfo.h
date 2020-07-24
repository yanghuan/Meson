#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Console::System {
enum class ConsoleKey;
enum class ConsoleModifiers;
namespace ConsoleKeyInfoNamespace {
using namespace ::System::Private::CoreLib::System;
struct ConsoleKeyInfo : public rt::ValueType<ConsoleKeyInfo> {
  public: Char get_KeyChar();
  public: ConsoleKey get_Key();
  public: ConsoleModifiers get_Modifiers();
  public: explicit ConsoleKeyInfo(Char keyChar, ConsoleKey key, Boolean shift, Boolean alt, Boolean control);
  public: Boolean Equals(Object value);
  public: Boolean Equals(ConsoleKeyInfo obj);
  public: static Boolean op_Equality(ConsoleKeyInfo a, ConsoleKeyInfo b);
  public: static Boolean op_Inequality(ConsoleKeyInfo a, ConsoleKeyInfo b);
  public: Int32 GetHashCode();
  public: explicit ConsoleKeyInfo() {}
  private: Char _keyChar;
  private: ConsoleKey _key;
  private: ConsoleModifiers _mods;
};
} // namespace ConsoleKeyInfoNamespace
using ConsoleKeyInfo = ConsoleKeyInfoNamespace::ConsoleKeyInfo;
} // namespace System::Console::System
