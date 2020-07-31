#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(UInt32)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::CompilerServices {
namespace UnsafeNamespace {
using namespace ::System::Private::CoreLib::System;
class Unsafe : public Object::in {
  public: template <class T>
  static void* AsPointer(T& value);
  public: template <class T>
  static Int32 SizeOf();
  public: template <class T>
  static T As(Object value);
  public: template <class TFrom, class TTo>
  static TTo& As(TFrom& source);
  public: template <class T>
  static T& Add(T& source, Int32 elementOffset);
  public: template <class T>
  static T& Add(T& source, IntPtr elementOffset);
  public: template <class T>
  static void* Add(void* source, Int32 elementOffset);
  public: template <class T>
  static T& AddByteOffset(T& source, UIntPtr byteOffset);
  public: template <class T>
  static Boolean AreSame(T& left, T& right);
  public: template <class T>
  static Boolean IsAddressGreaterThan(T& left, T& right);
  public: template <class T>
  static Boolean IsAddressLessThan(T& left, T& right);
  public: static void InitBlockUnaligned(Byte& startAddress, Byte value, UInt32 byteCount);
  public: template <class T>
  static T ReadUnaligned(void* source);
  public: template <class T>
  static T ReadUnaligned(Byte& source);
  public: template <class T>
  static void WriteUnaligned(void* destination, T value);
  public: template <class T>
  static void WriteUnaligned(Byte& destination, T value);
  public: template <class T>
  static T& AddByteOffset(T& source, IntPtr byteOffset);
  public: template <class T>
  static T Read(void* source);
  public: template <class T>
  static T Read(Byte& source);
  public: template <class T>
  static void Write(void* destination, T value);
  public: template <class T>
  static void Write(Byte& destination, T value);
  public: template <class T>
  static T& AsRef(void* source);
  public: template <class T>
  static T& AsRef(T& source);
  public: template <class T>
  static IntPtr ByteOffset(T& origin, T& target);
  public: template <class T>
  static T& NullRef();
  public: template <class T>
  static Boolean IsNullRef(T& source);
  public: template <class T>
  static void SkipInit(T& value);
};
} // namespace UnsafeNamespace
using Unsafe = UnsafeNamespace::Unsafe;
} // namespace System::Private::CoreLib::Internal::Runtime::CompilerServices
