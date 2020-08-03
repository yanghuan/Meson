#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace IDictionaryNamespace {
CLASS(IDictionary, TKey, TValue) : public Object::in {
  public: TValue get_Item(TKey key);
  public: void set_Item(TKey key, TValue value);
  public: ICollection<TKey> get_Keys();
  public: ICollection<TValue> get_Values();
  public: Boolean ContainsKey(TKey key);
  public: void Add(TKey key, TValue value);
  public: Boolean Remove(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
};
} // namespace IDictionaryNamespace
template <class TKey, class TValue>
using IDictionary = IDictionaryNamespace::IDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
