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
namespace DictionaryValueCollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(DictionaryValueCollection, TKey, TValue) {
  public: Int32 get_Count();
  private: Boolean get_IsReadOnlyOfICollectionTValue();
  public: void CopyTo(Array<TValue> array, Int32 index);
  public: Boolean Contains(TValue item);
  public: IEnumerator<TValue> GetEnumerator();
  private: IDictionary<TKey, TValue> dictionary;
};
} // namespace DictionaryValueCollectionNamespace
template <class TKey, class TValue>
using DictionaryValueCollection = DictionaryValueCollectionNamespace::DictionaryValueCollection<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
