#include "BinaryReader-dep.h"

namespace System::Private::CoreLib::System::IO::BinaryReaderNamespace {
Stream BinaryReader___::get_BaseStream() {
  return nullptr;
}

void BinaryReader___::Ctor(Stream input) {
}

void BinaryReader___::Ctor(Stream input, Encoding encoding) {
}

void BinaryReader___::Ctor(Stream input, Encoding encoding, Boolean leaveOpen) {
}

void BinaryReader___::Dispose(Boolean disposing) {
}

void BinaryReader___::Dispose() {
}

void BinaryReader___::Close() {
}

void BinaryReader___::ThrowIfDisposed() {
}

Int32 BinaryReader___::PeekChar() {
  return Int32();
}

Int32 BinaryReader___::Read() {
  return Int32();
}

Byte BinaryReader___::ReadByte() {
  return Byte();
}

Byte BinaryReader___::InternalReadByte() {
  return Byte();
}

SByte BinaryReader___::ReadSByte() {
  return SByte();
}

Boolean BinaryReader___::ReadBoolean() {
  return Boolean();
}

Char BinaryReader___::ReadChar() {
  return Char();
}

Int16 BinaryReader___::ReadInt16() {
  return Int16();
}

UInt16 BinaryReader___::ReadUInt16() {
  return UInt16();
}

Int32 BinaryReader___::ReadInt32() {
  return Int32();
}

UInt32 BinaryReader___::ReadUInt32() {
  return UInt32();
}

Int64 BinaryReader___::ReadInt64() {
  return Int64();
}

UInt64 BinaryReader___::ReadUInt64() {
  return UInt64();
}

Single BinaryReader___::ReadSingle() {
  return Single();
}

Double BinaryReader___::ReadDouble() {
  return Double();
}

Decimal BinaryReader___::ReadDecimal() {
  return Decimal();
}

String BinaryReader___::ReadString() {
  return nullptr;
}

Int32 BinaryReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 BinaryReader___::Read(Span<Char> buffer) {
  return Int32();
}

Int32 BinaryReader___::InternalReadChars(Span<Char> buffer) {
  return Int32();
}

Array<Char> BinaryReader___::ReadChars(Int32 count) {
  return Array<Char>();
}

Int32 BinaryReader___::Read(Array<Byte> buffer, Int32 index, Int32 count) {
  return Int32();
}

Int32 BinaryReader___::Read(Span<Byte> buffer) {
  return Int32();
}

Array<Byte> BinaryReader___::ReadBytes(Int32 count) {
  return Array<Byte>();
}

ReadOnlySpan<Byte> BinaryReader___::InternalRead(Int32 numBytes) {
  return ReadOnlySpan<Byte>();
}

void BinaryReader___::FillBuffer(Int32 numBytes) {
}

Int32 BinaryReader___::Read7BitEncodedInt() {
  return Int32();
}

Int64 BinaryReader___::Read7BitEncodedInt64() {
  return Int64();
}

} // namespace System::Private::CoreLib::System::IO::BinaryReaderNamespace
