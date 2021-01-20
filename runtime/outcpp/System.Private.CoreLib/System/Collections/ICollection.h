#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
namespace ICollectionNamespace {
CLASS(ICollection) : public object {
  public: using interface = rt::TypeList<IEnumerable>;
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: IEnumerator GetEnumerator();
  public: void CopyTo(Array<> array, Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICollectionNamespace
using ICollection = ICollectionNamespace::ICollection;
} // namespace System::Private::CoreLib::System::Collections
