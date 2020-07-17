#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace KeyValuePairsNamespace {
CLASS(KeyValuePairs) {
  public: void Ctor(Object key, Object value);
  private: Object _key;
  private: Object _value;
};
} // namespace KeyValuePairsNamespace
using KeyValuePairs = KeyValuePairsNamespace::KeyValuePairs;
} // namespace System::Private::CoreLib::System::Collections
