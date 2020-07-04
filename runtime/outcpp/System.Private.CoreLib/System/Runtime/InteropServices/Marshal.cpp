#include "Marshal-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalNamespace {
IntPtr Marshal::OffsetOf(Type t, String fieldName) {
  return IntPtr();
};
Byte Marshal::ReadByte(Object ptr, Int32 ofs) {
  return Byte();
};
Int16 Marshal::ReadInt16(Object ptr, Int32 ofs) {
  return Int16();
};
Int32 Marshal::ReadInt32(Object ptr, Int32 ofs) {
  return Int32();
};
Int64 Marshal::ReadInt64(Object ptr, Int32 ofs) {
  return Int64();
};
void Marshal::WriteByte(Object ptr, Int32 ofs, Byte val) {
};
void Marshal::WriteInt16(Object ptr, Int32 ofs, Int16 val) {
};
void Marshal::WriteInt32(Object ptr, Int32 ofs, Int32 val) {
};
void Marshal::WriteInt64(Object ptr, Int32 ofs, Int64 val) {
};
void Marshal::PrelinkCore(MethodInfo m) {
};
Object Marshal::PtrToStructureHelper(IntPtr ptr, Type structureType) {
  return nullptr;
};
IntPtr Marshal::GetHINSTANCE(Module m) {
  return IntPtr();
};
IntPtr Marshal::AllocHGlobal(IntPtr cb) {
  return IntPtr();
};
void Marshal::FreeHGlobal(IntPtr hglobal) {
};
IntPtr Marshal::ReAllocHGlobal(IntPtr pv, IntPtr cb) {
  return IntPtr();
};
String Marshal::GetTypeInfoName(ITypeInfo typeInfo) {
  return nullptr;
};
Type Marshal::GetTypeFromCLSID(Guid clsid) {
  return nullptr;
};
IntPtr Marshal::GetIUnknownForObject(Object o) {
  return IntPtr();
};
IntPtr Marshal::GetComInterfaceForObject(Object o, Type T) {
  return IntPtr();
};
IntPtr Marshal::GetComInterfaceForObject(Object o, Type T, CustomQueryInterfaceMode mode) {
  return IntPtr();
};
IntPtr Marshal::AllocCoTaskMem(Int32 cb) {
  return IntPtr();
};
void Marshal::FreeCoTaskMem(IntPtr ptr) {
};
IntPtr Marshal::ReAllocCoTaskMem(IntPtr pv, Int32 cb) {
  return IntPtr();
};
IntPtr Marshal::AllocBSTR(Int32 length) {
  return IntPtr();
};
void Marshal::FreeBSTR(IntPtr ptr) {
};
IntPtr Marshal::StringToBSTR(String s) {
  return IntPtr();
};
String Marshal::PtrToStringBSTR(IntPtr ptr) {
  return nullptr;
};
Int32 Marshal::ReleaseComObject(Object o) {
  return Int32();
};
Int32 Marshal::FinalReleaseComObject(Object o) {
  return Int32();
};
Object Marshal::GetComObjectData(Object obj, Object key) {
  return nullptr;
};
Boolean Marshal::SetComObjectData(Object obj, Object key, Object data) {
  return Boolean();
};
Object Marshal::CreateWrapperOfType(Object o, Type t) {
  return nullptr;
};
Object Marshal::BindToMoniker(String monikerName) {
  return nullptr;
};
IntPtr Marshal::AllocHGlobal(Int32 cb) {
  return IntPtr();
};
String Marshal::PtrToStringAnsi(IntPtr ptr) {
  return nullptr;
};
String Marshal::PtrToStringAnsi(IntPtr ptr, Int32 len) {
  return nullptr;
};
String Marshal::PtrToStringUni(IntPtr ptr) {
  return nullptr;
};
String Marshal::PtrToStringUni(IntPtr ptr, Int32 len) {
  return nullptr;
};
String Marshal::PtrToStringUTF8(IntPtr ptr) {
  return nullptr;
};
String Marshal::PtrToStringUTF8(IntPtr ptr, Int32 byteLen) {
  return nullptr;
};
Int32 Marshal::SizeOf(Object structure) {
  return Int32();
};
Int32 Marshal::SizeOf(Type t) {
  return Int32();
};
IntPtr Marshal::UnsafeAddrOfPinnedArrayElement(Array<> arr, Int32 index) {
  return IntPtr();
};
void Marshal::Copy(Array<Int32> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Char> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Int16> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Int64> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Single> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Double> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<Byte> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(Array<IntPtr> source, Int32 startIndex, IntPtr destination, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Int32> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Char> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Int16> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Int64> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Single> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Double> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<Byte> destination, Int32 startIndex, Int32 length) {
};
void Marshal::Copy(IntPtr source, Array<IntPtr> destination, Int32 startIndex, Int32 length) {
};
Byte Marshal::ReadByte(IntPtr ptr, Int32 ofs) {
  return Byte();
};
Byte Marshal::ReadByte(IntPtr ptr) {
  return Byte();
};
Int16 Marshal::ReadInt16(IntPtr ptr, Int32 ofs) {
  return Int16();
};
Int16 Marshal::ReadInt16(IntPtr ptr) {
  return Int16();
};
Int32 Marshal::ReadInt32(IntPtr ptr, Int32 ofs) {
  return Int32();
};
Int32 Marshal::ReadInt32(IntPtr ptr) {
  return Int32();
};
IntPtr Marshal::ReadIntPtr(Object ptr, Int32 ofs) {
  return IntPtr();
};
IntPtr Marshal::ReadIntPtr(IntPtr ptr, Int32 ofs) {
  return IntPtr();
};
IntPtr Marshal::ReadIntPtr(IntPtr ptr) {
  return IntPtr();
};
Int64 Marshal::ReadInt64(IntPtr ptr, Int32 ofs) {
  return Int64();
};
Int64 Marshal::ReadInt64(IntPtr ptr) {
  return Int64();
};
void Marshal::WriteByte(IntPtr ptr, Int32 ofs, Byte val) {
};
void Marshal::WriteByte(IntPtr ptr, Byte val) {
};
void Marshal::WriteInt16(IntPtr ptr, Int32 ofs, Int16 val) {
};
void Marshal::WriteInt16(IntPtr ptr, Int16 val) {
};
void Marshal::WriteInt16(IntPtr ptr, Int32 ofs, Char val) {
};
void Marshal::WriteInt16(Object ptr, Int32 ofs, Char val) {
};
void Marshal::WriteInt16(IntPtr ptr, Char val) {
};
void Marshal::WriteInt32(IntPtr ptr, Int32 ofs, Int32 val) {
};
void Marshal::WriteInt32(IntPtr ptr, Int32 val) {
};
void Marshal::WriteIntPtr(IntPtr ptr, Int32 ofs, IntPtr val) {
};
void Marshal::WriteIntPtr(Object ptr, Int32 ofs, IntPtr val) {
};
void Marshal::WriteIntPtr(IntPtr ptr, IntPtr val) {
};
void Marshal::WriteInt64(IntPtr ptr, Int32 ofs, Int64 val) {
};
void Marshal::WriteInt64(IntPtr ptr, Int64 val) {
};
void Marshal::Prelink(MethodInfo m) {
};
void Marshal::PrelinkAll(Type c) {
};
Object Marshal::PtrToStructure(IntPtr ptr, Type structureType) {
  return nullptr;
};
void Marshal::PtrToStructure(IntPtr ptr, Object structure) {
};
Exception Marshal::GetExceptionForHR(Int32 errorCode) {
  return nullptr;
};
Exception Marshal::GetExceptionForHR(Int32 errorCode, IntPtr errorInfo) {
  return nullptr;
};
void Marshal::ThrowExceptionForHR(Int32 errorCode) {
};
void Marshal::ThrowExceptionForHR(Int32 errorCode, IntPtr errorInfo) {
};
IntPtr Marshal::SecureStringToBSTR(SecureString s) {
  return IntPtr();
};
IntPtr Marshal::SecureStringToCoTaskMemAnsi(SecureString s) {
  return IntPtr();
};
IntPtr Marshal::SecureStringToCoTaskMemUnicode(SecureString s) {
  return IntPtr();
};
IntPtr Marshal::SecureStringToGlobalAllocAnsi(SecureString s) {
  return IntPtr();
};
IntPtr Marshal::SecureStringToGlobalAllocUnicode(SecureString s) {
  return IntPtr();
};
IntPtr Marshal::StringToHGlobalAnsi(String s) {
  return IntPtr();
};
IntPtr Marshal::StringToHGlobalUni(String s) {
  return IntPtr();
};
IntPtr Marshal::StringToCoTaskMemUni(String s) {
  return IntPtr();
};
IntPtr Marshal::StringToCoTaskMemUTF8(String s) {
  return IntPtr();
};
IntPtr Marshal::StringToCoTaskMemAnsi(String s) {
  return IntPtr();
};
Guid Marshal::GenerateGuidForType(Type type) {
  return Guid();
};
String Marshal::GenerateProgIdForType(Type type) {
  return nullptr;
};
Delegate Marshal::GetDelegateForFunctionPointer(IntPtr ptr, Type t) {
  return nullptr;
};
IntPtr Marshal::GetFunctionPointerForDelegate(Delegate d) {
  return IntPtr();
};
Int32 Marshal::GetHRForLastWin32Error() {
  return Int32();
};
IntPtr Marshal::GetIDispatchForObject(Object o) {
  return IntPtr();
};
void Marshal::ZeroFreeBSTR(IntPtr s) {
};
void Marshal::ZeroFreeCoTaskMemAnsi(IntPtr s) {
};
void Marshal::ZeroFreeCoTaskMemUnicode(IntPtr s) {
};
void Marshal::ZeroFreeCoTaskMemUTF8(IntPtr s) {
};
void Marshal::ZeroFreeGlobalAllocAnsi(IntPtr s) {
};
void Marshal::ZeroFreeGlobalAllocUnicode(IntPtr s) {
};
UInt32 Marshal::SysStringByteLen(IntPtr s) {
  return UInt32();
};
String Marshal::PtrToStringAuto(IntPtr ptr, Int32 len) {
  return nullptr;
};
String Marshal::PtrToStringAuto(IntPtr ptr) {
  return nullptr;
};
IntPtr Marshal::StringToHGlobalAuto(String s) {
  return IntPtr();
};
IntPtr Marshal::StringToCoTaskMemAuto(String s) {
  return IntPtr();
};
Int32 Marshal::GetSystemMaxDBCSCharSize() {
  return Int32();
};
Boolean Marshal::IsNullOrWin32Atom(IntPtr ptr) {
  return Boolean();
};
Int32 Marshal::StringToAnsiString(String s, Byte* buffer, Int32 bufferLength, Boolean bestFit, Boolean throwOnUnmappableChar) {
  return Int32();
};
Int32 Marshal::GetAnsiStringByteCount(ReadOnlySpan<Char> chars) {
  return Int32();
};
void Marshal::GetAnsiStringBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalNamespace
