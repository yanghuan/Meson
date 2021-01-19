#include "GCMemoryInfoData-dep.h"

#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>

namespace System::Private::CoreLib::System::GCMemoryInfoDataNamespace {
using namespace System::Runtime::InteropServices;

ReadOnlySpan<GCGenerationInfo> GCMemoryInfoData___::get_GenerationInfoAsSpan() {
  return MemoryMarshal::CreateReadOnlySpan(_generationInfo0, 5);
}

ReadOnlySpan<TimeSpan> GCMemoryInfoData___::get_PauseDurationsAsSpan() {
  return MemoryMarshal::CreateReadOnlySpan(_pauseDuration0, 2);
}

void GCMemoryInfoData___::ctor() {
}

} // namespace System::Private::CoreLib::System::GCMemoryInfoDataNamespace
