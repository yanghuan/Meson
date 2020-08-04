#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/IO/Stream.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
enum class FileAccess;
enum class SeekOrigin;
} // namespace System::Private::CoreLib::System::IO
namespace System::Console::System::IO {
namespace ConsoleStreamNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
CLASS(ConsoleStream) : public Stream::in {
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Boolean get_CanSeek();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void Ctor(FileAccess access);
  protected: void Dispose(Boolean disposing);
  public: void Flush();
  public: void SetLength(Int64 value);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  protected: void ValidateRead(Array<Byte> buffer, Int32 offset, Int32 count);
  protected: void ValidateWrite(Array<Byte> buffer, Int32 offset, Int32 count);
  private: Boolean _canRead;
  private: Boolean _canWrite;
};
} // namespace ConsoleStreamNamespace
using ConsoleStream = ConsoleStreamNamespace::ConsoleStream;
} // namespace System::Console::System::IO
