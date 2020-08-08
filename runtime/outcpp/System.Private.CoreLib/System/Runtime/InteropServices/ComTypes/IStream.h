#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(STATSTG)
namespace IStreamNamespace {
CLASS(IStream) : public Object::in {
  public: void Read(Array<Byte> pv, Int32 cb, IntPtr pcbRead);
  public: void Write(Array<Byte> pv, Int32 cb, IntPtr pcbWritten);
  public: void Seek(Int64 dlibMove, Int32 dwOrigin, IntPtr plibNewPosition);
  public: void SetSize(Int64 libNewSize);
  public: void CopyTo(IStream pstm, Int64 cb, IntPtr pcbRead, IntPtr pcbWritten);
  public: void Commit(Int32 grfCommitFlags);
  public: void Revert();
  public: void LockRegion(Int64 libOffset, Int64 cb, Int32 dwLockType);
  public: void UnlockRegion(Int64 libOffset, Int64 cb, Int32 dwLockType);
  public: void Stat(STATSTG& pstatstg, Int32 grfStatFlag);
  public: void Clone(IStream& ppstm);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IStreamNamespace
using IStream = IStreamNamespace::IStream;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
