#include "PasteArguments-dep.h"

#include <System.Private.CoreLib/System/ApplicationException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::PasteArgumentsNamespace {
void PasteArguments::AppendArgument(StringBuilder stringBuilder, String argument) {
  if (stringBuilder->get_Length() != 0) {
    stringBuilder->Append(' ');
  }
  if (argument->get_Length() != 0 && ContainsNoWhitespaceOrQuotes(argument)) {
    stringBuilder->Append(argument);
    return;
  }
  stringBuilder->Append('"');
  Int32 num = 0;
  while (num < argument->get_Length()) {
    Char c = argument[num++];
    switch (c.get()) {
      case '\\':
        {
          Int32 num2 = 1;
          while (num < argument->get_Length() && argument[num] == '\\') {
            num++;
            num2++;
          }
          if (num == argument->get_Length()) {
            stringBuilder->Append('\\', num2 * 2);
          } else if (argument[num] == '"') {
            stringBuilder->Append('\\', num2 * 2 + 1);
            stringBuilder->Append('"');
            num++;
          } else {
            stringBuilder->Append('\\', num2);
          }

          break;
        }case '"':
        stringBuilder->Append('\\');
        stringBuilder->Append('"');
        break;
      default:
        stringBuilder->Append(c);
        break;
    }
  }
  stringBuilder->Append('"');
}

Boolean PasteArguments::ContainsNoWhitespaceOrQuotes(String s) {
  for (Char&& c : *s) {
    if (Char::IsWhiteSpace(c) || c == '"') {
      return false;
    }
  }
  return true;
}

String PasteArguments::Paste(IEnumerable<String> arguments, Boolean pasteFirstArgumentUsingArgV0Rules) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  for (String&& argument : *arguments) {
    if (pasteFirstArgumentUsingArgV0Rules) {
      pasteFirstArgumentUsingArgV0Rules = false;
      Boolean flag = false;
      String text = argument;
      for (Char&& c : *text) {
        if (c == '"') {
          rt::throw_exception<ApplicationException>("The argv[0] argument cannot include a double quote.");
        }
        if (Char::IsWhiteSpace(c)) {
          flag = true;
        }
      }
      if (argument->get_Length() == 0 || flag) {
        stringBuilder->Append('"');
        stringBuilder->Append(argument);
        stringBuilder->Append('"');
      } else {
        stringBuilder->Append(argument);
      }
    } else {
      AppendArgument(stringBuilder, argument);
    }
  }
  return stringBuilder->ToString();
}

} // namespace System::Private::CoreLib::System::PasteArgumentsNamespace
