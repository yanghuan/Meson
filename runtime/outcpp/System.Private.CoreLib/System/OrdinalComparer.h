#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/StringComparer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
namespace OrdinalComparerNamespace {
CLASS(OrdinalComparer) : public StringComparer::in {
  public: void ctor(Boolean ignoreCase);
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: Boolean _ignoreCase;
};
} // namespace OrdinalComparerNamespace
using OrdinalComparer = OrdinalComparerNamespace::OrdinalComparer;
} // namespace System::Private::CoreLib::System
