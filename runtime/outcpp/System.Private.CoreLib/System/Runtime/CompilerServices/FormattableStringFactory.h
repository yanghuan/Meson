#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(FormattableString)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace FormattableStringFactoryNamespace {
class FormattableStringFactory {
  private: CLASS(ConcreteFormattableString) {
    public: String get_Format();
    public: Int32 get_ArgumentCount();
    public: Array<Object> GetArguments();
    public: Object GetArgument(Int32 index);
    public: String ToString(IFormatProvider formatProvider);
    private: String _format;
    private: Array<Object> _arguments;
  };
  public: static FormattableString Create(String format, Array<Object> arguments);
};
} // namespace FormattableStringFactoryNamespace
using FormattableStringFactory = FormattableStringFactoryNamespace::FormattableStringFactory;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
