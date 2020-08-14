#include "DiagnosticCounter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/CounterGroup-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DiagnosticCounter-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::DiagnosticCounterNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;

String DiagnosticCounter___::get_DisplayName() {
  return _displayName;
}

void DiagnosticCounter___::set_DisplayName(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("DisplayName");
  }
  _displayName = value;
}

String DiagnosticCounter___::get_DisplayUnits() {
  return _displayUnits;
}

void DiagnosticCounter___::set_DisplayUnits(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("DisplayUnits");
  }
  _displayUnits = value;
}

void DiagnosticCounter___::ctor(String name, Tracing::EventSource eventSource) {
  _displayName = "";
  _displayUnits = "";
}

void DiagnosticCounter___::Publish() {
  _group = CounterGroup::in::GetCounterGroup(EventSource);
  _group->Add((DiagnosticCounter)this);
}

void DiagnosticCounter___::Dispose() {
  if (_group != nullptr) {
    _group->Remove((DiagnosticCounter)this);
    _group = nullptr;
  }
}

void DiagnosticCounter___::AddMetadata(String key, String value) {
}

void DiagnosticCounter___::ReportOutOfBandMessage(String message) {
  EventSource->ReportOutOfBandMessage(message);
}

String DiagnosticCounter___::GetMetadataString() {
  if (_metadata == nullptr) {
    return "";
  }
  Dictionary<TKey, TValue>::in::Enumerator enumerator = _metadata->GetEnumerator();
  Boolean flag = enumerator.MoveNext();
  KeyValuePair<String, String> current = enumerator.get_Current();
  if (!enumerator.MoveNext()) {
    return current.get_Key() + ":" + current.get_Value();
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>()->Append(current.get_Key())->Append(58)->Append(current.get_Value());
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::DiagnosticCounterNamespace
