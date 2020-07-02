#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IKeyValuePairNamespace {
CLASS(IKeyValuePair, K, V) {
  public: K get_Key();
  public: V get_Value();
};
} // namespace IKeyValuePairNamespace
template <class K, class V>
using IKeyValuePair = IKeyValuePairNamespace::IKeyValuePair<K, V>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
