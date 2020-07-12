#include "CSTRMarshaler-dep.h"

namespace System::Private::CoreLib::System::StubHelpers::CSTRMarshalerNamespace {
IntPtr CSTRMarshaler::ConvertToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer) {
  return IntPtr();
};

String CSTRMarshaler::ConvertToManaged(IntPtr cstr) {
  return nullptr;
};

void CSTRMarshaler::ClearNative(IntPtr pNative) {
};

void CSTRMarshaler::ConvertFixedToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer, Int32 length) {
};

String CSTRMarshaler::ConvertFixedToManaged(IntPtr cstr, Int32 length) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::StubHelpers::CSTRMarshalerNamespace
