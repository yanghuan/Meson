#include "EventPipePayloadDecoder-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipePayloadDecoderNamespace {
using namespace System::Reflection;

Array<Object> EventPipePayloadDecoder::DecodePayload(EventSource::in::EventMetadata& metadata, ReadOnlySpan<Byte> payload) {
  Array<ParameterInfo> parameters = metadata.Parameters;
  Array<Object> array = rt::newarr<Array<Object>>(parameters->get_Length());
  for (Int32 i = 0; i < parameters->get_Length(); i++) {
    if (payload.get_Length() <= 0) {
      break;
    }
    Type parameterType = parameters[i]->get_ParameterType();
  }
  return array;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipePayloadDecoderNamespace
