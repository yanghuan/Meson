#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class DTSubStringType;
namespace DTSubStringNamespace {
struct DTSubString : public valueType<DTSubString> {
  public: Char get_Item(Int32 relativeIndex);
  public: ReadOnlySpan<Char> s;
  public: Int32 index;
  public: Int32 length;
  public: DTSubStringType type;
  public: Int32 value;
};
} // namespace DTSubStringNamespace
using DTSubString = DTSubStringNamespace::DTSubString;
} // namespace System::Private::CoreLib::System
