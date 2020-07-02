#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace MngdRefCustomMarshalerNamespace {
class MngdRefCustomMarshaler {
  public: static void CreateMarshaler(IntPtr pMarshalState, IntPtr pCMHelper);
  public: static void ConvertContentsToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ClearNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ClearManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
};
} // namespace MngdRefCustomMarshalerNamespace
using MngdRefCustomMarshaler = MngdRefCustomMarshalerNamespace::MngdRefCustomMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
