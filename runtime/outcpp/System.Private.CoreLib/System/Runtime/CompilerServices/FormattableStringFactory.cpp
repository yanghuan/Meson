#include "FormattableStringFactory-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/FormattableStringFactory-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::FormattableStringFactoryNamespace {
String FormattableStringFactory::ConcreteFormattableString___::get_Format() {
  return _format;
}

Int32 FormattableStringFactory::ConcreteFormattableString___::get_ArgumentCount() {
  return _arguments->get_Length();
}

void FormattableStringFactory::ConcreteFormattableString___::ctor(String format, Array<Object> arguments) {
  _format = format;
  _arguments = arguments;
}

Array<Object> FormattableStringFactory::ConcreteFormattableString___::GetArguments() {
  return _arguments;
}

Object FormattableStringFactory::ConcreteFormattableString___::GetArgument(Int32 index) {
  return _arguments[index];
}

String FormattableStringFactory::ConcreteFormattableString___::ToString(IFormatProvider formatProvider) {
  return String::in::Format(formatProvider, _format, rt::newarr<Array<Object>>(1, _arguments));
}

FormattableString FormattableStringFactory::Create(String format, Array<Object> arguments) {
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  if (arguments == nullptr) {
    rt::throw_exception<ArgumentNullException>("arguments");
  }
  return rt::newobj<ConcreteFormattableString>(format, arguments);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::FormattableStringFactoryNamespace
