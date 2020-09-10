#include "KeyValuePair-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::KeyValuePairNamespace {
using namespace System::Text;

String KeyValuePair<>::PairToString(Object key, Object value) {
  Char as[64] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  valueStringBuilder.Append('[');
  if (key != nullptr) {
    valueStringBuilder.Append(key->ToString());
  }
  valueStringBuilder.Append(", ");
  if (value != nullptr) {
    valueStringBuilder.Append(value->ToString());
  }
  valueStringBuilder.Append(']');
  return valueStringBuilder.ToString();
}

} // namespace System::Private::CoreLib::System::Collections::Generic::KeyValuePairNamespace
