#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
namespace HandleProcessCorruptedStateExceptionsAttributeNamespace {
CLASS(HandleProcessCorruptedStateExceptionsAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace HandleProcessCorruptedStateExceptionsAttributeNamespace
using HandleProcessCorruptedStateExceptionsAttribute = HandleProcessCorruptedStateExceptionsAttributeNamespace::HandleProcessCorruptedStateExceptionsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
