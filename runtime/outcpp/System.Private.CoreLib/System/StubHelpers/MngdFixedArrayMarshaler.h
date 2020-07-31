#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace MngdFixedArrayMarshalerNamespace {
class MngdFixedArrayMarshaler : public Object::in {
  public: static void CreateMarshaler(IntPtr pMarshalState, IntPtr pMT, Int32 dwFlags, Int32 cElements, IntPtr pManagedMarshaler);
  public: static void ConvertSpaceToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertSpaceToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ClearNativeContents(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
};
} // namespace MngdFixedArrayMarshalerNamespace
using MngdFixedArrayMarshaler = MngdFixedArrayMarshalerNamespace::MngdFixedArrayMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
