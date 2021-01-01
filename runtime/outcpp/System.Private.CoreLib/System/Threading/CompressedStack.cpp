#include "CompressedStack-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Threading/CompressedStack-dep.h>

namespace System::Private::CoreLib::System::Threading::CompressedStackNamespace {
void CompressedStack___::ctor() {
}

void CompressedStack___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

CompressedStack CompressedStack___::Capture() {
  return GetCompressedStack();
}

CompressedStack CompressedStack___::CreateCopy() {
  return (CompressedStack)this;
}

CompressedStack CompressedStack___::GetCompressedStack() {
  return rt::newobj<CompressedStack>();
}

void CompressedStack___::Run(CompressedStack compressedStack, ContextCallback<> callback, Object state) {
  if (compressedStack == nullptr) {
    rt::throw_exception<ArgumentNullException>("compressedStack");
  }
  callback(state);
}

} // namespace System::Private::CoreLib::System::Threading::CompressedStackNamespace
