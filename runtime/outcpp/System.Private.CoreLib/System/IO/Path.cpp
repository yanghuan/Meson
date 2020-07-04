#include "Path-dep.h"

namespace System::Private::CoreLib::System::IO::PathNamespace {
ReadOnlySpan<Byte> Path::get_Base32Char() {
  return ReadOnlySpan<Byte>();
};
StringComparison Path::get_StringComparison() {
  return StringComparison::OrdinalIgnoreCase;
};
Boolean Path::get_IsCaseSensitive() {
  return Boolean();
};
String Path::ChangeExtension(String path, String extension) {
  return nullptr;
};
String Path::GetDirectoryName(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::GetDirectoryName(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
Int32 Path::GetDirectoryNameOffset(ReadOnlySpan<Char> path) {
  return Int32();
};
String Path::GetExtension(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::GetExtension(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
String Path::GetFileName(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::GetFileName(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
String Path::GetFileNameWithoutExtension(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::GetFileNameWithoutExtension(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
String Path::GetRandomFileName() {
  return nullptr;
};
Boolean Path::IsPathFullyQualified(String path) {
  return Boolean();
};
Boolean Path::IsPathFullyQualified(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean Path::HasExtension(String path) {
  return Boolean();
};
Boolean Path::HasExtension(ReadOnlySpan<Char> path) {
  return Boolean();
};
String Path::Combine(String path1, String path2) {
  return nullptr;
};
String Path::Combine(String path1, String path2, String path3) {
  return nullptr;
};
String Path::Combine(String path1, String path2, String path3, String path4) {
  return nullptr;
};
String Path::Combine(Array<String> paths) {
  return nullptr;
};
String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2) {
  return nullptr;
};
String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3) {
  return nullptr;
};
String Path::Join(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, ReadOnlySpan<Char> path4) {
  return nullptr;
};
String Path::Join(String path1, String path2) {
  return nullptr;
};
String Path::Join(String path1, String path2, String path3) {
  return nullptr;
};
String Path::Join(String path1, String path2, String path3, String path4) {
  return nullptr;
};
String Path::Join(Array<String> paths) {
  return nullptr;
};
Boolean Path::TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
Boolean Path::TryJoin(ReadOnlySpan<Char> path1, ReadOnlySpan<Char> path2, ReadOnlySpan<Char> path3, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
String Path::CombineInternal(String first, String second) {
  return nullptr;
};
String Path::CombineInternal(String first, String second, String third) {
  return nullptr;
};
String Path::CombineInternal(String first, String second, String third, String fourth) {
  return nullptr;
};
String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second) {
  return nullptr;
};
String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third) {
  return nullptr;
};
String Path::JoinInternal(ReadOnlySpan<Char> first, ReadOnlySpan<Char> second, ReadOnlySpan<Char> third, ReadOnlySpan<Char> fourth) {
  return nullptr;
};
void Path::Populate83FileNameFromRandomBytes(Byte* bytes, Int32 byteCount, Span<Char> chars) {
};
String Path::GetRelativePath(String relativeTo, String path) {
  return nullptr;
};
String Path::GetRelativePath(String relativeTo, String path, StringComparison comparisonType) {
  return nullptr;
};
String Path::TrimEndingDirectorySeparator(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::TrimEndingDirectorySeparator(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
Boolean Path::EndsInDirectorySeparator(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean Path::EndsInDirectorySeparator(String path) {
  return Boolean();
};
Array<Char> Path::GetInvalidFileNameChars() {
  return Array<Char>();
};
Array<Char> Path::GetInvalidPathChars() {
  return Array<Char>();
};
String Path::GetFullPath(String path) {
  return nullptr;
};
String Path::GetFullPath(String path, String basePath) {
  return nullptr;
};
String Path::GetTempPath() {
  return nullptr;
};
void Path::GetTempPath(ValueStringBuilder& builder) {
};
String Path::GetTempFileName() {
  return nullptr;
};
Boolean Path::IsPathRooted(String path) {
  return Boolean();
};
Boolean Path::IsPathRooted(ReadOnlySpan<Char> path) {
  return Boolean();
};
String Path::GetPathRoot(String path) {
  return nullptr;
};
ReadOnlySpan<Char> Path::GetPathRoot(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
ReadOnlySpan<Char> Path::GetVolumeName(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
Int32 Path::GetUncRootLength(ReadOnlySpan<Char> path) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::IO::PathNamespace
