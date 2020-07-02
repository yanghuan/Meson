#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
namespace IDictionaryEnumeratorNamespace {
CLASS(IDictionaryEnumerator) {
  public: Object get_Key();
  public: Object get_Value();
  public: DictionaryEntry get_Entry();
};
} // namespace IDictionaryEnumeratorNamespace
using IDictionaryEnumerator = IDictionaryEnumeratorNamespace::IDictionaryEnumerator;
} // namespace System::Private::CoreLib::System::Collections
