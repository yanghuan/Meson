#include "AssemblyName-dep.h"

#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyNameNamespace {
String AssemblyName___::get_Name() {
  return nullptr;
};
void AssemblyName___::set_Name(String value) {
  return void();
};
Version AssemblyName___::get_Version() {
  return nullptr;
};
void AssemblyName___::set_Version(Version value) {
  return void();
};
CultureInfo AssemblyName___::get_CultureInfo() {
  return nullptr;
};
void AssemblyName___::set_CultureInfo(CultureInfo value) {
  return void();
};
String AssemblyName___::get_CultureName() {
  return nullptr;
};
void AssemblyName___::set_CultureName(String value) {
  return void();
};
String AssemblyName___::get_CodeBase() {
  return nullptr;
};
void AssemblyName___::set_CodeBase(String value) {
  return void();
};
String AssemblyName___::get_EscapedCodeBase() {
  return nullptr;
};
ProcessorArchitecture AssemblyName___::get_ProcessorArchitecture() {
  return ProcessorArchitecture();
};
void AssemblyName___::set_ProcessorArchitecture(ProcessorArchitecture value) {
  return void();
};
AssemblyContentType AssemblyName___::get_ContentType() {
  return AssemblyContentType();
};
void AssemblyName___::set_ContentType(AssemblyContentType value) {
  return void();
};
AssemblyNameFlags AssemblyName___::get_Flags() {
  return AssemblyNameFlags();
};
void AssemblyName___::set_Flags(AssemblyNameFlags value) {
  return void();
};
AssemblyHashAlgorithm AssemblyName___::get_HashAlgorithm() {
  return AssemblyHashAlgorithm();
};
void AssemblyName___::set_HashAlgorithm(AssemblyHashAlgorithm value) {
  return void();
};
AssemblyVersionCompatibility AssemblyName___::get_VersionCompatibility() {
  return AssemblyVersionCompatibility();
};
void AssemblyName___::set_VersionCompatibility(AssemblyVersionCompatibility value) {
  return void();
};
StrongNameKeyPair AssemblyName___::get_KeyPair() {
  return nullptr;
};
void AssemblyName___::set_KeyPair(StrongNameKeyPair value) {
  return void();
};
String AssemblyName___::get_FullName() {
  return nullptr;
};
AssemblyName AssemblyName___::GetFileInformationCore(String assemblyFile) {
  return nullptr;
};
void AssemblyName___::SetProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm) {
  return void();
};
ProcessorArchitecture AssemblyName___::CalculateProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm, AssemblyNameFlags flags) {
  return ProcessorArchitecture();
};
Object AssemblyName___::Clone() {
  return nullptr;
};
AssemblyName AssemblyName___::GetAssemblyName(String assemblyFile) {
  return nullptr;
};
Array<Byte> AssemblyName___::GetPublicKey() {
  return Array<Byte>();
};
void AssemblyName___::SetPublicKey(Array<Byte> publicKey) {
  return void();
};
Array<Byte> AssemblyName___::GetPublicKeyToken() {
  return Array<Byte>();
};
void AssemblyName___::SetPublicKeyToken(Array<Byte> publicKeyToken) {
  return void();
};
String AssemblyName___::ToString() {
  return nullptr;
};
void AssemblyName___::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
void AssemblyName___::OnDeserialization(Object sender) {
  return void();
};
Boolean AssemblyName___::ReferenceMatchesDefinition(AssemblyName reference, AssemblyName definition) {
  return Boolean();
};
String AssemblyName___::EscapeCodeBase(String codebase) {
  return nullptr;
};
Array<Char> AssemblyName___::EscapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPos, Boolean isUriString, Char force1, Char force2, Char rsvd) {
  return Array<Char>();
};
Array<Char> AssemblyName___::EnsureDestinationSize(Char* pStr, Array<Char> dest, Int32 currentInputPos, Int16 charsToAdd, Int16 minReallocateChars, Int32& destPos, Int32 prevInputPos) {
  return Array<Char>();
};
void AssemblyName___::EscapeAsciiChar(Char ch, Array<Char> to, Int32& pos) {
  return void();
};
Char AssemblyName___::EscapedAscii(Char digit, Char next) {
  return Char();
};
Boolean AssemblyName___::IsReservedUnreservedOrHash(Char c) {
  return Boolean();
};
Boolean AssemblyName___::IsUnreserved(Char c) {
  return Boolean();
};
Boolean AssemblyName___::IsAsciiLetter(Char character) {
  return Boolean();
};
Boolean AssemblyName___::IsAsciiLetterOrDigit(Char character) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Reflection::AssemblyNameNamespace
