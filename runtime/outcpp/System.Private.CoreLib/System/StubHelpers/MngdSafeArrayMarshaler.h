#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace MngdSafeArrayMarshalerNamespace {
class MngdSafeArrayMarshaler {
  public: static void CreateMarshaler(IntPtr pMarshalState, IntPtr pMT, Int32 iRank, Int32 dwFlags, IntPtr pManagedMarshaler);
  public: static void ConvertSpaceToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome, Object pOriginalManaged);
  public: static void ConvertSpaceToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ClearNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
};
} // namespace MngdSafeArrayMarshalerNamespace
using MngdSafeArrayMarshaler = MngdSafeArrayMarshalerNamespace::MngdSafeArrayMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
