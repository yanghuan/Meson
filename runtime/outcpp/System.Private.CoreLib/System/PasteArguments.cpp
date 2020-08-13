#include "PasteArguments-dep.h"

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
}

String PasteArguments::Paste(IEnumerable<String> arguments, Boolean pasteFirstArgumentUsingArgV0Rules) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
}

} // namespace System::Private::CoreLib::System::PasteArgumentsNamespace
