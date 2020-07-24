#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
enum class ResourceTypeCode;
namespace ResourceLocatorNamespace {
struct ResourceLocator {
  public: Int32 get_DataPosition();
  public: Object get_Value();
  public: void set_Value(Object value);
  public: explicit ResourceLocator(Int32 dataPos, Object value);
  public: static Boolean CanCache(ResourceTypeCode value);
  public: explicit ResourceLocator() {}
  public: Object _value;
  public: Int32 _dataPos;
};
} // namespace ResourceLocatorNamespace
using ResourceLocator = ResourceLocatorNamespace::ResourceLocator;
} // namespace System::Private::CoreLib::System::Resources
