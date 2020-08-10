#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextWriter.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Char)
FORWARDS(Double)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::CodeDom::Compiler {
namespace IndentedTextWriterNamespace {
using namespace IO;
using namespace Text;
CLASS(IndentedTextWriter) : public TextWriter::in {
  public: Encoding get_Encoding();
  public: String get_NewLine();
  public: void set_NewLine(String value);
  public: Int32 get_Indent();
  public: void set_Indent(Int32 value);
  public: TextWriter get_InnerWriter();
  public: void ctor(TextWriter writer);
  public: void ctor(TextWriter writer, String tabString);
  public: void Close();
  public: void Flush();
  protected: void OutputTabs();
  public: void Write(String s);
  public: void Write(Boolean value);
  public: void Write(Char value);
  public: void Write(Array<Char> buffer);
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(Double value);
  public: void Write(Single value);
  public: void Write(Int32 value);
  public: void Write(Int64 value);
  public: void Write(Object value);
  public: void Write(String format, Object arg0);
  public: void Write(String format, Object arg0, Object arg1);
  public: void Write(String format, Array<Object> arg);
  public: void WriteLineNoTabs(String s);
  public: void WriteLine(String s);
  public: void WriteLine();
  public: void WriteLine(Boolean value);
  public: void WriteLine(Char value);
  public: void WriteLine(Array<Char> buffer);
  public: void WriteLine(Array<Char> buffer, Int32 index, Int32 count);
  public: void WriteLine(Double value);
  public: void WriteLine(Single value);
  public: void WriteLine(Int32 value);
  public: void WriteLine(Int64 value);
  public: void WriteLine(Object value);
  public: void WriteLine(String format, Object arg0);
  public: void WriteLine(String format, Object arg0, Object arg1);
  public: void WriteLine(String format, Array<Object> arg);
  public: void WriteLine(UInt32 value);
  private: TextWriter _writer;
  private: String _tabString;
  private: Int32 _indentLevel;
  private: Boolean _tabsPending;
};
} // namespace IndentedTextWriterNamespace
using IndentedTextWriter = IndentedTextWriterNamespace::IndentedTextWriter;
} // namespace System::Private::CoreLib::System::CodeDom::Compiler
