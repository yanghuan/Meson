#include "ResourceReader-dep.h"

#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceReaderNamespace {
Object ResourceReader___::ResourceEnumerator___::get_Key() {
  return nullptr;
};
Object ResourceReader___::ResourceEnumerator___::get_Current() {
  return nullptr;
};
Int32 ResourceReader___::ResourceEnumerator___::get_DataPosition() {
  return Int32();
};
DictionaryEntry ResourceReader___::ResourceEnumerator___::get_Entry() {
  return DictionaryEntry();
};
Object ResourceReader___::ResourceEnumerator___::get_Value() {
  return nullptr;
};
Boolean ResourceReader___::ResourceEnumerator___::MoveNext() {
  return Boolean();
};
void ResourceReader___::ResourceEnumerator___::Reset() {
  return void();
};
void ResourceReader___::Close() {
  return void();
};
void ResourceReader___::Dispose() {
  return void();
};
void ResourceReader___::Dispose(Boolean disposing) {
  return void();
};
Int32 ResourceReader___::ReadUnalignedI4(Int32* p) {
  return Int32();
};
void ResourceReader___::SkipString() {
  return void();
};
Int32 ResourceReader___::GetNameHash(Int32 index) {
  return Int32();
};
Int32 ResourceReader___::GetNamePosition(Int32 index) {
  return Int32();
};
IDictionaryEnumerator ResourceReader___::GetEnumerator() {
  return nullptr;
};
ResourceReader::in::ResourceEnumerator ResourceReader___::GetEnumeratorInternal() {
  return nullptr;
};
Int32 ResourceReader___::FindPosForResource(String name) {
  return Int32();
};
Boolean ResourceReader___::CompareStringEqualsName(String name) {
  return Boolean();
};
String ResourceReader___::AllocateStringForNameIndex(Int32 index, Int32& dataOffset) {
  return nullptr;
};
Object ResourceReader___::GetValueForNameIndex(Int32 index) {
  return nullptr;
};
String ResourceReader___::LoadString(Int32 pos) {
  return nullptr;
};
Object ResourceReader___::LoadObject(Int32 pos) {
  return nullptr;
};
Object ResourceReader___::LoadObject(Int32 pos, ResourceTypeCode& typeCode) {
  return nullptr;
};
Object ResourceReader___::LoadObjectV1(Int32 pos) {
  return nullptr;
};
Object ResourceReader___::_LoadObjectV1(Int32 pos) {
  return nullptr;
};
Object ResourceReader___::LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode) {
  return nullptr;
};
Object ResourceReader___::_LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode) {
  return nullptr;
};
void ResourceReader___::ReadResources() {
  return void();
};
void ResourceReader___::_ReadResources() {
  return void();
};
Type ResourceReader___::FindType(Int32 typeIndex) {
  return nullptr;
};
String ResourceReader___::TypeNameFromTypeCode(ResourceTypeCode typeCode) {
  return nullptr;
};
Object ResourceReader___::DeserializeObject(Int32 typeIndex) {
  return nullptr;
};
void ResourceReader___::InitializeBinaryFormatter() {
  return void();
};
Boolean ResourceReader___::ValidateReaderType(String readerType) {
  return Boolean();
};
void ResourceReader___::GetResourceData(String resourceName, String& resourceType, Array<Byte>& resourceData) {
  return void();
};
} // namespace System::Private::CoreLib::System::Resources::ResourceReaderNamespace
