#include "ApplicationId-dep.h"

#include <System.Private.CoreLib/System/ApplicationId-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>

namespace System::Private::CoreLib::System::ApplicationIdNamespace {
using namespace System::Text;

Array<Byte> ApplicationId___::get_PublicKeyToken() {
  return (Array<Byte>)_publicKeyToken->Clone();
}

void ApplicationId___::ctor(Array<Byte> publicKeyToken, String name, System::Version version, String processorArchitecture, String culture) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyApplicationName());
  }
  if (version == nullptr) {
    rt::throw_exception<ArgumentNullException>("version");
  }
  if (publicKeyToken == nullptr) {
    rt::throw_exception<ArgumentNullException>("publicKeyToken");
  }
  _publicKeyToken = (Array<Byte>)publicKeyToken->Clone();
  Name = name;
  Version = version;
  ProcessorArchitecture = processorArchitecture;
  Culture = culture;
}

ApplicationId ApplicationId___::Copy() {
  return rt::newobj<ApplicationId>(_publicKeyToken, Name, Version, ProcessorArchitecture, Culture);
}

String ApplicationId___::ToString() {
  Char as[128] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder stringBuilder = ValueStringBuilder(initialBuffer);
  stringBuilder.Append(Name);
  if (Culture != nullptr) {
    stringBuilder.Append(", culture=\"");
    stringBuilder.Append(Culture);
    stringBuilder.Append(u'"');
  }
  stringBuilder.Append(", version=\"");
  stringBuilder.Append(Version->ToString());
  stringBuilder.Append(u'"');
  if (_publicKeyToken != nullptr) {
    stringBuilder.Append(", publicKeyToken=\"");
    EncodeHexString(_publicKeyToken, stringBuilder);
    stringBuilder.Append(u'"');
  }
  if (ProcessorArchitecture != nullptr) {
    stringBuilder.Append(", processorArchitecture =\"");
    stringBuilder.Append(ProcessorArchitecture);
    stringBuilder.Append(u'"');
  }
  return stringBuilder.ToString();
}

void ApplicationId___::EncodeHexString(Array<Byte> sArray, ValueStringBuilder& stringBuilder) {
  for (Int32 i = 0; i < sArray->get_Length(); i++) {
    HexConverter::ToCharsBuffer(sArray[i], stringBuilder.AppendSpan(2));
  }
}

Boolean ApplicationId___::Equals(Object o) {
  ApplicationId applicationId = rt::as<ApplicationId>(o);
  if (applicationId == nullptr) {
    return false;
  }
  if (!Object::in::Equals(Name, applicationId->get_Name()) || !Object::in::Equals(Version, applicationId->get_Version()) || !Object::in::Equals(ProcessorArchitecture, applicationId->get_ProcessorArchitecture()) || !Object::in::Equals(Culture, applicationId->get_Culture())) {
    return false;
  }
  if (_publicKeyToken->get_Length() != applicationId->_publicKeyToken->get_Length()) {
    return false;
  }
  for (Int32 i = 0; i < _publicKeyToken->get_Length(); i++) {
    if (_publicKeyToken[i] != applicationId->_publicKeyToken[i]) {
      return false;
    }
  }
  return true;
}

Int32 ApplicationId___::GetHashCode() {
  return Name->GetHashCode() ^ Version->GetHashCode();
}

} // namespace System::Private::CoreLib::System::ApplicationIdNamespace
