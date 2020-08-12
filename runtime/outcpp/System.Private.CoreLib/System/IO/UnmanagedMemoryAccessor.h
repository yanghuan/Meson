#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IDisposable)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeBuffer)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::IO {
enum class FileAccess : int32_t;
namespace UnmanagedMemoryAccessorNamespace {
using namespace System::Runtime::InteropServices;
CLASS(UnmanagedMemoryAccessor) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Int64 get_Capacity();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  protected: Boolean get_IsOpen();
  protected: void ctor();
  public: void ctor(SafeBuffer buffer, Int64 offset, Int64 capacity);
  public: void ctor(SafeBuffer buffer, Int64 offset, Int64 capacity, FileAccess access);
  protected: void Initialize(SafeBuffer buffer, Int64 offset, Int64 capacity, FileAccess access);
  protected: void Dispose(Boolean disposing);
  public: void Dispose();
  public: Boolean ReadBoolean(Int64 position);
  public: Byte ReadByte(Int64 position);
  public: Char ReadChar(Int64 position);
  public: Int16 ReadInt16(Int64 position);
  public: Int32 ReadInt32(Int64 position);
  public: Int64 ReadInt64(Int64 position);
  public: Decimal ReadDecimal(Int64 position);
  public: Single ReadSingle(Int64 position);
  public: Double ReadDouble(Int64 position);
  public: SByte ReadSByte(Int64 position);
  public: UInt16 ReadUInt16(Int64 position);
  public: UInt32 ReadUInt32(Int64 position);
  public: UInt64 ReadUInt64(Int64 position);
  public: template <class T>
  void Read(Int64 position, T& structure);
  public: template <class T>
  Int32 ReadArray(Int64 position, Array<T> array, Int32 offset, Int32 count);
  public: void Write(Int64 position, Boolean value);
  public: void Write(Int64 position, Byte value);
  public: void Write(Int64 position, Char value);
  public: void Write(Int64 position, Int16 value);
  public: void Write(Int64 position, Int32 value);
  public: void Write(Int64 position, Int64 value);
  public: void Write(Int64 position, Decimal value);
  public: void Write(Int64 position, Single value);
  public: void Write(Int64 position, Double value);
  public: void Write(Int64 position, SByte value);
  public: void Write(Int64 position, UInt16 value);
  public: void Write(Int64 position, UInt32 value);
  public: void Write(Int64 position, UInt64 value);
  public: template <class T>
  void Write(Int64 position, T& structure);
  public: template <class T>
  void WriteArray(Int64 position, Array<T> array, Int32 offset, Int32 count);
  private: void EnsureSafeToRead(Int64 position, Int32 sizeOfType);
  private: void EnsureSafeToWrite(Int64 position, Int32 sizeOfType);
  private: SafeBuffer _buffer;
  private: Int64 _offset;
  private: Int64 _capacity;
  private: FileAccess _access;
  private: Boolean _isOpen;
  private: Boolean _canRead;
  private: Boolean _canWrite;
};
} // namespace UnmanagedMemoryAccessorNamespace
using UnmanagedMemoryAccessor = UnmanagedMemoryAccessorNamespace::UnmanagedMemoryAccessor;
} // namespace System::Private::CoreLib::System::IO
