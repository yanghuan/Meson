#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IDictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace DictionaryKeyCollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(DictionaryKeyCollection, TKey, TValue) {
  public: Int32 get_Count();
  private: Boolean get_IsReadOnlyOfICollectionTKey();
  public: void CopyTo(Array<TKey> array, Int32 index);
  public: Boolean Contains(TKey item);
  public: IEnumerator<TKey> GetEnumerator();
  private: IDictionary<TKey, TValue> dictionary;
};
} // namespace DictionaryKeyCollectionNamespace
template <class TKey, class TValue>
using DictionaryKeyCollection = DictionaryKeyCollectionNamespace::DictionaryKeyCollection<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
