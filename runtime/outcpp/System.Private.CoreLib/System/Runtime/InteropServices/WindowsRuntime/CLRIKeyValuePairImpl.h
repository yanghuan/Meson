#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace CLRIKeyValuePairImplNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(CLRIKeyValuePairImpl, K, V) {
  public: K get_Key();
  public: V get_Value();
  public: static Object BoxHelper(Object pair);
  public: static Object UnboxHelper(Object wrapper);
  public: String ToString();
  private: KeyValuePair<K, V> _pair;
};
} // namespace CLRIKeyValuePairImplNamespace
template <class K, class V>
using CLRIKeyValuePairImpl = CLRIKeyValuePairImplNamespace::CLRIKeyValuePairImpl<K, V>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
