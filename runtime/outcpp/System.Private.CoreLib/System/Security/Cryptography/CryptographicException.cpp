#include "CryptographicException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Security::Cryptography::CryptographicExceptionNamespace {
void CryptographicException___::ctor() {
}

void CryptographicException___::ctor(Int32 hr) {
  Exception::in::set_HResult = hr;
}

void CryptographicException___::ctor(String message) {
}

void CryptographicException___::ctor(String message, Exception inner) {
}

void CryptographicException___::ctor(String format, String insert) {
}

void CryptographicException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Security::Cryptography::CryptographicExceptionNamespace
