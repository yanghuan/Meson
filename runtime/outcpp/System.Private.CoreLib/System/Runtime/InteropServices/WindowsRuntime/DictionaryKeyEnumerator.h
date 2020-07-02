#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerator, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace DictionaryKeyEnumeratorNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(DictionaryKeyEnumerator, TKey, TValue) {
  private: Object get_CurrentOfIEnumerator();
  public: TKey get_Current();
  public: Boolean MoveNext();
  public: void Reset();
  private: IDictionary<TKey, TValue> dictionary;
  private: IEnumerator<KeyValuePair<TKey, TValue>> enumeration;
};
} // namespace DictionaryKeyEnumeratorNamespace
template <class TKey, class TValue>
using DictionaryKeyEnumerator = DictionaryKeyEnumeratorNamespace::DictionaryKeyEnumerator<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
