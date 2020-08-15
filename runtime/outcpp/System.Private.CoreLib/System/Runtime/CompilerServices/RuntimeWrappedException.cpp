#include "RuntimeWrappedException-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeWrappedExceptionNamespace {
Object RuntimeWrappedException___::get_WrappedException() {
  return _wrappedException;
}

void RuntimeWrappedException___::ctor(Object thrownObject) {
  Exception::in::set_HResult = -2146233026;
  _wrappedException = thrownObject;
}

void RuntimeWrappedException___::ctor(SerializationInfo info, StreamingContext context) {
  _wrappedException = info->GetValue("WrappedException", rt::typeof<Object>());
}

void RuntimeWrappedException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("WrappedException", _wrappedException, rt::typeof<Object>());
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeWrappedExceptionNamespace
