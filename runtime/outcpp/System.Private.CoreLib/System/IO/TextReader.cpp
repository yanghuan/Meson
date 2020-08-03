#include "TextReader-dep.h"

#include <System.Private.CoreLib/System/IO/TextReader-dep.h>

namespace System::Private::CoreLib::System::IO::TextReaderNamespace {
void NullTextReader___::Ctor() {
}

Int32 NullTextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

String NullTextReader___::ReadLine() {
  return nullptr;
}

void SyncTextReader___::Ctor(TextReader t) {
}

void SyncTextReader___::Close() {
}

void SyncTextReader___::Dispose(Boolean disposing) {
}

Int32 SyncTextReader___::Peek() {
  return Int32();
}

Int32 SyncTextReader___::Read() {
  return Int32();
}

Int32 SyncTextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 SyncTextReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

String SyncTextReader___::ReadLine() {
  return nullptr;
}

String SyncTextReader___::ReadToEnd() {
  return nullptr;
}

Task<String> SyncTextReader___::ReadLineAsync() {
  return nullptr;
}

Task<String> SyncTextReader___::ReadToEndAsync() {
  return nullptr;
}

Task<Int32> SyncTextReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

Task<Int32> SyncTextReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

void TextReader___::Ctor() {
}

void TextReader___::Close() {
}

void TextReader___::Dispose() {
}

void TextReader___::Dispose(Boolean disposing) {
}

Int32 TextReader___::Peek() {
  return Int32();
}

Int32 TextReader___::Read() {
  return Int32();
}

Int32 TextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 TextReader___::Read(Span<Char> buffer) {
  return Int32();
}

String TextReader___::ReadToEnd() {
  return nullptr;
}

Int32 TextReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 TextReader___::ReadBlock(Span<Char> buffer) {
  return Int32();
}

String TextReader___::ReadLine() {
  return nullptr;
}

Task<String> TextReader___::ReadLineAsync() {
  return nullptr;
}

Task<String> TextReader___::ReadToEndAsync() {
  return nullptr;
}

Task<Int32> TextReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

ValueTask<Int32> TextReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

ValueTask<Int32> TextReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

Task<Int32> TextReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

ValueTask<Int32> TextReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

ValueTask<Int32> TextReader___::ReadBlockAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
}

TextReader TextReader___::Synchronized(TextReader reader) {
  return nullptr;
}

void TextReader___::SCtor() {
}

} // namespace System::Private::CoreLib::System::IO::TextReaderNamespace
