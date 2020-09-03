#include "IndentedTextWriter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>

namespace System::Private::CoreLib::System::CodeDom::Compiler::IndentedTextWriterNamespace {
Encoding IndentedTextWriter___::get_Encoding() {
  return _writer->get_Encoding();
}

String IndentedTextWriter___::get_NewLine() {
  return _writer->get_NewLine();
}

void IndentedTextWriter___::set_NewLine(String value) {
  _writer->set_NewLine(value);
}

Int32 IndentedTextWriter___::get_Indent() {
  return _indentLevel;
}

void IndentedTextWriter___::set_Indent(Int32 value) {
  _indentLevel = Math::Max(value, 0);
}

TextWriter IndentedTextWriter___::get_InnerWriter() {
  return _writer;
}

void IndentedTextWriter___::ctor(TextWriter writer) {
}

void IndentedTextWriter___::ctor(TextWriter writer, String tabString) {
  if (writer == nullptr) {
    rt::throw_exception<ArgumentNullException>("writer");
  }
  _writer = writer;
  _tabString = tabString;
  _indentLevel = 0;
  _tabsPending = false;
}

void IndentedTextWriter___::Close() {
  _writer->Close();
}

void IndentedTextWriter___::Flush() {
  _writer->Flush();
}

void IndentedTextWriter___::OutputTabs() {
  if (_tabsPending) {
    for (Int32 i = 0; i < _indentLevel; i++) {
      _writer->Write(_tabString);
    }
    _tabsPending = false;
  }
}

void IndentedTextWriter___::Write(String s) {
  OutputTabs();
  _writer->Write(s);
}

void IndentedTextWriter___::Write(Boolean value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Char value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Array<Char> buffer) {
  OutputTabs();
  _writer->Write(buffer);
}

void IndentedTextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
  OutputTabs();
  _writer->Write(buffer, index, count);
}

void IndentedTextWriter___::Write(Double value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Single value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Int32 value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Int64 value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(Object value) {
  OutputTabs();
  _writer->Write(value);
}

void IndentedTextWriter___::Write(String format, Object arg0) {
  OutputTabs();
  _writer->Write(format, arg0);
}

void IndentedTextWriter___::Write(String format, Object arg0, Object arg1) {
  OutputTabs();
  _writer->Write(format, arg0, arg1);
}

void IndentedTextWriter___::Write(String format, Array<Object> arg) {
  OutputTabs();
  _writer->Write(format, arg);
}

void IndentedTextWriter___::WriteLineNoTabs(String s) {
  _writer->WriteLine(s);
}

void IndentedTextWriter___::WriteLine(String s) {
  OutputTabs();
  _writer->WriteLine(s);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine() {
  OutputTabs();
  _writer->WriteLine();
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Boolean value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Char value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Array<Char> buffer) {
  OutputTabs();
  _writer->WriteLine(buffer);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  OutputTabs();
  _writer->WriteLine(buffer, index, count);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Double value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Single value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Int32 value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Int64 value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(Object value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(String format, Object arg0) {
  OutputTabs();
  _writer->WriteLine(format, arg0);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(String format, Object arg0, Object arg1) {
  OutputTabs();
  _writer->WriteLine(format, arg0, arg1);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(String format, Array<Object> arg) {
  OutputTabs();
  _writer->WriteLine(format, arg);
  _tabsPending = true;
}

void IndentedTextWriter___::WriteLine(UInt32 value) {
  OutputTabs();
  _writer->WriteLine(value);
  _tabsPending = true;
}

} // namespace System::Private::CoreLib::System::CodeDom::Compiler::IndentedTextWriterNamespace
