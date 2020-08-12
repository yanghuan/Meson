#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(Delegate)
FORWARDS(Double)
FORWARD(Exception)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Guid)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(IRuntimeFieldInfo)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(RuntimeMethodHandleInternal)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
FORWARD(Module)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(QCallModule)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IBindCtx)
FORWARD(IMoniker)
FORWARD(ITypeInfo)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Security {
FORWARD(SecureString)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CustomQueryInterfaceMode : int32_t;
namespace MarshalNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices::ComTypes;
using namespace System::Security;
class Marshal {
  public: static Int32 SizeOfHelper(Type t, Boolean throwIfNotMarshalable);
  public: static IntPtr OffsetOf(Type t, String fieldName);
  private: static IntPtr OffsetOfHelper(IRuntimeFieldInfo f);
  public: static Byte ReadByte(Object ptr, Int32 ofs);
  public: static Int16 ReadInt16(Object ptr, Int32 ofs);
  public: static Int32 ReadInt32(Object ptr, Int32 ofs);
  public: static Int64 ReadInt64(Object ptr, Int32 ofs);
  private: template <class T>
  static T ReadValueSlow(Object ptr, Int32 ofs, Func<IntPtr, Int32, T> readValueHelper);
  public: static void WriteByte(Object ptr, Int32 ofs, Byte val);
  public: static void WriteInt16(Object ptr, Int32 ofs, Int16 val);
  public: static void WriteInt32(Object ptr, Int32 ofs, Int32 val);
  public: static void WriteInt64(Object ptr, Int32 ofs, Int64 val);
  private: template <class T>
  static void WriteValueSlow(Object ptr, Int32 ofs, T val, Action<IntPtr, Int32, T> writeValueHelper);
  public: static Int32 GetLastWin32Error();
  public: static void SetLastWin32Error(Int32 error);
  private: static void PrelinkCore(MethodInfo m);
  private: static void InternalPrelink(RuntimeMethodHandleInternal m);
  public: static IntPtr GetExceptionPointers();
  public: static Int32 GetExceptionCode();
  public: static void StructureToPtr(Object structure, IntPtr ptr, Boolean fDeleteOld);
  private: static Object PtrToStructureHelper(IntPtr ptr, Type structureType);
  private: static void PtrToStructureHelper(IntPtr ptr, Object structure, Boolean allowValueClasses);
  public: static void DestroyStructure(IntPtr ptr, Type structuretype);
  public: static Boolean IsPinnable(Object obj);
  public: static IntPtr GetHINSTANCE(Module m);
  private: static IntPtr GetHINSTANCE(QCallModule m);
  public: static Exception GetExceptionForHRInternal(Int32 errorCode, IntPtr errorInfo);
  public: static IntPtr AllocHGlobal(IntPtr cb);
  public: static void FreeHGlobal(IntPtr hglobal);
  public: static IntPtr ReAllocHGlobal(IntPtr pv, IntPtr cb);
  public: static Int32 GetHRForException(Exception e);
  public: static String GetTypeInfoName(ITypeInfo typeInfo);
  public: static Type GetTypeFromCLSID(Guid clsid);
  public: static IntPtr GetIUnknownForObject(Object o);
  private: static IntPtr GetIUnknownForObjectNative(Object o, Boolean onlyInContext);
  public: static IntPtr GetIDispatchForObject(Object o);
  private: static IntPtr GetIDispatchForObjectNative(Object o, Boolean onlyInContext);
  public: static IntPtr GetComInterfaceForObject(Object o, Type T);
  public: template <class T, class TInterface>
  static IntPtr GetComInterfaceForObject(T o);
  public: static IntPtr GetComInterfaceForObject(Object o, Type T, CustomQueryInterfaceMode mode);
  private: static IntPtr GetComInterfaceForObjectNative(Object o, Type t, Boolean onlyInContext, Boolean fEnableCustomizedQueryInterface);
  public: static Object GetObjectForIUnknown(IntPtr pUnk);
  private: static Object GetObjectForIUnknownNative(IntPtr pUnk);
  public: static Object GetUniqueObjectForIUnknown(IntPtr unknown);
  private: static Object GetUniqueObjectForIUnknownNative(IntPtr unknown);
  public: static Object GetTypedObjectForIUnknown(IntPtr pUnk, Type t);
  public: static IntPtr CreateAggregatedObject(IntPtr pOuter, Object o);
  public: template <class T>
  static IntPtr CreateAggregatedObject(IntPtr pOuter, T o);
  public: static void CleanupUnusedObjectsInCurrentContext();
  public: static Boolean AreComObjectsAvailableForCleanup();
  public: static Boolean IsComObject(Object o);
  public: static IntPtr AllocCoTaskMem(Int32 cb);
  public: static void FreeCoTaskMem(IntPtr ptr);
  public: static IntPtr ReAllocCoTaskMem(IntPtr pv, Int32 cb);
  public: static IntPtr AllocBSTR(Int32 length);
  public: static void FreeBSTR(IntPtr ptr);
  public: static IntPtr StringToBSTR(String s);
  public: static String PtrToStringBSTR(IntPtr ptr);
  public: static Int32 ReleaseComObject(Object o);
  public: static Int32 InternalReleaseComObject(Object o);
  public: static Int32 FinalReleaseComObject(Object o);
  public: static void InternalFinalReleaseComObject(Object o);
  public: static Object GetComObjectData(Object obj, Object key);
  public: static Boolean SetComObjectData(Object obj, Object key, Object data);
  public: static Object CreateWrapperOfType(Object o, Type t);
  public: template <class T, class TWrapper>
  static TWrapper CreateWrapperOfType(T o);
  private: static Object InternalCreateWrapperOfType(Object o, Type t);
  public: static Boolean IsTypeVisibleFromCom(Type t);
  public: static Int32 QueryInterface(IntPtr pUnk, Guid& iid, IntPtr& ppv);
  public: static Int32 AddRef(IntPtr pUnk);
  public: static Int32 Release(IntPtr pUnk);
  public: static void GetNativeVariantForObject(Object obj, IntPtr pDstNativeVariant);
  public: template <class T>
  static void GetNativeVariantForObject(T obj, IntPtr pDstNativeVariant);
  public: static Object GetObjectForNativeVariant(IntPtr pSrcNativeVariant);
  public: template <class T>
  static T GetObjectForNativeVariant(IntPtr pSrcNativeVariant);
  public: static Array<Object> GetObjectsForNativeVariants(IntPtr aSrcNativeVariant, Int32 cVars);
  public: template <class T>
  static Array<T> GetObjectsForNativeVariants(IntPtr aSrcNativeVariant, Int32 cVars);
  public: static Int32 GetStartComSlot(Type t);
  public: static Int32 GetEndComSlot(Type t);
  public: static Object BindToMoniker(String monikerName);
  private: static void CreateBindCtx(UInt32 reserved, IBindCtx& ppbc);
  private: static void MkParseDisplayName(IBindCtx pbc, String szUserName, UInt32& pchEaten, IMoniker& ppmk);
  private: static void BindMoniker(IMoniker pmk, UInt32 grfOpt, Guid& iidResult, Object& ppvResult);
  public: static void ChangeWrapperHandleStrength(Object otp, Boolean fIsWeak);
  public: static Delegate GetDelegateForFunctionPointerInternal(IntPtr ptr, Type t);
  public: static IntPtr GetFunctionPointerForDelegateInternal(Delegate d);
  public: static IntPtr AllocHGlobal(Int32 cb);
  public: static String PtrToStringAnsi(IntPtr ptr);
  public: static String PtrToStringAnsi(IntPtr ptr, Int32 len);
  public: static String PtrToStringUni(IntPtr ptr);
  public: static String PtrToStringUni(IntPtr ptr, Int32 len);
  public: static String PtrToStringUTF8(IntPtr ptr);
  public: static String PtrToStringUTF8(IntPtr ptr, Int32 byteLen);
  public: static Int32 SizeOf(Object structure);
  public: template <class T>
  static Int32 SizeOf(T structure);
  public: static Int32 SizeOf(Type t);
  public: template <class T>
  static Int32 SizeOf();
  public: static IntPtr UnsafeAddrOfPinnedArrayElement(Array<> arr, Int32 index);
  public: template <class T>
  static IntPtr UnsafeAddrOfPinnedArrayElement(Array<T> arr, Int32 index);
  public: template <class T>
  static IntPtr OffsetOf(String fieldName);
  public: static void Copy(Array<Int32> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Char> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Int16> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Int64> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Single> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Double> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<Byte> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(Array<IntPtr> source, Int32 startIndex, IntPtr destination, Int32 length);
  private: template <class T>
  static void CopyToNative(Array<T> source, Int32 startIndex, IntPtr destination, Int32 length);
  public: static void Copy(IntPtr source, Array<Int32> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Char> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Int16> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Int64> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Single> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Double> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<Byte> destination, Int32 startIndex, Int32 length);
  public: static void Copy(IntPtr source, Array<IntPtr> destination, Int32 startIndex, Int32 length);
  private: template <class T>
  static void CopyToManaged(IntPtr source, Array<T> destination, Int32 startIndex, Int32 length);
  public: static Byte ReadByte(IntPtr ptr, Int32 ofs);
  public: static Byte ReadByte(IntPtr ptr);
  public: static Int16 ReadInt16(IntPtr ptr, Int32 ofs);
  public: static Int16 ReadInt16(IntPtr ptr);
  public: static Int32 ReadInt32(IntPtr ptr, Int32 ofs);
  public: static Int32 ReadInt32(IntPtr ptr);
  public: static IntPtr ReadIntPtr(Object ptr, Int32 ofs);
  public: static IntPtr ReadIntPtr(IntPtr ptr, Int32 ofs);
  public: static IntPtr ReadIntPtr(IntPtr ptr);
  public: static Int64 ReadInt64(IntPtr ptr, Int32 ofs);
  public: static Int64 ReadInt64(IntPtr ptr);
  public: static void WriteByte(IntPtr ptr, Int32 ofs, Byte val);
  public: static void WriteByte(IntPtr ptr, Byte val);
  public: static void WriteInt16(IntPtr ptr, Int32 ofs, Int16 val);
  public: static void WriteInt16(IntPtr ptr, Int16 val);
  public: static void WriteInt16(IntPtr ptr, Int32 ofs, Char val);
  public: static void WriteInt16(Object ptr, Int32 ofs, Char val);
  public: static void WriteInt16(IntPtr ptr, Char val);
  public: static void WriteInt32(IntPtr ptr, Int32 ofs, Int32 val);
  public: static void WriteInt32(IntPtr ptr, Int32 val);
  public: static void WriteIntPtr(IntPtr ptr, Int32 ofs, IntPtr val);
  public: static void WriteIntPtr(Object ptr, Int32 ofs, IntPtr val);
  public: static void WriteIntPtr(IntPtr ptr, IntPtr val);
  public: static void WriteInt64(IntPtr ptr, Int32 ofs, Int64 val);
  public: static void WriteInt64(IntPtr ptr, Int64 val);
  public: static void Prelink(MethodInfo m);
  public: static void PrelinkAll(Type c);
  public: template <class T>
  static void StructureToPtr(T structure, IntPtr ptr, Boolean fDeleteOld);
  public: static Object PtrToStructure(IntPtr ptr, Type structureType);
  public: static void PtrToStructure(IntPtr ptr, Object structure);
  public: template <class T>
  static void PtrToStructure(IntPtr ptr, T structure);
  public: template <class T>
  static T PtrToStructure(IntPtr ptr);
  public: template <class T>
  static void DestroyStructure(IntPtr ptr);
  public: static Exception GetExceptionForHR(Int32 errorCode);
  public: static Exception GetExceptionForHR(Int32 errorCode, IntPtr errorInfo);
  public: static void ThrowExceptionForHR(Int32 errorCode);
  public: static void ThrowExceptionForHR(Int32 errorCode, IntPtr errorInfo);
  public: static IntPtr SecureStringToBSTR(SecureString s);
  public: static IntPtr SecureStringToCoTaskMemAnsi(SecureString s);
  public: static IntPtr SecureStringToCoTaskMemUnicode(SecureString s);
  public: static IntPtr SecureStringToGlobalAllocAnsi(SecureString s);
  public: static IntPtr SecureStringToGlobalAllocUnicode(SecureString s);
  public: static IntPtr StringToHGlobalAnsi(String s);
  public: static IntPtr StringToHGlobalUni(String s);
  public: static IntPtr StringToCoTaskMemUni(String s);
  public: static IntPtr StringToCoTaskMemUTF8(String s);
  public: static IntPtr StringToCoTaskMemAnsi(String s);
  public: static Guid GenerateGuidForType(Type type);
  public: static String GenerateProgIdForType(Type type);
  public: static Delegate GetDelegateForFunctionPointer(IntPtr ptr, Type t);
  public: template <class TDelegate>
  static TDelegate GetDelegateForFunctionPointer(IntPtr ptr);
  public: static IntPtr GetFunctionPointerForDelegate(Delegate d);
  public: template <class TDelegate>
  static IntPtr GetFunctionPointerForDelegate(TDelegate d);
  public: static Int32 GetHRForLastWin32Error();
  public: static void ZeroFreeBSTR(IntPtr s);
  public: static void ZeroFreeCoTaskMemAnsi(IntPtr s);
  public: static void ZeroFreeCoTaskMemUnicode(IntPtr s);
  public: static void ZeroFreeCoTaskMemUTF8(IntPtr s);
  public: static void ZeroFreeGlobalAllocAnsi(IntPtr s);
  public: static void ZeroFreeGlobalAllocUnicode(IntPtr s);
  public: static UInt32 SysStringByteLen(IntPtr s);
  public: static String PtrToStringAuto(IntPtr ptr, Int32 len);
  public: static String PtrToStringAuto(IntPtr ptr);
  public: static IntPtr StringToHGlobalAuto(String s);
  public: static IntPtr StringToCoTaskMemAuto(String s);
  private: static Int32 GetSystemMaxDBCSCharSize();
  private: static Boolean IsNullOrWin32Atom(IntPtr ptr);
  public: static Int32 StringToAnsiString(String s, Byte* buffer, Int32 bufferLength, Boolean bestFit, Boolean throwOnUnmappableChar);
  public: static Int32 GetAnsiStringByteCount(ReadOnlySpan<Char> chars);
  public: static void GetAnsiStringBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes);
  private: static void ctor_static();
  public: static Guid IID_IUnknown;
  public: static Int32 SystemDefaultCharSize;
  public: static Int32 SystemMaxDBCSCharSize;
};
} // namespace MarshalNamespace
using Marshal = MarshalNamespace::Marshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
