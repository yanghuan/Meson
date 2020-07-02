#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IReadOnlyDictionary, TKey, TValue)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ReadOnlyDictionaryKeyEnumeratorNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(ReadOnlyDictionaryKeyEnumerator, TKey, TValue) {
  private: Object get_CurrentOfIEnumerator();
  public: TKey get_Current();
  public: Boolean MoveNext();
  public: void Reset();
  private: IReadOnlyDictionary<TKey, TValue> dictionary;
  private: IEnumerator<KeyValuePair<TKey, TValue>> enumeration;
};
} // namespace ReadOnlyDictionaryKeyEnumeratorNamespace
template <class TKey, class TValue>
using ReadOnlyDictionaryKeyEnumerator = ReadOnlyDictionaryKeyEnumeratorNamespace::ReadOnlyDictionaryKeyEnumerator<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
