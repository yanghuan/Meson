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
namespace ReadOnlyDictionaryValueEnumeratorNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(ReadOnlyDictionaryValueEnumerator, TKey, TValue) {
  private: Object get_CurrentOfIEnumerator();
  public: TValue get_Current();
  public: Boolean MoveNext();
  public: void Reset();
  private: IReadOnlyDictionary<TKey, TValue> dictionary;
  private: IEnumerator<KeyValuePair<TKey, TValue>> enumeration;
};
} // namespace ReadOnlyDictionaryValueEnumeratorNamespace
template <class TKey, class TValue>
using ReadOnlyDictionaryValueEnumerator = ReadOnlyDictionaryValueEnumeratorNamespace::ReadOnlyDictionaryValueEnumerator<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
