#include "PasteArguments-dep.h"

#include <System.Private.CoreLib/System/ApplicationException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::PasteArgumentsNamespace {
void PasteArguments::AppendArgument(StringBuilder stringBuilder, String argument) {
  if (stringBuilder->get_Length() != 0) {
    stringBuilder->Append(32);
  }
  if (argument->get_Length() != 0 && ContainsNoWhitespaceOrQuotes(argument)) {
    stringBuilder->Append(argument);
    return;
  }
  stringBuilder->Append(34);
  Int32 num = 0;
  while (num < argument->get_Length()) {
    Char c = argument[num++];
    switch (c.get()) {
      case 92:
        {
          Int32 num2 = 1;
          while (num < argument->get_Length() && argument[num] == 92) {
            num++;
            num2++;
          }
          if (num == argument->get_Length()) {
            stringBuilder->Append(92, num2 * 2);
          } else if (argument[num] == 34) {
            stringBuilder->Append(92, num2 * 2 + 1);
            stringBuilder->Append(34);
            num++;
          } else {
            stringBuilder->Append(92, num2);
          }

          break;
        }case 34:
        stringBuilder->Append(92);
        stringBuilder->Append(34);
        break;
      default:
        stringBuilder->Append(c);
        break;
    }
  }
  stringBuilder->Append(34);
}

Boolean PasteArguments::ContainsNoWhitespaceOrQuotes(String s) {
  for (Char&& c : *s) {
    if (Char::IsWhiteSpace(c) || c == 34) {
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
        if (c == 34) {
          rt::throw_exception<ApplicationException>("The argv[0] argument cannot include a double quote.");
        }
        if (Char::IsWhiteSpace(c)) {
          flag = true;
        }
      }
      if (argument->get_Length() == 0 || flag) {
        stringBuilder->Append(34);
        stringBuilder->Append(argument);
        stringBuilder->Append(34);
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
