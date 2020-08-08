#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
FORWARD(IEqualityComparer)
FORWARD(IHashCodeProvider)
namespace CompatibleComparerNamespace {
CLASS(CompatibleComparer) : public Object::in {
  using interface = rt::TypeList<IEqualityComparer>;
  public: IHashCodeProvider get_HashCodeProvider();
  public: IComparer get_Comparer();
  public: void Ctor(IHashCodeProvider hashCodeProvider, IComparer comparer);
  public: Boolean Equals(Object a, Object b);
  public: Int32 Compare(Object a, Object b);
  public: Int32 GetHashCode(Object obj);
  private: IHashCodeProvider _hcp;
  private: IComparer _comparer;
};
} // namespace CompatibleComparerNamespace
using CompatibleComparer = CompatibleComparerNamespace::CompatibleComparer;
} // namespace System::Private::CoreLib::System::Collections
