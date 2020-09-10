#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(IEnumerator)
namespace IDictionaryEnumeratorNamespace {
CLASS(IDictionaryEnumerator) : public object {
  public: using interface = rt::TypeList<IEnumerator>;
  public: Object get_Current();
  public: Object get_Key();
  public: Object get_Value();
  public: DictionaryEntry get_Entry();
  public: Boolean MoveNext();
  public: void Reset();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDictionaryEnumeratorNamespace
using IDictionaryEnumerator = IDictionaryEnumeratorNamespace::IDictionaryEnumerator;
} // namespace System::Private::CoreLib::System::Collections
