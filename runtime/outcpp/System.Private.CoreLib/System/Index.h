#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
namespace IndexNamespace {
struct Index {
  public: static Index get_Start();
  public: static Index get_End();
  public: Int32 get_Value();
  public: Boolean get_IsFromEnd();
  public: static Index FromStart(Int32 value);
  public: static Index FromEnd(Int32 value);
  public: Int32 GetOffset(Int32 length);
  public: Boolean Equals(Object value);
  public: Boolean Equals(Index other);
  public: Int32 GetHashCode();
  public: String ToString();
  private: String ToStringFromEnd();
  private: Int32 _value;
};
} // namespace IndexNamespace
using Index = IndexNamespace::Index;
} // namespace System::Private::CoreLib::System
