#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/FILETIME.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace STATSTGNamespace {
struct STATSTG {
  public: String pwcsName;
  public: Int32 type;
  public: Int64 cbSize;
  public: FILETIME mtime;
  public: FILETIME ctime;
  public: FILETIME atime;
  public: Int32 grfMode;
  public: Int32 grfLocksSupported;
  public: Guid clsid;
  public: Int32 grfStateBits;
  public: Int32 reserved;
};
} // namespace STATSTGNamespace
using STATSTG = STATSTGNamespace::STATSTG;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
