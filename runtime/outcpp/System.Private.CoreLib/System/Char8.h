#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
namespace Char8Namespace {
struct Char8 {
  public: Int32 CompareTo(Char8 other);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Char8 other);
  public: Int32 GetHashCode();
  public: String ToString();
  private: Byte _value;
};
} // namespace Char8Namespace
using Char8 = Char8Namespace::Char8;
} // namespace System::Private::CoreLib::System
