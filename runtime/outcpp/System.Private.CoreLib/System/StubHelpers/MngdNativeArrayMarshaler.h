#pragma once

#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace MngdNativeArrayMarshalerNamespace {
class MngdNativeArrayMarshaler {
  public: struct MarshalerState : public valueType<MarshalerState> {
    private: IntPtr m_pElementMT;
    private: IntPtr m_Array;
    private: IntPtr m_pManagedNativeArrayMarshaler;
    private: Int32 m_NativeDataValid;
    private: Int32 m_BestFitMap;
    private: Int32 m_ThrowOnUnmappableChar;
    private: Int16 m_vt;
  };
  public: static void CreateMarshaler(IntPtr pMarshalState, IntPtr pMT, Int32 dwFlags, IntPtr pManagedMarshaler);
  public: static void ConvertSpaceToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertSpaceToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome, Int32 cElements);
  public: static void ConvertContentsToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ClearNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome, Int32 cElements);
  public: static void ClearNativeContents(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome, Int32 cElements);
};
} // namespace MngdNativeArrayMarshalerNamespace
using MngdNativeArrayMarshaler = MngdNativeArrayMarshalerNamespace::MngdNativeArrayMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
