#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
FORWARDS(IntPtr)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IRestrictedErrorInfo)
FORWARDS(HSTRING_HEADER)
namespace UnsafeNativeMethodsNamespace {
class UnsafeNativeMethods {
  public: static IRestrictedErrorInfo GetRestrictedErrorInfo();
  public: static Boolean RoOriginateLanguageException(Int32 error, String message, IntPtr languageException);
  public: static void RoReportUnhandledError(IRestrictedErrorInfo error);
  public: static Int32 WindowsCreateString(String sourceString, Int32 length, IntPtr* hstring);
  public: static Int32 WindowsCreateStringReference(Char* sourceString, Int32 length, HSTRING_HEADER* hstringHeader, IntPtr* hstring);
  public: static Int32 WindowsDeleteString(IntPtr hstring);
  public: static Char* WindowsGetStringRawBuffer(IntPtr hstring, UInt32* length);
};
} // namespace UnsafeNativeMethodsNamespace
using UnsafeNativeMethods = UnsafeNativeMethodsNamespace::UnsafeNativeMethods;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
