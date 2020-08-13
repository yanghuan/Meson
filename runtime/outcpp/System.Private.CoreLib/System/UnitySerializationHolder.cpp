#include "UnitySerializationHolder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::UnitySerializationHolderNamespace {
void UnitySerializationHolder___::GetUnitySerializationInfo(SerializationInfo info, Int32 unityType) {
}

void UnitySerializationHolder___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _unityType = info->GetInt32("UnityType");
  _data = info->GetString("Data");
}

void UnitySerializationHolder___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnitySerHolder());
}

Object UnitySerializationHolder___::GetRealObject(StreamingContext context) {
  if (_unityType != 2) {
  }
  return DBNull::in::Value;
}

} // namespace System::Private::CoreLib::System::UnitySerializationHolderNamespace
