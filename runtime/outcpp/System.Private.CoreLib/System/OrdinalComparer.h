#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD(Object)
namespace OrdinalComparerNamespace {
CLASS(OrdinalComparer) {
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