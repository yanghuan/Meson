#include "AsyncLocalValueMap-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocalValueMap-dep.h>

namespace System::Private::CoreLib::System::Threading::AsyncLocalValueMapNamespace {
using namespace System::Collections::Generic;

IAsyncLocalValueMap AsyncLocalValueMap::EmptyAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  if (value == nullptr && treatNullValueAsNonexistent) {
    return (EmptyAsyncLocalValueMap)this;
  }
  return rt::newobj<OneElementAsyncLocalValueMap>(key, value);
}

Boolean AsyncLocalValueMap::EmptyAsyncLocalValueMap___::TryGetValue(IAsyncLocal key, Object& value) {
  value = nullptr;
  return false;
}

void AsyncLocalValueMap::EmptyAsyncLocalValueMap___::ctor() {
}

void AsyncLocalValueMap::OneElementAsyncLocalValueMap___::ctor(IAsyncLocal key, Object value) {
  _key1 = key;
  _value1 = value;
}

IAsyncLocalValueMap AsyncLocalValueMap::OneElementAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  if (value != nullptr || !treatNullValueAsNonexistent) {
    if (key != _key1) {
      return rt::newobj<TwoElementAsyncLocalValueMap>(_key1, _value1, key, value);
    }
    return rt::newobj<OneElementAsyncLocalValueMap>(key, value);
  }
  if (key != _key1) {
    return (OneElementAsyncLocalValueMap)this;
  }
  return Empty;
}

Boolean AsyncLocalValueMap::OneElementAsyncLocalValueMap___::TryGetValue(IAsyncLocal key, Object& value) {
  if (key == _key1) {
    value = _value1;
    return true;
  }
  value = nullptr;
  return false;
}

void AsyncLocalValueMap::TwoElementAsyncLocalValueMap___::ctor(IAsyncLocal key1, Object value1, IAsyncLocal key2, Object value2) {
  _key1 = key1;
  _value1 = value1;
  _key2 = key2;
  _value2 = value2;
}

IAsyncLocalValueMap AsyncLocalValueMap::TwoElementAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  if (value != nullptr || !treatNullValueAsNonexistent) {
    if (key != _key1) {
      if (key != _key2) {
        return rt::newobj<ThreeElementAsyncLocalValueMap>(_key1, _value1, _key2, _value2, key, value);
      }
      return rt::newobj<TwoElementAsyncLocalValueMap>(_key1, _value1, key, value);
    }
    return rt::newobj<TwoElementAsyncLocalValueMap>(key, value, _key2, _value2);
  }
  if (key != _key1) {
    if (key != _key2) {
      return (TwoElementAsyncLocalValueMap)this;
    }
    return rt::newobj<OneElementAsyncLocalValueMap>(_key1, _value1);
  }
  return rt::newobj<OneElementAsyncLocalValueMap>(_key2, _value2);
}

Boolean AsyncLocalValueMap::TwoElementAsyncLocalValueMap___::TryGetValue(IAsyncLocal key, Object& value) {
  if (key == _key1) {
    value = _value1;
    return true;
  }
  if (key == _key2) {
    value = _value2;
    return true;
  }
  value = nullptr;
  return false;
}

void AsyncLocalValueMap::ThreeElementAsyncLocalValueMap___::ctor(IAsyncLocal key1, Object value1, IAsyncLocal key2, Object value2, IAsyncLocal key3, Object value3) {
  _key1 = key1;
  _value1 = value1;
  _key2 = key2;
  _value2 = value2;
  _key3 = key3;
  _value3 = value3;
}

IAsyncLocalValueMap AsyncLocalValueMap::ThreeElementAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  if (value != nullptr || !treatNullValueAsNonexistent) {
    if (key == _key1) {
      return rt::newobj<ThreeElementAsyncLocalValueMap>(key, value, _key2, _value2, _key3, _value3);
    }
    if (key == _key2) {
      return rt::newobj<ThreeElementAsyncLocalValueMap>(_key1, _value1, key, value, _key3, _value3);
    }
    if (key == _key3) {
      return rt::newobj<ThreeElementAsyncLocalValueMap>(_key1, _value1, _key2, _value2, key, value);
    }
    MultiElementAsyncLocalValueMap multiElementAsyncLocalValueMap = rt::newobj<MultiElementAsyncLocalValueMap>(4);
    multiElementAsyncLocalValueMap->UnsafeStore(0, _key1, _value1);
    multiElementAsyncLocalValueMap->UnsafeStore(1, _key2, _value2);
    multiElementAsyncLocalValueMap->UnsafeStore(2, _key3, _value3);
    multiElementAsyncLocalValueMap->UnsafeStore(3, key, value);
    return multiElementAsyncLocalValueMap;
  }
  if (key != _key1) {
    if (key != _key2) {
      if (key != _key3) {
        return (ThreeElementAsyncLocalValueMap)this;
      }
      return rt::newobj<TwoElementAsyncLocalValueMap>(_key1, _value1, _key2, _value2);
    }
    return rt::newobj<TwoElementAsyncLocalValueMap>(_key1, _value1, _key3, _value3);
  }
  return rt::newobj<TwoElementAsyncLocalValueMap>(_key2, _value2, _key3, _value3);
}

Boolean AsyncLocalValueMap::ThreeElementAsyncLocalValueMap___::TryGetValue(IAsyncLocal key, Object& value) {
  if (key == _key1) {
    value = _value1;
    return true;
  }
  if (key == _key2) {
    value = _value2;
    return true;
  }
  if (key == _key3) {
    value = _value3;
    return true;
  }
  value = nullptr;
  return false;
}

void AsyncLocalValueMap::MultiElementAsyncLocalValueMap___::ctor(Int32 count) {
  _keyValues = rt::newarr<Array<KeyValuePair<IAsyncLocal, Object>>>(count);
}

void AsyncLocalValueMap::MultiElementAsyncLocalValueMap___::UnsafeStore(Int32 index, IAsyncLocal key, Object value) {
  _keyValues[index] = KeyValuePair<IAsyncLocal, Object>(key, value);
}

IAsyncLocalValueMap AsyncLocalValueMap::MultiElementAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  for (Int32 i = 0; i < _keyValues->get_Length(); i++) {
    if (key != _keyValues[i].get_Key()) {
      continue;
    }
    if (value != nullptr || !treatNullValueAsNonexistent) {
      MultiElementAsyncLocalValueMap multiElementAsyncLocalValueMap = rt::newobj<MultiElementAsyncLocalValueMap>(_keyValues->get_Length());
      Array<>::in::Copy(_keyValues, multiElementAsyncLocalValueMap->_keyValues, _keyValues->get_Length());
      multiElementAsyncLocalValueMap->_keyValues[i] = KeyValuePair<IAsyncLocal, Object>(key, value);
      return multiElementAsyncLocalValueMap;
    }
    if (_keyValues->get_Length() == 4) {
      switch (i.get()) {
        default:
          return rt::newobj<ThreeElementAsyncLocalValueMap>(_keyValues[0].get_Key(), _keyValues[0].get_Value(), _keyValues[1].get_Key(), _keyValues[1].get_Value(), _keyValues[2].get_Key(), _keyValues[2].get_Value());
        case 2:
          return rt::newobj<ThreeElementAsyncLocalValueMap>(_keyValues[0].get_Key(), _keyValues[0].get_Value(), _keyValues[1].get_Key(), _keyValues[1].get_Value(), _keyValues[3].get_Key(), _keyValues[3].get_Value());
        case 1:
          return rt::newobj<ThreeElementAsyncLocalValueMap>(_keyValues[0].get_Key(), _keyValues[0].get_Value(), _keyValues[2].get_Key(), _keyValues[2].get_Value(), _keyValues[3].get_Key(), _keyValues[3].get_Value());
        case 0:
          return rt::newobj<ThreeElementAsyncLocalValueMap>(_keyValues[1].get_Key(), _keyValues[1].get_Value(), _keyValues[2].get_Key(), _keyValues[2].get_Value(), _keyValues[3].get_Key(), _keyValues[3].get_Value());
      }
    }
    MultiElementAsyncLocalValueMap multiElementAsyncLocalValueMap2 = rt::newobj<MultiElementAsyncLocalValueMap>(_keyValues->get_Length() - 1);
    if (i != 0) {
      Array<>::in::Copy(_keyValues, multiElementAsyncLocalValueMap2->_keyValues, i);
    }
    if (i != _keyValues->get_Length() - 1) {
      Array<>::in::Copy(_keyValues, i + 1, multiElementAsyncLocalValueMap2->_keyValues, i, _keyValues->get_Length() - i - 1);
    }
    return multiElementAsyncLocalValueMap2;
  }
  if (value == nullptr && treatNullValueAsNonexistent) {
    return (MultiElementAsyncLocalValueMap)this;
  }
  if (_keyValues->get_Length() < 16) {
    MultiElementAsyncLocalValueMap multiElementAsyncLocalValueMap3 = rt::newobj<MultiElementAsyncLocalValueMap>(_keyValues->get_Length() + 1);
    Array<>::in::Copy(_keyValues, multiElementAsyncLocalValueMap3->_keyValues, _keyValues->get_Length());
    multiElementAsyncLocalValueMap3->_keyValues[_keyValues->get_Length()] = KeyValuePair<IAsyncLocal, Object>(key, value);
    return multiElementAsyncLocalValueMap3;
  }
  ManyElementAsyncLocalValueMap manyElementAsyncLocalValueMap = rt::newobj<ManyElementAsyncLocalValueMap>(17);
  Array<KeyValuePair<IAsyncLocal, Object>> keyValues = _keyValues;
  for (Int32 j = 0; j < keyValues->get_Length(); j++) {
    KeyValuePair<IAsyncLocal, Object> keyValuePair = keyValues[j];
    manyElementAsyncLocalValueMap[keyValuePair.get_Key()] = keyValuePair.get_Value();
  }
  manyElementAsyncLocalValueMap[key] = value;
  return manyElementAsyncLocalValueMap;
}

Boolean AsyncLocalValueMap::MultiElementAsyncLocalValueMap___::TryGetValue(IAsyncLocal key, Object& value) {
  Array<KeyValuePair<IAsyncLocal, Object>> keyValues = _keyValues;
  for (Int32 i = 0; i < keyValues->get_Length(); i++) {
    KeyValuePair<IAsyncLocal, Object> keyValuePair = keyValues[i];
    if (key == keyValuePair.get_Key()) {
      value = keyValuePair.get_Value();
      return true;
    }
  }
  value = nullptr;
  return false;
}

void AsyncLocalValueMap::ManyElementAsyncLocalValueMap___::ctor(Int32 capacity) {
}

IAsyncLocalValueMap AsyncLocalValueMap::ManyElementAsyncLocalValueMap___::Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  Int32 count = Dictionary<IAsyncLocal, Object>::in::get_Count();
  Boolean flag = ContainsKey(key);
  if (value != nullptr || !treatNullValueAsNonexistent) {
    ManyElementAsyncLocalValueMap manyElementAsyncLocalValueMap = rt::newobj<ManyElementAsyncLocalValueMap>(count + ((!flag) ? 1 : 0));
    {
      Dictionary<IAsyncLocal, Object>::in::Enumerator enumerator = GetEnumerator();
      rt::Using(enumerator);
      while (enumerator.MoveNext()) {
        KeyValuePair<IAsyncLocal, Object> current = enumerator.get_Current();
        manyElementAsyncLocalValueMap[current.get_Key()] = current.get_Value();
      }
    }
    manyElementAsyncLocalValueMap[key] = value;
    return manyElementAsyncLocalValueMap;
  }
  if (flag) {
    if (count == 17) {
      MultiElementAsyncLocalValueMap multiElementAsyncLocalValueMap = rt::newobj<MultiElementAsyncLocalValueMap>(16);
      Int32 num = 0;
      {
        Dictionary<IAsyncLocal, Object>::in::Enumerator enumerator2 = GetEnumerator();
        rt::Using(enumerator2);
        while (enumerator2.MoveNext()) {
          KeyValuePair<IAsyncLocal, Object> current2 = enumerator2.get_Current();
          if (key != current2.get_Key()) {
            multiElementAsyncLocalValueMap->UnsafeStore(num++, current2.get_Key(), current2.get_Value());
          }
        }
        return multiElementAsyncLocalValueMap;
      }
    }
    ManyElementAsyncLocalValueMap manyElementAsyncLocalValueMap2 = rt::newobj<ManyElementAsyncLocalValueMap>(count - 1);
    {
      Dictionary<IAsyncLocal, Object>::in::Enumerator enumerator3 = GetEnumerator();
      rt::Using(enumerator3);
      while (enumerator3.MoveNext()) {
        KeyValuePair<IAsyncLocal, Object> current3 = enumerator3.get_Current();
        if (key != current3.get_Key()) {
          manyElementAsyncLocalValueMap2[current3.get_Key()] = current3.get_Value();
        }
      }
      return manyElementAsyncLocalValueMap2;
    }
  }
  return (ManyElementAsyncLocalValueMap)this;
}

Boolean AsyncLocalValueMap::IsEmpty(IAsyncLocalValueMap asyncLocalValueMap) {
  return asyncLocalValueMap == Empty;
}

IAsyncLocalValueMap AsyncLocalValueMap::Create(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent) {
  if (value == nullptr && treatNullValueAsNonexistent) {
    return Empty;
  }
  return rt::newobj<OneElementAsyncLocalValueMap>(key, value);
}

void AsyncLocalValueMap::cctor() {
  Empty = rt::newobj<EmptyAsyncLocalValueMap>();
}

} // namespace System::Private::CoreLib::System::Threading::AsyncLocalValueMapNamespace
