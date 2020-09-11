#include "VersioningHelper-dep.h"

#include <System.Private.CoreLib/System/AppDomain-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/Versioning/SxSRequirements.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace {
using namespace System::Globalization;
using namespace System::Text;

String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to) {
  return MakeVersionSafeName(name, from, to, nullptr);
}

String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to, Type type) {
  ResourceScope resourceScope = from & (ResourceScope::Machine | ResourceScope::Process | ResourceScope::AppDomain | ResourceScope::Library);
  ResourceScope resourceScope2 = to & (ResourceScope::Machine | ResourceScope::Process | ResourceScope::AppDomain | ResourceScope::Library);
  if (resourceScope > resourceScope2) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_ResourceScopeWrongDirection(), resourceScope, resourceScope2), "from");
  }
  SxSRequirements requirements = GetRequirements(to, from);
  if ((requirements & (SxSRequirements::AssemblyName | SxSRequirements::TypeName)) != 0 && type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type", SR::get_ArgumentNull_TypeRequiredByResourceScope());
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(name);
  Char value = '_';
  if ((requirements & SxSRequirements::ProcessID) != 0) {
    stringBuilder->Append(value);
    stringBuilder->Append((Char)'p');
    stringBuilder->Append(Environment::get_ProcessId());
  }
  if ((requirements & SxSRequirements::CLRInstanceID) != 0) {
    String cLRInstanceString = GetCLRInstanceString();
    stringBuilder->Append(value);
    stringBuilder->Append((Char)'r');
    stringBuilder->Append(cLRInstanceString);
  }
  if ((requirements & SxSRequirements::AppDomainID) != 0) {
    stringBuilder->Append(value);
    stringBuilder->Append((String)"ad");
    stringBuilder->Append(AppDomain::in::get_CurrentDomain()->get_Id());
  }
  if ((requirements & SxSRequirements::TypeName) != 0) {
    stringBuilder->Append(value);
    stringBuilder->Append(type->get_Name());
  }
  if ((requirements & SxSRequirements::AssemblyName) != 0) {
    stringBuilder->Append(value);
    stringBuilder->Append(type->get_Assembly()->get_FullName());
  }
  return stringBuilder->ToString();
}

String VersioningHelper::GetCLRInstanceString() {
  return 3.ToString(CultureInfo::in::get_InvariantCulture());
}

SxSRequirements VersioningHelper::GetRequirements(ResourceScope consumeAsScope, ResourceScope calleeScope) {
  SxSRequirements sxSRequirements = SxSRequirements::None;
  switch (calleeScope & (ResourceScope::Machine | ResourceScope::Process | ResourceScope::AppDomain | ResourceScope::Library)) {
    case ResourceScope::Machine:
      switch (consumeAsScope & (ResourceScope::Machine | ResourceScope::Process | ResourceScope::AppDomain | ResourceScope::Library)) {
        case ResourceScope::Process:
          sxSRequirements |= SxSRequirements::ProcessID;
          break;
        case ResourceScope::AppDomain:
          sxSRequirements |= (SxSRequirements::AppDomainID | SxSRequirements::ProcessID | SxSRequirements::CLRInstanceID);
          break;
        default:
          rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_BadResourceScopeTypeBits(), consumeAsScope), "consumeAsScope");
        case ResourceScope::Machine:
          break;
      }
      break;
    case ResourceScope::Process:
      if ((consumeAsScope & ResourceScope::AppDomain) != 0) {
        sxSRequirements |= (SxSRequirements::AppDomainID | SxSRequirements::CLRInstanceID);
      }
      break;
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_BadResourceScopeTypeBits(), calleeScope), "calleeScope");
    case ResourceScope::AppDomain:
      break;
  }
  switch (calleeScope & (ResourceScope::Private | ResourceScope::Assembly)) {
    case ResourceScope::None:
      switch (consumeAsScope & (ResourceScope::Private | ResourceScope::Assembly)) {
        case ResourceScope::Assembly:
          sxSRequirements |= SxSRequirements::AssemblyName;
          break;
        case ResourceScope::Private:
          sxSRequirements |= (SxSRequirements::AssemblyName | SxSRequirements::TypeName);
          break;
        default:
          rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_BadResourceScopeVisibilityBits(), consumeAsScope), "consumeAsScope");
        case ResourceScope::None:
          break;
      }
      break;
    case ResourceScope::Assembly:
      if ((consumeAsScope & ResourceScope::Private) != 0) {
        sxSRequirements |= SxSRequirements::TypeName;
      }
      break;
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_BadResourceScopeVisibilityBits(), calleeScope), "calleeScope");
    case ResourceScope::Private:
      break;
  }
  return sxSRequirements;
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace
