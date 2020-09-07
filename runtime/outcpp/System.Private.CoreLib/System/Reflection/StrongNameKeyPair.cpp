#include "StrongNameKeyPair-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::StrongNameKeyPairNamespace {
Array<Byte> StrongNameKeyPair___::get_PublicKey() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_StrongNameSigning());
}

void StrongNameKeyPair___::ctor(FileStream keyPairFile) {
  if (keyPairFile == nullptr) {
    rt::throw_exception<ArgumentNullException>("keyPairFile");
  }
  Int32 num = (Int32)keyPairFile->get_Length();
  Array<Byte> buffer = rt::newarr<Array<Byte>>(num);
  keyPairFile->Read(buffer, 0, num);
}

void StrongNameKeyPair___::ctor(Array<Byte> keyPairArray) {
  if (keyPairArray == nullptr) {
    rt::throw_exception<ArgumentNullException>("keyPairArray");
  }
}

void StrongNameKeyPair___::ctor(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

void StrongNameKeyPair___::ctor(String keyPairContainer) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_StrongNameSigning());
}

void StrongNameKeyPair___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

void StrongNameKeyPair___::OnDeserializationOfIDeserializationCallback(Object sender) {
  rt::throw_exception<PlatformNotSupportedException>();
}

} // namespace System::Private::CoreLib::System::Reflection::StrongNameKeyPairNamespace
