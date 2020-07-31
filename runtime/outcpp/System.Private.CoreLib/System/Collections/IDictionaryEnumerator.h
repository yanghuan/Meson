#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
namespace IDictionaryEnumeratorNamespace {
CLASS(IDictionaryEnumerator) : public Object::in {
  public: Object get_Key();
  public: Object get_Value();
  public: DictionaryEntry get_Entry();
};
} // namespace IDictionaryEnumeratorNamespace
using IDictionaryEnumerator = IDictionaryEnumeratorNamespace::IDictionaryEnumerator;
} // namespace System::Private::CoreLib::System::Collections
