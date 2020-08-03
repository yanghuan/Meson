#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
namespace IReadOnlyDictionaryNamespace {
CLASS(IReadOnlyDictionary, TKey, TValue) : public Object::in {
  public: TValue get_Item(TKey key);
  public: IEnumerable<TKey> get_Keys();
  public: IEnumerable<TValue> get_Values();
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
};
} // namespace IReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using IReadOnlyDictionary = IReadOnlyDictionaryNamespace::IReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
