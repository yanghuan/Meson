#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IReadOnlyDictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ReadOnlyDictionaryValueCollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(ReadOnlyDictionaryValueCollection, TKey, TValue) {
  public: IEnumerator<TValue> GetEnumerator();
  private: IReadOnlyDictionary<TKey, TValue> dictionary;
};
} // namespace ReadOnlyDictionaryValueCollectionNamespace
template <class TKey, class TValue>
using ReadOnlyDictionaryValueCollection = ReadOnlyDictionaryValueCollectionNamespace::ReadOnlyDictionaryValueCollection<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
