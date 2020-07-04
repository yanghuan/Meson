#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(DateTimeOffset)
FORWARD(Exception)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(Type)
FORWARDS(UInt16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace MngdHiddenLengthArrayMarshalerNamespace {
class MngdHiddenLengthArrayMarshaler {
  public: static void CreateMarshaler(IntPtr pMarshalState, IntPtr pMT, IntPtr cbElementSize, UInt16 vt, IntPtr pManagedMarshaler);
  public: static void ConvertSpaceToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToNative(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToNative_DateTime(Array<DateTimeOffset>& managedArray, IntPtr pNativeHome);
  public: static void ConvertContentsToNative_Type(Array<Type>& managedArray, IntPtr pNativeHome);
  public: static void ConvertContentsToNative_Exception(Array<Exception>& managedArray, IntPtr pNativeHome);
  public: static void ConvertSpaceToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome, Int32 elementCount);
  public: static void ConvertContentsToManaged(IntPtr pMarshalState, Object& pManagedHome, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged_DateTime(Array<DateTimeOffset>& managedArray, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged_Type(Array<Type>& managedArray, IntPtr pNativeHome);
  public: static void ConvertContentsToManaged_Exception(Array<Exception>& managedArray, IntPtr pNativeHome);
  public: static void ClearNativeContents(IntPtr pMarshalState, IntPtr pNativeHome, Int32 cElements);
  public: static void ClearNativeContents_Type(IntPtr pNativeHome, Int32 cElements);
};
} // namespace MngdHiddenLengthArrayMarshalerNamespace
using MngdHiddenLengthArrayMarshaler = MngdHiddenLengthArrayMarshalerNamespace::MngdHiddenLengthArrayMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
