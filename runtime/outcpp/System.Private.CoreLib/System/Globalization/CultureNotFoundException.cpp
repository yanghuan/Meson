#include "CultureNotFoundException-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::CultureNotFoundExceptionNamespace {
Nullable<Int32> CultureNotFoundException___::get_InvalidCultureId() {
  return _invalidCultureId;
}

String CultureNotFoundException___::get_InvalidCultureName() {
  return _invalidCultureName;
}

String CultureNotFoundException___::get_DefaultMessage() {
  return SR::get_Argument_CultureNotSupported();
}

String CultureNotFoundException___::get_FormattedInvalidCultureId() {
  if (!get_InvalidCultureId().get_HasValue()) {
    return get_InvalidCultureName();
  }
  return String::in::Format(CultureInfo::in::get_InvariantCulture(), "{0} (0x{0:x4})", get_InvalidCultureId().get_Value());
}

String CultureNotFoundException___::get_Message() {
  String message = ArgumentException::in::get_Message();
  if (_invalidCultureId.get_HasValue() || _invalidCultureName != nullptr) {
    String text = SR::Format(SR::get_Argument_CultureInvalidIdentifier(), get_FormattedInvalidCultureId());
    if (message == nullptr) {
      return text;
    }
    return message + "
" + text;
  }
  return message;
}

void CultureNotFoundException___::ctor() {
}

void CultureNotFoundException___::ctor(String message) {
}

void CultureNotFoundException___::ctor(String paramName, String message) {
}

void CultureNotFoundException___::ctor(String message, Exception innerException) {
}

void CultureNotFoundException___::ctor(String paramName, String invalidCultureName, String message) {
  _invalidCultureName = invalidCultureName;
}

void CultureNotFoundException___::ctor(String message, String invalidCultureName, Exception innerException) {
  _invalidCultureName = invalidCultureName;
}

void CultureNotFoundException___::ctor(String message, Int32 invalidCultureId, Exception innerException) {
  _invalidCultureId = invalidCultureId;
}

void CultureNotFoundException___::ctor(String paramName, Int32 invalidCultureId, String message) {
  _invalidCultureId = invalidCultureId;
}

void CultureNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
  _invalidCultureId = (Nullable<Int32>)info->GetValue("InvalidCultureId", rt::typeof<Nullable<Int32>>());
  _invalidCultureName = (String)info->GetValue("InvalidCultureName", rt::typeof<String>());
}

void CultureNotFoundException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  ArgumentException::in::GetObjectData(info, context);
  info->AddValue("InvalidCultureId", _invalidCultureId, rt::typeof<Nullable<Int32>>());
  info->AddValue("InvalidCultureName", _invalidCultureName, rt::typeof<String>());
}

} // namespace System::Private::CoreLib::System::Globalization::CultureNotFoundExceptionNamespace
