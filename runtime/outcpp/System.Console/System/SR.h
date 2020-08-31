#pragma once

#include <System.Private.CoreLib/System/String.h>

namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Console::System {
namespace SRNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Resources;
class SR {
  public: static ResourceManager get_ResourceManager();
  public: static String get_ArgumentOutOfRange_ConsoleWindowBufferSize();
  public: static String get_ArgumentOutOfRange_ConsoleWindowSize_Size();
  public: static String get_ArgumentOutOfRange_NeedNonNegNum();
  public: static String get_ArgumentOutOfRange_NeedPosNum();
  public: static String get_ArgumentNull_Buffer();
  public: static String get_Argument_InvalidOffLen();
  public: static String get_NotSupported_UnseekableStream();
  public: static String get_ObjectDisposed_FileClosed();
  public: static String get_NotSupported_UnwritableStream();
  public: static String get_NotSupported_UnreadableStream();
  public: static String get_IO_AlreadyExists_Name();
  public: static String get_IO_FileExists_Name();
  public: static String get_IO_FileNotFound();
  public: static String get_IO_FileNotFound_FileName();
  public: static String get_IO_PathNotFound_NoPathName();
  public: static String get_IO_PathNotFound_Path();
  public: static String get_IO_PathTooLong();
  public: static String get_UnauthorizedAccess_IODenied_NoPathName();
  public: static String get_UnauthorizedAccess_IODenied_Path();
  public: static String get_IO_SharingViolation_File();
  public: static String get_IO_SharingViolation_NoFileName();
  public: static String get_IndexOutOfRange_IORaceCondition();
  public: static String get_Arg_InvalidConsoleColor();
  public: static String get_IO_NoConsole();
  public: static String get_InvalidOperation_ConsoleReadKeyOnFile();
  public: static String get_ArgumentOutOfRange_ConsoleKey();
  public: static String get_ArgumentOutOfRange_ConsoleBufferBoundaries();
  public: static String get_ArgumentOutOfRange_ConsoleWindowPos();
  public: static String get_InvalidOperation_ConsoleKeyAvailableOnFile();
  public: static String get_ArgumentOutOfRange_ConsoleBufferLessThanWindowSize();
  public: static String get_ArgumentOutOfRange_CursorSize();
  public: static String get_ArgumentOutOfRange_BeepFrequency();
  public: static String get_ArgumentNull_Array();
  public: static String get_ArgumentOutOfRange_IndexCountBuffer();
  public: static String get_ArgumentOutOfRange_IndexCount();
  public: static String get_ArgumentOutOfRange_Index();
  public: static String get_Argument_EncodingConversionOverflowBytes();
  public: static String get_Argument_EncodingConversionOverflowChars();
  public: static String get_ArgumentOutOfRange_GetByteCountOverflow();
  public: static String get_ArgumentOutOfRange_GetCharCountOverflow();
  public: static String get_Argument_InvalidCharSequenceNoIndex();
  public: static String get_IO_PathTooLong_Path();
  private: static Boolean UsingResourceKeys();
  public: static String GetResourceString(String resourceKey, String defaultString = nullptr);
  public: static String Format(String resourceFormat, Object p1);
  public: static String Format(String resourceFormat, Object p1, Object p2);
  private: static void cctor();
  private: static Boolean s_usingResourceKeys;
  private: static ResourceManager s_resourceManager;
};
} // namespace SRNamespace
using SR = SRNamespace::SR;
} // namespace System::Console::System
