#include "Comparer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Comparer-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/IComparable.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Collections::ComparerNamespace {
using namespace System::Globalization;

void Comparer___::ctor(CultureInfo culture) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  _compareInfo = culture->get_CompareInfo();
}

void Comparer___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _compareInfo = (CompareInfo)info->GetValue("CompareInfo", rt::typeof<CompareInfo>());
}

void Comparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("CompareInfo", _compareInfo);
}

Int32 Comparer___::Compare(Object a, Object b) {
  if (a == b) {
    return 0;
  }
  if (a == nullptr) {
    return -1;
  }
  if (b == nullptr) {
    return 1;
  }
  String text = rt::as<String>(a);
  if (text != nullptr) {
    String text2 = rt::as<String>(b);
    if (text2 != nullptr) {
      return _compareInfo->Compare(text, text2);
    }
  }
  IComparable comparable = rt::as<IComparable>(a);
  if (comparable != nullptr) {
    return comparable->CompareTo(b);
  }
  IComparable comparable2 = rt::as<IComparable>(b);
  if (comparable2 != nullptr) {
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ImplementIComparable());
}

void Comparer___::cctor() {
  Default = rt::newobj<Comparer>(CultureInfo::in::get_CurrentCulture());
  DefaultInvariant = rt::newobj<Comparer>(CultureInfo::in::get_InvariantCulture());
}

} // namespace System::Private::CoreLib::System::Collections::ComparerNamespace
