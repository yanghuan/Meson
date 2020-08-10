#pragma once

#include <System.Private.CoreLib/System/FormattableString.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace FormattableStringFactoryNamespace {
class FormattableStringFactory {
  private: CLASS(ConcreteFormattableString) : public FormattableString::in {
    public: String get_Format();
    public: Int32 get_ArgumentCount();
    public: void ctor(String format, Array<Object> arguments);
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
