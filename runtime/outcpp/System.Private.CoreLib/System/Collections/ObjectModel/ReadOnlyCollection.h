#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace ReadOnlyCollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
using System::Collections::Generic::IList;
CLASS(ReadOnlyCollection, T) {
  public: Boolean Contains(T value);
  public: void CopyTo(Array<T> array, Int32 index);
  public: IEnumerator<T> GetEnumerator();
  public: Int32 IndexOf(T value);
  private: static Boolean IsCompatibleObject(Object value);
  private: IList<T> list;
};
} // namespace ReadOnlyCollectionNamespace
template <class T>
using ReadOnlyCollection = ReadOnlyCollectionNamespace::ReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
