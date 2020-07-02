#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IMapViewNamespace {
CLASS(IMapView, K, V) {
  public: UInt32 get_Size();
  public: V Lookup(K key);
  public: Boolean HasKey(K key);
  public: void Split(IMapView<K, V>& first, IMapView<K, V>& second);
};
} // namespace IMapViewNamespace
template <class K, class V>
using IMapView = IMapViewNamespace::IMapView<K, V>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
