#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
namespace KeyValuePairsNamespace {
CLASS(KeyValuePairs) : public object {
  public: void ctor(Object key, Object value);
  private: Object _key;
  private: Object _value;
};
} // namespace KeyValuePairsNamespace
using KeyValuePairs = KeyValuePairsNamespace::KeyValuePairs;
} // namespace System::Private::CoreLib::System::Collections
