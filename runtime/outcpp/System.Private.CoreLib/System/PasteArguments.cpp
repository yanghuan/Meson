#include "PasteArguments-dep.h"

#include <System.Private.CoreLib/System/ApplicationException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::PasteArgumentsNamespace {
void PasteArguments::AppendArgument(StringBuilder stringBuilder, String argument) {
  if (stringBuilder->get_Length() != 0) {
    stringBuilder->Append((Char)u' ');
  }
  if (argument->get_Length() != 0 && ContainsNoWhitespaceOrQuotes(argument)) {
    stringBuilder->Append(argument);
    return;
  }
  stringBuilder->Append((Char)u'"');
  Int32 num = 0;
  while (num < argument->get_Length()) {
    Char c = argument[num++];
    switch (c.get()) {
      case u'\\':
        {
          Int32 num2 = 1;
          while (num < argument->get_Length() && argument[num] == u'\\') {
            num++;
            num2++;
          }
          if (num == argument->get_Length()) {
            stringBuilder->Append(u'\\', num2 * 2);
          } else if (argument[num] == u'"') {
            stringBuilder->Append(u'\\', num2 * 2 + 1);
            stringBuilder->Append((Char)u'"');
            num++;
          } else {
            stringBuilder->Append(u'\\', num2);
          }

          break;
        }case u'"':
        stringBuilder->Append((Char)u'\\');
        stringBuilder->Append((Char)u'"');
        break;
      default:
        stringBuilder->Append(c);
        break;
    }
  }
  stringBuilder->Append((Char)u'"');
}

Boolean PasteArguments::ContainsNoWhitespaceOrQuotes(String s) {
  for (Char&& c : *s) {
    if (Char::IsWhiteSpace(c) || c == u'"') {
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
        if (c == u'"') {
          rt::throw_exception<ApplicationException>("The argv[0] argument cannot include a double quote.");
        }
        if (Char::IsWhiteSpace(c)) {
          flag = true;
        }
      }
      if (argument->get_Length() == 0 || flag) {
        stringBuilder->Append((Char)u'"');
        stringBuilder->Append(argument);
        stringBuilder->Append((Char)u'"');
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
