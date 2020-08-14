#include "MissingSatelliteAssemblyException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Resources::MissingSatelliteAssemblyExceptionNamespace {
String MissingSatelliteAssemblyException___::get_CultureName() {
  return _cultureName;
}

void MissingSatelliteAssemblyException___::ctor() {
  Exception::set_HResult = -2146233034;
}

void MissingSatelliteAssemblyException___::ctor(String message) {
  Exception::set_HResult = -2146233034;
}

void MissingSatelliteAssemblyException___::ctor(String message, String cultureName) {
  Exception::set_HResult = -2146233034;
  _cultureName = cultureName;
}

void MissingSatelliteAssemblyException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233034;
}

void MissingSatelliteAssemblyException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Resources::MissingSatelliteAssemblyExceptionNamespace
