#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace Win32MarshalNamespace {
class Win32Marshal : public Object::in {
  public: static Exception GetExceptionForLastWin32Error(String path);
  public: static Exception GetExceptionForWin32Error(Int32 errorCode, String path);
  public: static Int32 MakeHRFromErrorCode(Int32 errorCode);
  public: static String GetMessage(Int32 errorCode);
};
} // namespace Win32MarshalNamespace
using Win32Marshal = Win32MarshalNamespace::Win32Marshal;
} // namespace System::Private::CoreLib::System::IO
