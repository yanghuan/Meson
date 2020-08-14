#include "DecoderFallbackException-dep.h"

namespace System::Private::CoreLib::System::Text::DecoderFallbackExceptionNamespace {
Array<Byte> DecoderFallbackException___::get_BytesUnknown() {
  return _bytesUnknown;
}

Int32 DecoderFallbackException___::get_Index() {
  return _index;
}

void DecoderFallbackException___::ctor() {
}

void DecoderFallbackException___::ctor(String message) {
}

void DecoderFallbackException___::ctor(String message, Exception innerException) {
}

void DecoderFallbackException___::ctor(String message, Array<Byte> bytesUnknown, Int32 index) {
  _bytesUnknown = bytesUnknown;
  _index = index;
}

void DecoderFallbackException___::ctor(SerializationInfo serializationInfo, StreamingContext streamingContext) {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackExceptionNamespace
