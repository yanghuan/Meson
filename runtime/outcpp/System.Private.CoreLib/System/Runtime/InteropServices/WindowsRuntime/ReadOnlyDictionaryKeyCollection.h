#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IReadOnlyDictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ReadOnlyDictionaryKeyCollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(ReadOnlyDictionaryKeyCollection, TKey, TValue) {
  public: IEnumerator<TKey> GetEnumerator();
  private: IReadOnlyDictionary<TKey, TValue> dictionary;
};
} // namespace ReadOnlyDictionaryKeyCollectionNamespace
template <class TKey, class TValue>
using ReadOnlyDictionaryKeyCollection = ReadOnlyDictionaryKeyCollectionNamespace::ReadOnlyDictionaryKeyCollection<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
