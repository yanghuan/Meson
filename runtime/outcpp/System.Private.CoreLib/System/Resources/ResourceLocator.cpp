#include "ResourceLocator-dep.h"

namespace System::Private::CoreLib::System::Resources::ResourceLocatorNamespace {
Int32 ResourceLocator::get_DataPosition() {
  return _dataPos;
}

Object ResourceLocator::get_Value() {
  return _value;
}

void ResourceLocator::set_Value(Object value) {
  _value = value;
}

ResourceLocator::ResourceLocator(Int32 dataPos, Object value) {
  _dataPos = dataPos;
  _value = value;
}

Boolean ResourceLocator::CanCache(ResourceTypeCode value) {
  return value <= ResourceTypeCode::TimeSpan;
}

} // namespace System::Private::CoreLib::System::Resources::ResourceLocatorNamespace
