#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
namespace PasteArgumentsNamespace {
using namespace Collections::Generic;
using namespace Text;
class PasteArguments {
  public: static void AppendArgument(StringBuilder stringBuilder, String argument);
  private: static Boolean ContainsNoWhitespaceOrQuotes(String s);
  public: static String Paste(IEnumerable<String> arguments, Boolean pasteFirstArgumentUsingArgV0Rules);
};
} // namespace PasteArgumentsNamespace
using PasteArguments = PasteArgumentsNamespace::PasteArguments;
} // namespace System::Private::CoreLib::System
