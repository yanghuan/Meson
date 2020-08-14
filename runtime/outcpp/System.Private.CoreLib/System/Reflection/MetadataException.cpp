#include "MetadataException-dep.h"

namespace System::Private::CoreLib::System::Reflection::MetadataExceptionNamespace {
void MetadataException___::ctor(Int32 hr) {
  m_hr = hr;
}

String MetadataException___::ToString() {
  return String::in::Format("MetadataException HResult = {0:x}.", m_hr);
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataExceptionNamespace
