#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IMoniker)
FORWARDS(FILETIME)
FORWARD(IEnumMoniker)
namespace IRunningObjectTableNamespace {
CLASS(IRunningObjectTable) {
  public: Int32 Register(Int32 grfFlags, Object punkObject, IMoniker pmkObjectName);
  public: void Revoke(Int32 dwRegister);
  public: Int32 IsRunning(IMoniker pmkObjectName);
  public: Int32 GetObject(IMoniker pmkObjectName, Object& ppunkObject);
  public: void NoteChangeTime(Int32 dwRegister, FILETIME& pfiletime);
  public: Int32 GetTimeOfLastChange(IMoniker pmkObjectName, FILETIME& pfiletime);
  public: void EnumRunning(IEnumMoniker& ppenumMoniker);
};
} // namespace IRunningObjectTableNamespace
using IRunningObjectTable = IRunningObjectTableNamespace::IRunningObjectTable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes