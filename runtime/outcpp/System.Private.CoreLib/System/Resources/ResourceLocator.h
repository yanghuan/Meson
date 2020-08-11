#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
enum class ResourceTypeCode : int32_t;
namespace ResourceLocatorNamespace {
struct ResourceLocator : public valueType<ResourceLocator> {
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
