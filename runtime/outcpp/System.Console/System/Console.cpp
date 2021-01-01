#include "Console-dep.h"

#include <System.Console/System/ConsoleCancelEventArgs-dep.h>
#include <System.Console/System/ConsoleCancelEventHandler-dep.h>
#include <System.Console/System/ConsolePal-dep.h>
#include <System.Console/System/IO/SyncTextReader-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Console/System/Text/EncodingExtensions-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/StreamWriter-dep.h>
#include <System.Private.CoreLib/System/IO/TextWriter-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StrongBox-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Console::System::ConsoleNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Threading;
using namespace System::IO;
using namespace System::Text;

TextReader Console::get_In() {
  auto EnsureInitialized = []() -> TextReader {
    ConsolePal::EnsureConsoleInitialized();
    {
      rt::lock(s_syncObject);
      if (s_in == nullptr) {
        Volatile::Write(s_in, ConsolePal::GetOrCreateReader());
      }
      return s_in;
    }
  };
  TextReader as = Volatile::Read(s_in);
  return as != nullptr ? as : EnsureInitialized();
}

Encoding Console::get_InputEncoding() {
  Encoding encoding = Volatile::Read(s_inputEncoding);
  if (encoding == nullptr) {
    {
      rt::lock(s_syncObject);
      if (s_inputEncoding == nullptr) {
        Volatile::Write(s_inputEncoding, ConsolePal::get_InputEncoding());
      }
      return s_inputEncoding;
    }
  }
  return encoding;
}

void Console::set_InputEncoding(Encoding value) {
  CheckNonNull(value, "value");
  {
    rt::lock(s_syncObject);
    ConsolePal::SetConsoleInputEncoding(value);
    Volatile::Write(s_inputEncoding, (Encoding)value->Clone());
    Volatile::Write(s_in, (TextReader)nullptr);
  }
}

Encoding Console::get_OutputEncoding() {
  Encoding encoding = Volatile::Read(s_outputEncoding);
  if (encoding == nullptr) {
    {
      rt::lock(s_syncObject);
      if (s_outputEncoding == nullptr) {
        Volatile::Write(s_outputEncoding, ConsolePal::get_OutputEncoding());
      }
      return s_outputEncoding;
    }
  }
  return encoding;
}

void Console::set_OutputEncoding(Encoding value) {
  CheckNonNull(value, "value");
  {
    rt::lock(s_syncObject);
    ConsolePal::SetConsoleOutputEncoding(value);
    if (s_out != nullptr && !s_isOutTextWriterRedirected) {
      s_out->Flush();
      Volatile::Write(s_out, (TextWriter)nullptr);
    }
    if (s_error != nullptr && !s_isErrorTextWriterRedirected) {
      s_error->Flush();
      Volatile::Write(s_error, (TextWriter)nullptr);
    }
    Volatile::Write(s_outputEncoding, (Encoding)value->Clone());
  }
}

Boolean Console::get_KeyAvailable() {
  if (get_IsInputRedirected()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConsoleKeyAvailableOnFile());
  }
  return ConsolePal::get_KeyAvailable();
}

TextWriter Console::get_Out() {
  auto EnsureInitialized = []() -> TextWriter {
    {
      rt::lock(s_syncObject);
      if (s_out == nullptr) {
        Volatile::Write(s_out, CreateOutputWriter(OpenStandardOutput()));
      }
      return s_out;
    }
  };
  TextWriter as = Volatile::Read(s_out);
  return as != nullptr ? as : EnsureInitialized();
}

TextWriter Console::get_Error() {
  auto EnsureInitialized = []() -> TextWriter {
    {
      rt::lock(s_syncObject);
      if (s_error == nullptr) {
        Volatile::Write(s_error, CreateOutputWriter(OpenStandardError()));
      }
      return s_error;
    }
  };
  TextWriter as = Volatile::Read(s_error);
  return as != nullptr ? as : EnsureInitialized();
}

Boolean Console::get_IsInputRedirected() {
  auto EnsureInitialized = []() -> StrongBox<Boolean> {
    Volatile::Write(_isStdInRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsInputRedirectedCore()));
    return _isStdInRedirected;
  };
  StrongBox<Boolean> as = Volatile::Read(_isStdInRedirected);
  StrongBox<Boolean> strongBox = as != nullptr ? as : EnsureInitialized();
  return strongBox->Value;
}

Boolean Console::get_IsOutputRedirected() {
  auto EnsureInitialized = []() -> StrongBox<Boolean> {
    Volatile::Write(_isStdOutRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsOutputRedirectedCore()));
    return _isStdOutRedirected;
  };
  StrongBox<Boolean> as = Volatile::Read(_isStdOutRedirected);
  StrongBox<Boolean> strongBox = as != nullptr ? as : EnsureInitialized();
  return strongBox->Value;
}

Boolean Console::get_IsErrorRedirected() {
  auto EnsureInitialized = []() -> StrongBox<Boolean> {
    Volatile::Write(_isStdErrRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsErrorRedirectedCore()));
    return _isStdErrRedirected;
  };
  StrongBox<Boolean> as = Volatile::Read(_isStdErrRedirected);
  StrongBox<Boolean> strongBox = as != nullptr ? as : EnsureInitialized();
  return strongBox->Value;
}

Int32 Console::get_CursorSize() {
  return ConsolePal::get_CursorSize();
}

void Console::set_CursorSize(Int32 value) {
  ConsolePal::set_CursorSize(value);
}

Boolean Console::get_NumberLock() {
  return ConsolePal::get_NumberLock();
}

Boolean Console::get_CapsLock() {
  return ConsolePal::get_CapsLock();
}

ConsoleColor Console::get_BackgroundColor() {
  return ConsolePal::get_BackgroundColor();
}

void Console::set_BackgroundColor(ConsoleColor value) {
  ConsolePal::set_BackgroundColor(value);
}

ConsoleColor Console::get_ForegroundColor() {
  return ConsolePal::get_ForegroundColor();
}

void Console::set_ForegroundColor(ConsoleColor value) {
  ConsolePal::set_ForegroundColor(value);
}

Int32 Console::get_BufferWidth() {
  return ConsolePal::get_BufferWidth();
}

void Console::set_BufferWidth(Int32 value) {
  ConsolePal::set_BufferWidth(value);
}

Int32 Console::get_BufferHeight() {
  return ConsolePal::get_BufferHeight();
}

void Console::set_BufferHeight(Int32 value) {
  ConsolePal::set_BufferHeight(value);
}

Int32 Console::get_WindowLeft() {
  return ConsolePal::get_WindowLeft();
}

void Console::set_WindowLeft(Int32 value) {
  ConsolePal::set_WindowLeft(value);
}

Int32 Console::get_WindowTop() {
  return ConsolePal::get_WindowTop();
}

void Console::set_WindowTop(Int32 value) {
  ConsolePal::set_WindowTop(value);
}

Int32 Console::get_WindowWidth() {
  return ConsolePal::get_WindowWidth();
}

void Console::set_WindowWidth(Int32 value) {
  ConsolePal::set_WindowWidth(value);
}

Int32 Console::get_WindowHeight() {
  return ConsolePal::get_WindowHeight();
}

void Console::set_WindowHeight(Int32 value) {
  ConsolePal::set_WindowHeight(value);
}

Int32 Console::get_LargestWindowWidth() {
  return ConsolePal::get_LargestWindowWidth();
}

Int32 Console::get_LargestWindowHeight() {
  return ConsolePal::get_LargestWindowHeight();
}

Boolean Console::get_CursorVisible() {
  return ConsolePal::get_CursorVisible();
}

void Console::set_CursorVisible(Boolean value) {
  ConsolePal::set_CursorVisible(value);
}

Int32 Console::get_CursorLeft() {
  return ConsolePal::get_CursorLeft();
}

void Console::set_CursorLeft(Int32 value) {
  SetCursorPosition(value, get_CursorTop());
}

Int32 Console::get_CursorTop() {
  return ConsolePal::get_CursorTop();
}

void Console::set_CursorTop(Int32 value) {
  SetCursorPosition(get_CursorLeft(), value);
}

String Console::get_Title() {
  return ConsolePal::get_Title();
}

void Console::set_Title(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  ConsolePal::set_Title(value);
}

Boolean Console::get_TreatControlCAsInput() {
  return ConsolePal::get_TreatControlCAsInput();
}

void Console::set_TreatControlCAsInput(Boolean value) {
  ConsolePal::set_TreatControlCAsInput(value);
}

ConsoleKeyInfo Console::ReadKey() {
  return ConsolePal::ReadKey(false);
}

ConsoleKeyInfo Console::ReadKey(Boolean intercept) {
  return ConsolePal::ReadKey(intercept);
}

TextWriter Console::CreateOutputWriter(Stream outputStream) {
  return TextWriter::in::Synchronized((outputStream == Stream::in::Null) ? StreamWriter::in::Null : rt::newobj<StreamWriter>(outputStream, EncodingExtensions::RemovePreamble(get_OutputEncoding()), 256, true));
}

void Console::ResetColor() {
  ConsolePal::ResetColor();
}

void Console::SetBufferSize(Int32 width, Int32 height) {
  ConsolePal::SetBufferSize(width, height);
}

void Console::SetWindowPosition(Int32 left, Int32 top) {
  ConsolePal::SetWindowPosition(left, top);
}

void Console::SetWindowSize(Int32 width, Int32 height) {
  ConsolePal::SetWindowSize(width, height);
}

void Console::Beep() {
  ConsolePal::Beep();
}

void Console::Beep(Int32 frequency, Int32 duration) {
  ConsolePal::Beep(frequency, duration);
}

void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop) {
  ConsolePal::MoveBufferArea(sourceLeft, sourceTop, sourceWidth, sourceHeight, targetLeft, targetTop, ' ', ConsoleColor::Black, get_BackgroundColor());
}

void Console::MoveBufferArea(Int32 sourceLeft, Int32 sourceTop, Int32 sourceWidth, Int32 sourceHeight, Int32 targetLeft, Int32 targetTop, Char sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {
  ConsolePal::MoveBufferArea(sourceLeft, sourceTop, sourceWidth, sourceHeight, targetLeft, targetTop, sourceChar, sourceForeColor, sourceBackColor);
}

void Console::Clear() {
  ConsolePal::Clear();
}

void Console::SetCursorPosition(Int32 left, Int32 top) {
  if (left < 0 || left >= 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("left", left, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  if (top < 0 || top >= 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("top", top, SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries());
  }
  ConsolePal::SetCursorPosition(left, top);
}

Stream Console::OpenStandardInput() {
  return ConsolePal::OpenStandardInput();
}

Stream Console::OpenStandardInput(Int32 bufferSize) {
  if (bufferSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return OpenStandardInput();
}

Stream Console::OpenStandardOutput() {
  return ConsolePal::OpenStandardOutput();
}

Stream Console::OpenStandardOutput(Int32 bufferSize) {
  if (bufferSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return OpenStandardOutput();
}

Stream Console::OpenStandardError() {
  return ConsolePal::OpenStandardError();
}

Stream Console::OpenStandardError(Int32 bufferSize) {
  if (bufferSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return OpenStandardError();
}

void Console::SetIn(TextReader newIn) {
  CheckNonNull(newIn, "newIn");
  newIn = SyncTextReader::in::GetSynchronizedTextReader(newIn);
  {
    rt::lock(s_syncObject);
    Volatile::Write(s_in, newIn);
  }
}

void Console::SetOut(TextWriter newOut) {
  CheckNonNull(newOut, "newOut");
  newOut = TextWriter::in::Synchronized(newOut);
  {
    rt::lock(s_syncObject);
    s_isOutTextWriterRedirected = true;
    Volatile::Write(s_out, newOut);
  }
}

void Console::SetError(TextWriter newError) {
  CheckNonNull(newError, "newError");
  newError = TextWriter::in::Synchronized(newError);
  {
    rt::lock(s_syncObject);
    s_isErrorTextWriterRedirected = true;
    Volatile::Write(s_error, newError);
  }
}

void Console::CheckNonNull(Object obj, String paramName) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>(paramName);
  }
}

Int32 Console::Read() {
  return get_In()->Read();
}

String Console::ReadLine() {
  return get_In()->ReadLine();
}

void Console::WriteLine() {
  get_Out()->WriteLine();
}

void Console::WriteLine(Boolean value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Char value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Array<Char> buffer) {
  get_Out()->WriteLine(buffer);
}

void Console::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  get_Out()->WriteLine(buffer, index, count);
}

void Console::WriteLine(Decimal value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Double value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Single value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Int32 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(UInt32 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Int64 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(UInt64 value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(Object value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(String value) {
  get_Out()->WriteLine(value);
}

void Console::WriteLine(String format, Object arg0) {
  get_Out()->WriteLine(format, arg0);
}

void Console::WriteLine(String format, Object arg0, Object arg1) {
  get_Out()->WriteLine(format, arg0, arg1);
}

void Console::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  get_Out()->WriteLine(format, arg0, arg1, arg2);
}

void Console::WriteLine(String format, Array<Object> arg) {
  if (arg == nullptr) {
    get_Out()->WriteLine(format, nullptr, nullptr);
  } else {
    get_Out()->WriteLine(format, arg);
  }
}

void Console::Write(String format, Object arg0) {
  get_Out()->Write(format, arg0);
}

void Console::Write(String format, Object arg0, Object arg1) {
  get_Out()->Write(format, arg0, arg1);
}

void Console::Write(String format, Object arg0, Object arg1, Object arg2) {
  get_Out()->Write(format, arg0, arg1, arg2);
}

void Console::Write(String format, Array<Object> arg) {
  if (arg == nullptr) {
    get_Out()->Write(format, nullptr, nullptr);
  } else {
    get_Out()->Write(format, arg);
  }
}

void Console::Write(Boolean value) {
  get_Out()->Write(value);
}

void Console::Write(Char value) {
  get_Out()->Write(value);
}

void Console::Write(Array<Char> buffer) {
  get_Out()->Write(buffer);
}

void Console::Write(Array<Char> buffer, Int32 index, Int32 count) {
  get_Out()->Write(buffer, index, count);
}

void Console::Write(Double value) {
  get_Out()->Write(value);
}

void Console::Write(Decimal value) {
  get_Out()->Write(value);
}

void Console::Write(Single value) {
  get_Out()->Write(value);
}

void Console::Write(Int32 value) {
  get_Out()->Write(value);
}

void Console::Write(UInt32 value) {
  get_Out()->Write(value);
}

void Console::Write(Int64 value) {
  get_Out()->Write(value);
}

void Console::Write(UInt64 value) {
  get_Out()->Write(value);
}

void Console::Write(Object value) {
  get_Out()->Write(value);
}

void Console::Write(String value) {
  get_Out()->Write(value);
}

Boolean Console::HandleBreakEvent(ConsoleSpecialKey controlKey) {
  ConsoleCancelEventHandler consoleCancelEventHandler = s_cancelCallbacks;
  if (consoleCancelEventHandler == nullptr) {
    return false;
  }
  ConsoleCancelEventArgs consoleCancelEventArgs = rt::newobj<ConsoleCancelEventArgs>(controlKey);
  consoleCancelEventHandler(nullptr, consoleCancelEventArgs);
  return consoleCancelEventArgs->get_Cancel();
}

void Console::cctor() {
  s_syncObject = rt::newobj<Object>();
}

TextReader Console::_get_In_g__EnsureInitialized13_0() {
  ConsolePal::EnsureConsoleInitialized();
  {
    rt::lock(s_syncObject);
    if (s_in == nullptr) {
      Volatile::Write(s_in, ConsolePal::GetOrCreateReader());
    }
    return s_in;
  }
}

TextWriter Console::_get_Out_g__EnsureInitialized25_0() {
  {
    rt::lock(s_syncObject);
    if (s_out == nullptr) {
      Volatile::Write(s_out, CreateOutputWriter(OpenStandardOutput()));
    }
    return s_out;
  }
}

TextWriter Console::_get_Error_g__EnsureInitialized27_0() {
  {
    rt::lock(s_syncObject);
    if (s_error == nullptr) {
      Volatile::Write(s_error, CreateOutputWriter(OpenStandardError()));
    }
    return s_error;
  }
}

StrongBox<Boolean> Console::_get_IsInputRedirected_g__EnsureInitialized33_0() {
  Volatile::Write(_isStdInRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsInputRedirectedCore()));
  return _isStdInRedirected;
}

StrongBox<Boolean> Console::_get_IsOutputRedirected_g__EnsureInitialized35_0() {
  Volatile::Write(_isStdOutRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsOutputRedirectedCore()));
  return _isStdOutRedirected;
}

StrongBox<Boolean> Console::_get_IsErrorRedirected_g__EnsureInitialized37_0() {
  Volatile::Write(_isStdErrRedirected, rt::newobj<StrongBox<Boolean>>(ConsolePal::IsErrorRedirectedCore()));
  return _isStdErrRedirected;
}

} // namespace System::Console::System::ConsoleNamespace
