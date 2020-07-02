#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IHashCodeProvider)
FORWARD(IComparer)
namespace CompatibleComparerNamespace {
CLASS(CompatibleComparer) {
  public: IHashCodeProvider get_HashCodeProvider();
  public: IComparer get_Comparer();
  public: Boolean Equals(Object a, Object b);
  public: Int32 Compare(Object a, Object b);
  public: Int32 GetHashCode(Object obj);
  private: IHashCodeProvider _hcp;
  private: IComparer _comparer;
};
} // namespace CompatibleComparerNamespace
using CompatibleComparer = CompatibleComparerNamespace::CompatibleComparer;
} // namespace System::Private::CoreLib::System::Collections
